#include <iostream>
#include "laboratorio.h"

using namespace std;

int main() {
    Computadora c01;
    c01.setSistemaOperativo("Windows 10");
    c01.setProcesador("Intel i5");
    c01.setMemoriaRam(6);
    c01.setAlmacenamiento(512);
    Computadora c02 = Computadora("MacOs Catalina","AMD ryzen 3",4,256);

    Laboratorio lab;

    // lab.agregarFinal(c01);
    // lab.agregarFinal(c02);

    Computadora c03;
    cin >> c03;
    lab << c01 << c02 << c03;
    lab.mostrar();
    return 0;
}