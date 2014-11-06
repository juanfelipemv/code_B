#include "nissan.h"
#include <iostream>
#include "carro.h"

nissan::nissan(string marca,string combustible,int motor)
{
   this->marca=marca;
   this->combustible=combustible;
   this->motor=motor;
}

void nissan::kilometraje()
{
    cout<<"rendimiento"<<"600"<<endl;
}

nissan::~nissan()
{
    //dtor
}

