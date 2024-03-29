#include "Asistentes.h"

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
void Asistentes::agregarDatos(vector<Asistentes*> asistentes)//esto es una mausque herramienta misteriosa que ocuparemos cuando sepa leer archivos.txt xd
{

}