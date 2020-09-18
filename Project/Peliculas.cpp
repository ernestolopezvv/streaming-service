#include "Peliculas.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;


Peliculas::Peliculas()
{
	id = "";
	nombre = "";
	duracion = "";
	genero = "";
	calificacion = "";
}

Peliculas::Peliculas(string _id, string _nombre, string _duracion, string _genero, string _calificacion): Video(_id, _nombre, _duracion, _genero)
{
	calificacion = _calificacion;
}

string Peliculas::getCalificacion()
{
	return calificacion;
}

void Peliculas::setCalificacion(string _calificacion)
{
	calificacion = _calificacion;
}


// Este metodo solo lee el archivo de películas, pero no imprime nada. (1)

void Peliculas::leerPeliculas()
{
	string numeroPelicula;
	vector <string> renglon;
	string linea, palabra;

	fstream archivoP;
	archivoP.open("peliculas.csv", ios::in);

	if (archivoP.is_open())
	{
		for (int i = 0; i < 8; i++)
		{
			renglon.clear();
			getline(archivoP, linea);

			stringstream s(linea);

			while (getline(s, palabra, ','))
			{
				renglon.push_back(palabra);
			}
			peliculas[i] = new Peliculas(renglon[0], renglon[1], renglon[2], renglon[3], renglon[4]);
		}
		archivoP.close();
	}
}


// Este método imprime los valores del archivo de peliculas. (2)

void Peliculas::mostrarPeliculas()
{
	for (int i = 0; i < 8; i++)
	{
		cout << peliculas[i]->getId() << " " << peliculas[i]->getNombre() << " " << peliculas[i]->getDuracion() << " " << peliculas[i]->getGenero() << " " << peliculas[i]->getCalificacion() << endl;
	}
}


// Este método te muestra las peliculas por su género. (2)

void Peliculas::peliculasGenero(string _genero)
{
	cout << "Las películas del genero " << _genero << "son: " << endl;
	for (int i = 0; i < 8; i++)
	{
		if (peliculas[i]->getGenero() == _genero)
		{
			cout << peliculas[i]->getNombre() << endl;
		}

	}
}


// Este método te muestra las películas por su calificación. (2 y 4)

void Peliculas::peliculasCalificacion(string _calificacion)
{
	cout << "Las películas con la calificación de calificación " << _calificacion << " son: " << endl;
	for (int i = 0; i < 8; i++)
	{
		if (peliculas[i]->getCalificacion() == _calificacion)
		{
			cout << peliculas[i]->getNombre() << endl;
		}
	}
}

// Este método calificará una película. (5)

void Peliculas::calificarPelicula(string _id, string _ncalificacionp)
{
	for (int i = 0; i < 8; i++)
	{
		if (peliculas[i]->getId() == _id)
		{
			string califa_str = peliculas[i]->getCalificacion();				 // Guarda el getCalificacion.
			float califa_flo = stoi(califa_str, nullptr, 10);					 // Convierte el string a float.
			califa_str = _ncalificacionp;										 // Guarda la calificación introducida por el usuario.
			float califn_flo = stoi(califa_str, nullptr, 10);					 // Convierte el string de la nueva calif a float.
			float sumaCalificaciones = (califa_flo + califn_flo) / 2;			 // Realiza la suma de las dos calificaciones en tipo float.
			string nuevaCalificacion = to_string(sumaCalificaciones);			 // Convierte la suma de float a string.
			peliculas[i]->setCalificacion(nuevaCalificacion);					 // Guarda el valor tipo string en el arreglo.
			cout << "La calificación actual es de: " << peliculas[i]->getCalificacion() << endl;
		}

	}
}

