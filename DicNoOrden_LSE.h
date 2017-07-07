#ifndef DICNOORDEN_LSE_H
#define DICNOORDEN_LSE_H
#include <iostream>
using namespace std;

class DicNoOrden_LSE
{
    public:
        /**
        * Constructor por defecto.
        * Este es el método Crear() que crea un nuevo diccionario.
        */
        DicNoOrden_LSE();
        /**
        * Destructor por defecto.
        * Este es el método Destruir() que destruye el diccionario.
        */
        virtual ~DicNoOrden_LSE();
        /**
        * Vacía un diccionario.
        */
        void Vaciar();
        /**
        * Booleano que devuelve 1 si el diccionario está vacío y 0 si no está vacío.
        * @return 1 si el diccionario esta vacío,0 si no.
        */
        bool Vacio();
        /**
        * Agrega el elemento e al diccionario.
        * @param Elemento e (Hilera) para agregarlo.
        */
        void Agregar(string);
        /**
        * Elimina el elemento e del diccionario.
        * @param Elemento e (Hilera) para eliminarlo.
        */
        void Eliminar(string);
        /**
        * Booleano, devuelve 1 si e pertenece al diccionario, de lo contrario devuelve 0.
        * @param Elemento e (Hilera) para ver si pertenece al diccionario.
        * @return 1 si e pertenece al diccionario,0 si no.
        */
        bool Pertenece(string);
        /**
        * Retorna el número de elementos que están en el diccionario.
        * @return Un entero que es la cantidad de elementos en el diccionario.
        */
        int NumElem();
        void Imprimir();
    protected:

    private:
        typedef struct Nodo
        {
            string elemento;
            Nodo* siguiente;
        }*nodoPtr;

        int num_elem;
        nodoPtr cabeza;
};

#endif // DICNOORDEN_LSE_H
