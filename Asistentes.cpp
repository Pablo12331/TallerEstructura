#include "Eventos.h"
#include "Asistentes.h"
#include <fstream>
#include <string.h>
#include <sstream>
#include <cstdlib>

using namespace std;

Asistentes::Asistentes(int edad, string tipoPersona, string rut, string nombre, string datoDiferenciador, string codigoEvento)
{
    this -> edad = edad;
    this -> tipoPersona = tipoPersona;
    this -> rut = rut;
    this -> nombre = nombre;
    this -> datoDiferenciador = datoDiferenciador;
    this -> codigoEvento = codigoEvento;
}

Asistentes::~Asistentes(){}//destructor

void Asistentes::eliminarAsistentes(vector<Asistentes*>& asistentes)
{
    for(Asistentes* asistente : asistentes)
    {
        delete(asistente); // Libera la memoria del objeto
    }
    asistentes.clear();
}

int Asistentes::getEdad()
{
    return this -> edad;
}

string Asistentes::getTipoPersona()
{
    return this -> tipoPersona;
}        

string Asistentes::getRut()
{
    return this -> rut;
}
string Asistentes::getNombre()
{
    return this -> nombre;
}
string Asistentes::getDatoDiferenciador()
{
    return this -> datoDiferenciador;
}
string Asistentes::getCodigoEvento()
{
    return this -> codigoEvento;
}

string Asistentes::informacionCompletaAsistente()
{
    string edad = to_string(this->edad);
    return edad + "," + this->tipoPersona + "," + this->rut + "," + this->nombre + "," + this->datoDiferenciador + "," + this->codigoEvento;
}

Asistentes* Asistentes::crearAsistente(string codigoEvento)
{
    string edadcrear,tipoInvi, rutcrear,nombreCrear,datoDife;
    cout<<"\nIngrese edad del invitado: ";
    cin>>edadcrear;
    int edadfinal = stoi(edadcrear);

    if (cin.peek() == '\n') cin.ignore();
    cout<<"\nIngrese el tipo de invitado (Ej: organizador, invitado, jefe, novia, etc.): ";
    getline(cin, tipoInvi);

    cout<<"\nIngrese rut del invitado: ";
    cin>>rutcrear;

    if (cin.peek() == '\n') cin.ignore();
    cout<<"\nIngrese nombre del invitado: ";
    getline(cin, nombreCrear);

    if (cin.peek() == '\n') cin.ignore();
    cout<<"\nIngrese dato diferenciador del invitado (Ej: familiar, analista financiero, etc.): ";
    getline(cin, datoDife);

    Asistentes* asistente = new Asistentes(edadfinal, tipoInvi,rutcrear, nombreCrear, datoDife, codigoEvento);
    return asistente;
}

int Asistentes::sumaEdades(vector<Asistentes*>& asistentes)
{
    int sumaEdades = 0;
    for(Asistentes* asistente : asistentes)
    {
        sumaEdades += asistente->edad;
    }
    return sumaEdades;
}

Asistentes* Asistentes::agregarDatosAsistentes(string datosAsistente)//esto es una mausque herramienta misteriosa que ocuparemos cuando sepa leer archivos.txt xd
{
    
    string edadString, tipoPersona, rut, nombre, datoDiferenciador, estadoAsistencia, codigoEvento;
    stringstream datosSeparar(datosAsistente);
    
    getline(datosSeparar, edadString, ',');
    getline(datosSeparar, tipoPersona, ',');
    getline(datosSeparar, rut, ',');
    getline(datosSeparar, nombre, ',');
    getline(datosSeparar, datoDiferenciador, ',');
    getline(datosSeparar, codigoEvento, ',');

    int edad = stoi(edadString);
    if(edad < 18)
    {
        return nullptr;
    }
    else
    {
        Asistentes* asistente = new Asistentes(edad, tipoPersona, rut, nombre, datoDiferenciador, codigoEvento);
        return asistente;
    }

}


void Asistentes::actualizarDatosAsistentes(string actualizacionAsistentes)
{
    ofstream datosAsistentes("Prueba Asistentes.txt", ios::out);
    datosAsistentes << actualizacionAsistentes;
    datosAsistentes.close();
}


