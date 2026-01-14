# Firmware Binaries

Esta carpeta contiene los archivos binarios compilados del firmware.

## Cómo Generar los Binarios

1. Abre `cheap_deck_c3_ble_16btn.ino` en Arduino IDE
2. Configura el board:
   - `Tools → Board → ESP32C3 Dev Module`
   - `Tools → USB CDC On Boot → Enabled`
3. Compila: `Sketch → Export Compiled Binary`
4. Busca el archivo `*.ino.merged.bin` en la carpeta firmware
5. Renómbralo a `cheap_deck_c3_ble_16btn.bin`
6. Cópialo a esta carpeta

## Archivos Esperados

- `cheap_deck_c3_ble_16btn.bin` - Para ESP32-C3
- `cheap_deck_s3_ble_16btn.bin` - Para ESP32-S3 (opcional)

## Nota

Los archivos .bin deben estar en esta carpeta para que el web flasher funcione correctamente.
