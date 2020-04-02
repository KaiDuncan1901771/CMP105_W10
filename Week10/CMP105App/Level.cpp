#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	level.setMap();

	playerTexture.loadFromFile("gfx/MushroomTrans.png");
	player.setTexture(&playerTexture);
	player.setCollisionBox(0, 0, 30, 30);
	player.setSize(sf::Vector2f(30, 30));
	player.setPosition(200, 100);
	player.setInput(input);


}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{

	player.update(dt);
	level.collisionCheck(player);


}

// Render level
void Level::render()
{
	beginDraw();
	level.render(window);
	window->draw(player);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}