#include "Asistentes.h"
#include <fstream>
#include <string.h>
#include <sstream>
#include <cstdlib>

using namespace std;

Asistentes::Asistentes(int edad, string tipoPersona, string rut, string nombre, string datoDiferenciador, string estadoAsistencia, string codigoEvento)
{
    this -> edad = edad;
    this -> tipoPersona = tipoPersona;
    this -> rut = rut;
    this -> nombre = nombre;
    this -> datoDiferenciador =datoDiferenciador;
    this -> estadoAsistencia = estadoAsistencia;
    this -> codigoEvento = codigoEvento;
}

Asistentes::~Asistentes(){}//destructor

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
string Asistentes::getEstadoAsistencia()
{
    return this -> estadoAsistencia;
}
string Asistentes::getCodigoEvento()
{
    return this -> codigoEvento;
}
void Asistentes::setEstadoAsistencia(string estadoAsistencia)
{
    this -> estadoAsistencia = estadoAsistencia;
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
    getline(datosSeparar, estadoAsistencia, ',');
    getline(datosSeparar, codigoEvento, ',');

    int edad = stoi(edadString);
    if(edad < 18)
    {
        return nullptr;
    }
    else
    {
        Asistentes* asistente = new Asistentes(edad, tipoPersona, rut, nombre, datoDiferenciador, estadoAsistencia, codigoEvento);
        return asistente;
    }

}