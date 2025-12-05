
#include "../include/agGeneros.h"
#include <assert.h>

struct rep_agGeneros
{
  int codigo;
  char genero[MAX_NOMBRE];
  TAGGeneros ph;
  TAGGeneros sh;
};

TAGGeneros crearTAGGeneros()
{
  TAGGeneros nuevoTAGGenero = new rep_agGeneros;
  nuevoTAGGenero->codigo = -1;
  nuevoTAGGenero->genero[0] = '\0';
  nuevoTAGGenero->ph = NULL;
  nuevoTAGGenero->sh = NULL;
  return nuevoTAGGenero;
}

void insertarGeneroTAGGeneros(TAGGeneros &arbolGeneros, int idGeneroPadre, int idGenero, const char nombreGenero[MAX_NOMBRE])
{
  if (idGeneroPadre == -1)
  {
    if (!arbolGeneros)
    {
      arbolGeneros = crearTAGGeneros();
    }
    arbolGeneros->codigo = idGenero;
    return;
  }
  if (!arbolGeneros)
  {
    return;
  }
  if (arbolGeneros->codigo == idGeneroPadre)
  {
    TAGGeneros nuevoArbol = crearTAGGeneros();
    nuevoArbol->codigo = idGenero;
    nuevoArbol->sh = arbolGeneros->sh;
    nuevoArbol->ph = NULL;
    arbolGeneros->ph = nuevoArbol;
    return;
  }
}

void imprimirTAGGeneros(TAGGeneros arbolGeneros)
{
}

void liberarTAGGeneros(TAGGeneros &arbolGeneros)
{
}

bool existeGeneroTAGGeneros(TAGGeneros arbolGeneros, int idGenero)
{
  return false;
}

char *nombreGeneroTAGGeneros(TAGGeneros arbolGeneros, int idGenero)
{
  return NULL;
}

nat alturaTAGGeneros(TAGGeneros arbolGeneros)
{
  return 0;
}

nat cantidadTAGGeneros(TAGGeneros arbolGeneros)
{
  return 0;
}

TAGGeneros obtenerSubarbolTAGGeneros(TAGGeneros arbolGeneros, int idGenero)
{
  return NULL;
}

TConjuntoGeneros obtenerConjuntoGeneros(TAGGeneros arbolGeneros, int idGenero)
{
  return NULL;
}

int obtenerMaxTAGGeneros(TAGGeneros arbolGeneros)
{
  return 0;
}

void removerGeneroTAGGeneros(TAGGeneros &arbolGeneros, int idGenero)
{
}
