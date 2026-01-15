# Firmware Binaries para GitHub Pages

⚠️ **IMPORTANTE:** Esta carpeta es necesaria para que GitHub Pages sirva los archivos .bin

## Cómo compilar y colocar el firmware aquí:

1. **Abre Arduino IDE**
2. **Abre:** `../../firmware/cheap_deck_c3_ble_16btn.ino` (carpeta raíz del repo)
3. **Configura:**
   - Tools → Board → ESP32C3 Dev Module
   - Tools → USB CDC On Boot → Enabled
4. **Compila:**
   - Sketch → Export Compiled Binary
5. **Busca el archivo compilado:**
   - En la carpeta `firmware/` del repositorio
   - Archivo: `cheap_deck_c3_ble_16btn.ino.merged.bin`
6. **Renombra a:** `cheap_deck_c3_ble_16btn.bin`
7. **Copia aquí:** `docs/firmware/binaries/cheap_deck_c3_ble_16btn.bin`

## Estructura necesaria:

```
docs/
├── firmware/
│   └── binaries/
│       └── cheap_deck_c3_ble_16btn.bin  ← EL ARCHIVO DEBE ESTAR AQUÍ
├── index.html
└── manifest.json
```

## Después de compilar:

```bash
git add docs/firmware/binaries/cheap_deck_c3_ble_16btn.bin
git commit -m "Add firmware binary for web flasher"
git push
```

Espera 1-2 minutos para que GitHub Pages actualice, luego el web flasher funcionará.
