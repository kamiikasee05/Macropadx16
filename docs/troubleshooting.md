# 🔧 Solución de Problemas

Guía para resolver problemas comunes.

## ❌ El dispositivo no aparece

**Soluciones:**
1. Mantén presionado **BOOT** al conectar USB
2. Prueba otro cable USB (con datos)
3. Instala drivers CH340/CP2102
4. Usa navegador Chrome o Edge

## ❌ No conecta por Bluetooth

**Soluciones:**
1. Olvida dispositivo anterior
2. Reinicia Bluetooth
3. Verifica LED (parpadea = buscando)
4. Acerca el macropad al PC (max 5m)

## ❌ Botón no responde

**Diagnóstico:**
1. Serial Monitor: `TEST`
2. Presiona el botón
3. ¿Se detecta?
   - SÍ → Problema de configuración
   - NO → Problema de hardware

**Solución:**
```bash
# Reconfigurar
SET,X,194,0  # X = índice del botón
SAVE
```

## ❌ Error de compilación

**Error: `cannot convert 'std::string'`**

Actualiza ESP32 BLE Keyboard:
1. Descarga: https://github.com/T-vK/ESP32-BLE-Keyboard/archive/refs/heads/master.zip
2. Arduino IDE → Include Library → Add .ZIP
3. Reinicia IDE

## ❌ Configuración no se guarda

**Solución:**
1. Verifica: "Configuration saved to flash"
2. Si no aparece: `Tools → Erase Flash → All`
3. Reflashea firmware

## 🔄 Reseteo Completo

```bash
# Borrar flash completo
Tools → Erase Flash → All Flash Contents
Sketch → Upload
```

## 📞 Ayuda

Si ninguna solución funcionó:
- 💬 [GitHub Discussions](../../discussions)
- 🐛 [Abrir Issue](../../issues/new)

[← Configuración](configuration.md) | [API →](api.md)
