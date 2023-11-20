#include <stdio.h>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const char WINDOW_NAME[] = "SDL2 Test";


int wmain(int argc, char *argv[]) {
    // Initialization
    printf("SDL2 Test\nInitializating SDL...");
    
    SDL_Window *mainWindow = NULL;
    SDL_Surface *mainSurface = NULL;
    SDL_Event eventState;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error: failed to initialize (%s)", SDL_GetError());
        return 0;
    }

    // Window Creation
    printf("\n\nSDL initialized successfully\nCreating Window...");

    mainWindow = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (mainWindow == NULL) {
        printf("Error: failed to create window (%s)", SDL_GetError());
        return 0;
    }

    // Main Loop
    mainSurface = SDL_GetWindowSurface(mainWindow);
    int shouldGameClose = 0;

    printf("\n\nWindow created successfully\nStarting main loop...");

    while(shouldGameClose == 0) {
        while(SDL_PollEvent(&eventState) != 0) {
            if (eventState.type == SDL_QUIT) {
                shouldGameClose = 1;
            }
        }
    }

    // Asset Unloading
    printf("\n\nQuit event triggered, unloading assets...");

    // SDL Shutdown
    SDL_DestroyWindow(mainWindow);
    SDL_Quit();

    printf("\n\nSDL closed, goodbye! :3");

    return 0;
}