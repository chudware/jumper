#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gb/gb.h>
#include "gamesprites.h"

int enemyX = 160;
int enemyY = 80;
int enemySize = 8;

int spike1X = 168;
int spike1Y = 112;
int spike2X = 176;
int spike2Y = 112;
int spike3X = 208;
int spike3Y = 112;
int spike4X = 216;
int spike4Y = 112;
int spike5X = 264;
int spike5Y = 112;


void setEnemy(void){

    // snowball
    set_sprite_tile(1, 1);     //the first "1" is the custom id of the tile, the second one is the id that sets the texture
    move_sprite(1, enemyX, enemyY);

    // spikes
    set_sprite_tile(2, 2);
    move_sprite(2, spike1X, spike1Y);
    set_sprite_tile(3, 2);
    move_sprite(3, spike2X, spike2Y);
    set_sprite_tile(4, 2);
    move_sprite(4, spike3X, spike3Y);
    set_sprite_tile(5, 2);
    move_sprite(5, spike4X, spike4Y);
    set_sprite_tile(6, 2);
    move_sprite(6, spike5X, spike5Y);
}