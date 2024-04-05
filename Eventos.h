#pragma once
#include <vector>
#include <iostream>
#include "Asistentes.h"

using namespace std;

class Eventos
{
    protected:
        string tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento;
        vector<Asistentes*> asistentes;
    
    public:
        Eventos(string, string, string, string, string, string);
        ~Eventos();//destructor
        void agregarAsistente(Asistentes*&);
        string obtenerCodigoEvento(vector<Eventos*>&);
        bool compararFechas(string, string);
        bool verificarCodigoEvento(string, vector<Eventos*>&);
        bool cantidadEventosDia(vector<Eventos*>&, string);
        void crearEvento(vector<Eventos*>&, string);
        void informacionGeneral(vector<Eventos*>&);
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