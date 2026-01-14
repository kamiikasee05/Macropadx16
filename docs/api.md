# 📡 Documentación de API Serial

Referencia completa de comandos serial.

## Conexión Serial

```
Baudrate: 115200
Line ending: Newline (\n)
```

## Comandos Disponibles

### PRINT
Muestra la configuración actual.
```bash
PRINT
```

### SAVE
Guarda configuración en flash.
```bash
SAVE
```

### LOAD
Carga configuración desde flash.
```bash
LOAD
```

### RESET
Restaura configuración de fábrica.
```bash
RESET
```

### TEST
Modo de prueba de botones.
```bash
TEST
# Presiona botones
DONE  # Para terminar
```

### SET
Configura un botón específico.
```bash
SET,<índice>,<tecla>,<modificadores>

# Ejemplos:
SET,0,194,0     # Botón 1 = F13
SET,1,195,1     # Botón 2 = CTRL+F14
SET,2,196,3     # Botón 3 = CTRL+SHIFT+F15
```

## Códigos de Teclas F

| Tecla | Código |
|-------|--------|
| F13 | 194 |
| F14 | 195 |
| F15 | 196 |
| F16 | 197 |
| F17 | 198 |
| F18 | 199 |
| F19 | 200 |
| F20 | 201 |
| F21 | 202 |
| F22 | 203 |
| F23 | 204 |
| F24 | 205 |

## Modificadores

| Modificador | Valor |
|-------------|-------|
| CTRL | 1 |
| SHIFT | 2 |
| ALT | 4 |
| GUI | 8 |

**Combinar:** Suma los valores
- CTRL+SHIFT = 3
- CTRL+ALT = 5
- CTRL+SHIFT+ALT = 7
- Todos = 15

## Ejemplo Python

```python
import serial

ser = serial.Serial('COM3', 115200)

# Configurar botones
ser.write(b'SET,0,194,1\n')
ser.write(b'SET,1,195,2\n')
ser.write(b'SAVE\n')

ser.close()
```

## Integración con Software

### AutoHotkey (Windows)
```autohotkey
F13::Run, chrome.exe
^F14::Send, ^c
```

### OBS Studio
Settings → Hotkeys → Asignar teclas a acciones

[← Troubleshooting](troubleshooting.md) | [README →](../README.md)
