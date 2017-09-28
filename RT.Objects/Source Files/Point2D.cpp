#include "RT.Objects\Header Files\Point2D.hpp"



#pragma region Constructors & Desctructor

Point2D::Point2D()
{
	x = 0.0L;
	y = 0.0L;

	w = 1.0L;
}

Point2D::Point2D(const long double p_x, const long double p_y)
{
	x = p_x;
	y = p_y;

	w = 1.0L;
}

Point2D::Point2D(const Point2D& p_point2D)
{
	x = p_point2D.x;
	y = p_point2D.y;

	w = p_point2D.w;
}

Point2D Point2D::operator=(Point2D p_point2D) // EXCEPTION SAFE
{
	std::swap(x, p_point2D.x);
	std::swap(y, p_point2D.y);

	std::swap(w, p_point2D.w);

	return *this;
}

Point2D::~Point2D()
{
}

#pragma endregion Constructors & Destructor



#pragma region Public Methods

#pragma region Point Operations

long double Point2D::DistanceFromOrigin() const
{
	//return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
	return std::sqrt((x*x) + (y*y));
}

/*
Vector2D Point2D::VectorFromOrigin() const
{
}
 */

long double Point2D::DistanceFromPoint(const Point2D& p_point2D) const
{
	//return std::sqrt(std::pow((p_point2D.x - x), 2.0L) + std::pow((p_point2D.y - y), 2.0L));
	return std::sqrt(((p_point2D.x - x) * (p_point2D.x - x)) + ((p_point2D.y - y) * (p_point2D.y - y)));
}

#pragma endregion Point Operations



#pragma endregion Public Methods



#pragma region Private Methods
#pragma endregion Private Methods