#ifndef PERSONAJEJUGADOR_H
#define PERSONAJEJUGADOR_H

#include "Personaje.h"

class PersonajeJugador : public Personaje
{
    public:
        SDL_Texture *rayo_texture;
        SDL_Rect rayo_rect;
        bool rayo_activado;
        int rayo_cooldown;
        int rayo_frame_actual;
        string rayo_orientacion;

        SDL_Texture *rayo_texture2;
        SDL_Rect rayo_rect2;
        bool rayo_activado2;
        int rayo_cooldown2;
        int rayo_frame_actual2;
        string rayo_orientacion2;
        PersonajeJugador(int x, int y,
                          SDL_Renderer* renderer,
                          list<Personaje*>*personajes);
        void logic(Uint8* teclas_presionadas);
        virtual void render(SDL_Renderer* renderer);
        virtual ~PersonajeJugador();
    protected:
    private:
};

#endif // PERSONAJEJUGADOR_H
