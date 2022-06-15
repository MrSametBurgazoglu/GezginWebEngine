#include "source/web_engine/web_engine.h"
#include "source/drawer/drawer_backend/draw_text.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


// some ordinary window nothing speacial
int main(int argc, char *argv[])
{
    open_web_page("example.html");
    SDL_Event event;
    SDL_Rect rect1, rect2;
    SDL_Renderer *renderer;
    SDL_Texture *texture1, *texture2;
    SDL_Window *window;
    int quit;

    /* Inint TTF. */
    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(500, 500, 0, &window, &renderer);
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("../docs/fonts/Sans.ttf", 24);
    if (font == NULL) {
        fprintf(stderr, "error: font not found\n");
        exit(EXIT_FAILURE);
    }

    get_text_and_rect(renderer, 0, 0, "hello, welcome to my world jackie", font, &texture1, &rect1);

    quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event) == 1) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        /* Use TTF textures. */
        SDL_RenderCopy(renderer, texture1, NULL, &rect1);
        SDL_RenderCopy(renderer, texture2, NULL, &rect2);

        SDL_RenderPresent(renderer);
    }

    /* Deinit TTF. */
    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    TTF_Quit();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    exit_web_engine();
    return EXIT_SUCCESS;
}