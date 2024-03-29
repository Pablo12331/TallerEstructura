#include "Eventos.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <sstream>


Eventos::Eventos(double duracion, string alimentos, string fecha, string tipoMusica, string estadoEvento)
{
    this -> duracion = duracion;
    this -> alimentos = alimentos;
    this -> fecha = fecha;
    this -> tipoMusica =tipoMusica;
    this -> estadoEvento = estadoEvento;
}
Eventos::~Eventos(){}//destructor

void Eventos::agregarAsistente(Asistentes asistente)
{
    this -> asistentes.push_back(&asistente);
}
void Eventos::setEstadoEvento(string estadoEvento) 
{
    this -> estadoEvento = estadoEvento;
}
void Eventos::informacionGeneral(vector<Eventos*>& eventos)
{
    for(Eventos* evento : eventos)
    {
        
    }
}
//Eventos::getDuracion();
string Eventos::getAlimentos()
{
    return this -> alimentos;
}
//Eventos::getFecha();
//Eventos::getTipoMusica();
string Eventos::getEstadoEvento()
{
    return this -> estadoEvento;
}

void Eventos::agregarDatos(vector<Eventos*>& eventos)//esto es una mausque herramienta misteriosa que ocuparemos cuando sepa leer archivos.txt xd
{
    ifstream archivo;
    string texto, duracionString, alimentos, fecha, tipoMusica, estadoEvento;

    archivo.open("prueba de leerArchivos.txt", ios::in);

    if(archivo.fail())
    {
        cout<<"ERROR! no se pudo abrir el archivo."<<endl;
        exit(1);
    }

    while(!archivo.eof())
    {
        getline(archivo, texto);

        stringstream datosSeparar(texto);
    
        getline(datosSeparar, duracionString, ',');
        getline(datosSeparar, alimentos, ',');
        getline(datosSeparar, fecha, ',');
        getline(datosSeparar, tipoMusica, ',');
        getline(datosSeparar, estadoEvento, ',');
        double duracion = stod(duracionString);

        Eventos *evento = new Eventos(duracion, alimentos, fecha, tipoMusica, estadoEvento);
        eventos.push_back(evento);
    }
    
}