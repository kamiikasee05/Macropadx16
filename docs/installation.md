# 📦 Guía de Instalación

Esta guía te llevará paso a paso en la instalación y configuración de tu ESP32 Macropad de 16 botones.

## Requisitos Previos

### Hardware Necesario
- ✅ ESP32-C3 SuperMini o ESP32-S3
- ✅ Cable USB-C con capacidad de datos
- ✅ Computadora con Windows, macOS o Linux

### Software Necesario
**Para Web Flasher:**
- ✅ Google Chrome (v89+) o Microsoft Edge (v89+)
- ✅ Conexión a internet

## Método 1: Web Flasher (Recomendado)

### Paso 1: Preparar el Hardware
1. **Conecta el ESP32** a tu computadora
2. **Si no se detecta**, mantén presionado **BOOT** mientras conectas

### Paso 2: Abrir el Web Flasher
1. Abre Chrome o Edge
2. Ve a tu URL de GitHub Pages
3. Verás la interfaz del flasher

### Paso 3: Flashear
1. Haz clic en **"INSTALL"**
2. Selecciona tu ESP32 del menú
3. Confirma el borrado
4. Espera a que complete (1-2 minutos)

## Verificación

### 1. LED
- **Parpadea**: Buscando conexión Bluetooth
- **Encendido fijo**: Conectado

### 2. Conectar Bluetooth
**Windows:**
- Settings → Bluetooth → Add device
- Busca "Super Keys 16"

**macOS:**
- System Preferences → Bluetooth
- Conecta "Super Keys 16"

### 3. Probar
1. Abre Serial Monitor (115200 baud)
2. Envía: `TEST`
3. Presiona cada botón

## Próximos Pasos
✅ [Configurar botones](configuration.md)
✅ [Ver ejemplos](../examples/)
✅ [Comandos serial](api.md)

[← Volver al README](../README.md)
