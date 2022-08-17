#include "source/web_engine/web_engine.h"
#include "source/drawer/drawer_backend/draw_text.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


// some ordinary window nothing speacial
int main(int argc, char *argv[])
{
    SDL_Event event;
    SDL_Rect rect1, rect2;
    SDL_Renderer* renderer;
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

    open_web_page("example.html");

    quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event) == 1) {
            if (event.type == SDL_QUIT) {
                printf("quit by click");
                quit = 1;
            }
        }
        SDL_SetRenderDrawColor(renderer, 250, 250, 250, 0);
        SDL_RenderClear(renderer);
        render_page(renderer);

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
