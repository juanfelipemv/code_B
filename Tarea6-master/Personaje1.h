#ifndef PERSONAJE1_H
#define PERSONAJE1_H

#include "Personaje.h"

class Personaje;

class Personaje1 : public Personaje
{
public:
        Personaje1(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes);
        virtual ~Personaje1();
        void logic(Uint8* teclas_presionadas);
    protected:
    private:
};

#endif // PERSONAJE1_H
