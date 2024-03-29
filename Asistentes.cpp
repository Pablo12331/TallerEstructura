#include "Asistentes.h"
#include <fstream>
#include <string.h>
#include <sstream>

Asistentes::Asistentes(int edad, string tipoPersona, string rut, string nombre, string datoDiferenciador, string estadoAsistencia)
{
    this -> edad = edad;
    this -> tipoPersona = tipoPersona;
    this -> rut = rut;
    this -> nombre = nombre;
    this -> datoDiferenciador =datoDiferenciador;
    this -> estadoAsistencia = estadoAsistencia;
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
void Asistentes::setEstadoAsistencia(string estadoAsistencia)
{
    this -> estadoAsistencia = estadoAsistencia;
}
void Asistentes::agregarDatos(vector<Asistentes*>& asistentes)//esto es una mausque herramienta misteriosa que ocuparemos cuando sepa leer archivos.txt xd
{
    ifstream archivo;
    string texto, edadString, tipoPersona, rut, nombre, datoDiferenciador, estadoAsistencia;

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
    
        getline(datosSeparar, edadString, ',');
        getline(datosSeparar, tipoPersona, ',');
        getline(datosSeparar, rut, ',');
        getline(datosSeparar, nombre, ',');
        getline(datosSeparar, datoDiferenciador, ',');
        getline(datosSeparar, estadoAsistencia, ',');
        int edad = stoi(edadString);

        Asistentes *asistente= new Asistentes(edad, tipoPersona, rut, nombre, datoDiferenciador, estadoAsistencia);
        asistentes.push_back(asistente);
    }
}