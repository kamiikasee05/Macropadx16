#include <BleKeyboard.h>
#include <Preferences.h>

// ============================================
// CONFIGURACIÓN PARA 16 BOTONES (4x4)
// ============================================
#define NUM_BUTTONS 16

// Distribución de botones vista desde el frente:
// TOP:    1  2  3  4
//         5  6  7  8
//         9  10 11 12
// BOTTOM: 13 14 15 16

const uint8_t buttonPins[NUM_BUTTONS] = {
  1,  // Button 1
  2,  // Button 2
  3,  // Button 3
  4,  // Button 4
  5,  // Button 5
  6,  // Button 6
  7,  // Button 7
  8,  // Button 8
  9,  // Button 9
  10, // Button 10
  20, // Button 11
  21, // Button 12
  18, // Button 13
  19, // Button 14
  0,  // Button 15
  12  // Button 16
};

// LED integrado para indicación visual
#define LED_PIN LED_BUILTIN

// Configuración de debounce
#define DEBOUNCE_DELAY 50

// Estados de los botones
bool buttonStates[NUM_BUTTONS] = {false};
bool lastButtonStates[NUM_BUTTONS] = {false};
unsigned long lastDebounceTime[NUM_BUTTONS] = {0};

// Teclas F por defecto (F13-F24 y combinaciones)
uint8_t fKeys[NUM_BUTTONS] = {
  KEY_F13, KEY_F14, KEY_F15, KEY_F16,  // Fila 1
  KEY_F17, KEY_F18, KEY_F19, KEY_F20,  // Fila 2
  KEY_F21, KEY_F22, KEY_F23, KEY_F24,  // Fila 3
  KEY_F13, KEY_F14, KEY_F15, KEY_F16   // Fila 4
};

// Modificadores para cada botón (CTRL, SHIFT, ALT, GUI)
uint8_t modifiers[NUM_BUTTONS] = {0};

// Objeto BLE Keyboard
BleKeyboard bleKeyboard("Super Keys 16", "Kamiikasee", 100);

// Objeto Preferences para almacenamiento
Preferences preferences;

// ============================================
// SETUP
// ============================================
void setup() {
  Serial.begin(115200);
  Serial.println("Starting ESP32 BLE Macro Keyboard - 16 Buttons");
  
  // Configurar LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  // Configurar pines de botones como entrada con pull-up
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  
  // Cargar configuración guardada
  loadConfiguration();
  
  // Iniciar BLE Keyboard
  bleKeyboard.begin();
  
  // Indicar inicio con LED
  blinkLED(3);
  
  Serial.println("Setup complete!");
  printConfiguration();
}

// ============================================
// LOOP PRINCIPAL
// ============================================
void loop() {
  // Verificar estado de conexión BLE
  if (bleKeyboard.isConnected()) {
    // LED encendido cuando está conectado
    digitalWrite(LED_PIN, HIGH);
    
    // Escanear todos los botones
    for (int i = 0; i < NUM_BUTTONS; i++) {
      handleButton(i);
    }
    
    // Verificar comandos seriales para configuración
    handleSerialCommands();
  } else {
    // LED parpadeando cuando está desconectado
    static unsigned long lastBlink = 0;
    if (millis() - lastBlink > 500) {
      digitalWrite(LED_PIN, !digitalRead(LED_PIN));
      lastBlink = millis();
    }
  }
  
  delay(1);
}

// ============================================
// MANEJO DE BOTONES
// ============================================
void handleButton(int buttonIndex) {
  // Leer estado actual del botón (invertido por pull-up)
  bool reading = !digitalRead(buttonPins[buttonIndex]);
  
  // Verificar si el estado cambió
  if (reading != lastButtonStates[buttonIndex]) {
    lastDebounceTime[buttonIndex] = millis();
  }
  
  // Aplicar debounce
  if ((millis() - lastDebounceTime[buttonIndex]) > DEBOUNCE_DELAY) {
    // Si el estado es diferente al actual
    if (reading != buttonStates[buttonIndex]) {
      buttonStates[buttonIndex] = reading;
      
      // Si el botón fue presionado
      if (buttonStates[buttonIndex]) {
        Serial.print("Button ");
        Serial.print(buttonIndex + 1);
        Serial.println(" pressed");
        
        // Presionar modificadores si están configurados
        pressModifiers(buttonIndex);
        
        // Presionar la tecla F
        bleKeyboard.press(fKeys[buttonIndex]);
        
        // Pequeño delay para asegurar el registro
        delay(10);
        
        // Soltar todo
        bleKeyboard.releaseAll();
        
        // Feedback visual
        blinkLED(1);
      }
    }
  }
  
  lastButtonStates[buttonIndex] = reading;
}

// ============================================
// MODIFICADORES
// ============================================
void pressModifiers(int buttonIndex) {
  uint8_t mod = modifiers[buttonIndex];
  
  if (mod & 0x01) bleKeyboard.press(KEY_LEFT_CTRL);
  if (mod & 0x02) bleKeyboard.press(KEY_LEFT_SHIFT);
  if (mod & 0x04) bleKeyboard.press(KEY_LEFT_ALT);
  if (mod & 0x08) bleKeyboard.press(KEY_LEFT_GUI);
}

// ============================================
// CONFIGURACIÓN SERIAL
// ============================================
void handleSerialCommands() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    
    if (command.startsWith("SET")) {
      // Formato: SET,buttonIndex,fKey,modifiers
      parseSetCommand(command);
    } else if (command == "SAVE") {
      saveConfiguration();
      Serial.println("Configuration saved!");
    } else if (command == "LOAD") {
      loadConfiguration();
      Serial.println("Configuration loaded!");
    } else if (command == "PRINT") {
      printConfiguration();
    } else if (command == "RESET") {
      resetConfiguration();
      Serial.println("Configuration reset to defaults!");
    } else if (command == "TEST") {
      testAllButtons();
    }
  }
}

void parseSetCommand(String command) {
  // Formato: SET,0,KEY_F13,5
  // buttonIndex,fKey,modifiers (CTRL=1, SHIFT=2, ALT=4, GUI=8)
  
  int firstComma = command.indexOf(',');
  int secondComma = command.indexOf(',', firstComma + 1);
  int thirdComma = command.indexOf(',', secondComma + 1);
  
  if (firstComma > 0 && secondComma > 0 && thirdComma > 0) {
    int buttonIndex = command.substring(firstComma + 1, secondComma).toInt();
    int fKey = command.substring(secondComma + 1, thirdComma).toInt();
    int mod = command.substring(thirdComma + 1).toInt();
    
    if (buttonIndex >= 0 && buttonIndex < NUM_BUTTONS) {
      fKeys[buttonIndex] = fKey;
      modifiers[buttonIndex] = mod;
      
      Serial.print("Button ");
      Serial.print(buttonIndex + 1);
      Serial.print(" configured: F-Key=");
      Serial.print(fKey);
      Serial.print(" Modifiers=");
      Serial.println(mod);
    }
  }
}

// ============================================
// ALMACENAMIENTO PERSISTENTE
// ============================================
void saveConfiguration() {
  preferences.begin("macropad", false);
  
  for (int i = 0; i < NUM_BUTTONS; i++) {
    char keyF[20];
    char keyM[20];
    sprintf(keyF, "fkey_%d", i);
    sprintf(keyM, "mod_%d", i);
    
    preferences.putUChar(keyF, fKeys[i]);
    preferences.putUChar(keyM, modifiers[i]);
  }
  
  preferences.end();
  Serial.println("Configuration saved to flash");
}

void loadConfiguration() {
  preferences.begin("macropad", true);
  
  for (int i = 0; i < NUM_BUTTONS; i++) {
    char keyF[20];
    char keyM[20];
    sprintf(keyF, "fkey_%d", i);
    sprintf(keyM, "mod_%d", i);
    
    fKeys[i] = preferences.getUChar(keyF, KEY_F13 + (i % 12));
    modifiers[i] = preferences.getUChar(keyM, 0);
  }
  
  preferences.end();
  Serial.println("Configuration loaded from flash");
}

void resetConfiguration() {
  // Restaurar valores por defecto
  for (int i = 0; i < NUM_BUTTONS; i++) {
    if (i < 12) {
      fKeys[i] = KEY_F13 + i;
    } else {
      fKeys[i] = KEY_F13 + (i - 12);
    }
    modifiers[i] = 0;
  }
  
  saveConfiguration();
}

// ============================================
// UTILIDADES
// ============================================
void blinkLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }
}

void printConfiguration() {
  Serial.println("\n===== CURRENT CONFIGURATION =====");
  Serial.print("Device Name: ");
  Serial.println("Super Keys 16");
  Serial.print("BLE Connected: ");
  Serial.println(bleKeyboard.isConnected() ? "YES" : "NO");
  Serial.println("\nButton Mappings:");
  
  for (int i = 0; i < NUM_BUTTONS; i++) {
    Serial.print("Button ");
    Serial.print(i + 1);
    Serial.print(" (Pin ");
    Serial.print(buttonPins[i]);
    Serial.print("): F-Key=");
    Serial.print(fKeys[i]);
    Serial.print(" Mods=");
    
    if (modifiers[i] == 0) {
      Serial.println("None");
    } else {
      if (modifiers[i] & 0x01) Serial.print("CTRL ");
      if (modifiers[i] & 0x02) Serial.print("SHIFT ");
      if (modifiers[i] & 0x04) Serial.print("ALT ");
      if (modifiers[i] & 0x08) Serial.print("GUI ");
      Serial.println();
    }
  }
  Serial.println("=================================\n");
}

void testAllButtons() {
  Serial.println("\n===== TESTING ALL BUTTONS =====");
  Serial.println("Press each button to test...");
  Serial.println("Send 'DONE' to finish test\n");
  
  bool testing = true;
  bool tested[NUM_BUTTONS] = {false};
  int testedCount = 0;
  
  while (testing && testedCount < NUM_BUTTONS) {
    for (int i = 0; i < NUM_BUTTONS; i++) {
      bool reading = !digitalRead(buttonPins[i]);
      
      if (reading && !tested[i]) {
        tested[i] = true;
        testedCount++;
        
        Serial.print("✓ Button ");
        Serial.print(i + 1);
        Serial.print(" (Pin ");
        Serial.print(buttonPins[i]);
        Serial.print(") - ");
        Serial.print(testedCount);
        Serial.print("/");
        Serial.println(NUM_BUTTONS);
        
        blinkLED(1);
        delay(300);
      }
    }
    
    if (Serial.available() > 0) {
      String cmd = Serial.readStringUntil('\n');
      cmd.trim();
      if (cmd == "DONE") {
        testing = false;
      }
    }
    
    delay(10);
  }
  
  Serial.println("\n===== TEST COMPLETE =====");
  Serial.print("Tested: ");
  Serial.print(testedCount);
  Serial.print("/");
  Serial.println(NUM_BUTTONS);
  
  if (testedCount == NUM_BUTTONS) {
    Serial.println("✓ All buttons working!");
    blinkLED(5);
  } else {
    Serial.println("⚠ Some buttons not tested:");
    for (int i = 0; i < NUM_BUTTONS; i++) {
      if (!tested[i]) {
        Serial.print("  - Button ");
        Serial.print(i + 1);
        Serial.print(" (Pin ");
        Serial.print(buttonPins[i]);
        Serial.println(")");
      }
    }
  }
  Serial.println("=========================\n");
}
