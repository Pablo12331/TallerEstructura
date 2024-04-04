#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Eventos.h"
#include "Asistentes.h"

using namespace std;

bool verificarFecha(string fecha)
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

void actualizarDatos(vector<Eventos*>& eventos)
{
    Eventos* auxEventos;
    Asistentes* auxAsistentes;
    string actualizacionEventos = "", actualizacionAsistentes = "";
    int contadorSaltoLinea = 0, contadorSaltoLinea2 = 0;
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
        
        contadorSaltoLinea2 = 0;
        cout<<evento->getAsistentes().size()<<endl;

        for(Asistentes* asistente : evento->getAsistentes())
        {
            if(contadorSaltoLinea2 != 0)
            {
                actualizacionAsistentes += "\n" + asistente->informacionCompletaAsistente();
            }
            else
            {
                actualizacionAsistentes += asistente->informacionCompletaAsistente();
            }
            contadorSaltoLinea2++;
        }
        ++contadorSaltoLinea;
    }
    cout<<actualizacionAsistentes<<endl;
    auxEventos->actualizarDatosEventos(actualizacionEventos);
    auxAsistentes->actualizarDatosAsistentes(actualizacionAsistentes);

}

void agregarDatos(vector<Eventos*>& eventos, string fechaHoy)
{
    ifstream datosEvento;
    string texto, tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento;

    datosEvento.open("prueba de leerArchivos.txt", ios::in);

    if(datosEvento.fail())
    {
        cout<<"ERROR! no se pudo leer el archivo eventos."<<endl;
        exit(1);
    }

    while(!datosEvento.eof())
    {
        Eventos* aux;
        getline(datosEvento, texto);
        aux->agregarDatosEventos(eventos, fechaHoy, texto);
    }
    datosEvento.close();

    ifstream datosAsistentes;

    datosAsistentes.open("Prueba Asistentes.txt", ios::in);

    if(datosAsistentes.fail())
    {
        cout<<"ERROR! no se pudo leer el archivo de asistentes."<<endl;
        exit(1);
    }  

    while(!datosAsistentes.eof())
    {
        Asistentes* aux;
        Asistentes* asistente;
        getline(datosAsistentes, texto);
        cout<<texto<<endl;
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

    // for(Eventos* evento : eventos)
    // {
    //     cout<<evento->getAsistentes().size()<<endl;
    // }

    datosAsistentes.close();
}

int sistema()
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

    cout<<eventos.size()<<endl;

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

                break;
            case 4:
                aux->informacionGeneral(eventos);
                break;
            case 5:
                
                break;
            case 6:
                cout<<"saliendo..."<<endl;
                cin.clear();
                cin.ignore();
                break;
        }

    }
    while(respuesta != 6);
    actualizarDatos(eventos);
    return 0;
}
int main()
{
    sistema();
    return 0;
}

