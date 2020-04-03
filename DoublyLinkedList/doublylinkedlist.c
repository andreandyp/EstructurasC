/* Creado por André Michel Pozos Nieto - @AndreAndyP */
/* Este es un ejemplo de cómo funciona una lista doblemente enlazada. Contiene las operaciones básicas. */
/* Probado en Windows 10*/
/* Una disculpa por la falta de acentos y signos de interrogación de apertura, no pude hacer que se mostraran en Windows*/
#include <stdio.h>
#include <stdlib.h>

// Métodos para especificar la operación. No son importantes para la lista
void agregar();
void mostrar();
void actualizar();
void eliminar();
void otros();

// El elemento debe tener el/los dato(s) que queremos guardar,
// una referencia al elemento anterior de la lista
// y una al elemento siguiente de la lista.
typedef struct Elemento
{
    struct Elemento *anterior;
    struct Elemento *siguiente;
    int dato;
} Elemento;

Elemento *crearElemento(int nuevoDato);

// Una lista doblemente enlazada necesita siempre 2 elementos importantes:
// el inicio y el final.
// Vamos a agregar también un contador para saber cuántos elementos hay en la lista.
// Como siempre, depende de la situacion:
//   1) Ocupamos más espacio pero ciertas operaciones serán más rápidas
//   2) Ocupamos menos espacio pero ciertas operaciones serán más lentas.
// Nos iremos por la opción 1.
typedef struct Lista
{
    Elemento *inicio;
    Elemento *fin;
    int elementos;
} Lista;

// La lista que se usa en todo el programa
Lista *lista = NULL;

/* Funciones de la lista */
Lista *crearLista();
// Create
void _agregarDatoInicio(int nuevoDato);
void _agregarDatoFin(int nuevoDato);
void _agregarDatoEn(int posicion, int nuevoDato);
// Read
void _mostrarListaDesdeInicio();
void _mostrarListaDesdeFin();
void _mostrarDatoEn(int posicion);
// Update
void _actualizarDatoEn(int posicion, int nuevoDato);
// Delete
void _eliminarAlInicio();
void _eliminarAlFinal();
void _eliminarEn(int posicion);
// Utilidades varias
void _generarListaEjemplo();
void _generarListaAleatoria();
void _vaciar();
void _obtenerTamano();
void _voltear();
void _ordenarConMerge();
void _busquedaBinaria();

int main(int argc, char const *argv[])
{
    int opc = 0;
    // Menú para seleccionar la operación
    while (1)
    {
        printf("------Lista doblemente enlazada-----\n");
        printf("1) Agregar...\n");    // Create
        printf("2) Mostrar...\n");    // Read
        printf("3) Actualizar...\n"); // Update
        printf("4) Eliminar...\n");   // Delete
        printf("5) Otros...\n");      // Utilidades
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
            actualizar();
            break;
        case 4:
            eliminar();
            break;
        case 5:
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
    int opc = 0, nuevoDato = 0, posicion = 0;
    printf("1) Agregar al principio\n");
    printf("2) Agregar al final\n");
    printf("3) Agregar en cierta posicion\n");
    printf("Escoge una opcion: ");
    scanf("%d", &opc);
    printf("Que valor quieres agregar? ");
    scanf("%d", &nuevoDato);
    switch (opc)
    {
    case 1:
        system("cls");
        _agregarDatoInicio(nuevoDato);
        break;
    case 2:
        system("cls");
        _agregarDatoFin(nuevoDato);
        break;
    case 3:
        printf("En que posicion quieres agregar el dato? ");
        scanf("%d", &posicion);
        system("cls");
        _agregarDatoEn(posicion, nuevoDato);
        break;
    default:
        system("cls");
        printf("-----Opción incorrecta-----\n");
        break;
    }
}

void mostrar()
{
    if (lista == NULL || lista->inicio == NULL)
    {
        printf("-----La lista esta vacia-----\n");
        return;
    }

    int opc = 0, posicion = 0;
    printf("1) Mostrar lista desde el inicio\n");
    printf("2) Mostrar lista desde el fin\n");
    printf("3) Mostrar dato en cierta posicion\n");
    printf("Escoge una opcion: ");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        system("cls");
        _mostrarListaDesdeInicio();
        break;
    case 2:
        system("cls");
        _mostrarListaDesdeFin();
        break;
    case 3:
        printf("En que posicion quieres ver el dato? ");
        scanf("%d", &posicion);
        system("cls");
        _mostrarDatoEn(posicion);
        break;
    default:
        system("cls");
        printf("-----Opción incorrecta-----\n");
        break;
    }
}

void actualizar()
{
    if (lista == NULL || lista->inicio == NULL)
    {
        printf("-----La lista esta vacia-----\n");
        return;
    }

    int nuevoDato = 0, posicion = 0;
    printf("Que valor quieres agregar? ");
    scanf("%d", &nuevoDato);
    printf("En que posicion esta el dato? ");
    scanf("%d", &posicion);

    system("cls");
    _actualizarDatoEn(posicion, nuevoDato);
}

void eliminar()
{
    if (lista == NULL || lista->inicio == NULL)
    {
        printf("-----La lista esta vacia-----\n");
        return;
    }

    int opc = 0, posicion = 0;
    printf("1) Eliminar al inicio\n");
    printf("2) Eliminar al final\n");
    printf("3) Eliminar cierta posicion\n");
    printf("Escoge una opcion: ");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        system("cls");
        _eliminarAlInicio();
        break;
    case 2:
        system("cls");
        _eliminarAlFinal();
        break;
    case 3:
        printf("Que posicion quieres eliminar? ");
        scanf("%d", &posicion);
        system("cls");
        _eliminarEn(posicion);
        break;
    default:
        system("cls");
        printf("-----Opción incorrecta-----\n");
        break;
    }
}

void otros()
{
    int opc = 0;
    printf("1) Generar lista de ejemplo (0..9) (Eliminara la lista que este actualmente en uso)\n");
    printf("2) Generar lista aleatoria (20 elementos, -100..100) (Eliminara la lista que este actualmente en uso)\n");
    printf("3) Vaciar lista\n");
    printf("4) Obtener el tamano de la lista\n");
    printf("5) Voltear (reverse) la lista\n");
    printf("6) Ordenar la lista (Merge sort)\n");
    printf("7) Buscar un elemento (Búsqueda binaria)\n");
    printf("Escoge una opcion: ");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        system("cls");
        _generarListaEjemplo();
        break;
    case 2:
        system("cls");
        _generarListaAleatoria();
        break;
    case 3:
        system("cls");
        _vaciar();
        printf("-----Lista vacia-----\n");
        break;
    case 4:
        system("cls");
        _obtenerTamano();
        break;
    case 5:
        system("cls");
        _voltear();
        break;
    case 6:
        system("cls");
        _ordenarConMerge();
        break;
    case 7:
        system("cls");
        _busquedaBinaria();
        break;
    default:
        system("cls");
        printf("-----Opción incorrecta-----\n");
        break;
    }
}

Lista *crearLista()
{
    // Creamos una nueva lista
    Lista *nuevaLista = (Lista *)malloc(sizeof(Lista));

    // El inicio y el fin van a ser nulos porque no hay elementos
    nuevaLista->inicio = NULL;
    nuevaLista->fin = NULL;
    nuevaLista->elementos = 0;
}

Elemento *crearElemento(int nuevoDato)
{
    // Creamos un elemento nuevo y le asignamos el dato que va a tener
    // e inicializamos las propiedades "anterior" y "siguiente" a nulo.
    // La propiedad "anterior" se va a usar después para enlazarse con el elemento anterior de la lista
    // Y la propiedad "siguiente" se va a usar después para enlazarse con el siguiente elemento de la lista
    Elemento *nuevo = (Elemento *)malloc(sizeof(Elemento));
    nuevo->dato = nuevoDato;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
    return nuevo;
}

void _agregarDatoInicio(int nuevoDato)
{
    // Si la lista no ha sido creada, creamos una nueva
    if (lista == NULL)
    {
        lista = crearLista(nuevoDato);
    }

    // Creamos al elemento nuevo que vamos a añadir a la lista
    Elemento *nuevoElemento = crearElemento(nuevoDato);

    // Si la lista está vacía, creamos el primer elemento
    if (lista->inicio == NULL)
    {

        // Le asignamos al inicio y al fin el mismo elemento
        // También aumentamos el número de elementos en la lista
        lista->inicio = nuevoElemento;
        lista->fin = nuevoElemento;
        ++lista->elementos;
        return;
    }

    // Si no, lo añadimos a la lista de la siguiente manera:
    // 1) Como va a estar al inicio, su elemento anterior será NULL
    nuevoElemento->anterior = NULL;

    // 2) El elemento siguiente al nuevo va a ser el que está al inicio de la lista
    nuevoElemento->siguiente = lista->inicio;

    // 3) El elemento anterior al inicio va a ser el nuevo elemento
    lista->inicio->anterior = nuevoElemento;

    // 4) El inicio de la lista ahora será nuestro nuevo elemento
    lista->inicio = nuevoElemento;

    // 5) También aumentamos el número de elementos en la lista
    ++lista->elementos;
}

void _agregarDatoFin(int nuevoDato)
{
    // Si la lista no ha sido creada, creamos una nueva
    if (lista == NULL)
    {
        lista = crearLista(nuevoDato);
    }

    // Creamos al elemento nuevo que vamos a añadir a la lista
    Elemento *nuevoElemento = crearElemento(nuevoDato);

    // Si la lista está vacía, creamos el primer elemento
    if (lista->inicio == NULL)
    {

        // Le asignamos al inicio y al fin el mismo elemento
        // También aumentamos el número de elementos en la lista
        lista->inicio = nuevoElemento;
        lista->fin = nuevoElemento;
        ++lista->elementos;
        return;
    }

    // Si no, lo añadimos a la lista de la siguiente manera:
    // 1) Como va a estar al final, su elemento "siguiente" será NULL
    nuevoElemento->siguiente = NULL;

    // 2) El elemento "anterior" será el final de la lista
    nuevoElemento->anterior = lista->fin;

    // 3) El siguiente elemento del final de la lista va a ser el nuevo elemento
    lista->fin->siguiente = nuevoElemento;

    // 4) El fin de la lista ahora será el nuevo elemento.
    lista->fin = nuevoElemento;

    // 5) También aumentamos el número de elementos en la lista
    ++lista->elementos;
}

void _agregarDatoEn(int posicion, int nuevoDato)
{
    // No es válido actualizar en una posición que no existe.
    if (posicion >= lista->elementos)
    {
        printf("-----No hay ningun elemento en esa posicion-----\n");
        return;
    }

    // Si se quiere añadir un valor en la posicion 0,
    // nos podemos ahorrar el proceso simplemente insertando el dato al inicio
    if (posicion == 0)
    {
        _agregarDatoInicio(nuevoDato);
        return;
    }

    // Si se quiere añadir un valor en la posicion final,
    // nos podemos ahorrar el proceso haciendo lo siguiente:
    if (posicion == lista->elementos - 1)
    {
        // 1) Obtenemos el valor original del elemento final de la lista
        int valorOriginal = lista->fin->dato;

        // 2) Asignamos el dato al elemento "fin" de la lista
        lista->fin->dato = nuevoDato;

        // 3) Añadimos el valor original de la lista al final de ésta
        _agregarDatoFin(valorOriginal);
        return;
    }

    // Si queremos insertar en cualquier otro lado, continuamos con el proceso

    // Con it vamos a iterar a través de la lista
    Elemento *it = NULL;
    int mitad = lista->elementos / 2;
    // Si el elemento está antes de la mitad de la lista,
    // iteramos desde el inicio
    if (posicion < mitad)
    {
        it = lista->inicio;
        for (int i = 0; i < posicion; i++)
        {
            it = it->siguiente;
        }
    }
    // Si el elemento está después de la mitad de la lista,
    // iteramos desde el final
    else
    {
        it = lista->fin;
        for (int i = lista->elementos - 1; i > posicion; i--)
        {
            it = it->anterior;
        }
    }

    // Agregamos el elemento de la siguiente manera:
    // 1) Obtenemos el dato que está en donde queremos insertar el elemento
    int valorOriginal = it->dato;

    // 2) Obtenemos el elemento que sigue de donde estamos
    Elemento *siguienteOriginal = it->siguiente;

    // 3) Creamos un nuevo elemento con el dato original
    Elemento *elementoOriginal = crearElemento(valorOriginal);

    // 4) Agregamos el dato en la posición indicada
    it->dato = nuevoDato;

    // 5) Unimos el elemento que insertamos con el que creamos con el valor original...
    it->siguiente = elementoOriginal;
    // ... y viceversa
    elementoOriginal->anterior = it;

    // 6) Unimos el elemento original al que originalmente le seguía...
    elementoOriginal->siguiente = siguienteOriginal;

    // ... y viceversa.
    // Nota: si el siguiente es nulo (la posición es la del elemento final)
    siguienteOriginal->anterior = elementoOriginal;

    // 7) Aumentamos el número de elementos de la lista
    ++lista->elementos;

    // Pasamod de esto:
    // Ex <-> Ey
    // a esto:
    // Ex <-> En <-> Ey
}

void _mostrarListaDesdeInicio()
{
    printf("-----\n");

    // Iteramos sobre la lista avanzando hacia adelante.
    // Desde el inicio, a través de la propiedad "siguiente" hasta que llegemos a NULL.
    // El elemento final de la lista es el que su propiedad "siguiente" es igual a NULL.
    for (Elemento *it = lista->inicio; it != NULL; it = it->siguiente)
    {
        printf("%d, ", it->dato);
    }

    printf("\n-----\n");
}

void _mostrarListaDesdeFin()
{
    printf("-----\n");
    // Iteramos sobre la lista avanzando hacia atrás.
    // Desde el fin, a través de la propiedad "anterior" hasta que llegemos a NULL.
    // El elemento inicial de la lista es el que su propiedad "anterior" es igual a NULL.
    for (Elemento *it = lista->fin; it != NULL; it = it->anterior)
    {
        printf("%d, ", it->dato);
    }

    printf("\n-----\n");
}

void _mostrarDatoEn(int posicion)
{
    // No es válido actualizar en una posición que no existe.
    if (posicion >= lista->elementos)
    {
        printf("-----No hay ningun elemento en esa posicion-----\n");
        return;
    }

    int mitad = lista->elementos / 2;
    // Si el elemento está antes de la mitad de la lista,
    // iteramos desde el inicio
    if (posicion < mitad)
    {
        Elemento *it = lista->inicio;
        for (int i = 0; i < posicion; i++)
        {
            it = it->siguiente;
        }
        printf("%d\n", it->dato);
    }
    // Si el elemento está después de la mitad de la lista,
    // iteramos desde el final
    else
    {
        Elemento *it = lista->fin;
        for (int i = lista->elementos - 1; i > posicion; i--)
        {
            it = it->anterior;
        }
        printf("%d\n", it->dato);
    }
}

void _actualizarDatoEn(int posicion, int nuevoDato)
{
    // No es válido actualizar en una posición que no existe.
    if (posicion >= lista->elementos)
    {
        printf("-----No hay ningun elemento en esa posicion-----\n");
        return;
    }

    int mitad = lista->elementos / 2;
    // Si el elemento está antes de la mitad de la lista,
    // iteramos desde el inicio
    if (posicion < mitad)
    {
        Elemento *it = lista->inicio;
        for (int i = 0; i < posicion; i++)
        {
            it = it->siguiente;
        }
        it->dato = nuevoDato;
    }
    // Si el elemento está después de la mitad de la lista,
    // iteramos desde el final
    else
    {
        Elemento *it = lista->fin;
        for (int i = lista->elementos - 1; i > posicion; i--)
        {
            it = it->anterior;
        }
        it->dato = nuevoDato;
    }
}

void _eliminarAlInicio() {}
void _eliminarAlFinal() {}
void _eliminarEn(int posicion) {}

void _generarListaEjemplo()
{
    int i = 0;

    // Si la lista ya existe, la vacíamos
    if (lista != NULL)
    {
        _vaciar();
    }
    // Si no, la creamos
    else
    {
        lista = crearLista();
    }

    // La llenamos con los elementos del 1 al 9
    while (i < 10)
    {
        _agregarDatoFin(i);
        ++i;
    }

    _mostrarListaDesdeInicio();
}

void _generarListaAleatoria()
{
    int i = 0;
    // Si la lista ya existe, la vacíamos
    if (lista != NULL)
    {
        _vaciar();
    }
    // Si no, la creamos
    else
    {
        lista = crearLista();
    }

    // La llenamos con 20 elementos desde el -100 hasta el 100, inclusive.
    while (i < 20)
    {
        _agregarDatoFin(rand() % 201 - 100);
        ++i;
    }

    _mostrarListaDesdeInicio();
}

void _vaciar()
{
    // Vamos a iterar la lista desde el inicio
    // También podríamos iterarla desde el final
    Elemento *it = lista->inicio;

    while (it != NULL)
    {
        // Obtenemos una referencia al elemento actual
        Elemento *actual = it;
        // Cambiamos al siguiente
        it = it->siguiente;
        // Borramos el elemento que obtuvimos antes
        free(actual);
        // Y finalmente disminuimos el número de elementos
        --lista->elementos;
    }

    // Ponemos el inicio y el fin a NULL porque ya no hay elementos
    lista->inicio = NULL;
    lista->fin = NULL;
}

void _obtenerTamano()
{
    if (lista == NULL)
    {
        printf("-----La lista esta vacia-----\n");
        return;
    }
    // Si hubieramos preferido menos espacio, aquí tendríamos que iterar sobre toda la lista.
    printf("-----La lista contiene %d elementos-----\n", lista->elementos);
}

void _voltear() {}
void _ordenarConMerge() {}
void _busquedaBinaria() {}