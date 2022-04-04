#include "TQE.hpp"


void main(void)
{
	double a, b, c;
	double x1, x2;
	int count_of_x;
	
	input(a, b, c);

	find_x(a, b, c, count_of_x, x1, x2);
	
	output(count_of_x, x1, x2);
}