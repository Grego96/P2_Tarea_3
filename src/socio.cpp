#include "../include/socio.h"

struct rep_socio
{
    int ci;
    char nombre[MAX_NOMBRE_SOCIO];
    char apellido[MAX_APELLIDO_SOCIO];
    TFecha fechaAlta;
    int idsGeneros[MAX_GENEROS_FAVORITOS];
    int cantidadGenerosFav;
};

TSocio crearTSocio(int ci, const char nombre[MAX_NOMBRE_SOCIO], const char apellido[MAX_APELLIDO_SOCIO], nat diaAlta, nat mesAlta, nat anioAlta)
{
    TSocio nuevoSocio = new rep_socio;
    nuevoSocio->ci = ci;
    strcpy(nuevoSocio->nombre, nombre);
    strcpy(nuevoSocio->apellido, apellido);
    nuevoSocio->fechaAlta = crearTFecha(diaAlta, mesAlta, anioAlta);
    for (int i = 0; i < MAX_GENEROS_FAVORITOS; i++)
    {
        nuevoSocio->idsGeneros[i] = 0;
    }
    nuevoSocio->cantidadGenerosFav = 0;
    return nuevoSocio;
}

void imprimirTSocio(TSocio socio)
{
    printf("Socio %d: %s %s\n", socio->ci, socio->nombre, socio->apellido);
    printf("Fecha de alta: ");
    imprimirTFecha(socio->fechaAlta);
    printf("Géneros favoritos: ");
    for (int i = 0; i < socio->cantidadGenerosFav; i++)
    {
        printf("%d ", socio->idsGeneros[i]);
    }
    printf("\n");

    // Socio <CI>: <nombre> <apellido>
    // Fecha de alta: <Fecha de Alta>
    // Géneros favoritos: <id genero favorito 1> <id genero favorito 2> ... <id genero favorito n>
    /* Requisitos específicos de la implementación solicitada: */
    // Debe ejecutar en O(1) peor caso
}

void liberarTSocio(TSocio &socio)
{
    liberarTFecha(socio->fechaAlta);
    delete socio;
    socio = NULL;
}

int ciTSocio(TSocio socio)
{
    return socio->ci;
}

char *nombreTSocio(TSocio socio)
{
    return socio->nombre;
}

char *apellidoTSocio(TSocio socio)
{
    return socio->apellido;
}

TFecha fechaAltaTSocio(TSocio socio)
{
    return socio->fechaAlta;
}

void agregarGeneroFavoritoTSocio(TSocio &socio, int idGenero)
{
    if (socio->cantidadGenerosFav < MAX_GENEROS_FAVORITOS)
    {
        socio->idsGeneros[socio->cantidadGenerosFav] = idGenero;
        socio->cantidadGenerosFav++;
    }
}

bool tieneGeneroFavoritoTSocio(TSocio socio, int idGenero)
{
    for (int i = 0; i < socio->cantidadGenerosFav; i++)
    {
        if (socio->idsGeneros[i] == idGenero)
        {
            return true;
        }
    }
    return false;
}

int cantidadGenerosFavoritosTSocio(TSocio socio)
{
    return socio->cantidadGenerosFav;
}

TSocio copiarTSocio(TSocio socio)
{
    TSocio copiaSocio = new rep_socio;
    copiaSocio->ci = socio->ci;
    strcpy(copiaSocio->nombre, socio->nombre);
    strcpy(copiaSocio->apellido, socio->apellido);
    copiaSocio->fechaAlta = copiarTFecha(socio->fechaAlta);
    for (int i = 0; i < socio->cantidadGenerosFav; i++)
    {
        copiaSocio->idsGeneros[i] = socio->idsGeneros[i];
    }
    copiaSocio->cantidadGenerosFav = socio->cantidadGenerosFav;
    return copiaSocio;
}
