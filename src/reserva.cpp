
#include "../include/reserva.h"

struct rep_reserva
{
  TSocio socio;
  TLibro libro;
};

TReserva crearTReserva(TSocio socio, TLibro libro)
{
  TReserva nuevaReserva = new rep_reserva;
  nuevaReserva->socio = socio;
  nuevaReserva->libro = libro;
  return nuevaReserva;
}

void imprimirTReserva(TReserva reserva)
{
  printf("Reserva de libro %s por %s %s.\n", tituloTLibro(reserva->libro), nombreTSocio(reserva->socio), apellidoTSocio(reserva->socio));
}

void liberarTReserva(TReserva &reserva)
{
  if (reserva == NULL)
  {
    return;
  }
  // liberar los objetos que la reserva creó/posee (socio y libro)
  // Asume las firmas: void liberarTSocio(TSocio&) y void liberarTLibro(TLibro&)
  if (reserva->socio != NULL)
    liberarTSocio(reserva->socio);
  if (reserva->libro != NULL)
    liberarTLibro(reserva->libro);

  delete reserva;
  reserva = NULL;
}

TSocio socioTReserva(TReserva reserva)
{
  return reserva->socio;
}

TLibro libroTReserva(TReserva reserva)
{
  return reserva->libro;
}

TReserva copiarTReserva(TReserva reserva)
{
  TReserva copiaReserva = new rep_reserva;
  copiaReserva->libro = copiarTLibro(reserva->libro);
  copiaReserva->socio = copiarTSocio(reserva->socio);
  return copiaReserva;
}

void liberarTReservaSoloEstructura(TReserva &reserva)
{
  if (reserva == NULL)
  {
    return;
  }
  delete reserva;
  reserva = NULL;
}
