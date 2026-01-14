# Changelog

Todos los cambios notables de este proyecto serán documentados en este archivo.

El formato está basado en [Keep a Changelog](https://keepachangelog.com/es/1.0.0/),
y este proyecto adhiere a [Semantic Versioning](https://semver.org/lang/es/).

## [1.0.0] - 2026-01-14

### 🎉 Lanzamiento Inicial

#### Añadido
- Soporte para 16 botones en configuración 4x4
- Firmware para ESP32-C3 con Bluetooth BLE
- Firmware para ESP32-S3 con Bluetooth BLE
- Firmware para ESP32-S3 con USB HID
- Web flasher con interfaz visual moderna
- Configuración individual por botón (F13-F24)
- Soporte para modificadores (CTRL, SHIFT, ALT, GUI)
- Almacenamiento persistente de configuración en flash
- Modo de prueba de botones (comando TEST)
- Comandos serial para configuración avanzada
- LED de estado de conexión
- Sistema de debounce por software (50ms)
- Documentación completa en español
- Diagramas de conexión SVG
- Lista de materiales (BOM)
- Ejemplos de configuración para streaming, OBS, edición de video

#### Características Principales
- ✅ 16 botones programables independientes
- ✅ Sin necesidad de diodos (conexión directa GPIO)
- ✅ Sin ghosting por diseño
- ✅ Configuración vía web sin recompilar
- ✅ Compatible con Windows, macOS y Linux
- ✅ Batería no requerida (alimentado por USB)
- ✅ Open source bajo licencia MIT

#### Documentación
- README.md con guía rápida
- Guía de instalación paso a paso
- Guía de configuración detallada
- Troubleshooting completo
- Documentación de API serial
- Estructura de archivos del proyecto

#### Hardware
- Mapeo de pines optimizado para ESP32-C3
- Diseño compatible con ESP32-S3
- Soporte para switches mecánicos estándar
- Archivos STL para carcasa impresa en 3D (próximamente)

### Notas de Desarrollo

Este es el primer lanzamiento estable del proyecto. Ha sido probado con:
- ESP32-C3 SuperMini
- Arduino IDE 2.3.x
- ESP32 Board Support 3.3.5
- ESP32 BLE Keyboard library (última versión)

---

## [Unreleased]

### En Desarrollo
- [ ] Soporte para pantalla OLED (opcional)
- [ ] Modo de configuración WiFi
- [ ] App móvil para configuración
- [ ] Perfiles múltiples guardables
- [ ] Macros complejos (secuencias de teclas)
- [ ] Retroiluminación RGB por botón
- [ ] Case imprimible en 3D
- [ ] PCB personalizado

### Propuesto
- [ ] Soporte para encoders rotativos
- [ ] Modo multimedia (play, pause, volumen)
- [ ] Integración con Home Assistant
- [ ] Soporte para mouse (movimiento y clicks)

---

## Formato de Versiones

### [X.Y.Z] - AAAA-MM-DD

- **X (Major)**: Cambios incompatibles en la API
- **Y (Minor)**: Nueva funcionalidad compatible con versiones anteriores
- **Z (Patch)**: Correcciones de bugs compatibles

### Tipos de Cambios
- `Añadido` - para nuevas características
- `Modificado` - para cambios en funcionalidad existente
- `Obsoleto` - para características que se eliminarán pronto
- `Eliminado` - para características eliminadas
- `Corregido` - para corrección de bugs
- `Seguridad` - para vulnerabilidades

---

## Reportar Issues

Si encuentras bugs o tienes sugerencias:
1. Revisa los [Issues existentes](../../issues)
2. Si no existe, crea un [Nuevo Issue](../../issues/new)
3. Describe el problema o sugerencia claramente
4. Incluye versión de firmware, hardware usado, y pasos para reproducir

---

*Última actualización: 2026-01-14*
