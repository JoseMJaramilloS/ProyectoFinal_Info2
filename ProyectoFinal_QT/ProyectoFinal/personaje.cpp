#include "personaje.h"

int personaje::getPosx() const
{
    return posx;
}

void personaje::setPosx(int value)
{
    posx = value;
}

int personaje::getPosy() const
{
    return posy;
}

void personaje::setPosy(int value)
{
    posy = value;
}

int personaje::getVidas() const
{
    return vidas;
}

void personaje::setVidas(int value)
{
    vidas = value;
}

int personaje::getBalas() const
{
    return balas;
}

void personaje::setBalas(int value)
{
    balas = value;
}

int personaje::getGranadas() const
{
    return granadas;
}

void personaje::setGranadas(int value)
{
    granadas = value;
}

personaje::personaje()
{
    
}

personaje::personaje(int x, int y)
{
    this->posx=x;
    this->posy=y;
    setPos(x,y);
}
