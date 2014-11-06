#include <iostream>
#include <list>
#include "ford.h"
#include "nissan.h"


using namespace std;




int main()
{
    list <carro*> coches;
    coches.push_back(new ford("escape","diesel",5));
    coches.push_back(new ford("explorer","diesel",8));


    for(list<carro*>::iterator i = coches.begin();
            i!=coches.end();
            i++)
    {
        (*i)->imprimir();
        (*i)->kilometraje();

       }
}
