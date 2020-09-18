#pragma once
#include "Video.h"

class Peliculas : public Video
{
protected:
	Peliculas* peliculas[8];
	string calificacion;

public:
	Peliculas();
	Peliculas(string, string, string, string, string);

	string getCalificacion();
	void setCalificacion(string);

	void leerPeliculas();
	void mostrarPeliculas();
	void peliculasCalificacion(string);
	void peliculasGenero(string);
	void calificarPelicula(string, string);
};

