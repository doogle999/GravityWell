#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

#include "PVector.h"

#define PI 3.14159265358979323846

class Entity
{
	private:
		PVector position;
		PVector velocity;
		PVector acceleration;

		double mass;
		static const double density;
		
		sf::CircleShape shape;

	public:
		Entity();

		Entity(PVector position, PVector velocity, PVector acceleration, double mass, sf::Color color);

		void setPose(PVector position, PVector velocity, PVector acceleration);
		void setPose(double positionX, double positionY, double velocityX, double velocityY, double accelerationX, double accelerationY);

		void setPosition(PVector position);
		void setPosition(double positionX, double positionY);
		PVector getPosition() const;

		void setVelocity(PVector velocity);
		void setVelocity(double velocityX, double velocityY);
		PVector getVelocity() const;

		void setAcceleration(PVector acceleration);
		void setAcceleration(double accelerationX, double accelerationY);
		PVector getAcceleration() const;

		void update(double deltaTime); // Milliseconds

		sf::CircleShape getShape() const;

		void setMass(double mass);
		double getMass() const;

		void setColor(sf::Color color);

		~Entity();
};

