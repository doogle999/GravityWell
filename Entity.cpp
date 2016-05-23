#include "Entity.h"

Entity::Entity()
{

}

Entity::Entity(PVector position, PVector velocity, PVector acceleration)
{
	this->position = position;
	this->velocity = velocity;
	this->acceleration = acceleration;
}

void Entity::setPose(PVector position, PVector velocity, PVector acceleration)
{
	this->position = position;
	this->velocity = velocity;
	this->acceleration = acceleration;
}

void Entity::update(double deltaTime)
{
	position = position + (velocity * (deltaTime / 1000));
	velocity = velocity + (acceleration * (deltaTime / 1000));
}

double Entity::getMass() const { return this->mass; }
void Entity::setMass(double mass) { this->mass = mass; }

Entity::~Entity()
{

}
