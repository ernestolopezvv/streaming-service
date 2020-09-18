#include <iostream>
#include "Video.h"
#include "Peliculas.h"
#include "Series.h"
#include "Episodios.h"
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "spanish");

	// Se crean los objetos que se utilizar�n.
	Peliculas movies;
	Series seriess;
	Episodios episodes;

	// Se cargan los datos en caso de que la opci�n #1 no sea la primera escogida por el usuario.
	movies.leerPeliculas();
	seriess.leerSeries();
	episodes.leerEpisodios();

	// Se inicializan variables que se utilizar�n.
	int i = 0;
	int menu = 28;

	// Se crea el tablero de men�.
	cout << "Bienvenido a mi proyecto final de Programaci�n Orientada a Objetos, a continuacion se te presentar� el menu de opciones." << endl;
	while (menu != 0)
	{
		cout << "1. Cargar archivos de datos." << endl;
		cout << "2. Mostrar los datos de los archivos en pantalla." << endl;
		cout << "3. Mostrar los videos en general con una cierta calificaci�n o de un cierto g�nero." << endl;
		cout << "4. Mostrar los episodios de una determinada serie con una calificaci�n determinada." << endl;
		cout << "5. Mostrar las pel�culas con cierta calificaci�n." << endl;
		cout << "6. Calificar un video." << endl;
		cout << "0. Salir del programa." << endl;
		cin >> menu;

		if (menu == 1)
		{
			movies.leerPeliculas();
			seriess.leerSeries();
			episodes.leerEpisodios();

			cout << "Se han cargado todos los archivos de texto. " << endl;
		}
		else if (menu == 2)
		{
			movies.mostrarPeliculas();
			seriess.mostrarSeries();
			episodes.mostrarEpisodios();
		}
		else if (menu == 3)
		{
			string _calificacione;
			string _genero;

			cout << "�Qu� calificaci�n tiene el video que est�s buscando?" << endl;
			cin >> _calificacione;
			movies.peliculasCalificacion(_calificacione);
			episodes.episodiosCalificacion(_calificacione);

			cout << "�Qu� g�nero es el video que est�s buscando?" << endl;
			cin >> _genero;
			movies.peliculasGenero(_genero);
			seriess.seriesGenero(_genero);
		}
		else if (menu == 4)
		{
			string _id;
			string _calificacione;

			cout << "�Cu�l es el ID de la serie?" << endl;
			cin >> _id;
			cout << "�Qu� calificaci�n tiene el episodio que est�s buscando?" << endl;
			cin >> _calificacione;
			episodes.episodiosEpCalificacion(_id, _calificacione);
		}
		else if (menu == 5)
		{
			string _calificacion;
			cout << "�Cu�l es la calificaci�n de la pel�cula que est�s buscando?" << endl;
			cin >> _calificacion;
			movies.peliculasCalificacion(_calificacion);
		}
		else if (menu == 6)
		{	
			int menu6 = 28;
			cout << "Bienvenido al cambio de calificaci�n de un titulo, �qu� va a querer cambiar?." << endl;
			cout << "1. Pel�cula." << endl;
			cout << "2. Episodio." << endl;
			cout << "0. Salir de esta opci�n." << endl;
			cin >> menu6;
			
			while (menu6 != 0)
			{
				if (menu6 == 1)
				{
					string _id;
					string _ncalificacionp;

					cout << "Coloca el ID de la pel�cula, por favor." << endl;
					cin >> _id;
					cout << "Coloca la nueva calificaci�n, por favor." << endl;
					cin >> _ncalificacionp;
					movies.calificarPelicula(_id, _ncalificacionp);
					break;
				}
				else if (menu6 == 2)
				{
					string _idep;
					string _ncalificacione;

					cout << "Coloca el ID del episodio, por favor." << endl;
					cin >> _idep;
					cout << "Coloca la nueva calificaci�n, por favor." << endl;
					cin >> _ncalificacione;
					episodes.calificarEpisodio(_idep, _ncalificacione);
					break;
				}
				else
				{
					cout << "Disculpa, no entiend� su respuesta." << endl;
				}
			}
		}
		else if (menu == 0)
		{
			cout << "�Muchas gracias por utilizar mi proyecto! Hasta la pr�xima." << endl;
			break;
		}
		else
		{
			cout << "Disculpa, no entend� lo que pusiste." << endl;
		}

	}

}