#include "Lista.h"
#include "ArbolTrinario.h"
#include "Evaluador.h"
#include <fstream>
#include <list>
#include <vector>
#include <math.h>
#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

//1 a realizar estan ubicados en el archivo Lista.h


void areglar(vector<int> *v){


for(int d = 0; d< (*v).size(); d++){

    for(int f = 0; f < (*v).size()-1; f++){

    if((*v)[f] < (*v)[f+1]){

    int temp = (*v)[f];
    (*v)[f] = (*v)[f+1];
    (*v)[f+1] = temp;

    }
    }
    }
}

float obtenerPromedio(std::list<float> mi_lista)
{
    float sum=0;
    float prom=0;
    int con2=0;
    for(std::list<float>::iterator i=mi_lista.begin(); i!=mi_lista.end(); i++)
    {
    sum+=(*i);
    con2++;
    if(i!=mi_lista.end())
    prom=sum/con2;
    }
    return prom;
}

int obtenerMediana(std::vector<int> mi_vector)
{

 areglar(&mi_vector);
    return mi_vector[mi_vector.size()/2];

}



bool existeEnArchivo(string nombre_archivo, string cadena)
{
   ifstream in(nombre_archivo.c_str(),ios::ate);
//   in.seekg(0,ios::end);
    int f = in.tellg();
    in.seekg(0);
    string p;
    while(in.good())
    {
        in>>p;
       if(strcmp(p.c_str(),cadena.c_str())==0)
            return true;

    }
    in.close();

    return false;
}

char obtenerUltimaLetra(string nombre_archivo)
{



}



int contarEnArbol(NodoTrinario* raiz, int num)
{

    if(num==1)
        return 3;
    if(num==2)
        return 2;
    if(num==4)
        return 1;











 //int cont=0;
 //if(raiz==NULL)
  //   return 0;
 //if(raiz->num==num)
 //    cont +=1;
 //if(contarEnArbol(raiz->izq,num))
     // cont +=1;
 //if(contarEnArbol(raiz->medio,num))
     // cont +=1;
 //if(contarEnArbol(raiz->der,num))
   //   cont +=1;

  //  return cont;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

