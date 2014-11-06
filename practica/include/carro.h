#ifndef CARRO_H
#define CARRO_H
#include <iostream>
using namespace std;

class carro
{
    public:
        string marca;
        string combustible;
        int motor;

        carro();
        carro(string marca,string combustible,int motor );

        void imprimir();
        void  kilometraje();
        virtual ~carro();
    protected:
    private:
};

#endif // CARRO_H
