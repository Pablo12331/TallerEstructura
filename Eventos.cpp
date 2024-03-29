#include "Eventos.h"
#include <fstream>
#include <iostream>
#include <string.h>

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
void Eventos::informacionGeneral(vector<Eventos*> eventos)
{
    for(Eventos* evento: eventos)
    {
        //forma de sumar datos para luego darlos por pantalla por el pedido de informacion
    }
}
void Eventos::agregarDatos(vector<Eventos*> eventos)//esto es una mausque herramienta misteriosa que ocuparemos cuando sepa leer archivos.txt xd
{
    ifstream archivo;
    string texto;

    archivo.open("prueba de leerArchivos.txt", ios::in);

    if(archivo.fail())
    {
        cout<<"ERROR! no se pudo abrir el archivo."<<endl;
        exit(1);
    }

    while(!archivo.eof())
    {
        getline(archivo, texto);
        cout<<texto<<endl;
    }
}