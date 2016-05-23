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

		PVector operator+(const PVector& addedVector);

		double getX() const;
		void setX(double x);

		double getY() const;
		void setY(double y);

		~PVector();
};