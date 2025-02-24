/*
Calculatrice_graphique.c

Une calculatrice scientifique graphique avec animations de fondu lors du survol et du clic.
Ce code utilise SDL2 et SDL2_ttf.
Pour compiler sous Linux, vous pouvez utiliser :
    gcc Calculatrice_graphique.c -o Calculatrice_graphique -lSDL2 -lSDL2_ttf -lm
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 640
#define BUTTON_ROWS 5
#define BUTTON_COLS 4
#define BUTTON_MARGIN 5
#define DISPLAY_HEIGHT 100

typedef struct {
    SDL_Rect rect;
    const char* label;
} Button;

Button buttons[BUTTON_ROWS * BUTTON_COLS] = {
    // Ligne 1 : fonctions scientifiques
    { { 0, 0, 0, 0 }, "sin" },
    { { 0, 0, 0, 0 }, "cos" },
    { { 0, 0, 0, 0 }, "tan" },
    { { 0, 0, 0, 0 }, "log" },
    // Ligne 2
    { { 0, 0, 0, 0 }, "7" },
    { { 0, 0, 0, 0 }, "8" },
    { { 0, 0, 0, 0 }, "9" },
    { { 0, 0, 0, 0 }, "/" },
    // Ligne 3
    { { 0, 0, 0, 0 }, "4" },
    { { 0, 0, 0, 0 }, "5" },
    { { 0, 0, 0, 0 }, "6" },
    { { 0, 0, 0, 0 }, "*" },
    // Ligne 4
    { { 0, 0, 0, 0 }, "1" },
    { { 0, 0, 0, 0 }, "2" },
    { { 0, 0, 0, 0 }, "3" },
    { { 0, 0, 0, 0 }, "-" },
    // Ligne 5
    { { 0, 0, 0, 0 }, "0" },
    { { 0, 0, 0, 0 }, "." },
    { { 0, 0, 0, 0 }, "=" },
    { { 0, 0, 0, 0 }, "+" }
};

void drawButton(SDL_Renderer* renderer, TTF_Font* font, Button btn, Uint8 alpha) {
    // Couleur du bouton
    SDL_SetRenderDrawColor(renderer, 70, 130, 180, alpha);
    SDL_RenderFillRect(renderer, &btn.rect);
    // Bordure du bouton
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, alpha);
    SDL_RenderDrawRect(renderer, &btn.rect);

    // Rendu du texte
    SDL_Color color = {255, 255, 255, alpha};
    SDL_Surface* surface = TTF_RenderText_Blended(font, btn.label, color);
    if (!surface) {
        fprintf(stderr, "Erreur TTF_RenderText_Blended: %s\n", TTF_GetError());
        return;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) return;
    
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstRect = {
        btn.rect.x + (btn.rect.w - texW) / 2,
        btn.rect.y + (btn.rect.h - texH) / 2,
        texW,
        texH
    };
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    SDL_DestroyTexture(texture);
}

void renderText(SDL_Renderer *renderer, TTF_Font *font, const char* text, SDL_Rect rect, Uint8 alpha) {
    SDL_Color color = {255, 255, 255, alpha};
    SDL_Surface* surface = TTF_RenderUTF8_Blended(font, text, color);
    if (!surface) {
        fprintf(stderr, "Erreur TTF_RenderUTF8_Blended: %s\n", TTF_GetError());
        return;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) return;
    
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstRect = {
        rect.x + 10,
        rect.y + (rect.h - texH) / 2,
        texW,
        texH
    };
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    SDL_DestroyTexture(texture);
}

double evalExpression(const char* expr, int* valid) {
    // Très simplifié : évalue une expression binaire du type "nombre op nombre"
    double op1 = 0, op2 = 0;
    char op;
    if (sscanf(expr, "%lf %c %lf", &op1, &op, &op2) != 3) {
        *valid = 0;
        return 0;
    }
    *valid = 1;
    switch(op) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op2 != 0 ? op1 / op2 : 0;
        default:
            *valid = 0;
            return 0;
    }
}

int main(int argc, char* argv[]) {
    (void)argc; (void)argv;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Erreur d'initialisation SDL: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    if (TTF_Init() != 0) {
        fprintf(stderr, "Erreur d'initialisation TTF: %s\n", TTF_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Window *win = SDL_CreateWindow("Calculatrice Scientifique",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!win) {
        fprintf(stderr, "Erreur de création de fenêtre: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return EXIT_FAILURE;
    }
    
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        SDL_DestroyWindow(win);
        TTF_Quit();
        SDL_Quit();
        return EXIT_FAILURE;
    }
    
    TTF_Font *font = TTF_OpenFont("FreeSans.ttf", 24);
    if (!font) {
        fprintf(stderr, "Erreur d'ouverture de police: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(win);
        TTF_Quit();
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Calcul de la taille de chaque bouton
    int btnW = (WINDOW_WIDTH - (BUTTON_COLS + 1) * BUTTON_MARGIN) / BUTTON_COLS;
    int btnH = (WINDOW_HEIGHT - DISPLAY_HEIGHT - (BUTTON_ROWS + 1) * BUTTON_MARGIN) / BUTTON_ROWS;
    for (int i = 0; i < BUTTON_ROWS; i++) {
        for (int j = 0; j < BUTTON_COLS; j++) {
            int index = i * BUTTON_COLS + j;
            buttons[index].rect.x = BUTTON_MARGIN + j * (btnW + BUTTON_MARGIN);
            buttons[index].rect.y = DISPLAY_HEIGHT + BUTTON_MARGIN + i * (btnH + BUTTON_MARGIN);
            buttons[index].rect.w = btnW;
            buttons[index].rect.h = btnH;
        }
    }

    char input[256] = "";
    char output[256] = "";
    int running = 1;
    SDL_Event event;
    Uint32 fadeStart = 0;
    int animating = 0;
    const Uint32 fadeDuration = 300;  // ms

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = 0;
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x = event.button.x, y = event.button.y;
                // Vérifier si clic sur un bouton
                for (int i = 0; i < BUTTON_ROWS * BUTTON_COLS; i++) {
                    if (x >= buttons[i].rect.x && x <= buttons[i].rect.x + buttons[i].rect.w &&
                        y >= buttons[i].rect.y && y <= buttons[i].rect.y + buttons[i].rect.h) {
                        const char* label = buttons[i].label;
                        if (strcmp(label, "=") == 0) {
                            int valid = 0;
                            double res = evalExpression(input, &valid);
                            if (valid)
                                snprintf(output, sizeof(output), "%.6g", res);
                            else
                                snprintf(output, sizeof(output), "Erreur");
                        } else if (strcmp(label, "C") == 0) {
                            input[0] = '\0';
                            output[0] = '\0';
                        } else if (strcmp(label, "sin") == 0 || strcmp(label, "cos") == 0 ||
                                   strcmp(label, "tan") == 0 || strcmp(label, "log") == 0) {
                            // Ajoute la fonction et une parenthèse
                            strncat(input, label, sizeof(input)-strlen(input)-1);
                            strncat(input, "(", sizeof(input)-strlen(input)-1);
                        } else {
                            strncat(input, label, sizeof(input)-strlen(input)-1);
                        }
                        // Démarrer l'animation de fondu
                        animating = 1;
                        fadeStart = SDL_GetTicks();
                    }
                }
            }
        }
        
        // Animation de fondu pour l'affichage
        Uint32 currentTime = SDL_GetTicks();
        Uint32 elapsed = currentTime - fadeStart;
        Uint8 alpha = 255;
        if (animating && elapsed < fadeDuration) {
            // Calcul d'une opacité croissante en fonction du temps -- effet de fondu
            alpha = (Uint8)(255 * elapsed / fadeDuration);
        } else if (animating) {
            animating = 0;
            alpha = 255;
        }
        
        // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderClear(renderer);
        
        // Zone d'affichage (display)
        SDL_Rect displayRect = {0, 0, WINDOW_WIDTH, DISPLAY_HEIGHT};
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
        SDL_RenderFillRect(renderer, &displayRect);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &displayRect);
        
        // Afficher l'entrée et le résultat avec effet de fondu
        renderText(renderer, font, input, displayRect, alpha);
        if (strlen(output) > 0) {
            SDL_Rect outRect = {0, DISPLAY_HEIGHT/2, WINDOW_WIDTH, DISPLAY_HEIGHT/2};
            renderText(renderer, font, output, outRect, alpha);
        }
        
        // Dessiner les boutons
        for (int i = 0; i < BUTTON_ROWS * BUTTON_COLS; i++) {
            drawButton(renderer, font, buttons[i], 255);
        }
        
        SDL_RenderPresent(renderer);
    }
    
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}