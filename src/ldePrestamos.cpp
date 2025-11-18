#include "../include/ldePrestamos.h"

typedef struct nodoDoble *TLDENodoDoble;

struct nodoDoble
{
    TPrestamo prestamo;
    nodoDoble *sig;
    nodoDoble *ant;
};

struct rep_ldePrestamos
{
    nodoDoble *primero;
    nodoDoble *ultimo;
    int cantidad;
};

void liberarTLDEPrestamosSoloEstructura(TLDEPrestamos &ldePrestamos)
{
    if (ldePrestamos == NULL)
    {
        return;
    }

    nodoDoble *actual = ldePrestamos->primero;
    while (actual != NULL)
    {
        nodoDoble *aux = actual;
        actual = actual->sig;
        // libera sólo la estructura del préstamo (no socios ni libros)
        liberarTPrestamoSoloEstructura(aux->prestamo);
        delete aux;
    }

    delete ldePrestamos;
    ldePrestamos = NULL;
};

TLDEPrestamos crearTLDEPrestamosVacia()
{
    TLDEPrestamos nuevoPrestamo = new rep_ldePrestamos;
    nuevoPrestamo->primero = NULL;
    nuevoPrestamo->ultimo = NULL;
    nuevoPrestamo->cantidad = 0;
    return nuevoPrestamo;
}

void insertarTLDEPrestamos(TLDEPrestamos &ldePrestamos, TPrestamo prestamo)
{
    TLDENodoDoble nuevoPrestamo = new nodoDoble;
    nuevoPrestamo->prestamo = copiarTPrestamo(prestamo);
    nuevoPrestamo->sig = NULL;
    nuevoPrestamo->ant = NULL;

    if (ldePrestamos == NULL)
    {
        ldePrestamos = crearTLDEPrestamosVacia();
    }

    if (ldePrestamos->cantidad == 0)
    {
        ldePrestamos->primero = nuevoPrestamo;
        ldePrestamos->ultimo = nuevoPrestamo;
        ldePrestamos->cantidad = 1;
        liberarTPrestamo(prestamo);
        return;
    }

    TLDENodoDoble actual = ldePrestamos->primero;
    TFecha fechaPrestamoInsertar = fechaRetiroTPrestamo(prestamo);
    // avanzar mientras fecha(actual) <= fechaNuevo
    while (actual != NULL && compararTFechas(fechaRetiroTPrestamo(actual->prestamo), fechaPrestamoInsertar) != 1)
    {
        actual = actual->sig;
    }

    if (actual == NULL)
    {
        // insertar al final
        nuevoPrestamo->ant = ldePrestamos->ultimo;
        ldePrestamos->ultimo->sig = nuevoPrestamo;
        ldePrestamos->ultimo = nuevoPrestamo;
    }
    else
    {
        // insertar antes de actual
        nuevoPrestamo->sig = actual;
        nuevoPrestamo->ant = actual->ant;
        if (actual->ant != NULL)
        {
            actual->ant->sig = nuevoPrestamo;
        }
        else
        {
            ldePrestamos->primero = nuevoPrestamo;
        }
        actual->ant = nuevoPrestamo;
    }

    ldePrestamos->cantidad++;
    liberarTPrestamo(prestamo);
}

void liberarTLDEPrestamos(TLDEPrestamos &ldePrestamos)
{
    if (ldePrestamos == NULL)
    {
        return;
    }
    else
    {
        nodoDoble *actual = ldePrestamos->primero;
        while (actual != NULL)
        {
            nodoDoble *aux = actual;
            actual = actual->sig;
            liberarTPrestamo(aux->prestamo);
            delete aux;
        }
        delete ldePrestamos;
        ldePrestamos = NULL;
    }
}

void imprimirTLDEPrestamos(TLDEPrestamos ldePrestamos)
{
    if (ldePrestamos == NULL)
    {
        return;
    }
    printf("LDE Préstamos:\n");
    TLDENodoDoble aux = ldePrestamos->primero;
    while (aux != NULL)
    {
        imprimirTPrestamo(aux->prestamo);
        aux = aux->sig;
    }
}

void imprimirInvertidoTLDEPrestamos(TLDEPrestamos ldePrestamos)
{
    if (ldePrestamos == NULL)
    {
        return;
    }
    printf("LDE Préstamos:\n");
    TLDENodoDoble aux = ldePrestamos->ultimo;
    while (aux != NULL)
    {
        imprimirTPrestamo(aux->prestamo);
        aux = aux->ant;
    }
}

nat cantidadTLDEPrestamos(TLDEPrestamos ldePrestamos)
{
    return ldePrestamos->cantidad;
}

TPrestamo obtenerPrimeroTLDEPrestamos(TLDEPrestamos ldePrestamos)
{
    return ldePrestamos->primero->prestamo;
}

TPrestamo obtenerUltimoTLDEPrestamos(TLDEPrestamos ldePrestamos)
{
    return ldePrestamos->ultimo->prestamo;
}

TPrestamo obtenerNesimoTLDEPrestamos(TLDEPrestamos &ldePrestamos, int n)
{
    // n es 1-based (1 -> primer elemento)
    if (ldePrestamos == NULL || ldePrestamos->primero == NULL)
        return NULL;

    TLDENodoDoble aux = ldePrestamos->primero;
    int contador = 1;
    while (aux != NULL && contador < n)
    {
        aux = aux->sig;
        contador++;
    }

    return aux->prestamo;
}

// criterio = 0 -> prestamos retornados
// criterio = 1 -> prestamos no retornados
TLDEPrestamos filtrarPrestamosTLDEPrestamos(TLDEPrestamos &ldePrestamos, int criterio)
{
    if (ldePrestamos == NULL)
    {
        return NULL;
    }

    TLDEPrestamos prestamosFiltro = crearTLDEPrestamosVacia();
    TLDENodoDoble aux = ldePrestamos->primero;
    for (int i = 0; i < ldePrestamos->cantidad; i++)
    {
        if (criterio == 0 && fueRetornadoTPrestamo(aux->prestamo))
        {
            insertarTLDEPrestamos(prestamosFiltro, copiarTPrestamo(aux->prestamo));
        }
        else if (criterio == 1 && !fueRetornadoTPrestamo(aux->prestamo))
        {
            insertarTLDEPrestamos(prestamosFiltro, copiarTPrestamo(aux->prestamo));
        }
        aux = aux->sig;
    }
    return prestamosFiltro;
}
