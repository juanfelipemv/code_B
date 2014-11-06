#ifndef FORD_H
#define FORD_H

#include "carro.h";

class ford:public carro
{
    public:
        ford(string marca,string combustible,int motor);
        virtual ~ford();
        void kilometraje();
        void imprimir();
    protected:
    private:
};

#endif // FORD_H
