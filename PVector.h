#pragma once

class PVector
{
	private:
		double x; // X component
		double y; // Y component

	public:
		PVector();

		PVector(double x, double y);

		PVector operator*(const double scalar);

		~PVector();
};
