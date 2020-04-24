#pragma once
#include "Framework/TileMap.h"
#include "Framework/GameObject.h"
#include  "Player.h"
class TileMapTest: public GameObject, public Player
{
public:
	TileMapTest();
	~TileMapTest();

	void setMap();
	void render(sf::RenderWindow* window);
	void collisionCheck(Player& player2);
	TileMap tileMap;


private:

	
protected:
	
};

