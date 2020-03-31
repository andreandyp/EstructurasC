#include <stdio.h>
#include <stdlib.h>

void agregar();
void mostrar();
void actualizar();
void eliminar();
void otros();

// El elemento debe tener el/los dato(s) que queremos guardar
// y una referencia al siguiente elemento en la lista.
typedef struct Elemento
{
    struct Elemento *siguiente;
    int dato;
} Elemento;

Elemento *crearElemento(int nuevoDato);

// Una lista enlazada necesita siempre 2 elementos importantes:
// el inicio y el final.
typedef struct Lista
{
    Elemento *inicio;
    Elemento *fin;
} Lista;

// La lista que se usa en todo el programa
Lista *lista;

Lista *crearLista(int datoInicial);
/* Funciones de la lista */
// Create
void _agregarDatoInicio(int nuevoDato);
void _agregarDatoFin(int nuevoDato);
void _agregarDatoEn(int posicion, int nuevoDato);
// Read
void _mostrarLista();
void _mostrarDatoEn(int posicion);
// Update
void _actualizarDatoEn(int posicion, int nuevoDato);
// Delete
void _eliminarAlInicio();
void _eliminarAlFinal();
void _eliminarEn(int posicion);
// Utilidades varias
void _generarListaEjemplo();
void _vaciar();

int main(int argc, char const *argv[])
{
    int opc = 0;
    while (1)
    {
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
    printf("1) Mostrar lista\n");
    printf("2) Mostrar dato en cierta posicion\n");
    printf("Escoge una opcion: ");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        system("cls");
        _mostrarLista();
        break;
    case 2:
        printf("En que posicion quieres ver el dato? :");
        scanf("%d", &posicion);
        system("cls");
        _mostrarDatoEn(posicion);
        break;
    default:
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
        break;
    }
}

void otros()
{
    int opc = 0;
    printf("1) Generar lista de ejemplo (0..9) (Eliminara la lista que este actualmente en uso)\n");
    printf("2) Vaciar lista\n");
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
        _vaciar();
        break;
    default:
        break;
    }
}

Lista *crearLista(int datoInicial)
{
    // Creamos una nueva lista
    Lista *nuevaLista = (Lista *)malloc(sizeof(Lista));

    // Creamos el elemento inicio que va a tener nuestro dato recién agregado
    Elemento *inicioDeLista = (Elemento *)malloc(sizeof(Elemento));
    inicioDeLista->dato = datoInicial;
    inicioDeLista->siguiente = NULL;

    // El elemento que acabamos de crear va a ser el elemento inicio de nuestra nueva lista
    nuevaLista->inicio = inicioDeLista;
    // Nuestro elemento [fin] va a ser EL MISMO que el elemento [inicio]
    nuevaLista->fin = nuevaLista->inicio;
}

Elemento *crearElemento(int nuevoDato)
{
    // Creamos un elemento nuevo
    Elemento *nuevo = (Elemento *)malloc(sizeof(Elemento));
    nuevo->dato = nuevoDato;
    nuevo->siguiente = NULL;
    return nuevo;
}

void _agregarDatoInicio(int nuevoDato)
{
    if (lista == NULL)
    {
        lista = crearLista(nuevoDato);
        return;
    }
    // Creamos un nuevo elemento
    Elemento *nuevoElemento = crearElemento(nuevoDato);

    Elemento *inicioLista = lista->inicio;

    // Al nuevo elemento lo ligamos con el inicio de la lista
    nuevoElemento->siguiente = inicioLista;

    // Y hacemos que el inicio de la lista sea ese nuevo elemento
    lista->inicio = nuevoElemento;
}
void _agregarDatoFin(int nuevoDato)
{
    if (lista == NULL)
    {
        lista = crearLista(nuevoDato);
        return;
    }
    // Creamos un nuevo elemento
    Elemento *nuevoElemento = crearElemento(nuevoDato);

    // Obtenemos el fin de la lista
    Elemento *previo = lista->fin;

    // Hacemos que el fin de la lista sea el nuevo elemento
    lista->fin = nuevoElemento;

    // Y al elemento previo, le indicamos que el siguiente será el fin de la lista
    previo->siguiente = lista->fin;
}

void _agregarDatoEn(int posicion, int nuevoDato)
{
    if (lista == NULL)
    {
        lista = crearLista(nuevoDato);
        return;
    }

    Elemento *it = lista->inicio;
    // Recorremos la lista hasta la posicion indicada
    for (int i = 0; i < posicion; i++)
    {
        it = it->siguiente;
        // Si en algún momento nos encontramos con que el elemento es NULL, entonces hemos llegado al final de la lista
        if (it == NULL)
        {
            printf("No hay ningun dato en esa posicion\n");
            printf("-----\n");
            return;
        }
    }

    // Se inserta el nuevo valor de la siguiente manera:
    // 1) Obtenemos el valor del elemento que ocupa la posición en la que queremos agregar el dato
    int valorPrevio = it->dato;

    // 2) Creamos un nuevo elemento con el valor previo del elemento
    Elemento *elementoPrevio = crearElemento(valorPrevio);

    // 3) Obtenemos el elemento siguiente al que le vamos a agregar el dato
    Elemento *elemSiguiente = it->siguiente;

    // 4) Asignamos el dato en la posición indicada
    it->dato = nuevoDato;

    // 5) Asignamos como siguiente al elemento previo, es decir, al que tiene el valor antes de la modificación
    it->siguiente = elementoPrevio;

    // 6) Al elemento previo, le decimos que su siguiente elemento va a ser el que originalmente era el siguiente de éste.
    elementoPrevio->siguiente = elemSiguiente;

    // Es decir, hicimos:
    // Ex -> Ey -> Ez
    // Ex -> En -> Ey -> Ez
}

void _mostrarLista()
{
    printf("-----\n");
    // Recorremos la lista: empezamos en el inicio y vamos avanzando a través de los elementos
    // mediante la propiedad "siguiente" de cada elemento
    // el límite es cuando el siguiente elemento sea NULL.
    // El elemento que tiene NULL en "siguiente" es el fin de la lista
    for (Elemento *it = lista->inicio; it != NULL; it = it->siguiente)
    {
        printf("%d\n", it->dato);
    }
    printf("-----\n");
}

void _mostrarDatoEn(int posicion)
{
    printf("-----\n");
    Elemento *it = lista->inicio;

    // Recorremos la lista hasta la posicion indicada
    for (int i = 0; i < posicion; i++)
    {
        it = it->siguiente;
        // Si en algún momento nos encontramos con que el elemento es NULL, entonces hemos llegado al final de la lista
        if (it == NULL)
        {
            printf("No hay ningun dato en esa posicion\n");
            printf("-----\n");
            return;
        }
    }
    printf("%d\n", it->dato);
    printf("-----\n");
}

void _actualizarDatoEn(int posicion, int nuevoDato)
{
    printf("-----\n");
    Elemento *it = lista->inicio;

    // Al igual que en _mostrarDatoEn(), obtenemos el elemento solicitado
    for (int i = 0; i < posicion; i++)
    {
        it = it->siguiente;
        if (it == NULL)
        {
            printf("No hay ningun dato en esa posicion\n");
            printf("-----\n");
            return;
        }
    }

    // Obtenemos el dato antes de la actualización ... (Este paso no es necesario, sólo es para logging)
    int prev = it->dato;
    // ... actualizamos al dato nuevo ...
    it->dato = nuevoDato;
    // ... y almacenamos el dato actualizado (Este paso no es necesario, sólo es para logging)
    int nuevo = it->dato;
    printf("El elemento %d paso de %d a %d\n", posicion, prev, nuevo);
    printf("-----\n");
}

void _eliminarAlInicio()
{
    // Obtenemos el segundo elemento para que sea el nuevo inicio de la lista
    Elemento *nuevoInicio = lista->inicio->siguiente;

    // Si el inicio y el final de la lista son los mismos, eliminamos el final de la lista
    if (lista->inicio == lista->fin)
    {
        free(lista->fin);
        lista->fin = NULL;
    }

    // Eliminamos el anterior inicio de la lista
    free(lista->inicio);

    // Y hacemos que el nuevo inicio de la lista sea el segundo elemento
    lista->inicio = nuevoInicio;
}

void _eliminarAlFinal()
{
    // Recorremos la lista: empezamos en el inicio y vamos avanzando a través de los elementos
    // mediante la propiedad "siguiente" de cada elemento.
    // El límite es cuando llegemos al fin de la lista.
    Elemento *it = lista->inicio;
    while (it->siguiente != lista->fin)
    {
        it = it->siguiente;
    }

    // Obtenemos el final de la lista
    Elemento *finalLista = lista->fin;

    // Al elemento penúltimo de la lista lo asignamos ahora como final de la lista
    lista->fin = it;

    // Y le decimos que su siguiente elemento es NULL
    it->siguiente = NULL;

    // Y eliminamos el antiguo final de la lista
    free(finalLista);
}

void _eliminarEn(int posicion)
{
    Elemento *it = lista->inicio;

    // Recorremos la lista hasta la posicion indicada MENOS 1.
    // Necesitamos obtener el nodo anterior al que vamos a eliminar
    for (int i = 0; i < posicion - 1; i++)
    {
        it = it->siguiente;
        // Si en algún momento nos encontramos con que el elemento es NULL, entonces hemos llegado al final de la lista
        if (it == NULL)
        {
            printf("-----\n");
            printf("No hay ningun dato en esa posicion\n");
            printf("-----\n");
            return;
        }
    }

    // Obtenemos el elemento que queremos eliminar
    Elemento *aEliminar = it->siguiente;

    // Obtenemos el elemento que le sigue al que queremos eliminar
    Elemento *siguiente = aEliminar->siguiente;

    // Eliminamos el elemento
    free(aEliminar);

    // Conectamos el elemento anterior al que eliminamos con el que le sigue al que eliminamos
    it->siguiente = siguiente;

    // Es decir, hicimos:
    // Ex -> Ey -> Ez
    // Ex -> Ez
}

void _generarListaEjemplo()
{
    int i = 0;
    // Si la lista ya existe
    if (lista != NULL)
    {
        _vaciar();
    }
    lista = crearLista(i);
    i++;

    while (i < 10)
    {
        _agregarDatoFin(i);
        ++i;
    }

    _mostrarLista();
}

void _vaciar()
{
    Elemento *it = lista->inicio;
    while (it != NULL)
    {
        Elemento *actual = it;
        it = it->siguiente;
        free(actual);
    }
    lista->inicio = NULL;
    lista->fin = NULL;
    free(lista);
    printf("-----Lista vacia-----\n");
}