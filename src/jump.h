BYTE jumping;
INT8 gravity = -1;
INT16 currentspeedY;
INT16 floorYposition = 112;

void performantdelay(UINT8 numloops)
{
    UINT8 i;
    for (i = 0; i < numloops; i++)
    {
        wait_vbl_done();
    }
}

INT8 wouldhitsurface(INT16 projectedYPosition)
{
    if (projectedYPosition >= floorYposition)
    {

        return floorYposition;
    }
    return -1;
}

void jump(UINT8 spriteid, UINT16 spritelocation[2])
{
    INT8 possiblesurfaceY;

    if (jumping == 0)
    {
        jumping = 1;
        currentspeedY = 10;
    }

    currentspeedY = currentspeedY + gravity;
    spritelocation[1] = spritelocation[1] - currentspeedY;
    possiblesurfaceY = wouldhitsurface(spritelocation[1]);

    if (possiblesurfaceY != -1)
    {
        jumping = 0;
        move_sprite(spriteid, spritelocation[0], possiblesurfaceY);
    }
    else
    {
        move_sprite(spriteid, spritelocation[0], spritelocation[1]);
    }
}