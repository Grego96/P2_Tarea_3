
#include "../include/lseSocios.h"

struct rep_lseSocios
{
	TSocio socio;
	rep_lseSocios *sig;
};

TLSESocios crearTLSESociosVacia()
{
	return NULL;
}

bool esVaciaTLSESocios(TLSESocios lseSocios)
{
	return (lseSocios == NULL);
}

void imprimirTLSESocios(TLSESocios lseSocios)
{
	printf("Lista de Socios:\n");
	TLSESocios aux = lseSocios;
	while (aux != NULL)
	{
		imprimirTSocio(aux->socio);
		aux = aux->sig;
	}
}

void liberarTLSESocios(TLSESocios &lseSocios)
{
	// Si la lista está vacía no hay nada que liberar
	if (esVaciaTLSESocios(lseSocios))
	{
		return;
	}

	TLSESocios actual = lseSocios;
	while (actual != NULL)
	{
		TLSESocios siguiente = actual->sig;
		// liberar el TSocio contenido
		liberarTSocio(actual->socio);
		delete actual;
		actual = siguiente;
	}
	lseSocios = NULL;
}

void insertarTLSESocios(TLSESocios &lseSocios, TSocio socio)
{
	// Crear el nuevo nodo
	TLSESocios nuevo = new rep_lseSocios;
	nuevo->socio = socio;
	nuevo->sig = NULL;

	// Si la lista está vacía, insertar como cabeza
	if (lseSocios == NULL)
	{
		lseSocios = nuevo;
		return;
	}

	TFecha fechaNuevo = fechaAltaTSocio(socio);

	// Si debe ir antes del primer elemento
	if (compararTFechas(fechaAltaTSocio(lseSocios->socio), fechaNuevo) == 1)
	{
		nuevo->sig = lseSocios;
		lseSocios = nuevo;
		return;
	}

	// Buscar posición: avanzar mientras la fecha actual sea <= fechaNuevo
	TLSESocios actual = lseSocios;
	TLSESocios previo = NULL;
	while (actual != NULL && compararTFechas(fechaAltaTSocio(actual->socio), fechaNuevo) != 1)
	{
		previo = actual;
		actual = actual->sig;
	}

	// Insertar entre previo y actual
	previo->sig = nuevo;
	nuevo->sig = actual;
}

bool existeSocioTLSESocios(TLSESocios lseSocios, int ci)
{
	TLSESocios aux = lseSocios;
	while (aux != NULL && ciTSocio(aux->socio) != ci)
	{
		aux = aux->sig;
	}

	return (aux != NULL);
}

TSocio obtenerSocioTLSESocios(TLSESocios lseSocios, int ci)
{
	TLSESocios aux = lseSocios;
	while (aux != NULL && ciTSocio(aux->socio) != ci)
	{
		aux = aux->sig;
	}
	if (aux == NULL)
		return NULL;
	return aux->socio;
}

TSocio obtenerNesimoTLSESocios(TLSESocios lseSocios, int n)
{
	int contador = 1; // n es 1-based según el header
	TLSESocios aux = lseSocios;
	while (aux != NULL && contador < n)
	{
		aux = aux->sig;
		contador++;
	}
	if (aux == NULL)
		return NULL;
	return aux->socio;
}

nat cantidadTLSESocios(TLSESocios lseSocios)
{
	nat contador = 0;
	TLSESocios aux = lseSocios;
	while (aux != NULL)
	{
		contador++;
		aux = aux->sig;
	}
	return contador;
}

void removerSocioTLSESocios(TLSESocios &lseSocios, int ci)
{
	if (lseSocios == NULL)
		return;

	// Si el elemento a eliminar está en la cabeza
	if (ciTSocio(lseSocios->socio) == ci)
	{
		TLSESocios aBorrar = lseSocios;
		lseSocios = lseSocios->sig;
		liberarTSocio(aBorrar->socio);
		delete aBorrar;
		return;
	}

	TLSESocios previo = lseSocios;
	TLSESocios actual = lseSocios->sig;
	while (actual != NULL && ciTSocio(actual->socio) != ci)
	{
		previo = actual;
		actual = actual->sig;
	}

	if (actual != NULL)
	{
		previo->sig = actual->sig;
		liberarTSocio(actual->socio);
		delete actual;
	}
}