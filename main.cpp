//main.cpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

int main(int argc, char* argv[]){
  SDL_Window *window;                    //window pointer
  SDL_Init(SDL_INIT_VIDEO);              //initialize SDL2

  //create an application window
  window = SDL_CreateWindow(
    "Lethal Larry",                  //window title
    SDL_WINDOWPOS_UNDEFINED,         //initial x position
    SDL_WINDOWPOS_UNDEFINED,         //initial y position
    640,                             //width, in pixels
    480,                             //height, in pixels
    SDL_WINDOW_OPENGL                //flags - see below
    );
    //check if window was successfully created
    if (window == NULL){
      printf("Could not create window: %s\n", SDL_GetError());
      return 1;
    }
    //window is open: could enter program loop here (SDL_PollEvent())
    SDL_Event e;
    bool quit = false;
    while (!quit){
      while (SDL_PollEvent(&e)){
        if (e.type == SDL_QUIT){
          quit = true;
        }
        if (e.type == SDL_KEYDOWN){
          quit = true;
        }
        if (e.type == SDL_MOUSEBUTTONDOWN){
          quit = true;
        }
      }
    }
    SDL_DestroyWindow(window); //close window
    SDL_Quit(); //quit
    return 0;
}
