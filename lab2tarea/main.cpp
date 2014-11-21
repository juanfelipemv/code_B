
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<cstdlib>
#include<list>
#include "pelotitas_manager.h"
#include <cstdio>
#include <time.h>
using namespace std;

int frames;
int contador;
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
pelotitas_manager manager;
SDL_Texture *background,*background2,*game_background,*game_background2, *pelotita_buena, *pelotita_mala, *gameover_background;
SDL_Rect rect_background,rect_background2, rect_pelotita, rect_gameover_background;
int boom;

void gameover(){

    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(Event.type == SDL_KEYDOWN)
            {
            }
        }

        SDL_RenderCopy(renderer, background2, NULL, &rect_background2);
        SDL_RenderPresent(renderer);
    }
}



void loopJuego()
{


    list<float> pelotitas_y;
    pelotitas_y.push_back(0);
    pelotitas_y.push_back(40);
    pelotitas_y.push_back(100);



    bool is_visible=true;
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                exit(0);
            }

           if(contador==0)
        {
            gameover();
        }

            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_ESCAPE)
                    return;
            }

            if(Event.type == SDL_MOUSEBUTTONDOWN)
            {
                int click_x, click_y;
                SDL_GetMouseState( &click_x, &click_y );
                cout<<click_x<<","<<click_y<<endl;

                for(int c = 0; c<manager.pelotitas.size(); c++)
                {
                    bool dimension_x = click_x>manager.pelotitas.at(c).rect.x &&
                         click_x<manager.pelotitas.at(c).rect.x+manager.pelotitas.at(c).rect.w;
                    bool dimension_y = click_y>manager.pelotitas.at(c).rect.y &&
                         click_y<manager.pelotitas.at(c).rect.y+manager.pelotitas.at(c).rect.h;

                    if(dimension_x && dimension_y)
                    {
                        manager.pelotitas.at(c).rect.y=9999;
                        contador--;
                        cout<<"contador en :" <<contador<< endl;
                    }


                }
            }
        }

        if(frames == 600)
        frames = 0;
        frames++;

        manager.mover(frames);

//velocidad
        SDL_RenderCopy(renderer, game_background, NULL, &rect_background);
         manager.render();

//posicion y
        int posicion_y=20;


        SDL_RenderPresent(renderer);
    }
  if (boom == 3)
        {
         SDL_RenderCopy(renderer, gameover_background, NULL, &rect_gameover_background);
        }



}

void loopMenu()
{
    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_RETURN)
                    loopJuego();
            }



        }


        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }
}


int main( int argc, char* args[] )
{
    frames=0;
    srand(time(NULL));
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );

    int y1 = rand( ) % 20 + 1;
    int y2 = rand( ) % 20 + 1;
    int y3 = rand( ) % 20 + 1;

    manager.crearPelotita(y1*10,80,renderer);
    manager.crearPelotita(y2*10,160,renderer);
    manager.crearPelotita(y3*10,235,renderer);
    manager.crearPelotita(y3*10,55,renderer);
    manager.crearPelotita(y3*10,15,renderer);
    manager.crearPelotita(y3*10,120,renderer);
    contador = manager.pelotitas.size();
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"assets/menu.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

 game_background = IMG_LoadTexture(renderer,"assets/background.png");


    //cargar imagen nueva
    background2 = IMG_LoadTexture(renderer,"assets/game_over.png");
    SDL_QueryTexture(background2, NULL, NULL, &w, &h);
    rect_background2.x = 0;
    rect_background2.y = 0;
    rect_background2.w = w;
    rect_background2.h = h;

//
    pelotita_buena = IMG_LoadTexture(renderer,"assets/pelotita_buena.png");
    pelotita_mala = IMG_LoadTexture(renderer,"assets/pelotita_mala.png");


    rect_pelotita.x = 0;
    rect_pelotita.y = 0;


    loopMenu();

	return 0;
}








