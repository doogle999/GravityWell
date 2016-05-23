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

		Entity(PVector position, PVector velocity, PVector acceleration);

		void setPose(PVector position, PVector velocity, PVector acceleration);

		void update(double deltaTime); // Milliseconds

		double getMass() const;
		void setMass(double mass);

		~Entity();
};

