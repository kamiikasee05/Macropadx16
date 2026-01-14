# 🤝 Guía de Contribución

¡Gracias por tu interés en contribuir a este proyecto! Este documento te guiará en el proceso.

## 📋 Tabla de Contenidos

- [Código de Conducta](#código-de-conducta)
- [¿Cómo puedo contribuir?](#cómo-puedo-contribuir)
- [Reportar Bugs](#reportar-bugs)
- [Sugerir Mejoras](#sugerir-mejoras)
- [Pull Requests](#pull-requests)
- [Guía de Estilo](#guía-de-estilo)

## 📜 Código de Conducta

Este proyecto adhiere a un código de conducta simple:

- Sé respetuoso con todos los contribuidores
- Acepta críticas constructivas
- Enfócate en lo que es mejor para la comunidad
- Muestra empatía hacia otros miembros

## 🎯 ¿Cómo puedo contribuir?

### Reportar Bugs

Antes de crear un reporte de bug:

1. **Verifica** que estés usando la última versión
2. **Busca** en los issues existentes para evitar duplicados
3. **Recopila** información sobre el bug

### Sugerir Mejoras

Las sugerencias de mejoras son bienvenidas.

## 🔧 Pull Requests

### Proceso

1. **Fork** el repositorio
2. **Crea** una rama desde `main`
3. **Haz** tus cambios
4. **Testea** que todo funcione
5. **Commit** con mensajes descriptivos
6. **Push** a tu fork
7. **Abre** un Pull Request

### Checklist antes de enviar PR

- [ ] El código compila sin errores
- [ ] Has probado en hardware real
- [ ] Has actualizado la documentación si es necesario
- [ ] Has agregado comentarios al código complejo

## 🎨 Guía de Estilo

### Código Arduino/C++

```cpp
// Constantes en UPPER_CASE
#define NUM_BUTTONS 16

// Funciones en camelCase
void handleButtonPress(int buttonIndex) {
    // Comentarios claros
    if (buttonIndex >= 0 && buttonIndex < NUM_BUTTONS) {
        pressButton(buttonIndex);
    }
}
```

## 💬 ¿Preguntas?

Si tienes preguntas sobre cómo contribuir:

1. Revisa la [documentación](docs/)
2. Busca en [Issues](../../issues)
3. Abre un nuevo issue con la etiqueta `question`

---

**¡Gracias por contribuir! 🎉**
