# 🎬 Configuración para OBS Studio

Configuración optimizada del macropad para control de OBS Studio.

## 📊 Layout

```
┌────────┬────────┬────────┬────────┐
│ Escena │ Escena │ Escena │ Escena │
│   1    │   2    │   3    │   4    │
│  F13   │  F14   │  F15   │  F16   │
├────────┼────────┼────────┼────────┤
│ Toggle │ Toggle │ Toggle │ Toggle │
│ Cámara │Pantalla│  Mic   │ Audio  │
│ C+F17  │ C+F18  │ C+F19  │ C+F20  │
├────────┼────────┼────────┼────────┤
│ Start  │ Stop   │  Rec   │ Stop   │
│ Stream │ Stream │  Start │  Rec   │
│  F21   │  F22   │  F23   │  F24   │
├────────┼────────┼────────┼────────┤
│  Fade  │  Cut   │Stinger │ Mute   │
│        │        │        │  Mic   │
│ S+F13  │ S+F14  │ S+F15  │ C+F16  │
└────────┴────────┴────────┴────────┘
```

C = CTRL, S = SHIFT

## ⚙️ Comandos de Configuración

```bash
# Conectar al serial monitor (115200 baud)
RESET

# Fila 1 - Escenas
SET,0,194,0     # F13 = Escena 1
SET,1,195,0     # F14 = Escena 2
SET,2,196,0     # F15 = Escena 3
SET,3,197,0     # F16 = Escena 4

# Fila 2 - Toggle Fuentes
SET,4,198,1     # CTRL+F17 = Toggle Cámara
SET,5,199,1     # CTRL+F18 = Toggle Pantalla
SET,6,200,1     # CTRL+F19 = Toggle Mic
SET,7,201,1     # CTRL+F20 = Toggle Audio

# Fila 3 - Stream/Recording
SET,8,202,0     # F21 = Start Streaming
SET,9,203,0     # F22 = Stop Streaming
SET,10,204,0    # F23 = Start Recording
SET,11,205,0    # F24 = Stop Recording

# Fila 4 - Transiciones
SET,12,194,2    # SHIFT+F13 = Fade
SET,13,195,2    # SHIFT+F14 = Cut
SET,14,196,2    # SHIFT+F15 = Stinger
SET,15,197,1    # CTRL+F16 = Mute Mic

SAVE
```

## 🎛️ Configuración en OBS

1. `File → Settings → Hotkeys`
2. Mapear cada función a su tecla

### Escenas
| Función | Hotkey | Botón |
|---------|--------|-------|
| Gameplay | F13 | 1 |
| Chatting | F14 | 2 |
| BRB | F15 | 3 |
| Ending | F16 | 4 |

### Fuentes
| Función | Hotkey | Botón |
|---------|--------|-------|
| Webcam | CTRL+F17 | 5 |
| Game Capture | CTRL+F18 | 6 |
| Microphone | CTRL+F19 | 7 |
| Desktop Audio | CTRL+F20 | 8 |

### Stream/Recording
| Función | Hotkey | Botón |
|---------|--------|-------|
| Start Streaming | F21 | 9 |
| Stop Streaming | F22 | 10 |
| Start Recording | F23 | 11 |
| Stop Recording | F24 | 12 |

### Transiciones
| Función | Hotkey | Botón |
|---------|--------|-------|
| Fade | SHIFT+F13 | 13 |
| Cut | SHIFT+F14 | 14 |
| Stinger | SHIFT+F15 | 15 |
| Mute Mic | CTRL+F16 | 16 |

## 💡 Tips

### Workflow
1. **Pre-Stream:** Test escenas y fuentes
2. **Durante Stream:** Cambios rápidos sin mouse
3. **Emergencias:** Botón 7 para mutear rápido

### Escenas Sugeridas
- Escena 1: Gameplay
- Escena 2: Chatting/Facecam
- Escena 3: BRB/Starting Soon
- Escena 4: Ending Screen

## 🎨 Personalización

Agregar más escenas con ALT:
```bash
SET,0,194,4     # ALT+F13 = Escena 5
SET,1,195,4     # ALT+F14 = Escena 6
```

## 🐛 Troubleshooting

**Escenas no cambian:**
- Verifica nombres exactos en OBS
- Revisa hotkeys asignados
- Reinicia OBS

**Fuentes no togglean:**
- Nombres case-sensitive
- Fuente debe existir en escenas

[← Volver a Ejemplos](../) | [Edición Video →](../video-editing/)
