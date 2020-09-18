#include "Video.h"

Video::Video()
{
	id = "";
	nombre = "";
	duracion = "";
	genero = "";
}

Video::Video(string _id, string _nombre, string _duracion, string _genero)
{
	id = _id;
	nombre = _nombre;
	duracion = _duracion;
	genero = _genero;
}

string Video::getId()
{
	return id;
}

string Video::getNombre()
{
	return nombre;
}

string Video::getDuracion()
{
	return duracion;
}

string Video::getGenero()
{
	return genero;
}


void Video::setId(string _id)
{
	id = _id;
}

void Video::setNombre(string _nombre)
{
	nombre = _nombre;
}

void Video::setDuracion(string _duracion)
{
	duracion = _duracion;
}

void Video::setGenero(string _genero)
{
	genero = _genero;
}



