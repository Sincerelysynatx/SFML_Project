#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"

class Character : public Entity
{
public:
  Character();
  Character(int x, int y, int width, int height, string imageName);
  
  ~Character();
private:

};
#endif
