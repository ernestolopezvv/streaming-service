#include "Episodios.h"
#include "Series.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

Episodios::Episodios()
{
	id = "";
	id_episodio = "";
	nombre = "";
	duracion = "";
	calificacion = "";
	temporada = "";
}

Episodios::Episodios(string _id, string _idep, string _nombre, string _duracion, string _calificacion, string _temporada)
{
	id = _id;
	id_episodio = _idep;
	nombre = _nombre;
	duracion = _duracion;
	calificacion = _calificacion;
	temporada = _temporada;
}

string Episodios::getIDEP()
{
	return id_episodio;
}

string Episodios::getCalificacion()
{
	return calificacion;
}

string Episodios::getTemporada()
{
	return temporada;
}

void Episodios::setCalificacion(string _calificacion)
{
	calificacion = _calificacion;
}

// Este método solo lee el archivo episodios, no imprime nada. (1)

void Episodios::leerEpisodios()
{
	string numeroEpisodios;
	vector <string> renglon;
	string linea, palabra;

	fstream archivoE;
	archivoE.open("episodios.csv", ios::in);

	if (archivoE.is_open())
	{
		for (int i = 0; i < 148; i++)
		{
			renglon.clear();
			getline(archivoE, linea);

			stringstream s(linea);

			while (getline(s, palabra, ','))
			{
				renglon.push_back(palabra);
			}
			episodios[i] = new Episodios(renglon[0], renglon[1], renglon[2], renglon[3], renglon[4], renglon[5]);
		}
		archivoE.close();
	}
}

// Este método imprime los valores del archivo de episodios. (2)

void Episodios::mostrarEpisodios()
{
	for (int i = 0; i < 148; i++)
	{
		cout << episodios[i]->getId() << episodios[i]->getIDEP() << " " << episodios[i]->getNombre() << " " << episodios[i]->getDuracion() << " " << episodios[i]->getCalificacion() << " " << episodios[i]->getTemporada() << endl;
	}
}


// Este método te muestra los episodios por género. (2)

void Episodios::episodiosGenero(string _generoe)
{
	cout << "Las películas del genero " << _generoe << "son: " << endl;
	for (int i = 0; i < 148; i++)
	{
		if (series[i]->getGenero() == _generoe)
		{
			cout << episodios[i]->getNombre() << endl;
		}

	}
}

// Este método te muestra los episodios por calificacion (2)

void Episodios::episodiosCalificacion(string _calificacion)
{
	cout << "Los episodios con calificacion: " << _calificacion << "son: " << endl;
	for (int i = 0; i < 148; i++)
	{
		if (episodios[i]->getCalificacion() == _calificacion)
		{
				cout << episodios[i]->getNombre() << endl;
			
		}

	}
}

// Este método te muestra los episodios por calificación de una determinada serie. (3)

void Episodios::episodiosEpCalificacion(string _id, string _calificacione)
{	
	cout << "Los episodios con esa ID y con esa calificacion son: " << endl;
	for (int i = 0; i <148; i++)
	{
		if (episodios[i]->getId() == _id)
		{
			if (episodios[i]->getCalificacion() == _calificacione)
			{
				cout << episodios[i]->getNombre() << endl;
			}
		}

	}
}

// Este método calificará los episodios de una serie. (5)

void Episodios::calificarEpisodio(string _idep, string _ncalificacione)
{
	for (int i = 0; i < 148; i++)
	{
		if (episodios[i]->getIDEP() == _idep)
		{
			string califa_strr = episodios[i]->getCalificacion();				 // Guarda el getCalificacion.
			float califa_floo = stoi(califa_strr, nullptr, 10);					 // Convierte el string a float.
			califa_strr = _ncalificacione;										 // Guarda la calificación introducida por el usuario.
			float califn_floo = stoi(califa_strr, nullptr, 10);					 // Convierte el string de la nueva calif a float.
			float sumaCalificacioness = (califa_floo + califn_floo) / 2;		 // Realiza la suma de las dos calificaciones en tipo float.
			string nuevaCalificacionn = to_string(sumaCalificacioness);			 // Convierte la suma de float a string.
			episodios[i]->setCalificacion(nuevaCalificacionn);					 // Guarda el valor tipo string en el arreglo.
			cout << "La calificación actual es de: " << episodios[i]->getCalificacion() << endl;
		}
	}
}