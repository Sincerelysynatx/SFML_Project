#include "Entity.h"

Entity::Entity()
{

}

Entity::Entity(int x, int y, int width, int height, string imageName)
{
  m_x = x;
  m_y = y;
  m_width = width;
  m_height = height;
  
  if (!m_texture.loadFromFile(imageName))
  {
    cout<<"Failed to load spritesheet!"<<endl;
  }

  m_movement.x = 0.0f;
  m_movement.y = 0.0f;  

  m_speed = 5.0f;

  m_maxSpeed = 100.0f;

  
  // set up the animations for all four directions (set spritesheet and push frames)
  m_walkingAnimationDown.setSpriteSheet(m_texture);
  m_walkingAnimationDown.addFrame(sf::IntRect(m_width * 1, m_height * 0, m_width, m_height));
  m_walkingAnimationDown.addFrame(sf::IntRect(m_width * 2, m_height * 0, m_width, m_height));
  m_walkingAnimationDown.addFrame(sf::IntRect(m_width * 1, m_height * 0, m_width, m_height));
  m_walkingAnimationDown.addFrame(sf::IntRect(m_width * 0, m_height * 0, m_width, m_height));
  
  m_walkingAnimationLeft.setSpriteSheet(m_texture);
  m_walkingAnimationLeft.addFrame(sf::IntRect(m_width * 1, m_height * 1, m_width, m_height));
  m_walkingAnimationLeft.addFrame(sf::IntRect(m_width * 2, m_height * 1, m_width, m_height));
  m_walkingAnimationLeft.addFrame(sf::IntRect(m_width * 1, m_height * 1, m_width, m_height));
  m_walkingAnimationLeft.addFrame(sf::IntRect(m_width * 0, m_height * 1, m_width, m_height));

  m_walkingAnimationRight.setSpriteSheet(m_texture);
  m_walkingAnimationRight.addFrame(sf::IntRect(m_width * 1, m_height * 2, m_width, m_height));
  m_walkingAnimationRight.addFrame(sf::IntRect(m_width * 2, m_height * 2, m_width, m_height));
  m_walkingAnimationRight.addFrame(sf::IntRect(m_width * 1, m_height * 2, m_width, m_height));
  m_walkingAnimationRight.addFrame(sf::IntRect(m_width * 0, m_height * 2, m_width, m_height));

  m_walkingAnimationUp.setSpriteSheet(m_texture);
  m_walkingAnimationUp.addFrame(sf::IntRect(m_width * 1, m_height * 3, m_width, m_height));
  m_walkingAnimationUp.addFrame(sf::IntRect(m_width * 2, m_height * 3, m_width, m_height));
  m_walkingAnimationUp.addFrame(sf::IntRect(m_width * 1, m_height * 3, m_width, m_height));
  m_walkingAnimationUp.addFrame(sf::IntRect(m_width * 0, m_height * 3, m_width, m_height));

  m_currentAnimation = &m_walkingAnimationDown;

  m_animatedSprite = new AnimatedSprite(sf::seconds(0.2), true, false);

  m_animatedSprite->setPosition(m_x, m_y);
}

Entity::~Entity()
{
  delete m_currentAnimation;
  delete m_animatedSprite;
}

void Entity::Update(sf::Time &frameTime)
{
  bool noKeyWasPressed = true;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    m_currentAnimation = &m_walkingAnimationUp;
    m_movement.y -= m_speed;
    noKeyWasPressed = false;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    m_currentAnimation = &m_walkingAnimationDown;
    m_movement.y += m_speed;
    noKeyWasPressed = false;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    m_currentAnimation = &m_walkingAnimationLeft;
    m_movement.x -= m_speed;
    noKeyWasPressed = false;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    m_currentAnimation = &m_walkingAnimationRight;
    m_movement.x += m_speed;
    noKeyWasPressed = false;
  }
  
  if (sqrt(m_movement.x * m_movement.x + m_movement.y * m_movement.y) > m_maxSpeed)
  {
    
  }

  m_animatedSprite->play(*m_currentAnimation);
  m_animatedSprite->move(m_movement * frameTime.asSeconds());

  // if no key was pressed stop the animation
  if (noKeyWasPressed)
  {
      m_animatedSprite->stop();
      if (m_movement.x > 0)
        m_movement.x -= 10;
      if (m_movement.x < 0)
        m_movement.x += 10;
      if (m_movement.y > 0)
        m_movement.y -= 10;
      if (m_movement.y < 0)
        m_movement.y += 10;
  }
  noKeyWasPressed = true;

  m_animatedSprite->update(frameTime);
}

void Entity::Render(sf::RenderWindow &window)
{
  window.draw(*m_animatedSprite);
}