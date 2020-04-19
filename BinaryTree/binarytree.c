/* Creado por André Michel Pozos Nieto - @AndreAndyP */
/* Este es un ejemplo de cómo funciona un árbol binario. Contiene las operaciones básicas. */
/* Probado en Windows 10*/
/* Una disculpa por la falta de acentos y signos de interrogación de apertura, no pude hacer que se mostraran en Windows*/
#include <stdio.h>
#include <stdlib.h>

// Métodos para especificar la operación. No son importantes para la lista.
void agregar();
void mostrar();
void eliminar();
void otros();

// El elemento debe tener el/los dato(s) que queremos guardar
// y dos referencias:
// una al elemento de la izquierda
// y otra al elemento de la derecha.
typedef struct Elemento
{
    int dato;
    struct Elemento *izquierda;
    struct Elemento *derecha;
} Elemento;

Elemento *crearElemento(int nuevoDato);

// Un árbol sólo necesita saber una cosa: la raíz.
typedef struct Arbol
{
    Elemento *raiz;
} Arbol;

// El árbol que se usa en todo el programa
Arbol *arbol;

/* Funciones del arbol */
Arbol *crearArbol(int nuevoDato);
// Create
Elemento *_insertar(Elemento *raiz, int nuevoDato);
// Read
void _recorrerPreorden(Elemento *raiz);
void _recorrerInorden(Elemento *raiz);
void _recorrerPostorden(Elemento *raiz);
void _buscar(int dato);
// Delete
void _eliminarArbol();
// Utilidades varias
void _generarArbolEjemplo();
void _obtenerProfundidad();
void _voltear();

int main(int argc, char const *argv[])
{
    int opc = 0;
    // Menú para seleccionar la operación
    while (1)
    {
        printf("------Arbol binario-----\n");
        printf("1) Insertar\n");    // Create
        printf("2) Mostrar...\n");  // Read
        printf("3) Eliminar...\n"); // Delete
        printf("4) Otros...\n");    // Utilidades
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
    printf("Que valor quieres insertar? ");
    scanf("%d", &nuevoDato);

    system("cls");
    if (arbol == NULL)
    {
        arbol = crearArbol(nuevoDato);
        return;
    }
    _insertar(arbol->raiz, nuevoDato);
}

void mostrar()
{
    if (arbol == NULL || arbol->raiz == NULL)
    {
        printf("-----El arbol esta vacio-----\n");
        return;
    }

    int opc = 0, posicion = 0, dato = 0;
    printf("1) Recorrer en preorden\n");
    printf("2) Recorrer en inorden\n");
    printf("3) Recorrer en postorden\n");
    printf("4) Buscar dato\n");
    printf("Escoge una opcion: ");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        system("cls");
        _recorrerPreorden(arbol->raiz);
        break;
    case 2:
        system("cls");
        _recorrerInorden(arbol->raiz);
        break;
    case 3:
        system("cls");
        _recorrerPostorden(arbol->raiz);
        break;
    case 4:
        printf("Que dato quieres buscar? ");
        scanf("%d", &dato);
        system("cls");
        _buscar(dato);
        break;
    default:
        break;
    }
    printf("-----\n");
}

void eliminar()
{
    if (arbol == NULL || arbol->raiz == NULL)
    {
        printf("-----El arbol esta vacio-----\n");
        return;
    }

    _eliminarArbol();
}

void otros() {}

Arbol *crearArbol(int nuevoDato)
{
    // Creamos un nuevo árbol.
    Arbol *nuevoArbol = (Arbol *)malloc(sizeof(Arbol));

    // La raíz será NULL, el método _insertar() se encargará de añadir el dato inicial
    nuevoArbol->raiz = crearElemento(nuevoDato);

    return nuevoArbol;
}

Elemento *crearElemento(int nuevoDato)
{
    // Creamos un elemento nuevo y le asignamos el dato que va a tener.
    Elemento *nuevo = (Elemento *)malloc(sizeof(Elemento));
    nuevo->dato = nuevoDato;

    // Inicializamos sus propiedades "izquierda" y "derecha" a NULL
    // Nos servirán para añadir nuevos hijos.
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;

    return nuevo;
}

Elemento *_insertar(Elemento *raiz, int nuevoDato)
{
    // Si la raiz de este sub-árbol es NULL, (venimos de un nodo hoja)
    if (raiz == NULL)
    {
        // insertamos el dato en la raiz de este sub-árbol
        raiz = crearElemento(nuevoDato);
        return raiz;
    }

    // Si no es NULL, insertamos un nuevo dato de la siguiente manera:
    // Si el dato es menor o igual al dato que está en la raíz de este árbol,
    if (nuevoDato < raiz->dato)
    {
        // Nos vamos por el sub-árbol de la izquierda
        raiz->izquierda = _insertar(raiz->izquierda, nuevoDato);
    }
    // Si no, nos vamos por el sub-árbol de la derecha
    else
    {
        raiz->derecha = _insertar(raiz->derecha, nuevoDato);
    }

    return raiz;
}

void _recorrerPreorden(Elemento *raiz)
{
    // Vamos a recorrer el árbol de la siguiente manera:
    // Si la raiz de este sub-árbol es NULL, (venimos de un nodo hoja)
    if (raiz == NULL)
    {
        // Acabamos la ejecución de la función
        return;
    }

    // Si no, entonces hacemos lo siguiente:
    // 1) Mostramos el dato que está en la raíz del sub-árbol actual:
    printf("%d, ", raiz->dato);

    // 2) Recorremos el árbol por la izquierda:
    _recorrerPreorden(raiz->izquierda);

    // 3) Recorremos el árbol por la derecha:
    _recorrerPreorden(raiz->derecha);
}

void _recorrerInorden(Elemento *raiz)
{
    // Vamos a recorrer el árbol de la siguiente manera:
    // Si la raiz de este sub-árbol es NULL, (venimos de un nodo hoja)
    if (raiz == NULL)
    {
        // Acabamos la ejecución de la función
        return;
    }

    // Si no, entonces hacemos lo siguiente:
    // 1) Recorremos el árbol por la izquierda:
    _recorrerInorden(raiz->izquierda);

    // 2) Mostramos el dato que está en la raíz del sub-árbol actual:
    printf("%d, ", raiz->dato);

    // 3) Recorremos el árbol por la derecha:
    _recorrerInorden(raiz->derecha);
}

void _recorrerPostorden(Elemento *raiz)
{
    // Vamos a recorrer el árbol de la siguiente manera:
    // Si la raiz de este sub-árbol es NULL, (venimos de un nodo hoja)
    if (raiz == NULL)
    {
        // Acabamos la ejecución de la función
        return;
    }

    // Si no, entonces hacemos lo siguiente:
    // 1) Recorremos el árbol por la izquierda:
    _recorrerPostorden(raiz->izquierda);

    // 2) Recorremos el árbol por la derecha:
    _recorrerPostorden(raiz->derecha);

    // 3) Mostramos el dato que está en la raíz del sub-árbol actual:
    printf("%d, ", raiz->dato);
}

void _buscar(int dato) {}
void _eliminarArbol() {}
void _generarArbolEjemplo() {}
void _obtenerProfundidad() {}
void _voltear() {}
