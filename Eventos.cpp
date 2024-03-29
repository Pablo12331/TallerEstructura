#include "Eventos.h"

Eventos::Eventos(double duracion, string alimentos, string fecha, string musica, string estadoEvento, string ubicacion)
{
    this -> duracion = duracion;
    this -> alimentos = alimentos;
    this -> fecha = fecha;
    this -> musica = musica;
    this -> estadoEvento = estadoEvento;
    this -> ubicacion = ubicacion;
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

}