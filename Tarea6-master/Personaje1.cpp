#include "Personaje1.h"
    bool primeraVezX=true;
    bool primeraVezY=true;


Personaje1::Personaje1(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes)
{
    //ctor
    this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->personajes=personajes;
    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/npcs/npc2/down1.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);

    texturas_down.push_back(textura);
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/down2.png"));

    textura_actual=texturas_down.begin();

    orientacion="down";
}

Personaje1::~Personaje1()
{
    //dtor

}
void Personaje1::logic(Uint8* teclas_presionadas)
{

    if(primeraVezX==true)
    {
        rectangulo.x++;
        if(rectangulo.x+rectangulo.w==500)
        primeraVezX=false;
    }
     if(primeraVezX==false)
    {
        rectangulo.x--;
        if(rectangulo.x==0)
        primeraVezX=true;
    }

    if(primeraVezY==true)
    {
        rectangulo.y--;
        if(rectangulo.y==0)
        primeraVezY=false;
    }
     if(primeraVezY==false)
    {
        rectangulo.y++;
        if(rectangulo.y+rectangulo.h==250)
        primeraVezY=true;
    }


}
