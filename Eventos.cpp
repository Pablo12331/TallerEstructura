#include "Eventos.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <sstream>


Eventos::Eventos(string ubicacion, string alimentos, string fecha, string tipoMusica, string codigoEvento)
{
    this-> ubicacion = ubicacion;
    this -> alimentos = alimentos;
    this -> fecha = fecha;
    this -> tipoMusica =tipoMusica;
    this -> codigoEvento = codigoEvento;
}
Eventos::~Eventos(){}//destructor

void Eventos::agregarAsistente(Asistentes asistente)
{
    this -> asistentes.push_back(&asistente);
}

void Eventos::informacionGeneral(vector<Eventos*>& eventos)
{
    for(Eventos* evento : eventos)
    {
        
    }
}

string Eventos::getAlimentos()
{
    return this -> alimentos;
}
string Eventos::getFecha()
{
    return this->fecha;
}

string Eventos::getTipoMusica()
{
    return this->tipoMusica;
}

string Eventos::getCodigoEvento()
{
    return this -> codigoEvento;
}
bool compararFechas();

void Eventos::crearEvento(vector<Eventos*>& eventos, string fechaHoy)
{
    string ubicacion, alimentos, fecha, tipoMusica, codigoEvento; 
    do
    {
        cout<<"\nIngrese la fecha en la que se hara el evento(Ej:28/03/2024): ";
        cin >> fecha;
        if(fecha == fechaHoy)
        {
            break;
        }
    } while (compararFechas());
    
}

void Eventos::agregarDatos(vector<Eventos*>& eventos)//esto es una mausque herramienta misteriosa que ocuparemos cuando sepa leer archivos.txt xd
{
    ifstream archivo;
    string texto, ubicacion, alimentos, fecha, tipoMusica, codigoEvento;

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
    
        getline(datosSeparar, ubicacion, ',');
        getline(datosSeparar, alimentos, ',');
        getline(datosSeparar, fecha, ',');
        getline(datosSeparar, tipoMusica, ',');
        getline(datosSeparar, codigoEvento, ',');

        Eventos *evento = new Eventos(ubicacion, alimentos, fecha, tipoMusica, codigoEvento);
        eventos.push_back(evento);
    }
}