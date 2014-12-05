#ifndef CIRCULAR_H
#define CIRCULAR_H
#include "Personaje.h"

class Circular : public Personaje
{
    public:
        Circular(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes);
            void logic(Uint8* teclas_presionadas);
            void getCos(float c);
            virtual ~Circular();
            void cmpf(float a, float b);
            void getSin(float s, int m);
            void getSin2(float s, int YS);
        void logic(Uint8* teclas_presionadas);
    protected:
    private:
};

#endif // CIRCULAR_H
