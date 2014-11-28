
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<list>
#include<vector>
#include<map>
#include<fstream>
#include "PersonajeJugador.h"
#include "NPC.h"
#include <stdlib.h>     /* srand, rand */



using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character;
SDL_Rect rect_background,rect_character;

class Tile
{
public:
    int origen_x;
    int origen_y;
    int ubicacion_x;
    int ubicacion_y;
    Tile(int origen_x, int origen_y, int ubicacion_x, int ubicacion_y)
    {
        this->origen_x=origen_x;
        this->origen_y=origen_y;
        this->ubicacion_x=ubicacion_x;
        this->ubicacion_y=ubicacion_y;
    }
};

vector<Tile*> cargarTiles(string nombre_archivo)
{
    vector<Tile*> tiles;
    ifstream archivo(nombre_archivo.c_str());
    for(int ubicacion_y=0; ubicacion_y<10; ubicacion_y++)
    {
        for(int ubicacion_x=0; ubicacion_x<10; ubicacion_x++)
        {
            int origen_x;
            int origen_y;
            archivo>>origen_x;
            archivo>>origen_y;
            tiles.push_back(new Tile(origen_x,origen_y,ubicacion_x,ubicacion_y));
        }
    }
    archivo.close();
    return tiles;
}
void dibujarTile(SDL_Texture *tileset_texture, SDL_Renderer* renderer,
        int origen_x, int origen_y, int ubicacion_x, int ubicacion_y)
{
    SDL_Rect fuente,destino;
    fuente.x = 32*origen_x;
    fuente.y = 32*origen_y;
    fuente.w = 32;
    fuente.h = 32;

    destino.x = 32*ubicacion_x;
    destino.y = 32*ubicacion_y;
    destino.w = 32;
    destino.h = 32;

    SDL_RenderCopy(renderer,tileset_texture,&fuente,&destino);
}

int main( int argc, char* args[] )
{

    cargarTiles("assets/tile.map");
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
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;

    character = IMG_LoadTexture(renderer, "assets/personaje/down.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0;
    rect_character.y = 100;
    rect_character.w = w;
    rect_character.h = h;

    list<Personaje*>personajes;
    personajes.push_back(new PersonajeJugador (0,128,renderer,&personajes));

    SDL_Texture* tileset_texture = IMG_LoadTexture(renderer, "assets/Tiles.png");
    vector<Tile*>tiles=cargarTiles("assets/tile.map");

    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
        }

        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->logic((Uint8*)SDL_GetKeyboardState( NULL ));

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        for(int i=0;i<tiles.size();i++)
        {
            dibujarTile(tileset_texture,renderer,
                    tiles[i]->origen_x,tiles[i]->origen_y,
                    tiles[i]->ubicacion_x,tiles[i]->ubicacion_y);
        }
        // piedras fondo
       for(int x = 0; x < 16; x++)
        {
            for(int y = 0 ; y < 8 ; y++)
            {
            dibujarTile(tileset_texture,renderer,1,5,x ,y);
            }
        }
        //bordo arriba
         for(int x = 0; x <= 15; x++)
        {
            for(int y = 0; y < 1; y++)
                dibujarTile(tileset_texture,renderer,10,15,x,y);
        }
        //bordo abajo
        for(int x = 0; x <= 15; x++)
        {
            for(int y = 7; y < 8; y++)
                dibujarTile(tileset_texture,renderer,10,15,x,y);
        }

        //bordo verticales izquierda
        for(int x = 0; x <= 0.5; x++)
        {
            for(int y = 0; y < 15; y++)
                dibujarTile(tileset_texture,renderer,10,15,x,y);
        }

        //bordo verticales derecha
        for(int x = 14; x <= 15; x++)
        {
            for(int y = 0; y < 15; y++)
                dibujarTile(tileset_texture,renderer,10,15,x,y);
        }

        //arbustos superiores izquierdo
        for(int x = 0; x < 5 ; x++)
        {
            if(x > 0 && x <= 5)
            {
                dibujarTile(tileset_texture,renderer,11,8,x,0);
                dibujarTile(tileset_texture,renderer,11,9,x,1);
                dibujarTile(tileset_texture,renderer,11,10,x,2);
            }

        }

        //arbustos inferior izquierdo
        for(int x = 0; x < 5 ; x++)
        {
            if(x > 0 && x <= 5)
            {
                dibujarTile(tileset_texture,renderer,11,8,x,4);
                dibujarTile(tileset_texture,renderer,11,9,x,5);
                dibujarTile(tileset_texture,renderer,11,10,x,6);
            }

        }

        //arbustos inferiores derecho
        for(int x = 5; x <= 14 ; x++)
        {
            if(x > 8 && x < 14)
            {


                dibujarTile(tileset_texture,renderer,11,8,x,4);
                dibujarTile(tileset_texture,renderer,11,9,x,5);
                dibujarTile(tileset_texture,renderer,11,10,x,6);
            }
        }

        //arbustos superior derecho
        for(int x = 5; x <= 14 ; x++)
        {

            if(x > 8 && x < 14)
            {
                dibujarTile(tileset_texture,renderer,11,8,x,0);
                dibujarTile(tileset_texture,renderer,11,9,x,1);
                dibujarTile(tileset_texture,renderer,11,10,x,2);
            }

        }

        //arbustos central
        for(int x = 6; x <= 7 ; x++)
        {

            if(x > 4 && x < 9)
            {
                dibujarTile(tileset_texture,renderer,11,9,x,3.7);

            }

        }

        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->render(renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(16.66);
    }

	return 0;
}
