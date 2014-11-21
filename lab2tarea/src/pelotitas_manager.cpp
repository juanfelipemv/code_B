#include "pelotitas_manager.h"

pelotitas_manager::pelotitas_manager()
{
    //ctor
}


pelotitas_manager::~pelotitas_manager()
{
    //dtor
}


void pelotitas_manager::mover(int delta)
{
    for(int c =0; c<pelotitas.size();c++)
    {
        if(delta % 5== 0)
        pelotitas.at(c).rect.x++;
        if(pelotitas.at(c).rect.x > 450)
            pelotitas.at(c).rect.x=0;
    }



}

void pelotitas_manager::render()
{
    for(int c =0; c<pelotitas.size();c++)
        pelotitas.at(c).render();
}

void pelotitas_manager::crearPelotita(int y,int x,SDL_Renderer*renderer)
{
    pelotita temporal(y,x,renderer);
    pelotitas.push_back(temporal);
}
