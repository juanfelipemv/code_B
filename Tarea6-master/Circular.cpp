#include "Circular.h"
#include<iostream>
#include<math.h>
#include <stdio.h>
#define PI 3.14
#include <stdlib.h>

using namespace std;
bool circulo=true;
int a=0;
float pi=3.14;
 int suma=0;
 int cosX=500/2;
    int sinY=250.0/2.0;
    int x=0;
    int y=0;
Circular::Circular(int x, int y,SDL_Renderer* renderer,
                   list<Personaje*>*personajes)
{
    this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->personajes=personajes;
    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/npcs/npc1/down1.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);

    texturas_down.push_back(textura);
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc1/down2.png"));

    textura_actual=texturas_down.begin();

    orientacion="down";
}

Circular::~Circular()
{
    //dtor
}

void getCos(float c)
{
    x=(((500/2)-suma)+(cos(c) *25.0));

}
void getSin(float s,int Ys)
{
    y=((Ys)+(sin(s) *25.0));
}
void getSin2(float s,int Ys)
{
    y=((Ys)-(sin(s) *25.0));
}
bool cmpf(float A, float B)
{
    float epsilon = 0.005f;
    return (fabs(A - B) < epsilon);
}

Circular::logic(Uint8* teclas_presionadas)
{
    // CIRCULAR


    //arreglar la colision
    for(list<Personaje*>::iterator i = personajes->begin();
            i!=personajes->end();
            i++)
    {
        if(this==(*i))
            continue;
        if(colision(this->rectangulo, (*i)->rectangulo))
            rectangulo=temp;
    }
}
