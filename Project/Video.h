#pragma once
#include <iostream>
using namespace std;

class Video
{
protected:
	string id;
	string nombre;
	string duracion;
	string genero;

public:
	Video();
	Video(string, string, string, string);

	string getId();
	string getNombre();
	string getDuracion();
	string getGenero();

	void setId(string);
	void setNombre(string);
	void setDuracion(string);
	void setGenero(string);

	
};

