#include "Eventos.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

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
    string tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento; 
    int eleccion;
    do
    {
        cout<<"\nIngrese la fecha en la que se hara el evento(Ej:28/03/2024): ";
        cin >> fecha;
        if(compararFechas(fechaHoy, fecha))
        {
            cout<<"\nLa fecha ingresada es menor a la fecha de el dia de hoy.";
            continue;
        }
    } while (compararFechas(fechaHoy, fecha));

    do
    {
        cout<<"\nDe que tipo quiere que sea su evento: \n"
            <<"\n 1) boda"
            <<"\n 2) Reunion de Trabajo"
            <<"\n 3) Carrete"
            <<endl
            <<"\n Coloque su opciones aqui(Ejemplo: 1): ";
        cin >> eleccion;
        switch (eleccion)
        {
            case 1:
                tipoEvento = "boda";
                break;
            case 2:
                tipoEvento = "Reunion de trabajo";
                break;
            case 3:
                tipoEvento = "Carrete";
                break;
            default:
                cout<<"La eleccion seleccionada es incorrecta, coloque una de las que aparece en pantalla.";
        }

    } while (eleccion != 1 && eleccion != 2 && eleccion != 3);

    cout<<"\nUbicacion del evento(Ejemplo: Coquimbo, Parte Alta): ";
    cin >> ubicacion;

    do
    {
        cout<<"\nQue formatos de comida y bebestibles se solicita en el evento: \n"
            <<"\n 1) Comida y bebestibles tipo coctel."
            <<"\n 2) barra libre y picoteo."
            <<"\n 3) Almuerzo y once."
            <<endl
            <<"\n Coloque su opciones aqui(Ejemplo: 1): ";
        cin >> eleccion;
        switch (eleccion)
        {
            case 1:
                alimentos = "Comida y bebestibles tipo coctel";
                break;
            case 2:
                alimentos = "barra libre y picoteo";
                break;
            case 3:
                alimentos = "Almuerzo y once";
                break;
            default:
                cout<<"La eleccion seleccionada es incorrecta, coloque una de las que aparece en pantalla.";
        }
    } while (eleccion != 1 && eleccion != 2 && eleccion != 3);

     do
    {
        cout<<"\nQue tipo de musica se escuchara en el evento: \n"
            <<"\n 1) Moderna."
            <<"\n 2) Clasica."
            <<"\n 3) Ochentera."
            <<endl
            <<"\n Coloque su opciones aqui(Ejemplo: 1): ";
        cin >> eleccion;
        switch (eleccion)
        {
            case 1:
                tipoMusica = "Moderna";
                break;
            case 2:
                tipoMusica = "Clasica";
                break;
            case 3:
                tipoMusica = "Ochentera";
                break;
            default:
                cout<<"La eleccion seleccionada es incorrecta, coloque una de las que aparece en pantalla.";
        }
    } while (eleccion != 1 && eleccion != 2 && eleccion != 3);

    cout<<"\ncodigo evento: ";
    cin >> codigoEvento;
    
    Eventos *evento = new Eventos(tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento);
    eventos.push_back(evento);
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