#include <iostream>
#include "include/DicNoOrden_LSE.h"

using namespace std;

int main(int argc, char *argv[])
{
    DicNoOrden_LSE D;
    D.Imprimir();
    D.Agregar("Jason");
    D.Agregar("Isa");
    D.Agregar("Akisha");
    D.Agregar("Cookie");
    D.Agregar("Estres");
    D.Imprimir();
    cout<<"Vacio(): "<<D.Vacio() <<endl;
    cout<<"Pertence(Jason): "<<D.Pertenece("Jason")<<endl;
    cout<<"NumElem(): "<<D.NumElem()<<endl;

    D.Eliminar("Estres");
    D.Imprimir();
    D.Eliminar("Akisha");
    D.Imprimir();
    D.Eliminar("Cookie");
    D.Imprimir();
    D.Eliminar("Jason");
    D.Imprimir();
    D.Eliminar("Isa");
    D.Imprimir();
    D.Eliminar("Akisha");
    D.Imprimir();
    cout<<"Vacio(): "<<D.Vacio() <<endl;
    cout<<"Pertence(Jason): "<<D.Pertenece("Jason")<<endl;
    cout<<"NumElem(): "<<D.NumElem()<<endl;

    D.Agregar("Jason");
    D.Agregar("Isa");
    D.Agregar("Akisha");
    D.Agregar("Cookie");
    D.Agregar("Estres");
    D.Imprimir();
    cout<<"Nota: Aplicamos Vaciar() que es lo mismo que Destruir()"<<endl;
    D.Vaciar();
    D.Imprimir();
    return 0;
}
