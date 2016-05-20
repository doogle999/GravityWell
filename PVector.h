#pragma once

template<typename T>
class PVector
{
	private:
		T x; // X component
		T y; // Y component

	public:
		PVector();

		PVector(T x, T y);

		PVector<T> operator*(const double scalar);

		~PVector();
};
