#include <SFML/Graphics.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "library.h"


int map[WIDTH][HEIGHT];


int main()
{
    //RANDOM NUMBERS
    int to_srand;
    time_t tt;
    to_srand = time(&tt);
    srand(to_srand);

    sfVideoMode mode = { WIDTH, HEIGHT, 32 };
    sfRenderWindow* window;

    //FONTS
    sfFont* font = sfFont_createFromFile("ka1.ttf");
    
    //CREATING MAIN WINDOW
    window = sfRenderWindow_create(mode, "", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 64);


    //BACKGROUND
    sfTexture* texture;
    sfSprite* background;

    texture = sfTexture_createFromFile("background.jpg", NULL);
    background = sfSprite_create();
    
    sfRenderWindow_drawSprite(window, background, NULL);

    
    //PLAYERS SETUP
    player p1, p2;

    p1.id = 1;
    p2.id = 2;

    p1.name = "Blue";
    p2.name = "Red";

    p1.color = sfBlue;
    p2.color = sfRed;

    p1.pos_x = rand() % WIDTH;
    p2.pos_x = rand() % WIDTH;

    p1.pos_y = rand() % HEIGHT;
    p2.pos_y = rand() % HEIGHT;

    p1.dir = 0;
    p2.dir = 0;

    struct player winner;
    int restart = 0;
    int menu_open = 1;
    int just_started = 1;

    while (sfRenderWindow_isOpen(window))
    {
        if (menu_open == 1)
        {
            int result = menu_page(window, font);
            sfRenderWindow_clear(window, sfBlack);
            if (result == 1) sfRenderWindow_close(window);
            menu_open = 0;
        }

        sfEvent event;
        
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
            {
                sfRenderWindow_close(window);
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyLeft))
        {
            if (p1.dir != 2) p1.dir = 1;

        }
        if (sfKeyboard_isKeyPressed(sfKeyRight))
        {
            if (p1.dir != 1) p1.dir = 2;

        }
        if (sfKeyboard_isKeyPressed(sfKeyUp))
        {
            if (p1.dir != 0) p1.dir = 3;

        }
        if (sfKeyboard_isKeyPressed(sfKeyDown))
        {
            if (p1.dir != 3) p1.dir = 0;

        }
        if (sfKeyboard_isKeyPressed(sfKeyA))
        {
            if (p2.dir != 2) p2.dir = 1;

        }
        if (sfKeyboard_isKeyPressed(sfKeyD))
        {
            if (p2.dir != 1) p2.dir = 2;

        }
        if (sfKeyboard_isKeyPressed(sfKeyW))
        {
            if (p2.dir != 0) p2.dir = 3;

        }
        if (sfKeyboard_isKeyPressed(sfKeyS))
        {
            if (p2.dir != 3) p2.dir = 0;

        }

        for (int i = 0; i < pace; i++)
        {
            update(&p1);
            update(&p2);

            if (map[p1.pos_x][p1.pos_y] == 1)
            {
                winner = p2;
                restart = 1;
            }
            if (map[p2.pos_x][p2.pos_y] == 1)
            {
                winner = p1;
                restart = 1;
            }
            map[p1.pos_x][p1.pos_y] = 1;
            map[p2.pos_x][p2.pos_y] = 1;

            sfCircleShape* circle = sfCircleShape_create();
            sfVector2f v1, v2;
            v1.x = p1.pos_x;
            v1.y = p1.pos_y;

            v2.x = p2.pos_x;
            v2.y = p2.pos_y;

            sfCircleShape_setRadius(circle, radius);
            sfCircleShape_setPosition(circle, v1);
            sfCircleShape_setFillColor(circle, p1.color);
            sfRenderWindow_drawCircleShape(window, circle, NULL);

            sfCircleShape_setPosition(circle, v2);
            sfCircleShape_setFillColor(circle, p2.color);
            sfRenderWindow_drawCircleShape(window, circle, NULL);
            

        }


        //END GAME MENU
        if (restart == 1)
        {
            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_display(window);
            ending_screen(window, font, winner);

            int loop = 1;
            
            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_drawSprite(window, background, NULL);
            sfRenderWindow_display(window);


            p1.pos_x = rand() % WIDTH;
            p2.pos_x = rand() % WIDTH;

            p1.pos_y = rand() % HEIGHT;
            p2.pos_y = rand() % HEIGHT;


            clear_map(map);
            menu_open = 1;
            restart = 0;
            just_started = 2;
        }

        sfRenderWindow_display(window);

        if (just_started == 1)
        {
            counting(window, font, p1, p2, 3);
            sfRenderWindow_clear(window, sfBlack);
            just_started = 0;
        }
        if (just_started == 2) just_started = 1;


        printf("V1: (x,y) = (%d,%d)\n", p1.pos_x, p1.pos_y);
        printf("V2: (x,y) = (%d,%d)\n", p2.pos_x, p2.pos_y);

    }


}
