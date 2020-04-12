## Cola

Esta implementación contiene las siguientes operaciones:

- Agregar datos _(Create)_
  - Encolar _(enqueue)_.
- Mostrar la cola _(Read)_
  - Mostrar toda la cola.
  - Mostrar el frente de la cola _(peek)_.
  - Mostrar estado de la cola (llena/vacía, elementos insertados, tamaño máximo).
- Eliminar datos _(Delete)_
  - Desencolar _(dequeue)_.
- Utilidades
  - Generar una cola del 0 al 9.
  - Vaciar la cola.
  - Aumentar el tamaño máximo de la cola.
  - Disminuir el tamaño máximo de la cola.

### Uso

Compilar con gcc (Linux):

```
gcc cola.c -o cola
./cola
```

Compilar con gcc (Windows, es necesario MinGW):

```
gcc cola.c -o cola.exe
cola.exe
```
