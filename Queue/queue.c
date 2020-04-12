/* Creado por André Michel Pozos Nieto - @AndreAndyP */
/* Este es un ejemplo de cómo funciona una cola. Contiene las operaciones básicas. */
/* Probado en Windows 10*/
/* Una disculpa por la falta de acentos y signos de interrogación de apertura, no pude hacer que se mostraran en Windows*/
#include <stdio.h>
#include <stdlib.h>

// Métodos para especificar la operación. No son importantes para la implementación de la cola.
void agregar();
void mostrar();
void eliminar();
void otros();

// El elemento debe tener el/los dato(s) que queremos guardar
// y una referencia al siguiente elemento en la cola.
typedef struct Elemento
{
    struct Elemento *siguiente;
    int dato;
} Elemento;

Elemento *crearElemento(int nuevoDato);

// Una cola necesita conocer al elemento que esta al final de la cola
// y al elemento que está al principio de la cola.
// Vamos a agregar también una propiedad de tamaño máximo
// por si queremos que la cola tenga un límite.
// Incluso podemos agregar una propiedad que nos diga el número de elementos para evitar iterarla
// cada vez que queremos saber cuántos elementos hay.
// Como siempre: más uso de memoria, más rápidas serán ciertas operaciones
// menos uso de memoria, menos rápidas serán ciertas opercaciones.
typedef struct Cola
{
    Elemento *inicio;
    Elemento *fin;
    int tamanoMaximo;
    int elementos;
} Cola;

// La cola que se usa en todo el programa
Cola *cola;

/* Funciones de la cola */
Cola *crearCola(int tamMaximo);

// Create
void _encolar(int nuevoDato); // enqueue
// Read
void _mostrarCola();
Elemento *_mostrarFrente();
void _mostrarEstado();
// Delete
Elemento *_desencolar(); // dequeue
// Utilidades varias
void _generarColaEjemplo();
void _vaciar();
void _aumentarTamano();
void _disminuirTamano();

int main(int argc, char const *argv[])
{
    int opc = 0;
    // Menú para seleccionar la operación
    while (1)
    {
        printf("------Cola-----\n");
        printf("1) Encolar (enqueue)\n");    // Create
        printf("2) Mostrar...\n");           // Read
        printf("3) Desencolar (dequeue)\n"); // Delete
        printf("4) Otros...\n");             // Utilidades
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
    if (cola == NULL)
    {
        int tamanoMax = 0;
        printf("No hay ninguna cola creada. Vamos a crear una\n");
        printf("Que tamano maximo quieres ponerle? (n < 0 == sin limite) ");
        scanf("%d", &tamanoMax);
        cola = crearCola(tamanoMax);
    }
    printf("Que valor quieres agregar? ");
    scanf("%d", &nuevoDato);

    system("cls");
    _encolar(nuevoDato);
}

void mostrar()
{
    if (cola == NULL || cola->inicio == NULL)
    {
        system("cls");
        printf("-----La cola esta vacia-----\n");
        return;
    }

    int opc = 0;
    printf("1) Mostrar cola\n");
    printf("2) Mostrar el frente de la cola\n");
    printf("3) Mostrar estado de la cola\n");
    printf("Escoge una opcion: ");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        system("cls");
        _mostrarCola();
        break;
    case 2:
        system("cls");
        _mostrarFrente();
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
    Elemento *aEliminar = _desencolar();
    if (aEliminar != NULL)
    {
        free(aEliminar);
    }
}

void otros()
{
    int opc = 0;
    printf("1) Generar cola de ejemplo (0..9) (Eliminara la cola que este actualmente en uso)\n");
    printf("2) Vaciar cola\n");
    printf("3) Aumentar tamano\n");
    printf("4) Disminuir tamano\n");
    printf("Escoge una opcion: ");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        system("cls");
        _generarColaEjemplo();
        break;
    case 2:
        system("cls");
        _vaciar();
        printf("-----Cola vacia-----\n");
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

Cola *crearCola(int tamMaximo)
{
    // Creamos una nueva cola con 0 elementos
    Cola *nuevaCola = (Cola *)malloc(sizeof(Cola));
    nuevaCola->inicio = NULL;
    nuevaCola->fin = NULL;
    nuevaCola->elementos = 0;

    // Asignamos el tamaño máximo (menor a 0 significa que tiene límite)
    nuevaCola->tamanoMaximo = tamMaximo;
}

Elemento *crearElemento(int nuevoDato)
{
    // Creamos un elemento nuevo y le asignamos el dato que va a tener e inicializamos la propiedad "siguiente" a nulo.
    // La propiedad "siguiente" se va a usar después para enlazarse con el siguiente elemento
    Elemento *nuevo = (Elemento *)malloc(sizeof(Elemento));
    nuevo->dato = nuevoDato;
    nuevo->siguiente = NULL;
    return nuevo;
}

void _encolar(int nuevoDato)
{
    // Obtenemos el tamaño máximo de la cola
    int tamMaximo = cola->tamanoMaximo;

    // Verificamos que aún le quede espacio (si hay límite de espacio)
    if (tamMaximo > 0 && tamMaximo == cola->elementos)
    {
        printf("-----Ya no le caben mas elementos a la cola-----\n");
        return;
    }
    // Creamos un nuevo elemento
    Elemento *nuevoElemento = crearElemento(nuevoDato);

    // Si no hay elementos en la cola...
    if (cola->inicio == NULL)
    {
        // ... establecemos el nuevo elemento como el inicio de la cola,
        cola->inicio = nuevoElemento;

        // así como el final de la cola.
        cola->fin = cola->inicio;

        // Finalmente, aumentamos el número de elementos en la cola.
        ++cola->elementos;
        return;
    }

    // Si sí hay, entonces
    // 1) Obtenemos el fin de la cola
    Elemento *ultimoElemento = cola->fin;

    // 2) Conectamos el último elemento al elemento recién creado
    ultimoElemento->siguiente = nuevoElemento;

    // 3) El fin de la cola ahora será nuestro nuevo elemento
    cola->fin = nuevoElemento;

    // 4) Finalmente, aumentamos el número de elementos de la cola.
    ++cola->elementos;
}

void _mostrarCola()
{
    printf("-----\n");
    // Iteramos desde el inicio de la cola hasta llegar a NULL
    // El elemento final de la cola es el que apunta a NULL, porque no tiene más elementos después
    for (Elemento *it = cola->inicio; it != NULL; it = it->siguiente)
    {
        printf("(%d)->", it->dato);
    }

    // Esta linea la ponemos para que se muestre un "NULL" al final de la cola
    printf("NULL\n");

    if (cola->tamanoMaximo > 0)
    {
        printf("Tamano maximo: %d\n", cola->tamanoMaximo);
    }
    printf("-----\n");
}

Elemento *_mostrarFrente()
{
    // Obtenemos el frente de la cola
    Elemento *frente = cola->inicio;

    // Comprobamos que no sea NULL (es decir, que la cola no esté vacía)
    if (frente == NULL)
    {
        printf("-----La cola esta vacia-----\n");
        return NULL;
    }
    printf("El frente de la cola tiene el dato (%d)\n", frente->dato);

    // Simplemente retornamos el valor. No lo sacamos de la cola.
    return frente;
}

void _mostrarEstado()
{
    printf("-----\n");
    if (cola->elementos == cola->tamanoMaximo)
    {
        printf("COLA LLENA\n");
    }
    printf("Elementos: %d ", cola->elementos);

    if (cola->tamanoMaximo > 0)
    {
        printf("- Tamano maximo: %d\n", cola->tamanoMaximo);
    }
    else
    {
        printf("\n");
    }
    printf("-----\n");
}

Elemento *_desencolar()
{
    // Comprobamos que la cola no esté vacía
    if (cola == NULL)
    {
        printf("-----La cola esta vacia-----\n");
        return NULL;
    }

    // Obtenemos el frente de la cola
    Elemento *frente = cola->inicio;

    // Comprobamos que no sea NULL (es decir, que la cola no esté vacía)
    if (frente == NULL)
    {
        printf("-----La cola esta vacia-----\n");
        return NULL;
    }

    // Si sí hay elementos, entonces
    // 1) Obtenemos el elemento que está después del frente
    Elemento *nuevoFrente = frente->siguiente;

    // 2) Y lo convertimos en el nuevo frente (en el nuevo inicio)
    // hemos sacado al antiguo elemento inicial de la cola
    cola->inicio = nuevoFrente;

    // 3) Disminuimos el número de elementos de la cola
    --cola->elementos;

    // 4) Finalmente, regresamos el elemento que antes era el inicio
    return frente;
}

void _generarColaEjemplo()
{
    // Si la cola no existe, la creamos
    if (cola == NULL)
    {
        int tamanoMax = 0;
        printf("No hay ninguna cola creada. Vamos a crear una\n");
        printf("Que tamano maximo quieres ponerle? (n < 0 == sin limite) ");
        scanf("%d", &tamanoMax);
        cola = crearCola(tamanoMax);
    }

    _vaciar();

    // La llenamos con elementos desde el 0 hasta el 9
    for (int i = 0; i < 10; i++)
    {
        _encolar(i);
    }
}

void _vaciar()
{
    // Comprobamos que la cola no esté vacía
    if (cola == NULL)
    {
        system("cls");
        printf("-----La cola esta vacia-----\n");
        return;
    }

    // Vamos iterando la cola...
    for (int i = cola->elementos; i > 0; i--)
    {
        // ... desencolando sus elementos
        Elemento *it = _desencolar();
        free(it);
    }
}

void _aumentarTamano()
{
    // Comprobamos que la cola no esté vacía
    if (cola == NULL)
    {
        system("cls");
        printf("-----La cola esta vacia-----\n");
        return;
    }

    if (cola->tamanoMaximo <= 0)
    {
        printf("La cola no tiene limite. No se puede aumentar el tamano, solo disminuirlo\n");
        return;
    }
    // Pedimos el tamaño nuevo
    int nuevoTamano = 0;
    printf("A cuanto quieres aumentar el tamano? (n < 0 == sin limite): ");
    scanf("%d", &nuevoTamano);
    printf("-----\n");

    // Si el nuevo tamaño es mayor a 0 y es menor o igual al tamaño actual,
    // no se cambia el tamaño
    if (nuevoTamano > 0 && nuevoTamano <= cola->tamanoMaximo)
    {
        printf("No se puede aumentar el tamano a un numero menor\n");
        printf("En ese caso, disminuye el tamano\n");
    }
    else
    {
        // Si sí, se asigna el nuevo tamaño
        cola->tamanoMaximo = nuevoTamano;
        printf("Nuevo tamano: ");
        if (nuevoTamano <= 0)
        {
            printf("sin limite\n");
        }
        else
        {
            printf("%d\n", cola->tamanoMaximo);
        }
    }
    printf("-----\n");
}

void _disminuirTamano()
{
    // Comprobamos que la cola no esté vacía
    if (cola == NULL)
    {
        system("cls");
        printf("-----La cola esta vacia-----\n");
        return;
    }

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
        printf("La cola no se puede disminuir a 'sin limite'.\n");
        printf("En ese caso, aumenta el tamano\n");
        printf("-----\n");
        return;
    }

    // Si el nuevo tamaño es mayor al tamaño de la cola (y considerando que la cola tiene tamaño infinito)
    if (nuevoTamano >= cola->tamanoMaximo && cola->tamanoMaximo > 0)
    {
        // Entonces no se puede disminuir a un tamaño mayor al que ya tiene
        printf("No se puede disminuir el tamano a un numero mayor\n");
        printf("En ese caso, aumenta el tamano\n");
        printf("-----\n");
        return;
    }

    // Obtenemos el tamaño actual
    int actual = cola->elementos;

    // Iteramos desde el tamaño actual hasta el nuevo tamaño para sacar los elementos
    for (int i = actual; i > nuevoTamano; i--)
    {
        Elemento *it = _desencolar();
        free(it);
    }

    // Asignamos el nuevo tamaño
    cola->tamanoMaximo = nuevoTamano;
    printf("Nuevo tamano: ");
    if (nuevoTamano < 0)
    {
        printf("sin limite\n");
    }
    else
    {
        printf("%d\n", cola->tamanoMaximo);
    }
    printf("-----\n");
}
