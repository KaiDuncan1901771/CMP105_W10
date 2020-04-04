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
	canPlayerMove = true;
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
		isJumping = true;
	}

	if (isCollider() == false)
	{
		isGravityOn = true;
	}
}

void Player::handleInput(float dt)
{
	if (canPlayerMove == true)
	{
		if (input->isKeyDown(sf::Keyboard::Space))
		{
			if (!isJumping)
			{
				stepVelocity = jumpVector;
				isJumping = true;
				isGravityOn = true;
				canPlayerMove = true;
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
}

void Player::collisionResponse(GameObject* collider)
{
	float diffX = (collider->getPosition().x + (collider->getSize().x / 2)) - (getPosition().x + (getSize().x / 2));
	float diffY = (collider->getPosition().y + (collider->getSize().y / 2)) - (getPosition().y + (getSize().y / 2));

	if (abs(diffX) > abs(diffY))
	{
		if (abs(diffX < 0))
		{ //Right side collision
			setPosition(collider->getPosition().x + collider->getSize().x + 0.25f, getPosition().y);
			canPlayerMove = false;

		}
		else
		{  //Left side collision
			setPosition(collider->getPosition().x - getSize().x - 0.25f, getPosition().y);
			canPlayerMove = false;

		}
	}
	else 
	{
	//	std::cout << "Y-axis collision";
		velocity.y = 0;
		setPosition(getPosition().x, collider->getPosition().y - getSize().y);
		isGravityOn = false;
	    isJumping = false;
		canPlayerMove = true;
	}
}