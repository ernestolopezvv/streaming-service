#pragma once
#include "Series.h"

class Episodios : public Series
{
protected:
	Episodios* episodios[148];
	string id_episodio;
	string calificacion;
	string temporada;

public:
	Episodios();
	Episodios(string, string, string, string, string, string);

	string getIDEP();
	string getCalificacion();
	string getTemporada();

	void setCalificacion(string);
	void leerEpisodios();
	void mostrarEpisodios();
	void episodiosCalificacion(string);
	void episodiosEpCalificacion(string, string);
	void episodiosGenero(string);
	void calificarEpisodio(string, string);

};

