#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Asistentes
{
    private:
        int edad;
        string tipoPersona, rut, nombre, datoDiferenciador, estadoAsistencia;
    public:
        Asistentes(int, string, string, string, string, string);
        ~Asistentes();
        int getEdad();
        string getTipoPersona();
        string getRut();
        string getNombre();
        string getDatoDiferenciador();
        string getEstadoAsistencia();
        void setEstadoAsistencia(string);
        void agregarDatos(vector<Asistentes*>&);
};