#pragma once

#include <vector>

#include "Entity.h"

class EntityCont
{
	protected:
		std::vector<Entity> entities;

		sf::Color color;

	public:
		EntityCont();

		void addEntity(double positionX, double positionY, double velocityX, double velocityY, double accelerationX, double accelerationY, double mass);

		void updateAll(double deltatime); // Milliseconds

		std::vector<sf::CircleShape> getShapes();

		void setColor(sf::Color color);

		~EntityCont();
};

