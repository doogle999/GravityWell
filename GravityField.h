#pragma once

#include <cmath>
#include <vector>

#include "Entity.h"
#include "EntityCont.h"

#define GRAV_CONSTANT 6.67408e-11

class GravityField : public EntityCont
{
	private:

	public:
		GravityField();

		PVector getGravAcceleration(PVector position);

		void updateAll(double deltaTime);

		~GravityField();
};

