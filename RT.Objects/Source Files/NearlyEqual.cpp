#include "RT.Objects\Header Files\NearlyEqual.hpp"



bool NearlyEqual(long double p_number1, long double p_number2, long double p_epsilon)
{
	const long double absNumber1 = std::abs(p_number1);
	const long double absNumber2 = std::abs(p_number2);

	const long double difference = std::abs(absNumber1 - absNumber2);

	if (absNumber1 == absNumber2)
	{
		return true;
	}
	else if ((absNumber1 * absNumber2) == 0.0L)
	{
		//return (difference < (std::pow(p_epsilon, 2.0L)));
		return (difference < (p_epsilon * p_epsilon));
	}
	else
	{
		return ((difference / (absNumber1 + absNumber2)) < p_epsilon);
	}
}