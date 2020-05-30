#pragma once
#include <SFML/Graphics.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

const int WIDTH = 500;
const int HEIGHT = 400;
const int pace = 1;
const int radius = 4;


struct player
{
    int id;
    const char* name;
    int pos_x;
    int pos_y;
    int dir;
    sfColor color;

};

void update(player* p);
void clear_map(int map[WIDTH][HEIGHT]);
int menu_page(sfRenderWindow* window, sfFont* font);
void ending_screen(sfRenderWindow* window, sfFont* font, struct player winner);
void counting(sfRenderWindow* window, sfFont* font, struct player p1, struct player p2, int pause);
