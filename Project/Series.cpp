#include "Series.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

Series::Series()
{
	id = "";
	nombre = "";
	genero = "";
	temporadas = "";
}

Series::Series(string _id, string _nombre, string _genero, string _temporadas)
{
	id = _id;
	nombre = _nombre;
	genero = _genero;
	temporadas = _temporadas;
}

string Series::getTemporadas()
{
	return temporadas;
}



// Este método solo lee el archivo de las series, no imprime nada. (1)
void Series::leerSeries()
{
	string numeroSerie;
	vector <string> renglon;
	string linea, palabra;

	fstream archivoS;
	archivoS.open("series.csv", ios::in);

	if (archivoS.is_open())
	{
		for (int i = 0; i < 5; i++)
		{
			renglon.clear();
			getline(archivoS, linea);

			stringstream s(linea);

			while (getline(s, palabra, ','))
			{
				renglon.push_back(palabra);
			}
			series[i] = new Series(renglon[0], renglon[1], renglon[2], renglon[3]);
		}
		archivoS.close();
	}
}

// Este método imprime los valores del archivo de peliculas. (2)

void Series::mostrarSeries()
{
	for (int i = 0; i < 5; i++)
	{
		cout << series[i]->getId() << " " << series[i]->getNombre() << " " << " " << series[i]->getGenero() << " " << series[i]->getTemporadas() << endl;
	}
}


// Este método te imprime las series según su género.

void Series::seriesGenero(string _genero)
{
	cout << "Las series del genero " << _genero << " son: " << endl;
	for (int i = 0; i < 5; i++)
	{
		if (series[i]->getGenero() == _genero)
		{
			cout << series[i]->getNombre() << endl;
		}
	}
}