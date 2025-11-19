#include "../include/conjuntoGeneros.h"

struct rep_conjuntogeneros
{
  int cantidad;
  int cota;
  bool *tabla;
};

TConjuntoGeneros crearTConjuntoGeneros(int cantMax)
{
  TConjuntoGeneros nuevoConjunto = new rep_conjuntogeneros;
  nuevoConjunto->cantidad = 0;
  nuevoConjunto->cota = cantMax;
  nuevoConjunto->tabla = new bool[cantMax];
  for (int i = 0; i < cantMax; i++)
  {
    nuevoConjunto->tabla[i] = 0;
  }
  return nuevoConjunto;
}

bool esVacioTConjuntoGeneros(TConjuntoGeneros c)
{
  return c->cantidad == 0;
}

void insertarTConjuntoGeneros(TConjuntoGeneros &c, int id)
{
  if (c == NULL)
    return;
  if (id >= 0 && id < c->cota)
  {
    if (c->tabla[id] == 0)
    {
      c->tabla[id] = 1;
      c->cantidad++;
    }
  }
}

void borrarDeTConjuntoGeneros(TConjuntoGeneros &c, int id)
{
  if (!perteneceTConjuntoGeneros(c, id))
  {
    return;
  }

  if (c->tabla[id] == 1)
  {
    c->tabla[id] = 0;
    c->cantidad--;
  }
}

bool perteneceTConjuntoGeneros(TConjuntoGeneros c, int id)
{
  if (c == NULL)
    return false;
  if (id < 0 || id >= c->cota)
    return false;
  return c->tabla[id] == 1;
}

int cardinalTConjuntoGeneros(TConjuntoGeneros c)
{
  return c->cantidad;
}

int cantMaxTConjuntoGeneros(TConjuntoGeneros c)
{
  return c->cota;
}

void imprimirTConjuntoGeneros(TConjuntoGeneros c)
{
  {
    if (c == NULL)
    {
      printf("\n");
      return;
    }
    bool first = true;
    for (int i = 0; i < c->cota; i++)
    {
      if (c->tabla[i])
      {
        if (!first)
          printf(" ");
        printf("%d", i);
        first = false;
      }
    }
    printf("\n");
  }
}

void liberarTConjuntoGeneros(TConjuntoGeneros &c)
{
  delete[] c->tabla;
  delete c;
  c = NULL;
}

TConjuntoGeneros unionTConjuntoGeneros(TConjuntoGeneros c1, TConjuntoGeneros c2)
{
  return NULL;
}

TConjuntoGeneros interseccionTConjuntoGeneros(TConjuntoGeneros c1, TConjuntoGeneros c2)
{
  return NULL;
}

TConjuntoGeneros diferenciaTConjuntoGeneros(TConjuntoGeneros c1, TConjuntoGeneros c2)
{
  return NULL;
}
