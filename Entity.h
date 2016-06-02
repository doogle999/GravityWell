#pragma once

#include "PVector.h"

class Entity
{
	private:
		PVector position;
		PVector velocity;
		PVector acceleration;
		double mass;

	public:
		Entity();

		Entity(PVector position, PVector velocity, PVector acceleration, double mass);

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

		void render();

		void setMass(double mass);
		double getMass() const;

		~Entity();
};

