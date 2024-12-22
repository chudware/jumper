#include <gb/gb.h>
#include <stdio.h>
#include "bgTiles.h"
#include "background.h"
#include "gamesprites.h"
#include "enemy.h"
#include "sound.h"
#include "detectCollisions.h"
#include "gameOver.h"
#include "jump.h"

int playerSize = 8;
INT16 playerlocation[2]; // stores two INT16 x and y position of player

void main(void)
{

    // sets music
    NR52_REG = 0x80;
    NR50_REG = 0x77;
    NR51_REG = 0xFF;

    // sets background
    set_bkg_data(0, 10, bgTiles);
    set_bkg_tiles(0, 0, 32, 16, background);

    // sets the player / player
    playerlocation[0] = 16;
    playerlocation[1] = floorYposition;

    set_sprite_data(0, 8, gameSpritesTileLabel); /* defines the sprite data */
    set_sprite_tile(0, 0);                       /* defines the tiles numbers */
    move_sprite(0, playerlocation[0], playerlocation[1]);

    // sets enemy
    setEnemy();

    // other
    jumping = 0;
    DISPLAY_ON;
    SHOW_BKG;
    SHOW_SPRITES;
    while (!detectCollisions(playerlocation[0], playerlocation[1], enemyX, enemyY, playerSize, enemySize) && !detectCollisions(playerlocation[0], playerlocation[1], spike1X, spike1Y, playerSize, enemySize) && !detectCollisions(playerlocation[0], playerlocation[1], spike2X, spike2Y, playerSize, enemySize) && !detectCollisions(playerlocation[0], playerlocation[1], spike3X, spike3Y, playerSize, enemySize) && !detectCollisions(playerlocation[0], playerlocation[1], spike4X, spike4Y, playerSize, enemySize) && !detectCollisions(playerlocation[0], playerlocation[1], spike5X, spike5Y, playerSize, enemySize))
    {
        scroll_bkg(3, 0);
        enemyX -= 3;
        spike1X -= 2;
        spike2X -= 2;
        spike3X -= 2;
        spike4X -= 2;
        spike5X -= 2;
        move_sprite(1, enemyX, enemyY);
        move_sprite(2, spike1X, spike1Y);
        move_sprite(3, spike2X, spike2Y);
        move_sprite(4, spike3X, spike3Y);
        move_sprite(5, spike4X, spike4Y);
        move_sprite(6, spike5X, spike5Y);
        if ((joypad() & J_A) || jumping == 1)
        {
            jump(0, playerlocation);
            “jumpSound();
        }
        performantdelay(2);
    }
    gameOver();
}
