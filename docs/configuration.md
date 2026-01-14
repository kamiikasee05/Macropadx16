# ⚙️ Guía de Configuración

Aprende a configurar tu macropad para diferentes usos.

## Configuración Web

### Paso 1: Abrir Configurador
1. Ve al web flasher
2. Sección "2. Configurar Botones"

### Paso 2: Configurar Botones
Para cada botón:
- **Tecla F**: F13 hasta F24
- **Modificadores**: CTRL, SHIFT, ALT, GUI

### Paso 3: Guardar
1. Haz clic en "💾 Guardar Configuración"
2. Se guarda automáticamente en flash

## Configuración Serial

### Comandos Básicos
```bash
PRINT  # Ver configuración
SAVE   # Guardar en flash
LOAD   # Cargar desde flash
RESET  # Restaurar defaults
TEST   # Modo de prueba
```

### Configurar Botón
```bash
SET,<índice>,<tecla>,<modificadores>

# Ejemplo:
SET,0,194,1    # Botón 1 = CTRL+F13
SET,1,195,0    # Botón 2 = F14
```

## Códigos de Teclas

| Tecla | Código | Tecla | Código |
|-------|--------|-------|--------|
| F13 | 194 | F19 | 200 |
| F14 | 195 | F20 | 201 |
| F15 | 196 | F21 | 202 |
| F16 | 197 | F22 | 203 |
| F17 | 198 | F23 | 204 |
| F18 | 199 | F24 | 205 |

## Modificadores

| Modificador | Valor |
|-------------|-------|
| CTRL | 1 |
| SHIFT | 2 |
| ALT | 4 |
| GUI | 8 |

Para combinar: suma los valores (ej: CTRL+SHIFT = 3)

## Ejemplo: OBS Studio

```bash
# Escenas
SET,0,194,0     # F13 = Escena 1
SET,1,195,0     # F14 = Escena 2
SET,2,196,0     # F15 = Escena 3
SET,3,197,0     # F16 = Escena 4

# Toggle Fuentes
SET,4,198,1     # CTRL+F17 = Toggle Cámara
SET,5,199,1     # CTRL+F18 = Toggle Pantalla
SET,6,200,1     # CTRL+F19 = Toggle Mic

SAVE
```

[← Instalación](installation.md) | [Troubleshooting →](troubleshooting.md)
