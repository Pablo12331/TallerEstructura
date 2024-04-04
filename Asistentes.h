#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Asistentes
{
    private:
        int edad;
        string tipoPersona, rut, nombre, datoDiferenciador, codigoEvento;
    public:
        Asistentes(int, string, string, string, string, string);
        ~Asistentes();
        int getEdad();
        string getTipoPersona();
        string getRut();
        string getNombre();
        string getDatoDiferenciador();
        string getCodigoEvento();

        Asistentes* agregarDatosAsistentes(string);
};