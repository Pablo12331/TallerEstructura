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
        ~Asistentes();//xd
        int getEdad();//arroz
        void eliminarAsistentes(vector<Asistentes*>&);
        int sumaEdades(vector<Asistentes*>&);
        Asistentes* crearAsistente(string);
        string getTipoPersona();
        string getRut();
        string getNombre();
        string getDatoDiferenciador();
        string getCodigoEvento();
        string informacionCompletaAsistente();
        void actualizarDatosAsistentes(string);
        Asistentes* agregarDatosAsistentes(string);
};