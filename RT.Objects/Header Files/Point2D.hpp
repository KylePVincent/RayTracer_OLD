#pragma once



#ifndef RT_OBJECTS_3DGEOMETRY_POINT2D
#define RT_OBJECTS_3DGEOMETRY_POINT2D



	#include <utility>
	//#include <cassert>
	#include <cmath>
	//#include <iostream>

	#include "RT.Objects\Header Files\NearlyEqual.hpp"



	class Point2D
	{
		public:
			long double x;
			long double y;



			#pragma region Contructors & Destructor

			/// <summary>
			/// </summary>
			Point2D();

			/// <summary>
			/// </summary>
			///
			/// <param name="p_x">
			/// </param>
			///
			/// <param name="p_y">
			/// </param>
			Point2D(const long double p_x, const long double p_y);

			/// <summary>
			/// </summary>
			///
			/// <param name="p_point2D">
			/// </param>
			Point2D(const Point2D& p_point2D);

			/// <summary>
			/// </summary>
			///
			/// <param name="p_point2D">
			/// </param>
			Point2D operator=(Point2D p_point2D); // EXCEPTION SAFE

			/// <summary>
			/// </summary>
			~Point2D();

			#pragma endregion Contructors & Destructor



			#pragma region Point Operations

			/// <summary>
			/// </summary>
			///
			/// <returns>
			/// Distance between this point and the origin.
			/// </returns>
			long double DistanceFromOrigin() const;

			//Vector2D VectorFromOrigin() const;

			/// <summary>
			/// </summary>
			///
			/// <param name="p_point2D">
			/// </param>
			///
			/// <returns>
			/// Distance between this point and point parameter passed.
			/// </returns>
			long double DistanceFromPoint(const Point2D& p_point2D) const;

			#pragma endregion Point Operations



		private:
			long double w;
	};



#endif