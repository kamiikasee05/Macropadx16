# ⚡ ESP32 Macropad - 16 Botones

<div align="center">

![Version](https://img.shields.io/badge/version-1.0.0-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Platform](https://img.shields.io/badge/platform-ESP32--C3%20%7C%20ESP32--S3-orange.svg)
![Status](https://img.shields.io/badge/status-stable-success.svg)

**Macropad programable de 16 botones con Bluetooth BLE para streaming, edición y productividad**

[🚀 Quick Start](#-quick-start) •
[📖 Documentación](#-documentación) •
[🛠️ Hardware](#️-hardware) •
[💻 Software](#-software) •
[🤝 Contribuir](#-contribuir)

</div>

---

## 📸 Preview

```
┌─────────────────────────────────┐
│   ⚡ ESP32 MACROPAD 4x4         │
├────┬────┬────┬────┬─────────────┤
│ F13│ F14│ F15│ F16│             │
├────┼────┼────┼────┤   [ESP32]   │
│ F17│ F18│ F19│ F20│             │
├────┼────┼────┼────┤   Bluetooth │
│ F21│ F22│ F23│ F24│             │
├────┼────┼────┼────┤   USB-C     │
│ 🎬 │ 📹 │ 🔊 │ 💡 │             │
└────┴────┴────┴────┴─────────────┘
```

## ✨ Características

- ✅ **16 botones programables** independientes (matriz 4x4)
- ✅ **Bluetooth BLE 5.0** - Conexión inalámbrica sin lag
- ✅ **Teclas F13-F24** con modificadores (CTRL, SHIFT, ALT, GUI)
- ✅ **Configuración web** - Sin necesidad de recompilar código
- ✅ **Memoria persistente** - Guarda tu configuración en flash
- ✅ **Sin ghosting** - Cada botón usa GPIO independiente
- ✅ **Plug & Play** - Compatible con Windows, macOS y Linux
- ✅ **Open Source** - Hardware y software libre (MIT)
- ✅ **Bajo costo** - ~$15-30 USD en componentes

## 🎯 Casos de Uso

| Aplicación | Uso |
|------------|-----|
| **🎬 Streaming** | Control de OBS, escenas, fuentes, transiciones |
| **🎥 Edición** | Shortcuts para Premiere, DaVinci, Final Cut |
| **🎮 Gaming** | Macros personalizados, comandos rápidos |
| **💼 Productividad** | Atajos de teclado, automatización |
| **🎨 Diseño** | Photoshop, Illustrator, Blender shortcuts |
| **🎵 Audio** | Control de DAW, mezclador, efectos |

## 🚀 Quick Start

### 1. Flashear Firmware

**Opción A: Web Flasher (Recomendado)**

1. Abre: [Web Flasher](https://kamiikasee05.github.io/esp32-macropad-16-buttons)
2. Conecta tu ESP32-C3/S3 por USB
3. Haz clic en "Connect" y selecciona tu dispositivo
4. Haz clic en "Install" y espera
5. ¡Listo! 🎉

**Opción B: Arduino IDE**

1. Instala [Arduino IDE 2.x](https://www.arduino.cc/en/software)
2. Instala ESP32 Board Support
3. Instala biblioteca `ESP32 BLE Keyboard`
4. Abre `firmware/cheap_deck_c3_ble_16btn.ino`
5. Selecciona tu board y puerto
6. Compila y sube

### 2. Conectar por Bluetooth

1. Busca **"Super Keys 16"** en dispositivos Bluetooth
2. Empareja (no requiere PIN)
3. LED se mantendrá encendido cuando conecte

### 3. Configurar Botones

**Opción A: Web Configurator**
- Abre el web flasher y configura cada botón visualmente

**Opción B: Serial (avanzado)**
```bash
# Conecta a 115200 baud
SET,0,194,1  # Botón 1 = CTRL+F13
SET,1,195,2  # Botón 2 = SHIFT+F14
SAVE         # Guardar configuración
```

## 📖 Documentación

### Guías Completas
- [📦 Instalación](docs/installation.md) - Setup paso a paso
- [⚙️ Configuración](docs/configuration.md) - Personalización
- [🔧 Troubleshooting](docs/troubleshooting.md) - Solución de problemas
- [📡 API Serial](docs/api.md) - Comandos avanzados

### Ejemplos
- [🎬 OBS Studio](examples/obs-control/) - Control de streaming
- [🎥 Edición de Video](examples/video-editing/) - Shortcuts para editores
- [📺 Streaming](examples/streaming/) - Setup para streamers

## 🛠️ Hardware

### Componentes Necesarios

| Componente | Cantidad | Precio Aprox. |
|------------|----------|---------------|
| ESP32-C3 SuperMini | 1 | $3-5 USD |
| Switches Mecánicos | 16 | $5-15 USD |
| Cable USB-C | 1 | $2-5 USD |
| PCB/Protoboard | 1 | $2-10 USD |
| **Total** | | **$12-35 USD** |

📋 [Lista completa de materiales (BOM)](hardware/bom.md)

### Pinout ESP32-C3

```
Botón 1-4:   GPIO 1, 2, 3, 4
Botón 5-8:   GPIO 5, 6, 7, 8
Botón 9-10:  GPIO 9, 10
Botón 11-12: GPIO 20, 21
Botón 13-14: GPIO 18, 19
Botón 15-16: GPIO 0, 12
```

🔌 [Ver diagrama de conexión completo](hardware/schematic/wiring-diagram.svg)

### Carcasa 3D

Archivos STL para imprimir tu propia carcasa:
- 📦 [Modelos 3D](hardware/3d-models/)
- ⏱️ Tiempo de impresión: ~8 horas
- 📏 Material necesario: ~110g PLA

## 💻 Software

### Requisitos del Sistema

- **Para Flashear:**
  - Chrome o Edge (Web Flasher)
  - O Arduino IDE 2.x (manual)
  
- **Para Usar:**
  - Windows 10/11, macOS 10.15+, o Linux
  - Bluetooth 4.0+ (BLE)

### Configuración por Defecto

| Botón | Tecla | Modificadores |
|-------|-------|---------------|
| 1-4 | F13-F16 | Ninguno |
| 5-8 | F17-F20 | Ninguno |
| 9-12 | F21-F24 | Ninguno |
| 13-16 | F13-F16 | Personalizables |

### Comandos Serial

```bash
PRINT  # Ver configuración actual
SAVE   # Guardar en flash
LOAD   # Cargar desde flash
RESET  # Restaurar defaults
TEST   # Modo de prueba
SET,index,key,mods  # Configurar botón
```

📡 [Documentación completa de API](docs/api.md)

## 🏗️ Estructura del Proyecto

```
esp32-macropad-16-buttons/
├── firmware/              # Código Arduino
│   ├── cheap_deck_c3_ble_16btn.ino
│   └── binaries/          # Archivos .bin compilados
├── web-flasher/           # Interfaz web
│   ├── index.html
│   └── manifest.json
├── hardware/              # Esquemas y PCB
│   ├── schematic/
│   ├── 3d-models/
│   └── bom.md
├── docs/                  # Documentación
│   ├── installation.md
│   ├── configuration.md
│   └── troubleshooting.md
└── examples/              # Configuraciones ejemplo
    ├── obs-control/
    ├── video-editing/
    └── streaming/
```

## 🎨 Personalización

### Cambiar Nombre del Dispositivo

```cpp
// En el archivo .ino, línea ~50
BleKeyboard bleKeyboard("Tu Nombre Aquí", "Fabricante", 100);
```

### Ajustar Debounce

```cpp
#define DEBOUNCE_DELAY 50  // Milisegundos (default: 50ms)
```

### Modificar Pines

```cpp
const uint8_t buttonPins[NUM_BUTTONS] = {
    1, 2, 3, 4,     // Tus GPIOs aquí
    // ...
};
```

## 🐛 Troubleshooting

### El dispositivo no se detecta
1. Mantén presionado el botón **BOOT** al conectar USB
2. Prueba con otro cable USB (debe soportar datos)
3. Instala drivers CH340/CP2102 si es necesario

### No conecta por Bluetooth
1. Olvida el dispositivo si ya estaba emparejado
2. Reinicia Bluetooth en tu PC
3. Verifica que el LED parpadee (buscando) o esté fijo (conectado)

### Botones no responden
1. Ejecuta `TEST` por serial para verificar cada botón
2. Revisa las conexiones de los GPIO
3. Verifica que los switches funcionen con multímetro

🔧 [Guía completa de troubleshooting](docs/troubleshooting.md)

## 📊 Especificaciones Técnicas

| Especificación | Valor |
|----------------|-------|
| Microcontrolador | ESP32-C3 / ESP32-S3 |
| Conectividad | Bluetooth BLE 5.0 |
| Botones | 16 independientes |
| Latencia | <10ms |
| Batería | No (USB powered) |
| Consumo | ~100mA @ 5V |
| Dimensiones PCB | ~100x80mm |
| Peso | ~150g (con carcasa) |

## 🤝 Contribuir

¡Las contribuciones son bienvenidas! Por favor lee nuestra [guía de contribución](CONTRIBUTING.md).

### Formas de Contribuir
- 🐛 Reportar bugs
- 💡 Sugerir nuevas características
- 📝 Mejorar documentación
- 🔧 Enviar pull requests
- ⭐ Dar una estrella al proyecto

## 📜 Licencia

Este proyecto está bajo la licencia MIT. Ver [LICENSE](LICENSE) para más detalles.

## 🙏 Agradecimientos

- Basado en el trabajo de [dieskim](https://github.com/dieskim)
- Biblioteca [ESP32 BLE Keyboard](https://github.com/T-vK/ESP32-BLE-Keyboard) de T-vK
- Comunidad de Arduino y ESP32

## 📞 Soporte

- 📧 Email: tu-email@ejemplo.com
- 💬 [Discussions](../../discussions)
- 🐛 [Issues](../../issues)
- 📺 [YouTube](https://youtube.com) (tutoriales próximamente)

## 🗺️ Roadmap

- [ ] v1.1: Soporte para pantalla OLED
- [ ] v1.2: Perfiles múltiples
- [ ] v1.3: Retroiluminación RGB
- [ ] v2.0: PCB personalizado
- [ ] v2.1: Encoders rotativos

## 📈 Estado del Proyecto

- ✅ **Estable** - Listo para uso en producción
- 🧪 **Probado** - En ESP32-C3 y ESP32-S3
- 📝 **Documentado** - Guías completas disponibles
- 🔄 **Mantenido** - Actualizaciones regulares

---

<div align="center">

**⭐ Si te gusta este proyecto, considera darle una estrella ⭐**

Hecho con ❤️ por [Kamiikasee](https://github.com/kamiikasee05)

[⬆ Volver arriba](#-esp32-macropad---16-botones)

</div>
