#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <string>
#include <cmath>
#include <iostream>
#include "assert.h"
//#include "AnimatedSprite.hpp"

using std::string;
using std::cout;
using std::endl;

class Entity
{
public:
  Entity();
  Entity(int x, int y, int width, int height, string imageName);
  ~Entity();
  void Update(sf::Time &frameTime);
  void Render(sf::RenderWindow &window);
protected:
  float m_x;
  float m_y;
  int m_height;
  int m_width;
  int m_health;
  int m_stamina;
  int m_attackSpeed;
  bool m_immune;
  float m_speed;
  float m_maxSpeed;
  sf::Vector2f m_movement;
  sf::Texture m_texture;
  Animation *m_currentAnimation;
  Animation m_walkingAnimationDown;
  Animation m_walkingAnimationLeft;
  Animation m_walkingAnimationRight;
  Animation m_walkingAnimationUp;
  // set up AnimatedSprite
  AnimatedSprite *m_animatedSprite;
};

#endif
