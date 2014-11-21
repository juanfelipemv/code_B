#ifndef PELOTITA_H
#define PELOTITA_H
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>


class pelotita
{
    public:
        pelotita();
        pelotita(int y,int x,SDL_Renderer*renderer);
        SDL_Rect rect;
        SDL_Texture *textura_pelotita;
        SDL_Renderer*Renderer;
        void render();
        virtual ~pelotita();
    protected:
    private:
};

#endif // PELOTITA_H
