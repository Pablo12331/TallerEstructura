#pragma once
#include "Asistentes.h"
#include <iostream>
#include <vector>

using namespace std;

class Eventos//esto esta abierto a cambios, como lo veo lo que es la musica y fechas no se podrian modificar a menos que lo querramos agregar
{
    private:
        vector<Asistentes*> asistentes;//se pueden tener lista con solo direcciones de memorias lets goooooo
        string tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento;
    
    public:
        Eventos(string, string, string, string, string, string);
        ~Eventos();//destructor
        void agregarAsistente(Asistentes);
        bool compararFechas(string, string);
        bool verificarCodigoEvento(string, vector<Eventos*>&);
        bool cantidadEventosDia(vector<Eventos*>&, string);
        void crearEvento(vector<Eventos*>&, string);
        void informacionGeneral(vector<Eventos*>&);/*la idea es darle como parametro la lista de eventos que sera
        creada en el main y poder ir tirando la informacion que piden o al menos lo que es la lista de eventos programados y la lista 
        de asistentes registrados por cada evento*/
        void agregarDatos(vector<Eventos*>&, string);
        string getAlimentos();
        string getFecha();
        string getTipoMusica();
        string getCodigoEvento();
};