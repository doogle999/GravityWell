#pragma once

#include <cmath>
#include <vector>

#include "Entity.h"

#define GRAV_CONSTANT 6.67408e-11

class GravityField // A box for entities that also has gravity
{
	private:
		std::vector<Entity*> entities;

	public:
		GravityField();

		void addEntity(Entity* addedEntity);

		PVector getGravAcceleration(PVector position);

		void update(double deltaTime); // Milliseconds, updates all entities with gravity as acceleration

		~GravityField();
};

