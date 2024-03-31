#include "Eventos.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <sstream>


Eventos::Eventos(string tipoEvento, string ubicacion, string alimentos, string fecha, string tipoMusica, string codigoEvento)
{
    this-> tipoEvento = tipoEvento;
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

bool Eventos::cantidadEventosDia(vector<Eventos*>& eventos, string fechaHoy)
{
    int cantidadEventos = 0;
    for(Eventos* evento : eventos)
    {
        if(evento->getFecha() == fechaHoy)
        {
            ++cantidadEventos;
        }
    }
    if(cantidadEventos == 3){return false;}
    else{return true;}
}

bool Eventos::compararFechas(string fecha1, string fecha2)
{
    string dia1, dia2, mes1, mes2, year1, year2;
    if(fecha1 == fecha2)
    {
        return false;
    }

    stringstream fecha1Separada(fecha1);
    getline(fecha1Separada, dia1,'/'); getline(fecha1Separada, mes1,'/'); getline(fecha1Separada, year1,'/');
    stringstream fecha2Separada(fecha2);
    getline(fecha2Separada, dia2,'/'); getline(fecha2Separada, mes2,'/'); getline(fecha2Separada, year2,'/');
    
    if(year1 < year2)
    {
        return false;
    }
    else if(mes1 < mes2 && year1 == year2)
    {
        return false;
    }
    else if(dia1 < dia2 && mes1 == mes2 && year1 == year2)
    {
        return false;
    }

    return true;
}



void Eventos::crearEvento(vector<Eventos*>& eventos, string fechaHoy)
{
    string tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento, eleccion; 
    do
    {
        cout<<"\nIngrese la fecha en la que se hara el evento(Ej:28/03/2024): ";
        cin >> fecha;
        if(compararFechas(fechaHoy, fecha))
        {
            cout<<"La fecha ingresada es menor a la fecha de el dia de hoy.";
            continue;
        }
    } while (compararFechas(fechaHoy, fecha));

    do
    {
        cout<<"Seleccione una de las opciones en pantalla: \n"
            <<"\n 1) boda"
            <<"\n 2) Reunion de Trabajo"
            <<"\n 3) Carrete"
            <<endl
            <<"\n Coloque su opciones aqui(Ejemplo: 1): ";
        
    } while (eleccion != "1" || eleccion != "2" || eleccion != "3");

    cout<<"Ubicacion del evento: ";
    cin >> ubicacion;

    cout<<"Ubicacion del evento: ";
    cin >> alimentos;
    
    cout<<"Ubicacion del evento: ";
    cin >> fecha;

    cout<<"Ubicacion del evento: ";
    cin >> codigoEvento;

}

void Eventos::agregarDatos(vector<Eventos*>& eventos, string fechaHoy)//esto es una mausque herramienta misteriosa que ocuparemos cuando sepa leer archivos.txt xd
{
    ifstream archivo;
    string texto, tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento;

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

        getline(datosSeparar, tipoEvento, ',');
        getline(datosSeparar, ubicacion, ',');
        getline(datosSeparar, alimentos, ',');
        getline(datosSeparar, fecha, ',');
        getline(datosSeparar, tipoMusica, ',');
        getline(datosSeparar, codigoEvento, ',');

        Eventos *evento;
        
        if(!compararFechas(fechaHoy, fecha))
        {
            evento = new Eventos(tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento);
            eventos.push_back(evento);
        }
        
    }
    archivo.close();
}