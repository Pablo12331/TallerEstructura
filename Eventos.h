#pragma once
#include <vector>
#include <iostream>
#include "Asistentes.h"

using namespace std;

class Eventos//esto esta abierto a cambios, como lo veo lo que es la musica y fechas no se podrian modificar a menos que lo querramos agregar
{
    protected:
        string tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento;
        vector<Asistentes*> asistentes;//se pueden tener lista con solo direcciones de memorias lets goooooo
    
    public:
        Eventos(string, string, string, string, string, string);
        ~Eventos();//destructor
        void agregarAsistente(Asistentes*&);
        string obtenerCodigoEvento(vector<Eventos*>&);
        bool compararFechas(string, string);
        bool verificarCodigoEvento(string, vector<Eventos*>&);
        bool cantidadEventosDia(vector<Eventos*>&, string);
        void crearEvento(vector<Eventos*>&, string);
        void informacionGeneral(vector<Eventos*>&);/*la idea es darle como parametro la lista de eventos que sera
        creada en el main y poder ir tirando la informacion que piden o al menos lo que es la lista de eventos programados y la lista 
        de asistentes registrados por cada evento*/
        void agregarDatosEventos(vector<Eventos*>&, string, string);
        void desplegarEventos(vector<Eventos*>&);
        void actualizarDatosEventos(string);
        void registrarAsistente(vector<Eventos*>&);
        void revisionAsistentes(vector<Eventos*>&);
        void eliminarEvento(vector<Eventos*>&);
        string informacionCompletaEventos();
        vector<Asistentes*> getAsistentes();
        string getTipoEvento();
        string getUbicacion();
        string getAlimentos();
        string getFecha();
        string getTipoMusica();
        string getCodigoEvento();
};