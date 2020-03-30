#pragma once
#include "Framework/TileMap.h"
class TileMapTest
{
public:
	TileMapTest();
	~TileMapTest();

	void setMap();
	void render(sf::RenderWindow* window);
private:

protected:
	TileMap tileMap;
};

