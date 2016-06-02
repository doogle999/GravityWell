#include "Entity.h"

Entity::Entity()
{

}

Entity::Entity(PVector position, PVector velocity, PVector acceleration, double mass)
{
	this->position = position;
	this->velocity = velocity;
	this->acceleration = acceleration;
	this->mass = mass;
}

void Entity::setPose(PVector position, PVector velocity, PVector acceleration)
{
	this->position = position;
	this->velocity = velocity;
	this->acceleration = acceleration;
}

void Entity::setPose(double positionX, double positionY, double velocityX, double velocityY, double accelerationX, double accelerationY)
{
	position.setXY(positionX, positionY);
	velocity.setXY(velocityX, velocityY);
	acceleration.setXY(accelerationX, accelerationY);
}

void Entity::setPosition(PVector position) { this->position = position; }
void Entity::setPosition(double positionX, double positionY) { this->position.setXY(positionX, positionY); }
PVector Entity::getPosition() const { return this->position; }

void Entity::setVelocity(PVector velocity) { this->velocity = velocity; }
void Entity::setVelocity(double velocityX, double velocityY) { this->velocity.setXY(velocityX, velocityY); }
PVector Entity::getVelocity() const { return this->velocity; }

void Entity::setAcceleration(PVector acceleration) { this->acceleration = acceleration; }
void Entity::setAcceleration(double accelerationX, double accelerationY) { this->acceleration.setXY(accelerationX, accelerationY); }
PVector Entity::getAcceleration() const { return this->acceleration; }

void Entity::update(double deltaTime)
{
	position = position + (velocity * (deltaTime / 1000));
	velocity = velocity + (acceleration * (deltaTime / 1000));
}

void Entity::setMass(double mass) { this->mass = mass; }
double Entity::getMass() const { return this->mass; }

Entity::~Entity()
{

}
