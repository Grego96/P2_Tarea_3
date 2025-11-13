
#include "../include/prestamo.h"

struct rep_prestamo
{
  TSocio socioPrestamo;
  TLibro libroPrestamo;
  TFecha fechaRetiro;
  TFecha fechaDevolucion;
};

TPrestamo crearTPrestamo(TSocio socio, TLibro libro, TFecha fechaRetiro)
{
  TPrestamo nuevoPrestamo = new rep_prestamo;
  nuevoPrestamo->socioPrestamo = socio;
  nuevoPrestamo->libroPrestamo = libro;
  nuevoPrestamo->fechaRetiro = fechaRetiro;
  nuevoPrestamo->fechaDevolucion = NULL;
  return nuevoPrestamo;
}

void imprimirTPrestamo(TPrestamo prestamo)
{
  printf("Préstamo de libro %s a %s %s.\n", tituloTLibro(prestamo->libroPrestamo), nombreTSocio(prestamo->socioPrestamo), apellidoTSocio(prestamo->socioPrestamo));
  imprimirTFecha(prestamo->fechaRetiro);
  if (prestamo->fechaDevolucion != NULL)
  {
    imprimirTFecha(prestamo->fechaDevolucion);
  }
  else
  {
    printf("No retornado\n");
  }
}

void liberarTPrestamo(TPrestamo &prestamo)
{
  liberarTSocio(prestamo->socioPrestamo);
  liberarTLibro(prestamo->libroPrestamo);
  liberarTFecha(prestamo->fechaRetiro);
  liberarTFecha(prestamo->fechaDevolucion);
  delete prestamo;
  prestamo = NULL;
}

TSocio socioTPrestamo(TPrestamo prestamo)
{
  return prestamo->socioPrestamo;
}

TFecha fechaRetiroTPrestamo(TPrestamo prestamo)
{
  return prestamo->fechaRetiro;
}

TFecha fechaDevolucionTPrestamo(TPrestamo prestamo)
{
  return prestamo->fechaDevolucion;
}

TLibro libroTPrestamo(TPrestamo prestamo)
{
  return prestamo->libroPrestamo;
}

bool fueRetornadoTPrestamo(TPrestamo prestamo)
{
  if (prestamo->fechaDevolucion != NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void actualizarFechaDevolucionTPrestamo(TPrestamo prestamo, TFecha fechaDevolucion)
{
  if (prestamo->fechaDevolucion != NULL)
  {
    liberarTFecha(prestamo->fechaDevolucion);
    prestamo->fechaDevolucion = fechaDevolucion;
  }
  else
  {
    prestamo->fechaDevolucion = fechaDevolucion;
  }
}

TPrestamo copiarTPrestamo(TPrestamo prestamo)
{
  TPrestamo copiaPrestamo = new rep_prestamo;
  copiaPrestamo->socioPrestamo = copiarTSocio(prestamo->socioPrestamo);
  copiaPrestamo->libroPrestamo = copiarTLibro(prestamo->libroPrestamo);
  copiaPrestamo->fechaRetiro = copiarTFecha(prestamo->fechaRetiro);
  if (prestamo->fechaDevolucion != NULL)
  {
    copiaPrestamo->fechaDevolucion = copiarTFecha(prestamo->fechaDevolucion);
  }
  else
  {
    copiaPrestamo->fechaDevolucion = NULL;
  }
  return copiaPrestamo;
}