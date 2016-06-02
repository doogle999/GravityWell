#pragma once

#include <math.h>
#include <vector>

#include "Entity.h"

const double GRAV_CONSTANT = 6.67408e-11;

class GravityField
{
	private:
		std::vector<Entity*> entities;

	public:
		GravityField();

		void addEntity(Entity* addedEntity);

		PVector getGravAccleration(PVector position);

		~GravityField();
};

