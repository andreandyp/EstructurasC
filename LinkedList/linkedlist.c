#include <stdio.h>
#include <stdlib.h>

void agregarDato();
void mostrarDato();
void mostrarLista();
void actualizarDato();
void eliminarDato();
void vaciarLista();

typedef struct Elemento
{
    struct Elemento *anterior;
    struct Elemento *siguiente;
    int dato;
} Elemento;

void _crearLista(int dato);
Elemento *_crearElemento(int nuevoDato);

Elemento *inicio = NULL;
Elemento *fin = NULL;

int main(int argc, char const *argv[])
{
    int opc = 0;
    while (1)
    {
        printf("1) Agregar dato\n"); // Create
        printf("2) Mostrar dato\n"); // Read
        printf("3) Mostrar lista\n");
        printf("4) Actualizar dato\n"); // Update
        printf("5) Eliminar dato\n");   // Delete
        printf("6) Vaciar lista\n");
        printf("0) Salir\n");
        printf("Escoge una opcion: ");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            agregarDato();
            break;
        case 2:
            mostrarDato();
            break;
        case 3:
            mostrarLista();
            break;
        case 4:
            actualizarDato();
            break;
        case 5:
            eliminarDato();
            break;
        case 6:
            vaciarLista();
            break;
        case 0:
            return 0;
        default:
            printf("Escoge una opción");
            break;
        }
    }
    return 0;
}

void agregarDato()
{
    int dato = 0;
    printf("Que valor quieres agregar? ");
    scanf("%d", &dato);
    if (inicio == NULL)
    {
        _crearLista(dato);
    }
    else
    {
        // Obtenemos el elemento que antes era el fin
        Elemento *previo = fin;

        // Obtenemos el nuevo elemento creado
        Elemento *nuevoElemento = _crearElemento(dato);

        // Hacemos que el elemento fin sea el elemento recién creado
        fin = nuevoElemento;

        // Y al elemento previo, le indicamos que el siguiente será el fin
        previo->siguiente = fin;
    }
    printf("Dato agregado\n");
}

void mostrarDato()
{
    int indice = 0;
    printf("En que posicion esta el dato? ");
    scanf("%d", &indice);
    printf("-----\n");
    Elemento *it = inicio;
    for (int i = 0; i < indice; i++)
    {
        if (it == NULL)
        {
            printf("No hay ningun dato en esa posicion\n");
            printf("-----\n");
            return;
        }
        it = it->siguiente;
    }
    if (it == NULL)
    {
        printf("No hay ningun dato en esa posicion\n");
        printf("-----\n");
        return;
    }
    printf("%d\n", it->dato);
    printf("-----\n");
}

void mostrarLista()
{
    printf("-----\n");
    if (inicio == fin)
    {
        printf("La lista esta vacia\n");
    }
    for (Elemento *it = inicio; it != NULL; it = it->siguiente)
    {
        printf("%d\n", it->dato);
    }
    printf("-----\n");
}

void _crearLista(int nuevoDato)
{
    // Creamos el elemento inicio que va a tener nuestro dato recién agregado
    inicio = (Elemento *)malloc(sizeof(Elemento));
    inicio->dato = nuevoDato;
    inicio->siguiente = NULL;

    // Nuestro elemento inicio va a ser EL MISMO que el elemento fin
    fin = inicio;
}

Elemento *_crearElemento(int nuevoDato)
{
    // Creamos un elemento nuevo
    Elemento *nuevo = (Elemento *)malloc(sizeof(Elemento));
    nuevo->dato = nuevoDato;
    nuevo->siguiente = NULL;
    return nuevo;
}

void actualizarDato()
{
    int nuevoDato = 0;
    printf("Que valor quieres agregar? ");
    scanf("%d", &nuevoDato);
    int indice = 0;
    printf("En que posicion esta el dato? ");
    scanf("%d", &indice);
    printf("-----\n");
    Elemento *it = inicio;
    for (int i = 0; i < indice; i++)
    {
        if (it == NULL)
        {
            printf("No hay ningun dato en esa posicion\n");
            printf("-----\n");
            return;
        }
        it = it->siguiente;
    }
    if (it == NULL)
    {
        printf("No hay ningun dato en esa posicion\n");
        printf("-----\n");
        return;
    }
    int prev = it->dato;
    it->dato = nuevoDato;
    int nuevo = it->dato;
    printf("El elemento %d paso de %d a %d\n", indice, prev, nuevo);
    printf("-----\n");
}
void eliminarDato()
{
    Elemento *nuevoInicio = inicio->siguiente;
    if (inicio == fin)
    {
        free(fin);
        fin = NULL;
    }
    free(inicio);
    inicio = nuevoInicio;
}
void vaciarLista()
{
    printf("-----\n");
    if (inicio == fin)
    {
        printf("La lista ya esta vacia\n");
        return;
    }
    Elemento *it = inicio;
    while (it != NULL)
    {
        Elemento *actual = it;
        it = it->siguiente;
        free(actual);
    }
    inicio = NULL;
    fin = NULL;
    printf("Lista vacia\n");
    printf("-----\n");
}