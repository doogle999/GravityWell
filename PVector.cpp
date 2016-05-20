#include "PVector.h"

PVector::PVector()
{

}

PVector::PVector(double x, double y)
{
	this->x = x;
	this->y = y;
}

PVector::~PVector()
{

}

PVector PVector::operator*(const double scalar)
{
	PVector tempVector(this->x * scalar, this->y * scalar);

	return tempVector;
}