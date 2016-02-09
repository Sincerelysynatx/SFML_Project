#ifndef GAME_H
#define GAME_H 

#include <SFML/Graphics.hpp>
#include "Tilemap.h"
#include "AnimatedSprite.hpp"

class Game
{
public:
  int MainLoop();


private:
  const int level[117] =
  {
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 
    3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 
    3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 
    3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 
    3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 
    3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 
    3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 
    3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 
    6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 
  };
};

#endif