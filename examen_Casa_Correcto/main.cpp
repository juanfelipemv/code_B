#include <iostream>
#include <sstream>
#include <string>
 #include<stdio.h>
 #include <stdlib.h>

using namespace std;

string tablero[11][11];

//asignacion - en todo tablero
 void iniciartablero()
 {
     for(int x=0;x<11;x++)
     {
         for(int y=0;y<11;y++){

            tablero[x][y]="-";
         }
     }
 }

 void imprimirtablero()
 {
     for(int x=0;x<11;x++)
     {
         for(int y=0;y<11;y++){
                cout<<tablero[x][y]<<"  ";
         }
         cout<<endl;
     }
 }

 void asignarnumeros()
 {
    for(int x=1;x<11;x++)
    {
stringstream stream;

int numero = x;
string palabra;

stream << numero;

palabra = stream.str();

     tablero[0][x]=palabra;
    }


    for(int x=1;x<11;x++)
    {
    stringstream stream;

int numero = x;
string palabra;

stream << numero;

palabra = stream.str();

        tablero[x][0]=palabra;
    }
 }



void tiro(int e,int r)
{
    tablero[e][r]="O";
}

void tiroAcertado(int e,int r)
{
    tablero[e][r]="X";
}



int main()
{
    int x,y;
    int contTiros=0;

iniciartablero();
asignarnumeros();
cout<<endl;
cout<<endl;
cout<<"    BIENVENIDO AL BATTLESHIP        "<<endl;
cout<<endl;
cout<<endl;

do{

int numeroa = rand() % 11;
int numerob = rand() % (10+1);
imprimirtablero();
cout<<endl;
cout<<endl;
cout<<"*************************************************"<<endl;
cout<<"             Tiros Realizados :    "<< contTiros<<endl;
cout<<"*************************************************"<<endl;
cout<<"        Posicion Aleatoria del Barco (Secreta)"<<endl;
cout<<"                       x : "<<numeroa<<endl;
cout<<"                       y : "<<numerob<<endl;
cout<<"*************************************************"<<endl;
cout<<"       Ingrese coordenada en eje X  : "<<"\t";
cin>>x;
cout<<"       Ingrese coordenada en eje Y  : "<<"\t";
cin>>y;
cout<<"*************************************************"<<endl;
if(numeroa==x&&numerob==y){
        cout<<endl;
        cout<<endl;
        tiroAcertado(x,y);
    cout<<"-------------------------------------------------"<<endl;

    cout<<"                 Has ACERTADO el disparo "<<endl;
    cout<<"             FELICIDADES has GANADO el Juego"<<endl;
     cout<<"-------------------------------------------------"<<endl;
     imprimirtablero();
    break;
}
else
{  contTiros+=1;
    cout<<endl;
    cout<<"---------Has Fallado el Disparo------------2 "<<endl;
    cout<<endl;

}
tiro( x, y);

if(contTiros==5){
    cout<<"-------------------------------------------------"<<endl;

    cout<<"             GAME OVER            "<<endl;

     cout<<"-------------------------------------------------"<<endl;
     imprimirtablero();
     break;
}

}while(true);



}
