#include "pelotita.h"

pelotita::pelotita()
{
    //ctor
    rect.w=66;
    rect.h=66;
    rect.y=0;
    rect.x=0;

}

pelotita::pelotita(int y,int x,SDL_Renderer*renderer)
{
    //ctor
    rect.w=66;
    rect.h=66;
    rect.y=y;
    rect.x=x;
    this->Renderer=renderer;
    textura_pelotita=IMG_LoadTexture(renderer,"assets/pelotita_buena.png");
}

pelotita::~pelotita()
{
    //dtor
}

void pelotita::render()
{
    SDL_RenderCopy(this->Renderer,textura_pelotita,NULL,&rect);
}
