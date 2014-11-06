#include "ford.h"

ford::ford(string marca,string combustible,int motor)
{
    this->marca=marca;
    this->combustible=combustible;
    this->motor=motor;
}

void ford::kilometraje(){
    cout<<"rendimiento"<<"100"<<endl;
}


ford::~ford()
{
    //dtor
}
