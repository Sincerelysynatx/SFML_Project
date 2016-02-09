#include "Character.h"

Character::Character()
{

}

Character::Character(int x, int y, int width, int height, string imageName) : Entity(x, y, width, height, imageName)
{
  m_health = 3;
  m_stamina = 100;
  m_attackSpeed = 60;
  m_immune = false;
}

Character::~Character()
{

}

