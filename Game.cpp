#include "Game.h"
#include "Entity.h"
#include "Character.h"
#include <vector>

using std::vector;

int Game::MainLoop()
{
  sf::RenderWindow window(sf::VideoMode(832, 576), "Game");
  window.setFramerateLimit(60);

  TileMap map;
  if (!map.load("WallTileSheet.png", sf::Vector2u(64, 64), level, 13, 9))
    return -1;

  vector<Entity*> entities;
  Entity *player = new Character(100, 100, 64, 64, "character.png");
  entities.push_back(player);

  sf::Clock frameClock;

  bool noKeyWasPressed = true;

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
          window.close();
      if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
          window.close();
    }

    sf::Time frameTime = frameClock.restart();

    for (Entity *entity : entities)
    {
      entity->Update(frameTime);
    }

    window.clear();
    window.draw(map);

    for (Entity *entity : entities)
    {
      entity->Render(window);
    }

    window.display();
  }

  //cleanup



  return 0;
}
