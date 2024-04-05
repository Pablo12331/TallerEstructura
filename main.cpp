#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Eventos.h"
#include "Asistentes.h"

using namespace std;

bool verificarFecha(string fecha)// Revisa que la fecha esté bien escrita
{
    string dia = "", mes = "", year = "";
    stringstream separarFechas(fecha);
    getline(separarFechas, dia, '/');
    getline(separarFechas, mes, '/');
    getline(separarFechas, year, '/');
    if(dia == "" || mes == "" || year == "")
    {
        cout<<"ERROR! El formato de la fecha ingresada es incorrecto siga el ejemplo por favor."<<endl;
        return true;
    }
    else
    {
        return false;
    }
}

void actualizarDatosAsistentes(vector<Asistentes*>& asistentes)// Actualiza los datos de asistentes en el sistema 
{
    Asistentes* auxAsistente;
    string actualizacionAsistentes = "";
    int contadorSaltoLinea = 0;

    for(Asistentes* asistente : asistentes)
    {
        if(contadorSaltoLinea < asistentes.size() - 1)
        {
            actualizacionAsistentes += asistente->informacionCompletaAsistente() + "\n";
        }
        else
        {
            actualizacionAsistentes += asistente->informacionCompletaAsistente();
        }
        contadorSaltoLinea++;
    }
    auxAsistente->actualizarDatosAsistentes(actualizacionAsistentes);
}

void actualizarDatosEventos(vector<Eventos*>& eventos)// Actualiza los datos del sistema cuando se modifican los eventos
{
    Eventos* auxEventos;
    string actualizacionEventos = "";
    int contadorSaltoLinea = 0;
    vector<Asistentes*> asistentes;
    for(Eventos* evento : eventos)
    {
        if(contadorSaltoLinea < eventos.size() - 1)
        {
            actualizacionEventos += evento->informacionCompletaEventos() + "\n";
        }
        else
        {
            actualizacionEventos += evento->informacionCompletaEventos();
        }

        for(Asistentes* asistente : evento->getAsistentes())
        {
            asistentes.push_back(asistente);
        }

        contadorSaltoLinea++;
    }
    auxEventos->actualizarDatosEventos(actualizacionEventos);
    actualizarDatosAsistentes(asistentes);
}


void agregarDatos(vector<Eventos*>& eventos, string fechaHoy)// Agrega los datos de los txt dentro del sistema
{
    string texto;
    
    ifstream datosEvento;

    datosEvento.open("Datos Eventos.txt", ios::in);

    if(datosEvento.fail())
    {
        cout<<"ERROR! no se pudo leer el archivo eventos."<<endl;
        exit(1);
    }

    while(getline(datosEvento, texto))
    {
        Eventos* aux;
        aux->agregarDatosEventos(eventos, fechaHoy, texto);
    }
    datosEvento.close();

    ifstream datosAsistentes;

    datosAsistentes.open("Datos Asistentes.txt", ios::in);

    if(datosAsistentes.fail())
    {
        cout<<"ERROR! no se pudo leer el archivo de asistentes."<<endl;
        exit(1);
    }  

    while(getline(datosAsistentes, texto))
    {
        Asistentes* aux;
        Asistentes* asistente;
        asistente = aux->agregarDatosAsistentes(texto);
        for(Eventos* evento : eventos)
        {
            if(asistente == nullptr)
            {
                break;
            }
            else if(stoi(evento->getCodigoEvento()) == stoi(asistente->getCodigoEvento()))
            {
                evento->agregarAsistente(asistente);
            }
        }
    }
    datosAsistentes.close();
}

int sistema()//menú y funcionamiento del sistema
{
    string fechaActualidad;
    string resp;

    vector<Eventos*> eventos;
    Eventos* aux;
    do
    {
        cout<<"Bienvenido. Ingrese la fecha de hoy(Ej:28/03/2024): ";
        cin >> fechaActualidad;
    } while (verificarFecha(fechaActualidad));

    agregarDatos(eventos, fechaActualidad);

    int respuesta;
    do
    {
        respuesta = 0;
        cout<<"\nEscoja una opción válida: "<<endl<<"1)Crear nuevo evento"<<endl<<"2)Registrar asistentes"<<
        endl<<"3)Revisión de Asistentes"<<endl<<"4)Informes de eventos"<<endl
        <<"5)Cancelar evento"<<endl<<"6)Salir."<<endl<<"\nColoque su opciones aqui(Ejemplo: 1): ";
        cin >> resp;

        respuesta = stoi(resp);

        switch(respuesta)
        {
            case 1:
                if(aux->cantidadEventosDia(eventos, fechaActualidad))
                {
                    aux->crearEvento(eventos, fechaActualidad);
                }
                else
                {
                    cout<<"Capacidad maxima de eventos alcanzada, no se pueden crear mas eventos."<<endl;
                }
                break;
            case 2:
                aux->registrarAsistente(eventos);
                break;
            case 3:
                aux ->revisionAsistentes(eventos);
                break;
            case 4:
                aux->informacionGeneral(eventos);
                break;
            case 5:
                aux->eliminarEvento(eventos);
                break;
            case 6:
                cout<<"saliendo..."<<endl;
                cin.clear();
                cin.ignore();
                break;
        }

    }
    while(respuesta != 6);
    actualizarDatosEventos(eventos);
    return 0;
}
int main()//main
{
    sistema();
    return 0;
}
