#include "laboratorio.h"
#include <fstream>

Laboratorio::Laboratorio()
{
    cont = 0;
}

void Laboratorio::agregarFinal(const Computadora &c)
{
    if (cont < 5) {
        arreglo[cont] = c;
        cont++;
    }
    else{
        cout << "Arreglo lleno" << endl;
    }
}

void Laboratorio::mostrar()
{
    cout << left;
    cout << setw(20) << "Sistema Operativo";
    cout << setw(15) << "Procesador";
    cout << setw(5) << "Ram" ;
    cout << setw(5) << "Almacenamiento";
    cout << endl;
    for (size_t i = 0; i < cont; i++){
        Computadora &c = arreglo[i];
        cout << c;
        // cout << "Sistema operativo: " << c.getSistemaOperativo() << endl;
        // cout << "Procesador: " << c.getProcesador() << endl;
        // cout << "Memoria RAM: " << c.getMemoriaRam() << " Gb" << endl;
        // cout << "Almacenamiento: " << c.getAlmacenamiento() << " Gb" <<  endl;
        // cout << endl;
    }
}

void Laboratorio::respaldar_tabla()
{
    ofstream archivo ("computadoras_tabla.txt");
    if (archivo.is_open()){
        archivo << left;
        archivo << setw(20) << "Sistema Operativo";
        archivo << setw(15) << "Procesador";
        archivo << setw(5) << "Ram" ;
        archivo << setw(5) << "Almacenamiento";
        archivo << endl;
        for (size_t i = 0; i < cont; i++){
            Computadora &c = arreglo[i];
            archivo << c;
        }
    }
    archivo.close();
}

void Laboratorio::respaldar()
{
    ofstream archivo ("computadoras.txt");
    if (archivo.is_open()){
        for (size_t i = 0; i < cont; i++){
            Computadora &c = arreglo[i];
            archivo << c.getSistemaOperativo() << endl;
            archivo << c.getProcesador() << endl;
            archivo << c.getMemoriaRam() << endl;
            archivo << c.getAlmacenamiento() << endl;
        }
    }
    archivo.close();
}

void Laboratorio::recuperar()
{
    ifstream archivo ("computadoras.txt");
    if (archivo.is_open()){
        string temp;
        int dato;
        Computadora c;
        while (true){
            getline(archivo, temp);
            if (archivo.eof())
                break;
            c.setSistemaOperativo(temp);
            getline(archivo, temp);
            c.setProcesador(temp);
            getline(archivo, temp);
            dato = stoi (temp);
            c.setMemoriaRam(dato);
            getline(archivo, temp);
            dato = stoi (temp);
            c.setAlmacenamiento(dato);
            
            agregarFinal(c);
        }
    }
    archivo.close();
}