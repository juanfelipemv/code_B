#ifndef PELOTITAS_MANAGER_H
#define PELOTITAS_MANAGER_H
#include "pelotita.h"
#include <vector>
using namespace std;
class pelotitas_manager
{
    public:
        pelotitas_manager();
        vector<pelotita> pelotitas;
        void render();
        void crearPelotita(int y,int x,SDL_Renderer*renderer);
        virtual ~pelotitas_manager();
        void mover(int frames);
    protected:
    private:
};

#endif // PELOTITAS_MANAGER_H
