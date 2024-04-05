#include "Eventos.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <random>
#include<string.h>

using namespace std;

Eventos::Eventos(string tipoEvento, string ubicacion, string alimentos, string fecha, string tipoMusica, string codigoEvento)
{
    this -> tipoEvento = tipoEvento;
    this -> ubicacion = ubicacion;
    this -> alimentos = alimentos;
    this -> fecha = fecha;
    this -> tipoMusica =tipoMusica;
    this -> codigoEvento = codigoEvento;
    this ->asistentes.reserve(1);
}
Eventos::~Eventos(){}//destructor

void Eventos::agregarAsistente(Asistentes*& asistente)
{
    if(asistente != nullptr)
    {
        this -> asistentes.push_back(asistente);
    }
}



void Eventos::informacionGeneral(vector<Eventos*>& eventos)
{
    Asistentes* aux;
    cout<<"\nInformes y datos:"<<endl;
    cout<<"\nLista de eventos planeados:\n"<<endl;

    vector<int> ciudadesCont;
    vector<string> ciudadesNombre;
    int ciudadesAux=0;
    string ciudNombres;

    int contBoda = 0, contCarre = 0, contReu = 0;
    int cantiBoda = 0, cantiCarre = 0, cantiReu = 0;
    int contEdadBoda = 0,  contEdadCarrete = 0, contEdadReu = 0; 

    Asistentes* a;
    for(Eventos* evento : eventos)
    {
        cout<<evento->getTipoEvento()<<" | "<<evento->getUbicacion()<<" | "
            <<evento->getFecha()<<" | "<<evento->getCodigoEvento()<<" | "
            <<evento->getTipoMusica()<<" | "<<evento->getAlimentos()<<"\n"<<endl;
        if(evento->getTipoEvento() == "Carrete")
        {
            contCarre += 1;
            cantiCarre += evento->getAsistentes().size();
            vector<Asistentes*> listaAsistentes = evento->getAsistentes();
            contEdadCarrete += aux->sumaEdades(listaAsistentes);
        }
        else if(evento->getTipoEvento() == "Boda")
        {
            contBoda += 1;
            cantiBoda += evento->getAsistentes().size();
            vector<Asistentes*> listaAsistentes = evento->getAsistentes();
            contEdadBoda += aux->sumaEdades(listaAsistentes);
        }
        else if(evento->getTipoEvento() == "Reunion de Trabajo")
        {
            contReu += 1;
            cantiReu += evento->getAsistentes().size();
            vector<Asistentes*> listaAsistentes = evento->getAsistentes();
            contEdadReu += aux->sumaEdades(listaAsistentes);
        }

        if(ciudadesNombre.size() == 0)
        {
            ciudadesNombre.push_back(evento->getUbicacion());
            ciudadesCont.push_back(1);
        }
        else 
        {
            for(string ciudades : ciudadesNombre) 
            {
                if(evento->getUbicacion() == ciudades)
                {
                    ciudadesAux++;
                }
            }
            if(ciudadesAux == 0)
            {
                ciudadesNombre.push_back(evento->getUbicacion());
                ciudadesCont.push_back(1);
            }
            ciudadesAux = 0;
        }
    }

    int contaux;
    for(Eventos* evento : eventos)
    {
        contaux = 0;
        for(string ciudades : ciudadesNombre)
        {
            if(ciudades == evento->getUbicacion())
            {
                ciudadesCont[contaux]++;
            }
            contaux++;
        }
    }
    contaux = 0;
    int max = 0;
    for(int num : ciudadesCont)
    {
        if(num > max)
        {
            max = num;
            ciudNombres = ciudadesNombre[contaux];
        }
        contaux++;
    }

    cout<<"\n";

    cout<<"Asistentes de cada evento: "<<endl; 
    for(Eventos* evento : eventos)
    {
        cout<<evento -> getTipoEvento()<<" "<<evento -> getCodigoEvento()<<":"<<endl;
        for(Asistentes* asistente: evento->getAsistentes())
        {
            cout<<"Nombre: "<<asistente->getNombre()<<" | Rut: "<<asistente->getRut()<<endl;
        }
        if(evento->getAsistentes().size() ==0)
        {
            cout<<"No hay asistentes registrados todavía."<<endl;
        }
        cout<<""<<endl;
    }
    cout<<"Porcentaje de cada tipo de evento:"
        <<"\nPorcentaje de Carrete: " << contCarre*100/(contCarre + contBoda + contReu) << "%"
        <<"\nPorcentaje de Boda: " << contBoda*100/(contCarre + contBoda + contReu) << "%"
        <<"\nPorcentaje de Reunion de Trabajo: " << contReu*100/(contCarre + contBoda + contReu) << "%"<<endl;
    
    cout<<"\nCantidad de eventos:"
        <<"\nCantidad de Carretes: "<< contCarre
        <<"\nCantidad de Bodas: "<< contBoda
        <<"\nCantidad de Reuniones de trabajo: "<< contReu<<endl;

    cout<<"\nUbicación más usada en eventos:"
        <<"\n"<<ciudNombres<<endl;

    cout<<"\nPromedio de asistentes por evento: "
        <<"\nPromedio Asistencia Carretes: "<< cantiCarre/contCarre
        <<"\nPromedio Asistencia Boda: "<< cantiBoda/contBoda
        <<"\nPromedio Asistencia Reunion de Trabajo: "<< cantiReu/contReu<<endl;

    cout<<"\nPromedio de edad por Evento: "
        <<"\nPromedio edad Carrete: " << contEdadCarrete/cantiCarre
        <<"\nPromedio edad Boda: " << contEdadBoda/cantiBoda
        <<"\nPromedio edad Reunion de Trabajo: " << contEdadReu/cantiReu<<endl;
    

}
void Eventos::eliminarEvento(vector<Eventos*>& eventos)
{
    int identiCont = -1;
    string codElim;
    for(Eventos* evento : eventos)
    {
        cout<<evento -> getTipoEvento()<<" "<<evento -> getCodigoEvento()<<endl;
    }
    cout<<"Ingrese el código del evento que desea eliminar: "<<endl;
    cin>>codElim;
    for(Eventos* evento : eventos)
    {
        identiCont++;
        if(evento->getCodigoEvento()==codElim)
        {
            std::vector<Eventos*>::iterator it = eventos.begin() + identiCont;
            eventos.erase(it);
            cout<<"Evento borrado."<<endl;
        }
    }
}
void Eventos::revisionAsistentes(vector<Eventos*>& eventos)
{ 
    for(Eventos* evento : eventos)
    {
        cout<<evento -> getTipoEvento()<<" "<<evento -> getCodigoEvento()<<endl;
    }
    cout<<"Ingrese el código del evento que desea revisar: "<<endl;
    string codigoEvento;
    int detector = 0;
    cin>>codigoEvento;
    for(Eventos* evento : eventos)
    {
        if(evento->getCodigoEvento()==codigoEvento)
        {
            detector++;
            for(Asistentes* asistente: evento->getAsistentes())
            {
            cout<<"Nombre: "<<asistente->getNombre()<<" | Rut: "<<asistente->getRut()<<endl;
            }
            if(evento->getAsistentes().size() ==0)
            {
            cout<<"No hay asistentes registrados todavía."<<endl;
            }

        }
        
    }
    cout<<""<<endl;
    if(detector==0){
        cout<<"El código ingresado no existe."<<endl;
    }
    detector = 0;
}
string Eventos::getTipoEvento()
{
    return this -> tipoEvento;
}
string Eventos::getUbicacion()
{
    return this -> ubicacion;
}
void Eventos::setAsistentes(vector<Asistentes*>asistentes)
{
    this->asistentes = asistentes;
}

vector<Asistentes*> Eventos::getAsistentes()
{
    return this -> asistentes;
}

string Eventos::getAlimentos()
{
    return this -> alimentos;
}

string Eventos::getFecha()
{
    return this->fecha;
}

string Eventos::getTipoMusica()
{
    return this->tipoMusica;
}

string Eventos::getCodigoEvento()
{
    return this -> codigoEvento;
}

bool Eventos::cantidadEventosDia(vector<Eventos*>& eventos, string fechaHoy)
{
    int cantidadEventos = 0;
    for(Eventos* evento : eventos)
    {
        if(evento->getFecha() == fechaHoy)
        {
            ++cantidadEventos;
        }
    }
    if(cantidadEventos == 3){return false;}
    else{return true;}
}

bool Eventos::compararFechas(string fecha1, string fecha2)
{
    string dia1, dia2, mes1, mes2, year1, year2;
    if(fecha1 == fecha2)
    {
        return false;
    }

    stringstream fecha1Separada(fecha1);
    getline(fecha1Separada, dia1,'/'); getline(fecha1Separada, mes1,'/'); getline(fecha1Separada, year1,'/');
    stringstream fecha2Separada(fecha2);
    getline(fecha2Separada, dia2,'/'); getline(fecha2Separada, mes2,'/'); getline(fecha2Separada, year2,'/');
    
    if(year1 < year2)
    {
        return false;
    }
    else if(mes1 < mes2 && year1 == year2)
    {
        return false;
    }
    else if(dia1 < dia2 && mes1 == mes2 && year1 == year2)
    {
        return false;
    }

    return true;
}

string Eventos::informacionCompletaEventos()
{
    return this->tipoEvento + "," + this->ubicacion + "," + this->alimentos + "," + this->fecha + "," + this->tipoMusica + "," + this->codigoEvento; 
}

void Eventos::registrarAsistente(vector<Eventos*>& eventos)
{
    Asistentes* aux;
    vector<Asistentes*> listaAsistentes;
    string codigoEvento;
    cout<<endl;
    for(Eventos* evento : eventos)
    {
        cout<<"Tipo de Evento: "<<evento->getTipoEvento() << " | Codigo de Evento: " << evento->getCodigoEvento() << endl;
    }
    do
    {
        cout<<"\nInserte el codigo del evento al cual quiere registrar asistentes: ";
        cin >> codigoEvento; 
        if(!verificarCodigoEvento(codigoEvento, eventos))
        {
            cout<<"ERROR! El codigo de evento ingresado es erroneo, coloque uno de los mostrados anteriormente."<<endl;
        }
        else
        {
            break;
        }

    } while (!verificarCodigoEvento(codigoEvento, eventos));
    for(Eventos* evento : eventos)
    {
        if(evento->getCodigoEvento() == codigoEvento)
        {
            listaAsistentes = evento->getAsistentes();
        }
    }
    string cantAsis;
    cout<<"Ingrese la cantidad de asistentes(Ej: 3): "<<endl;
    cin>>cantAsis;
    int contAsis = stoi(cantAsis);
    for(int i=0; i < contAsis;i++)
    {
        aux->crearAsistente(listaAsistentes, codigoEvento);
    }

    //aqui con el aux deberiamos llamar una funcion en Asistentes para pedir el numero de asistentes que se ingresaran y luego ir agregandolos a la lista
}

bool Eventos::verificarCodigoEvento(string codigoEvento, vector<Eventos*>& eventos)
{
    for(Eventos* evento : eventos)
    {
        if(evento->getCodigoEvento() == codigoEvento)
        {
            return true;
        }
    }
    return false;
}

void Eventos::crearEvento(vector<Eventos*>& eventos, string fechaHoy)
{
    int codigoDelEvento;
    string tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento; 
    string eleccionTipoEvento, eleccionAlimentos, eleccionTipoMusica;
    do
    {
        cout<<"\nIngrese la fecha en la que se hara el evento(Ej:28/03/2024): ";
        cin >> fecha;
        if(compararFechas(fechaHoy, fecha))
        {
            cout<<"\nLa fecha ingresada es menor a la fecha de el dia de hoy.";
            continue;
        }
    } while (compararFechas(fechaHoy, fecha));

    do
    {
        cout<<"\nDe que tipo quiere que sea su evento: \n"
            <<"\n 1) Boda"
            <<"\n 2) Reunion de Trabajo"
            <<"\n 3) Carrete"
            <<endl
            <<"\n Coloque su opciones aqui(Ejemplo: 1): ";
        cin >> eleccionTipoEvento;
        int opcion = stoi(eleccionTipoEvento);
        switch (opcion)
        {
            case 1:
                tipoEvento = "Boda";
                break;
            case 2:
                tipoEvento = "Reunion de Trabajo";
                break;
            case 3:
                tipoEvento = "Carrete";
                break;
            default:
                cout<<"La eleccion seleccionada es incorrecta, coloque una de las que aparece en pantalla.";
        }

    } while (eleccionTipoEvento != "1" && eleccionTipoEvento != "2" && eleccionTipoEvento != "3");


    do
    {
        cout<<"\nQue formatos de comida y bebestibles se solicita en el evento: \n"
            <<"\n 1) Comida y bebestibles tipo coctel."
            <<"\n 2) barra libre y picoteo."
            <<"\n 3) Almuerzo y once."
            <<endl
            <<"\n Coloque su opciones aqui(Ejemplo: 1): ";
        cin >> eleccionAlimentos;
        int opcion = stoi(eleccionAlimentos);
        switch (opcion)
        {
            case 1:
                alimentos = "Comida y bebestibles tipo coctel";
                break;
            case 2:
                alimentos = "barra libre y picoteo";
                break;
            case 3:
                alimentos = "Almuerzo y once";
                break;
            default:
                cout<<"La eleccion seleccionada es incorrecta, coloque una de las que aparece en pantalla.";
        }
    } while (eleccionAlimentos != "1" && eleccionAlimentos != "2" && eleccionAlimentos != "3");

     do
    {
        cout<<"\nQue tipo de musica se escuchara en el evento: \n"
            <<"\n 1) Moderna."
            <<"\n 2) Clasica."
            <<"\n 3) Ochentera."
            <<endl
            <<"\n Coloque su opciones aqui(Ejemplo: 1): ";
        cin >> eleccionTipoMusica;
        int opcion = stoi(eleccionTipoMusica);
        switch (opcion)
        {
            case 1:
                tipoMusica = "Moderna";
                break;
            case 2:
                tipoMusica = "Clasica";
                break;
            case 3:
                tipoMusica = "Ochentera";
                break;
            default:
                cout<<"La eleccion seleccionada es incorrecta, coloque una de las que aparece en pantalla.";
        }
    } while (eleccionTipoMusica != "1"&& eleccionTipoMusica!= "2" && eleccionTipoMusica != "3");

    do
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1000, 9999);
        codigoDelEvento = dis(gen);
    }while(verificarCodigoEvento(to_string(codigoDelEvento), eventos));
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<"\nUbicacion del evento(Ejemplo: Coquimbo Parte Alta): ";
    getline(cin, ubicacion);

    codigoEvento = to_string(codigoDelEvento);

    Eventos *evento = new Eventos(tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento);
    eventos.push_back(evento);
}

void Eventos::agregarDatosEventos(vector<Eventos*>& eventos, string fechaHoy, string linea)//esto es una mausque herramienta misteriosa que ocuparemos cuando sepa leer archivos.txt xd
{
    string tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento;

    Eventos* evento;
    
    stringstream datosSeparar(linea);

    getline(datosSeparar, tipoEvento, ',');
    getline(datosSeparar, ubicacion, ',');
    getline(datosSeparar, alimentos, ',');
    getline(datosSeparar, fecha, ',');
    getline(datosSeparar, tipoMusica, ',');
    getline(datosSeparar, codigoEvento, ',');

    evento = new Eventos(tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento);
    eventos.push_back(evento);
}

void Eventos::actualizarDatosEventos(string eventosActualizados)
{
    ofstream datosEventos("prueba de leerArchivos.txt");
    datosEventos << eventosActualizados;
    datosEventos.close();
}