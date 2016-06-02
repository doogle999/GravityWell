#include "GravityField.h"

GravityField::GravityField()
{
	
}

void GravityField::addEntity(Entity* addedEntity)
{
	entities.push_back(addedEntity);
}

PVector GravityField::getGravAccleration(PVector position)
{
	PVector gravAcceleration;
	gravAcceleration.setXY(0, 0);

	for (unsigned int i = 0; i < entities.size(); i++)
	{
		
	}

	return gravAcceleration;
}

GravityField::~GravityField()
{

}
