#include "../include/libro.h"

struct rep_libro
{
    int isbn;
    char titulo[MAX_TITULO];
    char nombreAutor[MAX_NOMBRE_AUTOR];
    char apellidoAutor[MAX_APELLIDO_AUTOR];
    char descripcion[MAX_DESCRIPCION];
    int idGeneroLibro;
    TFecha fechaEdicion;
};

// Crea y retorna un elemento de tipo TLibro con los valores dados
TLibro crearTLibro(int isbn, const char titulo[MAX_TITULO], const char nombreAutor[MAX_NOMBRE_AUTOR], const char apellidoAutor[MAX_APELLIDO_AUTOR], const char descripcion[MAX_DESCRIPCION], int idGeneroLibro, TFecha fechaEdicion)
{
    TLibro nuevoLibro = new rep_libro;
    nuevoLibro->isbn = isbn;
    strcpy(nuevoLibro->titulo, titulo);
    strcpy(nuevoLibro->nombreAutor, nombreAutor);
    strcpy(nuevoLibro->apellidoAutor, apellidoAutor);
    strcpy(nuevoLibro->descripcion, descripcion);
    nuevoLibro->idGeneroLibro = idGeneroLibro;
    nuevoLibro->fechaEdicion = fechaEdicion;

    return nuevoLibro;
}

// Libera la memoria asignada para el libro 'l'
// Debe liberar también la memoria de la fecha asociada
void liberarTLibro(TLibro &l)
{
    liberarTFecha(l->fechaEdicion);
    delete l;
    l = NULL;
}

// Retorna el isbn del libro 'l'
int isbnTLibro(TLibro l)
{
    return l->isbn;
}

// Retorna el titulo del libro 'l'
// El titulo retornado comparte memoria con el parámetro.
char *tituloTLibro(TLibro l)
{
    return l->titulo;
}

// Retorna la descripción del libro 'l'
// La descripción retornada comparte memoria con el parámetro.
char *descripcionTLibro(TLibro l)
{
    return l->descripcion;
}

// Retorna el nombre del autor del libro 'l'
// El nombre retornado comparte memoria con el parámetro.
char *nombreAutorTLibro(TLibro l)
{
    return l->nombreAutor;
}

// Retorna el apellido del autor del libro 'l'
// El apellido retornado comparte memoria con el parámetro.
char *apellidoAutorTLibro(TLibro l)
{
    return l->apellidoAutor;
}

// Retorna el id del género del libro 'l'
int idGeneroTLibro(TLibro l)
{
    return l->idGeneroLibro;
}

// Retorna la fecha de edición del libro 'l'.
// La fecha retornada comparte memoria con el parámetro.
TFecha fechaEdicionTLibro(TLibro l)
{
    return l->fechaEdicion;
}

// Imprime la información del libro 'l' en el siguiente formato:
// Libro <isbn>
// Título: <título>
// Autor: <nombre autor> <apellido autor>
// Descripción: <descripcion>
// Género: <id género>
// Fecha de edición: <fecha de edición>
void imprimirTLibro(TLibro l)
{
    printf("Libro %d\n", l->isbn);
    printf("Título: %s\n", l->titulo);
    printf("Autor: %s ", l->nombreAutor);
    printf("%s\n", l->apellidoAutor);
    printf("Descripción: %s\n", l->descripcion);
    printf("Género: %d\n", l->idGeneroLibro);
    printf("Fecha de edición: ");
    imprimirTFecha(l->fechaEdicion);
}

// Retorna una copia del libro 'l' que no comparte memoria con el parámetro.
TLibro copiarTLibro(TLibro l)
{
    TLibro copiaLibro = new rep_libro;

    copiaLibro->isbn = l->isbn;
    strcpy(copiaLibro->titulo, l->titulo);
    strcpy(copiaLibro->nombreAutor, l->nombreAutor);
    strcpy(copiaLibro->apellidoAutor, l->apellidoAutor);
    strcpy(copiaLibro->descripcion, l->descripcion);
    copiaLibro->idGeneroLibro = l->idGeneroLibro;
    copiaLibro->fechaEdicion = copiarTFecha(l->fechaEdicion);

    return copiaLibro;
}
