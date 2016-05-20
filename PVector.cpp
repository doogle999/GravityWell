#include "PVector.h"

template<typename T>
PVector<T>::PVector()
{

}

template<typename T>
PVector<T>::PVector(T x, T y)
{
	this->x = x;
	this->y = y;
}

template<typename T>
PVector<T>::~PVector()
{

}

template<typename T>
PVector<T> PVector<T>::operator*(const double scalar)
{
	PVector<T> tempVector(this->x * scalar, this->y * scalar);

	return tempVector;
}

template class PVector<double>;