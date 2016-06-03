#include "EntityCont.h"

EntityCont::EntityCont()
{
	color = sf::Color::White;
}

void EntityCont::addEntity(double positionX, double positionY, double velocityX, double velocityY, double accelerationX, double accelerationY, double mass)
{
	Entity temp;
	temp.setPose(positionX, positionY, velocityX, velocityY, accelerationX, accelerationY);
	temp.setMass(mass);

	temp.setColor(color);

	entities.push_back(temp);
}

void EntityCont::updateAll(double deltaTime)
{
	for(unsigned int i = 0; i < entities.size(); i++)
	{
		entities[i].update(deltaTime);
	}
}

std::vector<sf::CircleShape> EntityCont::getShapes()
{
	std::vector<sf::CircleShape> shapes;

	for(unsigned int i = 0; i < entities.size(); i++)
	{
		shapes.push_back(entities[i].getShape());
	}

	return shapes;
}

void EntityCont::setColor(sf::Color color)
{
	this->color = color;

	for (unsigned int i = 0; i < entities.size(); i++)
	{
		entities[i].setColor(color);
	}
}

EntityCont::~EntityCont()
{

}