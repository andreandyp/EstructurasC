/* Creado por André Michel Pozos Nieto - @AndreAndyP */
/* Este es un ejemplo de cómo funciona una pila. Contiene las operaciones básicas. */
/* Probado en Windows 10*/
/* Una disculpa por la falta de acentos y signos de interrogación de apertura, no pude hacer que se mostraran en Windows*/
#include <stdio.h>
#include <stdlib.h>

// Métodos para especificar la operación. No son importantes para la implementación de la pila
void agregar();
void mostrar();
void eliminar();
void otros();

// El elemento debe tener el/los dato(s) que queremos guardar
// y una referencia al elemento que estará abajo de este.
typedef struct Elemento
{
    struct Elemento *inferior;
    int dato;
} Elemento;

Elemento *crearElemento(int nuevoDato);

// Una pila sólo necesita conocer al elemento que está hasta arriba (la cima).
// Vamos a agregar también una propiedad de tamaño máximo
// ya que las pilas también suelen tener un límite.
// Incluso podemos agregar una propiedad que nos diga el número de elementos para evitar iterarla
// cada vez que queremos saber cuántos elementos hay.
// Como siempre: más uso de memoria, más rápidas serán ciertas operaciones
// menos uso de memoria, menos rápidas serán ciertas opercaciones.
typedef struct Pila
{
    Elemento *top;
    int tamanoMaximo;
    int elementos;
} Pila;

// La pila que se usa en todo el programa
Pila *pila;

/* Funciones de la pila */
Pila *crearPila(int tamMaximo);

// Create
void _apilar(int nuevoDato); // push
// Read
void _mostrarPila();
Elemento *_mostrarCima();
void _mostrarEstado();
// Delete
Elemento *_desapilar(); // pop
// Utilidades varias
void _generarPilaEjemplo();
void _vaciar();
void _aumentarTamano();
void _disminuirTamano();

int main(int argc, char const *argv[])
{
    int opc = 0;
    // Menú para seleccionar la operación
    while (1)
    {
        printf("------Pila-----\n");
        printf("1) Apilar (push)\n");   // Create
        printf("2) Mostrar...\n");      // Read
        printf("3) Desapilar (pop)\n"); // Delete
        printf("4) Otros...\n");        // Utilidades
        printf("0) Salir\n\n");
        printf("Escoge una opcion: ");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            agregar();
            break;
        case 2:
            mostrar();
            break;
        case 3:
            eliminar();
            break;
        case 4:
            otros();
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
    return 0;
}

void agregar()
{
    int nuevoDato = 0;
    if (pila == NULL)
    {
        int tamanoMax = 0;
        printf("No hay ninguna pila creada. Vamos a crear una\n");
        printf("Que tamano maximo quieres ponerle? (n < 0 == sin limite) ");
        scanf("%d", &tamanoMax);
        pila = crearPila(tamanoMax);
    }
    printf("Que valor quieres agregar? ");
    scanf("%d", &nuevoDato);

    system("cls");
    _apilar(nuevoDato);
}

void mostrar()
{
    if (pila == NULL || pila->top == NULL)
    {
        system("cls");
        printf("-----La pila esta vacia-----\n");
        return;
    }

    int opc = 0;
    printf("1) Mostrar pila\n");
    printf("2) Mostrar la cima de la pila\n");
    printf("3) Mostrar estado de la pila\n");
    printf("Escoge una opcion: ");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        system("cls");
        _mostrarPila();
        break;
    case 2:
        system("cls");
        _mostrarCima();
        break;
    case 3:
        system("cls");
        _mostrarEstado();
        break;
    default:
        break;
    }
}

void eliminar()
{
    system("cls");
    Elemento *aEliminar = _desapilar();
    if (aEliminar != NULL)
    {
        free(aEliminar);
    }
}

void otros()
{
    int opc = 0;
    printf("1) Generar pila de ejemplo (0..9) (Eliminara la pila que este actualmente en uso)\n");
    printf("2) Vaciar pila\n");
    printf("3) Aumentar tamano\n");
    printf("4) Disminuir tamano\n");
    printf("Escoge una opcion: ");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        system("cls");
        _generarPilaEjemplo();
        break;
    case 2:
        system("cls");
        _vaciar();
        printf("-----Pila vacia-----\n");
        break;
    case 3:
        system("cls");
        _aumentarTamano();
        break;
    case 4:
        system("cls");
        _disminuirTamano();
        break;
    default:
        break;
    }
}

Pila *crearPila(int tamMaximo)
{
    // Creamos una nueva pila con 0 elementos
    Pila *nuevaPila = (Pila *)malloc(sizeof(Pila));
    nuevaPila->top = NULL;
    nuevaPila->elementos = 0;

    // Asignamos el tamaño máximo (menor a 0 significa que tiene límite)
    nuevaPila->tamanoMaximo = tamMaximo;
}

Elemento *crearElemento(int nuevoDato)
{
    // Creamos un elemento nuevo y le asignamos el dato que va a tener e inicializamos la propiedad "siguiente" a nulo.
    // La propiedad "siguiente" se va a usar después para enlazarse con el siguiente elemento
    Elemento *nuevo = (Elemento *)malloc(sizeof(Elemento));
    nuevo->dato = nuevoDato;
    nuevo->inferior = NULL;
    return nuevo;
}

void _apilar(int nuevoDato)
{
    // Obtenemos el tamaño máximo de la pila
    int tamMaximo = pila->tamanoMaximo;

    // Verificamos que aún le quede espacio (si hay límite de espacio)
    if (tamMaximo > 0 && tamMaximo == pila->elementos)
    {
        printf("-----Ya no le caben mas elementos a la pila-----\n");
        return;
    }
    // Creamos un nuevo elemento
    Elemento *nuevoElemento = crearElemento(nuevoDato);

    // Si no hay elementos en la pila...
    if (pila->top == NULL)
    {
        // ... establecemos el nuevo elemento como la cima de la pila
        pila->top = nuevoElemento;
        ++pila->elementos;
        return;
    }

    // Si sí hay, entonces
    // 1) Obtenemos la cima de la pila
    Elemento *ultimoElemento = pila->top;

    // 2) Conectamos nuestro nuevo elemento con la cima
    nuevoElemento->inferior = ultimoElemento;

    // 3) La nueva cima de la pila ahora será nuestro elemento
    pila->top = nuevoElemento;

    // 4) Aumentamos el número de elementos de la pila
    ++pila->elementos;
}

void _mostrarPila()
{
    printf("-----\n");
    // Iteramos desde la cima de la pila hacia abajo hasta llegar a NULL
    // El elemento del fondo es el que apunta a NULL, porque no tiene más elementos abajo
    for (Elemento *it = pila->top; it != NULL; it = it->inferior)
    {
        printf("(%d)\n", it->dato);
    }
    if (pila->tamanoMaximo > 0)
    {
        printf("Tamano maximo: %d\n", pila->tamanoMaximo);
    }
    printf("-----\n");
}

Elemento *_mostrarCima()
{
    // Obtenemos la cima de la pila
    Elemento *cima = pila->top;

    // Comprobamos que no sea NULL (es decir, que la pila no esté vacía)
    if (cima == NULL)
    {
        printf("-----La pila está vacía-----\n");
        return NULL;
    }
    printf("La cima de la pila tiene el dato (%d)\n", cima->dato);

    // Simplemente retornamos el valor. No lo sacamos de la pila
    return cima;
}

void _mostrarEstado()
{
    printf("-----\n");
    if (pila->elementos == pila->tamanoMaximo)
    {
        printf("PILA LLENA\n");
    }
    printf("Elementos: %d ", pila->elementos);

    if (pila->tamanoMaximo > 0)
    {
        printf("- Tamano maximo: %d\n", pila->tamanoMaximo);
    }
    else
    {
        printf("\n");
    }
    printf("-----\n");
}

Elemento *_desapilar()
{
    // Obtenemos la cima de la pila
    Elemento *cima = pila->top;

    // Comprobamos que no sea NULL (es decir, que la pila no esté vacía)
    if (cima == NULL)
    {
        printf("-----La pila está vacía-----\n");
        return NULL;
    }

    // Si sí hay elementos, entonces
    // 1) Obtenemos el elemento que hasta abajo de la cima
    Elemento *nuevaCima = cima->inferior;

    // 2) Y lo hacemos la nueva cima,
    // hemos sacado al antiguo elemento "cima" de la pila
    pila->top = nuevaCima;

    // 3) Disminuimos el número de elementos de la pila
    --pila->elementos;

    // 4) Finalmente, regresamos la cima anterior
    return cima;
}

void _generarPilaEjemplo()
{
    // Si la pila no existe, la creamos
    if (pila == NULL)
    {
        int tamanoMax = 0;
        printf("No hay ninguna pila creada. Vamos a crear una\n");
        printf("Que tamano maximo quieres ponerle? (n < 0 == sin limite) ");
        scanf("%d", &tamanoMax);
        pila = crearPila(tamanoMax);
    }

    _vaciar();

    // La llenamos con elementos desde el 9 hasta el 0
    // Para que al leerla, los leamos desde el 0 hasta el 9
    for (int i = 9; i > -1; i--)
    {
        _apilar(i);
    }
}

void _vaciar()
{
    // Vamos iterando la fila...
    for (int i = pila->elementos; i > 0; i--)
    {
        // ... desapilando sus elementos
        Elemento *it = _desapilar();
        free(it);
    }
}

void _aumentarTamano()
{
    if (pila->tamanoMaximo <= 0)
    {
        printf("La pila no tiene limite, no puede aumentar el tamano, solo disminuirlo\n");
        return;
    }
    // Pedimos el tamaño nuevo
    int nuevoTamano = 0;
    printf("A cuanto quieres aumentar el tamano? (n < 0 == sin limite): ");
    scanf("%d", &nuevoTamano);
    printf("-----\n");

    // Si el nuevo tamaño es mayor a 0 y es menor o igual al tamaño actual,
    // no se cambia el tamaño
    if (nuevoTamano > 0 && nuevoTamano <= pila->tamanoMaximo)
    {
        printf("No se puede aumentar el tamano a un numero menor\n");
        printf("En ese caso, disminuye el tamano\n");
    }
    else
    {
        // Si sí, se asigna el nuevo tamaño
        pila->tamanoMaximo = nuevoTamano;
        printf("Nuevo tamano: ");
        if (nuevoTamano <= 0)
        {
            printf("sin limite\n");
        }
        else
        {
            printf("%d\n", pila->tamanoMaximo);
        }
    }
    printf("-----\n");
}

void _disminuirTamano()
{
    // Pedimos el nuevo tamaño
    int nuevoTamano = 0;
    printf("A cuanto quieres disminuir el tamano? (debe ser mayor a 0)\n");
    printf("(Eliminara los elementos sobrantes si existen): ");
    scanf("%d", &nuevoTamano);
    printf("-----\n");

    // Si el nuevo tamaño es menor a 0
    if (nuevoTamano <= 0)
    {
        // Entonces no se puede alterar el nuevo tamaño (no se puede disminuir a "sin limite")
        printf("La pila no se puede disminuir a 'sin limite'.\n");
        printf("En ese caso, aumenta el tamano\n");
        printf("-----\n");
        return;
    }

    // Si el nuevo tamaño es mayor al tamaño de la pila (y considerando que la pila tiene tamaño infinito)
    if (nuevoTamano >= pila->tamanoMaximo && pila->tamanoMaximo > 0)
    {
        // Entonces no se puede disminuir a un tamaño mayor al que ya tiene
        printf("No se puede disminuir el tamano a un numero mayor\n");
        printf("En ese caso, aumenta el tamano\n");
        printf("-----\n");
        return;
    }

    // Obtenemos el tamaño actual
    int actual = pila->elementos;

    // Iteramos desde el tamaño actual hasta el nuevo tamaño para sacar los elementos
    for (int i = actual; i > nuevoTamano; i--)
    {
        Elemento *it = _desapilar();
        free(it);
    }

    // Asignamos el nuevo tamaño
    pila->tamanoMaximo = nuevoTamano;
    printf("Nuevo tamano: ");
    if (nuevoTamano < 0)
    {
        printf("sin limite\n");
    }
    else
    {
        printf("%d\n", pila->tamanoMaximo);
    }
    printf("-----\n");
}
