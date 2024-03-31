#pragma once
#include "Eventos.h"
#include "Asistentes.h"
#include <iostream>
#include <vector>


class Carrete : public Eventos
{
    public:
        Carrete(string, string, string, string, string);
        ~Carrete();
        void agregarAsistente(Asistentes);
        bool compararFechas(string, string);
        bool cantidadEventosDia(vector<Eventos*>&, string);
        void crearEvento(vector<Eventos*>&, string);
        void informacionGeneral(vector<Eventos*>&);
        void agregarDatos(vector<Eventos*>&);
};