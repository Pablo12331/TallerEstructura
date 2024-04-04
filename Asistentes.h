#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Asistentes
{
    private:
        int edad;
        string tipoPersona, rut, nombre, datoDiferenciador, estadoAsistencia, codigoEvento;
    public:
        Asistentes(int, string, string, string, string, string, string);
        ~Asistentes();
        int getEdad();
        string getTipoPersona();
        string getRut();
        string getNombre();
        string getDatoDiferenciador();
        string getEstadoAsistencia();
        string getCodigoEvento();
        void setEstadoAsistencia(string);
        Asistentes* agregarDatosAsistentes(string);
};