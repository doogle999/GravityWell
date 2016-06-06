#include "GravityField.h"

GravityField::GravityField()
{
	color = sf::Color::White;
}

PVector GravityField::getGravAcceleration(PVector position)
{
	PVector gravAcceleration;
	gravAcceleration.setXY(0, 0);
	
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		double radius = pow(position.getX() - entities[i].getPosition().getX(), 2) + pow(position.getY() - entities[i].getPosition().getY(), 2);
		if (radius > 0)
		{
			radius = pow(radius, 0.5);

			double scaleMass = 1;
			if (entities[i].getRadius() > radius)
			{
				scaleMass = pow(radius / entities[i].getRadius(), 3);
			}

			gravAcceleration.setXY(
				gravAcceleration.getX() + (GRAV_CONSTANT * scaleMass * entities[i].getMass() * -(position.getX() - entities[i].getPosition().getX()) / (radius * radius * radius)),
				gravAcceleration.getY() + (GRAV_CONSTANT * scaleMass * entities[i].getMass() * -(position.getY() - entities[i].getPosition().getY()) / (radius * radius * radius)));
		}
	}

	return gravAcceleration;
}

void GravityField::updateAll(double deltaTime)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		entities[i].setAcceleration(getGravAcceleration(entities[i].getPosition()));

		entities[i].update(deltaTime);
	}
}

GravityField::~GravityField()
{

}
