/* Creado por André Michel Pozos Nieto - @AndreAndyP */
/* Este es un ejemplo de cómo funciona una lista doblemente enlazada. Contiene las operaciones básicas. */
/* Probado en Windows 10*/
/* Una disculpa por la falta de acentos y signos de interrogación de apertura, no pude hacer que se mostraran en Windows*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

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
void _busquedaBinaria(int buscar);
// Métodos para merge sort
void _mergeSort(Lista *list, int limiteIzq, int limiteDer);
void _merge(Lista *list, int limiteIzq, int mitad, int limiteDer);
int _valorEn(Lista *list, int posicion);
void _ponerValorEn(Lista *list, int posicion, int nuevoDato);

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
        printf("-----Opcion incorrecta-----\n");
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
        printf("-----Opcion incorrecta-----\n");
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
        printf("-----Opcion incorrecta-----\n");
        break;
    }
}

void otros()
{
    int opc = 0, buscar = 0;
    printf("1) Generar lista de ejemplo (0..9) (Eliminara la lista que este actualmente en uso)\n");
    printf("2) Generar lista aleatoria (20 elementos, -100..100) (Eliminara la lista que este actualmente en uso)\n");
    printf("3) Vaciar lista\n");
    printf("4) Obtener el tamano de la lista\n");
    printf("5) Voltear (reverse) la lista\n");
    printf("6) Ordenar la lista (Merge sort)\n");
    printf("7) Buscar un elemento (Busqueda binaria)\n");
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
        printf("Que valor quieres buscar? ");
        scanf("%d", &buscar);
        system("cls");
        _busquedaBinaria(buscar);
        break;
    default:
        system("cls");
        printf("-----Opcion incorrecta-----\n");
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
    // No es válido agregar en una posición que no existe.
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

void _eliminarAlInicio()
{
    // Obtenemos el inicio de la lista
    Elemento *inicioActual = lista->inicio;

    // En caso de que estemos al final de la lista ... (que este sea el último elemento)
    if (inicioActual == lista->fin)
    {
        // ... quitamos también el final
        lista->fin = NULL;
    }
    // Y obtenemos el siguiente elemento en la lista
    // (en el caso de que sólo haya un elemento, esto será NULL)
    Elemento *nuevoInicio = inicioActual->siguiente;

    // Eliminamos el elemento
    free(inicioActual);

    // Disminuimos en 1 el número de elementos
    --lista->elementos;

    // Establecemos el nuevo inicio de la lista
    lista->inicio = nuevoInicio;

    // Y ya que el nuevo inicio no tiene elemento anterior, se lo quitamos
    nuevoInicio->anterior = NULL;
}

void _eliminarAlFinal()
{
    // Obtenemos el final de la lista
    Elemento *finalActual = lista->fin;

    // En caso de que estemos al inicio de la lista ... (que este sea el último elemento)
    if (finalActual == lista->inicio)
    {
        // ... quitamos también el inicio
        lista->inicio = NULL;
    }
    // Y obtenemos el elemento anterior en la lista
    // (en el caso de que sólo haya un elemento, esto será NULL)
    Elemento *nuevoFinal = finalActual->anterior;

    // Eliminamos el elemento
    free(finalActual);

    // Disminuimos en 1 el número de elementos
    --lista->elementos;

    // Establecemos el nuevo final de la lista
    lista->fin = nuevoFinal;

    // Y ya que el nuevo final no tiene elemento siguiente, se lo quitamos
    nuevoFinal->siguiente = NULL;
}

void _eliminarEn(int posicion)
{
    // No es válido eliminar una posición que no existe.
    if (posicion >= lista->elementos)
    {
        printf("-----No hay ningun elemento en esa posicion-----\n");
        return;
    }

    // Si se quiere eliminar un valor en la posicion 0,
    // nos podemos ahorrar el proceso simplemente eliminando el dato al inicio
    if (posicion == 0)
    {
        _eliminarAlInicio();
        return;
    }

    // Si se quiere añadir un valor en la posicion final,
    // nos podemos ahorrar el proceso haciendo lo siguiente:
    if (posicion == lista->elementos - 1)
    {
        _eliminarAlFinal();
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

    // Eliminamos el elemento de la siguiente manera:
    // 1) Obtenemos el elemento anterior y al siguiente al que queremos eliminar
    Elemento *antes = it->anterior;
    Elemento *despues = it->siguiente;

    // 2) Unimos el elemento que va antes del que queremos eliminar con el que le sigue
    // y viceversa
    antes->siguiente = despues;
    despues->anterior = antes;

    // 3) Disminuimos el número de elementos de la lista
    ++lista->elementos;

    // 4) Eliminamos el elemento
    free(it);

    // Pasamod de esto:
    // Ex <-> Ey <-> Ez
    // a esto:
    // Ex <-> Ez
}

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

void _voltear()
{
    // Preparamos 2 iteradores:
    // uno que vaya iterando desde el principio hacia adelante,
    // otro que vaya desde el final hacia atrás.
    Elemento *itInicio = lista->inicio;
    Elemento *itFinal = lista->fin;

    // Vamos a iterar hasta la mitad del tamaño de la lista
    int limite = lista->elementos / 2;

    // Vamos a intercambiar los valores de cada elemento de la lista
    // utilizando ambos iteradores previamente definidos para avanzar por ambos lados
    // hasta que intercambiemos todos los elementos.
    // Si la lista es de tamaño par, se intercambiaran todos los elementos
    // Si es impar, se intercambiaran todos excepto el centro
    for (int i = 1; i != limite; i++)
    {
        // Vamos a intercambiar n y m de lugar sin usar ninguna variable extra en 3 pasos:
        // 1) n = n + m
        itInicio->dato = itInicio->dato + itFinal->dato;
        // 2) m = n - m
        //    m = (n + m) - m
        //    m = n
        itFinal->dato = itInicio->dato - itFinal->dato;
        // 3) n = n - m
        //    n = (n + m) - m
        //    n = n;
        itInicio->dato = itInicio->dato - itFinal->dato;

        // Continuamos iterando...
        itInicio = itInicio->siguiente;
        itFinal = itFinal->anterior;
    }
    printf("Lista desde el inicio:\n");
    _mostrarListaDesdeInicio();
    printf("Lista desde el final:\n");
    _mostrarListaDesdeFin();
}

void _ordenarConMerge()
{
    printf("Antes de ordenar\n");
    _mostrarListaDesdeInicio();
    Lista *temp = lista;
    _mergeSort(temp, 0, lista->elementos - 1);
    printf("Después de ordenar\n");
    lista = temp;
    _mostrarListaDesdeInicio();
}

void _busquedaBinaria(int buscar)
{
    if (lista == NULL || lista->inicio == NULL)
    {
        printf("-----La lista esta vacia-----\n");
        return;
    }

    // Definimos una variable que nos ayudará a iterar sobre la lista
    Elemento *it = lista->inicio;

    // Y una variable que también nos ayudará a movernos
    bool iterarAdelante = true;

    // (Algoritmo) establecemos L y R
    int posIzquierda = 0;
    int posDerecha = lista->elementos - 1;
    int mitad = 0;

    while (posIzquierda <= posDerecha)
    {
        // (Algoritmo) obtenemos la mitad de la lista. Truncamos el número si es decimal
        mitad = floor((posIzquierda + posDerecha) / 2);

        // Nos vomeos hacia adelante
        if (iterarAdelante)
        {
            // Desde la posicion izquierda hasta la mitad del arreglo
            for (int i = posIzquierda; i < mitad; i++)
            {
                it = it->siguiente;
            }
        }

        // o hacia atrás, según nos diga el algoritmo
        else
        {
            // Desde la posicion derecha hasta la mitad del arreglo
            for (int i = posDerecha; i > mitad; i--)
            {
                it = it->anterior;
            }
        }

        // (Algoritmo) Si el dato de la mitad es menor al dato que buscamos
        if (it->dato < buscar)
        {
            // (Algoritmo) L será m + 1
            posIzquierda = mitad + 1;
            it = it->siguiente;

            // Iteraremos hacia adelante en la siguiente iteración del algoritmo
            iterarAdelante = true;
        }
        // (Algoritmo) Si el dato de la mitad es mayor al dato que buscamos
        else if (it->dato > buscar)
        {
            // (Algoritmo) R será m - 1
            posDerecha = mitad - 1;
            it = it->anterior;

            // Iteraremos hacia atras en la siguiente iteración del algoritmo
            iterarAdelante = false;
        }
        // (Algoritmo) Si el dato coincide con el dato de la mitad, ya lo encontramos
        else
        {
            printf("El elemento %d se encontro en la posicion %d\n", it->dato, mitad);
            return;
        }
    }
    printf("No se encontro el valor");
}

void _mergeSort(Lista *list, int limiteIzq, int limiteDer)
{
    // Si el array es 2 o más, lo separamos
    // Si no, continuamos con la otra mitad del arreglo
    if (limiteIzq < limiteDer)
    {
        int mitad = (limiteIzq + limiteDer) / 2;
        _mergeSort(list, limiteIzq, mitad);
        _mergeSort(list, mitad + 1, limiteDer);
        _merge(list, limiteIzq, mitad, limiteDer);
    }
}

void _merge(Lista *list, int limiteIzq, int mitad, int limiteDer)
{
    // Índices para iterar sobre cada mitad y sobre la lista
    int indexIzq, indexDer, indexMerge;

    // Tamaño de las mitades
    int tamIzq = mitad - limiteIzq + 1;
    int tamDer = limiteDer - mitad;

    // Mitades de la lista
    int mitadIzquierda[tamIzq], mitadDerecha[tamDer];

    for (indexIzq = 0; indexIzq < tamIzq; indexIzq++)
    {
        // De la lista a ordenar, obtenemos los elementos para la mitad izquierda
        mitadIzquierda[indexIzq] = _valorEn(list, limiteIzq + indexIzq);
    }
    for (indexDer = 0; indexDer < tamDer; indexDer++)
    {
        // De la lista a ordenar, obtenemos los elementos para la mitad derecha
        mitadDerecha[indexDer] = _valorEn(list, mitad + 1 + indexDer);
    }

    // Reiniciamos los índices para iterar desde el principio
    indexIzq = 0;
    indexDer = 0;
    indexMerge = limiteIzq;

    // Mientras ninguna de las mitades esté vacía,
    // vamos a iterar sobre ambas a la vez
    while (indexIzq < tamIzq && indexDer < tamDer)
    {
        // Si el valor en la mitad izquierda es menor que el de la mitad derecha
        if (mitadIzquierda[indexIzq] <= mitadDerecha[indexDer])
        {
            // Ponemos dicho valor en la lista
            _ponerValorEn(list, indexMerge, mitadIzquierda[indexIzq]);

            // Y avanzamos sobre la izquierda
            ++indexIzq;
        }
        // Si el valor en la mitad derecha es menor que el de la mitad izquierda
        else
        {
            // Ponemos dicho valor en la lista
            _ponerValorEn(list, indexMerge, mitadDerecha[indexDer]);
            // Y avanzamos sobre la derecha
            ++indexDer;
        }
        ++indexMerge;
    }

    // Cuando alguna de las mitades se quedó vacía...
    // Copiamos los elementos de la mitad izquierda restantes (si hay)
    while (indexIzq < tamIzq)
    {
        _ponerValorEn(list, indexMerge, mitadIzquierda[indexIzq]);
        ++indexIzq;
        ++indexMerge;
    }

    // Y también los de la derecha (si hay)
    while (indexDer < tamDer)
    {
        _ponerValorEn(list, indexMerge, mitadDerecha[indexDer]);
        ++indexDer;
        ++indexMerge;
    }
}

// Esta función hace lo mismo que "Mostrar elemento en"
// Sólo que sin comentarios, sin impresiones y regresa el valor
int _valorEn(Lista *list, int posicion)
{
    int mitad = list->elementos / 2;
    if (posicion < mitad)
    {
        Elemento *it = list->inicio;
        for (int i = 0; i < posicion; i++)
        {
            it = it->siguiente;
        }
        return it->dato;
    }
    else
    {
        Elemento *it = list->fin;
        for (int i = list->elementos - 1; i > posicion; i--)
        {
            it = it->anterior;
        }
        return it->dato;
    }
}

// Esta función hace lo mismo que "Actualizar elemento en"
// Sólo que sin comentarios y sin impresiones
void _ponerValorEn(Lista *list, int posicion, int nuevoDato)
{
    int mitad = list->elementos / 2;
    if (posicion < mitad)
    {
        Elemento *it = list->inicio;
        for (int i = 0; i < posicion; i++)
        {
            it = it->siguiente;
        }
        it->dato = nuevoDato;
    }
    else
    {
        Elemento *it = list->fin;
        for (int i = list->elementos - 1; i > posicion; i--)
        {
            it = it->anterior;
        }
        it->dato = nuevoDato;
    }
}
