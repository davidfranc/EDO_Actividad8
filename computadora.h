#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include <iostream>
using namespace std;

class Computadora
{
private:
    string sistemaOperativo;
    string procesador;
    int memoriaRam;
    float almacenamiento;
public:
    Computadora();
    Computadora(const string &sistemaOperativo, const string &procesador, int memoriaRam, int almacenamiento);
    void setSistemaOperativo(const string &v);
    string getSistemaOperativo();
    void setProcesador(const string &v);
    string getProcesador();
    void setMemoriaRam(int v);
    int getMemoriaRam();
    void setAlmacenamiento(int v);
    int getAlmacenamiento();
};



#endif