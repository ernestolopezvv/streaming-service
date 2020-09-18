#pragma once
#include "Video.h"

class Series : public Video
{
protected:
	Series* series[5];
	string temporadas;

public:
	Series();
	Series(string, string, string, string);

	string getTemporadas();

	void leerSeries();
	void mostrarSeries();
	void seriesGenero(string);
};

