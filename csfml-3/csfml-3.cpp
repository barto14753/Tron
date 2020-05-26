﻿#include <SFML/Graphics.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>


const int WIDTH = 500;
const int HEIGHT = 400;
const int pace = 1;
const int radius = 4;

int map[WIDTH][HEIGHT];


struct player
{
    int id;
    const char* name;
    int pos_x;
    int pos_y;
    int dir;
    sfColor color;

};


void update(player* p)
{
    if (p->dir == 0) p->pos_y += 1;
    if (p->dir == 1) p->pos_x -= 1;
    if (p->dir == 2) p->pos_x += 1;
    if (p->dir == 3) p->pos_y -= 1;

    //BORDERS
    if (p->pos_x >= WIDTH-1) p->pos_x = 0;
    if (p->pos_y >= HEIGHT-1) p->pos_y = 0;

    if (p->pos_x < 0) p->pos_x = WIDTH;
    if (p->pos_y < 0) p->pos_y = HEIGHT;

}

void clear_map()
{
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            map[i][j] = 0;
        }
    }
}

int menu_page(sfRenderWindow* window, sfFont* font)
{
    sfText* title = sfText_create();
    sfText_setString(title, "TRON");
    sfText_setFont(title, font);
    sfText_setCharacterSize(title, 60);
    sfVector2f title_pos;
    title_pos.x = 150;
    title_pos.y = 0;
    sfText_setPosition(title, title_pos);


    sfText* start_button = sfText_create();
    sfText_setString(start_button, "START");
    sfText_setFont(start_button, font);
    sfText_setCharacterSize(start_button, 35);
    sfVector2f start_pos;
    start_pos.x = 180;
    start_pos.y = 150;
    sfText_setPosition(start_button, start_pos);

    sfText* quit_button = sfText_create();
    sfText_setString(quit_button, "QUIT");
    sfText_setFont(quit_button, font);
    sfText_setCharacterSize(quit_button, 35);
    sfVector2f quit_pos;
    quit_pos.x = 200;
    quit_pos.y = 200;
    sfText_setPosition(quit_button, quit_pos);
    
    sfVector2i mouse_pos;
    int running = 1;

    while (running == 1)
    {

        mouse_pos = sfMouse_getPositionRenderWindow(window);
        if (mouse_pos.x > start_pos.x&& mouse_pos.x < start_pos.x + 150 && mouse_pos.y > start_pos.y && mouse_pos.y < start_pos.y + 50)
        {
            sfText_setFillColor(start_button, sfBlue);
            if (sfMouse_isButtonPressed(sfMouseLeft))
            {
                sfRenderWindow_clear(window, sfBlack);
                sfRenderWindow_display(window);
                return 2;
            }

        }
        else sfText_setFillColor(start_button, sfWhite);

        if (mouse_pos.x > quit_pos.x&& mouse_pos.x < quit_pos.x + 125 && mouse_pos.y > quit_pos.y && mouse_pos.y < quit_pos.y + 50)
        {
            sfText_setFillColor(quit_button, sfBlue);
            if (sfMouse_isButtonPressed(sfMouseLeft))
            {
                sfRenderWindow_clear(window, sfBlack);
                return 1;
            }
        }
        else sfText_setFillColor(quit_button, sfWhite);


        sfRenderWindow_drawText(window, title, NULL);
        sfRenderWindow_drawText(window, start_button, NULL);
        sfRenderWindow_drawText(window, quit_button, NULL);

        sfRenderWindow_display(window);

    }
}

void ending_screen(sfRenderWindow* window, sfFont* font, struct player winner)
{
    sfRenderWindow_clear(window, sfBlack);
    sfText* title = sfText_create();


    sfText_setString(title, "WINNER");
    sfText_setFont(title, font);
    sfText_setCharacterSize(title, 60);
    sfVector2f title_pos;
    title_pos.x = 100;
    title_pos.y = 0;
    sfText_setPosition(title, title_pos);

    sfText* winner_name = sfText_create();
    sfText_setString(winner_name, winner.name);
    sfText_setFont(winner_name, font);
    sfText_setCharacterSize(winner_name, 60);
    sfText_setFillColor(winner_name, winner.color);
    sfVector2f winner_pos;
    winner_pos.x = 150;
    winner_pos.y = 100;
    sfText_setPosition(winner_name, winner_pos);

    sfText* continue_button = sfText_create();
    sfText_setString(continue_button, "CONTINUE");
    sfText_setFont(continue_button, font);
    sfText_setCharacterSize(continue_button, 40);
    sfVector2f continue_pos;
    continue_pos.x = 120;
    continue_pos.y = 300;
    sfText_setPosition(continue_button, continue_pos);


    sfVector2i mouse_pos;
    int running = 1;

    while (running == 1)
    {

        mouse_pos = sfMouse_getPositionRenderWindow(window);
        if (mouse_pos.x > continue_pos.x&& mouse_pos.x < continue_pos.x + 100, mouse_pos.y > continue_pos.y&& mouse_pos.y < continue_pos.y + 50)
        {
            sfText_setFillColor(continue_button, sfBlue);
            if (sfMouse_isButtonPressed(sfMouseLeft))
            {
                sfRenderWindow_clear(window, sfBlack);
                sfRenderWindow_display(window);
                return;
            }
        }
        else sfText_setFillColor(continue_button, sfWhite);

        
        sfRenderWindow_drawText(window, title, NULL);
        sfRenderWindow_drawText(window, winner_name, NULL);
        sfRenderWindow_drawText(window, continue_button, NULL);

        sfRenderWindow_display(window);

    }
}

void counting(sfRenderWindow* window, sfFont* font, struct player p1, struct player p2, int pause)
{
    for (int i = 0; i < pause; i++)
    {

        
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
        sfRenderWindow_display(window);
        Sleep(500);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
        Sleep(1000);

    }
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_display(window);

}


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


            clear_map();
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
