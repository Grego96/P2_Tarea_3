
#include "../include/abbLibros.h"

struct rep_abbLibros
{
    TLibro libro;
    TABBLibros izq;
    TABBLibros der;
};

TABBLibros crearTABBLibrosVacio()
{
    return NULL;
}

void insertarLibroTABBLibros(TABBLibros &abbLibros, TLibro libro)
{

    if (abbLibros == NULL)
    {
        TABBLibros nodoArbol = new rep_abbLibros;
        // Transferir la propiedad del puntero 'libro' al nodo del árbol.
        // No se copia aquí: el árbol será responsable de liberar el libro.
        nodoArbol->libro = libro;
        nodoArbol->izq = NULL;
        nodoArbol->der = NULL;
        abbLibros = nodoArbol;
    }
    else if (isbnTLibro(libro) < isbnTLibro(abbLibros->libro))
    {
        insertarLibroTABBLibros(abbLibros->izq, libro);
    }
    else if (isbnTLibro(libro) > isbnTLibro(abbLibros->libro))
    {
        insertarLibroTABBLibros(abbLibros->der, libro);
    }
}

void imprimirTABBLibros(TABBLibros abbLibros)
{
    if (abbLibros != NULL)
    {
        imprimirTABBLibros(abbLibros->izq);
        imprimirTLibro(abbLibros->libro);
        imprimirTABBLibros(abbLibros->der);
    }
}

void liberarTABBLibros(TABBLibros &abbLibros)
{
    if (abbLibros != NULL)
    {
        liberarTABBLibros(abbLibros->izq);
        liberarTABBLibros(abbLibros->der);
        liberarTLibro(abbLibros->libro);
        delete abbLibros;
        abbLibros = NULL;
    }
}

bool existeLibroTABBLibros(TABBLibros abbLibros, int isbn)
{
    // Caso base: árbol vacío -> no existe
    if (abbLibros == NULL)
    {
        return false;
    }

    int isbnNodo = isbnTLibro(abbLibros->libro);

    if (isbn == isbnNodo)
    {
        return true;
    }
    else if (isbn < isbnNodo)
    {
        // Buscar en subárbol izquierdo
        return existeLibroTABBLibros(abbLibros->izq, isbn);
    }
    else
    {
        // Buscar en subárbol derecho
        return existeLibroTABBLibros(abbLibros->der, isbn);
    }
}

TLibro obtenerLibroTABBLibros(TABBLibros abbLibros, int isbn)
{

    int isbnNodo = isbnTLibro(abbLibros->libro);

    if (isbn == isbnNodo)
    {
        return abbLibros->libro;
    }
    else if (isbn < isbnNodo)
    {
        // Buscar en subárbol izquierdo
        return obtenerLibroTABBLibros(abbLibros->izq, isbn);
    }
    else
    {
        // Buscar en subárbol derecho
        return obtenerLibroTABBLibros(abbLibros->der, isbn);
    }
}

nat alturaTABBLibros(TABBLibros abbLibros)
{
    if (abbLibros != NULL)
    {
        if (alturaTABBLibros(abbLibros->der) >= alturaTABBLibros(abbLibros->izq))
        {
            return alturaTABBLibros(abbLibros->der) + 1;
        }
        else
        {
            return alturaTABBLibros(abbLibros->izq) + 1;
        }
    }
    return 0;
}

TLibro maxISBNLibroTABBLibros(TABBLibros abbLibros)
{
    TABBLibros aux = abbLibros;
    while (aux->der != NULL)
    {
        aux = aux->der;
    }
    return aux->libro;
}

TABBLibros minimo(TABBLibros abbLibros)
{
    if (abbLibros == NULL)
    {
        return NULL;
    }
    else
    {
        while (abbLibros->izq != NULL)
        {
            abbLibros = abbLibros->izq;
        }
        return abbLibros;
    }
}

void removerLibroTABBLibros(TABBLibros &abbLibros, int isbn)
{
    if (abbLibros != NULL)
    {
        if (isbn < isbnTLibro(abbLibros->libro))
        {
            removerLibroTABBLibros(abbLibros->izq, isbn);
        }
        else if (isbn > isbnTLibro(abbLibros->libro))
        {
            removerLibroTABBLibros(abbLibros->der, isbn);
        }
        else
        { // isbn == key
            if (abbLibros->der == NULL)
            {
                TABBLibros aBorrar = abbLibros;
                abbLibros = abbLibros->izq;
                liberarTLibro(aBorrar->libro);
                delete aBorrar;
            }
            else if (abbLibros->izq == NULL)
            {
                TABBLibros aBorrar = abbLibros;
                abbLibros = abbLibros->der;
                liberarTLibro(aBorrar->libro);
                delete aBorrar;
            }
            else
            {
                // Encontrar el sucesor (mínimo del subárbol derecho)
                TABBLibros minimo_der = minimo(abbLibros->der);
                // Hacer una copia del libro del sucesor
                TLibro copiaSucesor = copiarTLibro(minimo_der->libro);
                // Liberar el libro del nodo actual y reemplazarlo por la copia
                liberarTLibro(abbLibros->libro);
                abbLibros->libro = copiaSucesor;
                // Remover el nodo sucesor del subárbol derecho por su ISBN
                removerLibroTABBLibros(abbLibros->der, isbnTLibro(minimo_der->libro));
            }
        }
    }
}

int cantidadTABBLibros(TABBLibros abbLibros)
{
    if (abbLibros == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + cantidadTABBLibros(abbLibros->izq) + cantidadTABBLibros(abbLibros->der);
    }
}

void obtenerNesimoLibroTABBLibrosAux(TABBLibros abbLibros, int n, int &k, TLibro &res)
{
    if (abbLibros == NULL || res != NULL)
    {
        return;
    }

    obtenerNesimoLibroTABBLibrosAux(abbLibros->izq, n, k, res);
    if (res != NULL)
        return;

    k++;
    if (k == n)
    {
        res = abbLibros->libro; // devolver puntero almacenado (no copia)
        return;
    }

    obtenerNesimoLibroTABBLibrosAux(abbLibros->der, n, k, res);
}

TLibro obtenerNesimoLibroTABBLibros(TABBLibros abbLibros, int n)
{
    TLibro res = NULL;
    int k = 0;
    obtenerNesimoLibroTABBLibrosAux(abbLibros, n, k, res);
    return res;
}

// Auxiliar recursivo in-order que añade copias de los libros con el género dado
static void filtradoAux(TABBLibros nodo, TABBLibros &dest, int genero)
{
    if (nodo == NULL)
        return;
    filtradoAux(nodo->izq, dest, genero);
    if (idGeneroTLibro(nodo->libro) == genero)
    {
        insertarLibroTABBLibros(dest, copiarTLibro(nodo->libro));
    }
    filtradoAux(nodo->der, dest, genero);
}

TABBLibros filtradoPorGeneroTABBLibros(TABBLibros abbLibros, int genero)
{
    TABBLibros filtrado = crearTABBLibrosVacio();
    filtradoAux(abbLibros, filtrado, genero);
    return filtrado;
}