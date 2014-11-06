#include "carro.h"

carro::carro()
{
    //ctor
}

carro::carro(string marca,string combustible,int motor)
{
    this->combustible=combustible;
    this->marca=marca;
    this->motor=motor;
}

void carro::imprimir()
{
    cout<<"marca de carro"<<marca<<"\t";
    cout<<"tipo de combustible"<<combustible<<"\t";
    cout<<"tamano de motor"<<motor<<endl;

}
void carro::kilometraje()
{
    cout<<"rendimiento"<<motor<<endl;

}
carro::~carro()
{
    //dtor
}
