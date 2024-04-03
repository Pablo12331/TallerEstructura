#include "Asistentes.h"
#include "Eventos.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

Eventos::Eventos(string tipoEvento, string ubicacion, string alimentos, string fecha, string tipoMusica, string codigoEvento)
{
    this -> tipoEvento = tipoEvento;
    this -> ubicacion = ubicacion;
    this -> alimentos = alimentos;
    this -> fecha = fecha;
    this -> tipoMusica =tipoMusica;
    this -> codigoEvento = codigoEvento;
    this ->asistentes.reserve(1);
}
Eventos::~Eventos(){}//destructor

void Eventos::agregarAsistente(Asistentes*& asistente)
{
    if(asistente != nullptr)
    {
        cout<<"b"<<endl;
        this -> asistentes.push_back(asistente);
        cout<<"a"<<endl;
    }
}

void Eventos::informacionGeneral(vector<Eventos*>& eventos)
{

    cout<<"Informes y datos:"<<endl;
    cout<<"Lista de eventos planeados:"<<endl;
    int contBoda=0;
    int contCarre=0;
    int contReu=0;
    int cantiBoda=0;
    int cantiCarre=0;
    int cantiReu=0;
    for(Eventos* evento : eventos)
    {
        cout<<evento->getTipoEvento()<<" "<<evento->getUbicacion()<<" "<<evento->getFecha()<<" "<<evento->getCodigoEvento()<<" "<<evento->getTipoMusica()<<" "<<evento->getAlimentos()<<endl;
    }
    cout<<" "<<endl;
    cout<<"Asistentes de cada evento: "<<endl; 
    for(Eventos* evento : eventos)
    {
        cout<<evento -> getTipoEvento()<<" "<<evento -> getCodigoEvento()<<endl;
        for(Asistentes* asistente: evento->getAsistentes())
        {
            cout<<asistente->getNombre()<<asistente->getRut()<<endl;
        }
        cout<<""<<endl;
    }
    cout<<"Promedio de asistentes por tipo de evento: "<<endl;
    

}
string Eventos::getTipoEvento()
{
    return this -> tipoEvento;
}
string Eventos::getUbicacion()
{
    return this -> ubicacion;
}
void Eventos::setAsistentes(vector<Asistentes*>asistentes)
{
    this->asistentes = asistentes;
}

vector<Asistentes*> Eventos::getAsistentes()
{
    return this -> asistentes;
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

bool Eventos::verificarCodigoEvento(string codigoEvento, vector<Eventos*>& eventos)
{
    for(Eventos* evento : eventos)
    {
        if(evento->getCodigoEvento() == codigoEvento)
        {
            return true;
        }
    }
    return false;
}

void Eventos::crearEvento(vector<Eventos*>& eventos, string fechaHoy)
{
    string tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento; 
    int eleccion1, eleccion2, eleccion3;
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
        cin >> eleccion1;
        switch (eleccion1)
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

    } while (eleccion1 != 1 && eleccion1 != 2 && eleccion1 != 3);

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
        cin >> eleccion2;
        switch (eleccion2)
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
    } while (eleccion2 != 1 && eleccion2 != 2 && eleccion2 != 3);

     do
    {
        cout<<"\nQue tipo de musica se escuchara en el evento: \n"
            <<"\n 1) Moderna."
            <<"\n 2) Clasica."
            <<"\n 3) Ochentera."
            <<endl
            <<"\n Coloque su opciones aqui(Ejemplo: 1): ";
        cin >> eleccion3;
        switch (eleccion3)
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
    } while (eleccion3 != 1 && eleccion3!= 2 && eleccion3 != 3);

    do
    {
        codigoEvento = 1000 + rand() % 8999;
    }while(verificarCodigoEvento(codigoEvento, eventos));
    
    Eventos *evento = new Eventos(tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento);
    eventos.push_back(evento);
}

void Eventos::agregarDatosEventos(vector<Eventos*>& eventos, string fechaHoy, string linea)//esto es una mausque herramienta misteriosa que ocuparemos cuando sepa leer archivos.txt xd
{
    string tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento;

    Eventos* evento;
    
    stringstream datosSeparar(linea);

    getline(datosSeparar, tipoEvento, ',');
    getline(datosSeparar, ubicacion, ',');
    getline(datosSeparar, alimentos, ',');
    getline(datosSeparar, fecha, ',');
    getline(datosSeparar, tipoMusica, ',');
    getline(datosSeparar, codigoEvento, ',');

    if(!compararFechas(fechaHoy, fecha))
    {
        evento = new Eventos(tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento);
        eventos.push_back(evento);
    } 
}

void Eventos::actualizarDatos(vector<Eventos*>&, string)
{

}