#include "Player.h"

Player::Player()
{
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	stepVelocity = sf::Vector2f(0, 0);
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = false;
	velocity = sf::Vector2f(150, 0);
	isGravityOn = true;
}

Player::~Player()
{

}

void Player::update(float dt)
{
	if (isGravityOn == true)
	{
		sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
		stepVelocity += gravity * dt;
		setPosition(getPosition() + pos);
	}

	if (isCollider() == false)
	{
		isGravityOn = true;
	}
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			stepVelocity = jumpVector;
			isJumping = true;
			isGravityOn = true;
		}
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		move(-velocity * dt);
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		move(velocity * dt);
	}
}

void Player::collisionResponse(GameObject* collider)
{
	velocity.y = 0;
	setPosition(getPosition().x, collider->getPosition().y - getSize().y);
	isJumping = false;
	isGravityOn = false;

	float diffX = (collider->getPosition().x + (collider->getSize().x / 2)) - (getPosition().x + (getSize().x / 2));
	float diffY = (collider->getPosition().y + (collider->getSize().y / 2)) - (getPosition().y + (getSize().y / 2));
}