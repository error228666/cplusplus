#include "TQE.hpp"


void input(double& a, double& b, double& c)
{
	cout << "Please, input ratios\na: ";
	cin >> a;
	cout << "\nb:";
	cin >> b;
	cout << "\nc:";
	cin >> c;
	cout << "\nc:";

}

void output(int count_of_x, double x1, double x2)
{
	switch (count_of_x)
	{
	case 0:
		cout << "no roots(" << endl;
		return;
		break;
	case 1:
		cout << "x = " << x1 << endl;
		break;
	case 2:
		cout << "x = [" << x1 << ", "<< x2 <<"]" << endl;
		break;
	default:
		break;
	}
}
void find_x(double a, double b, double c, int& count_of_x, double& x1, double& x2)
{

	if (a == 0 )
	{
		if (b == 0)
			count_of_x = 0;

		else
		{
			count_of_x = 1;
			x1 = -c / b;
		}
		return;
	}
	double disc = b * b - 4 * a * c;
	
	if (disc < 0)
	{
		count_of_x = 0;
		return;
	}
	if (disc == 0)
	{
		
		x1 = (-b) / (2 * a);
		count_of_x = 1;
		return;
	}
	if (disc > 0)
	{
		x1 = (-b - sqrt(disc)) / (2 * a);
		x2 = (-b + sqrt(disc)) / (2 * a);
		count_of_x = 2;
		return;
	}
}