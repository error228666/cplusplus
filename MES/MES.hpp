#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <ctime>

class Solve 
{
public:
	double x1;
	double x2;
	int count_of_x;
	
};

class Quadratic_Equation 
{	
public:
	double a;
	double b;
	double c;
	

	Solve good_solve()
	{
		Solve result;
		double d = this->b * this->b - 4 * this->a * this->c;
		if (d == 0)
		{
			result.count_of_x = 1;
			result.x1 = -this->b / (2 * this->a);
			return result;
		}
		if (d < 0)
		{
			result.count_of_x = 0;
			return result;
		}
		if (d > 0)
		{
			result.count_of_x = 2;
			result.x1 = (-this->b + sqrt(d)) / (2 * this->a);
			result.x2 = (-this->b - sqrt(d)) / (2 * this->a);
			return result;
		}
	}

	bool check_solve(const Solve solve)
	{
		Solve good = this->good_solve();
		if (solve.count_of_x != good.count_of_x)
			return false;
		else
		{
			if (good.count_of_x == 0)
				return true;
			if (good.count_of_x == 1)
			{
				if (solve.x1 == good.x1)
					return true;
				else
				{
					return false;

					//std::cout << solve.x1 << " " << good.x1 << this->number << std::endl;
				}
			}
			if (good.count_of_x == 2)
			{
				if (solve.x1 == good.x1 && solve.x2 == good.x2)
					return true;
				else
				{
					//std::cout << solve.x1 << " " << good.x1 << std::endl<<solve.x2 << " " << good.x2 << this->number << std::endl;
					return false;
				}
			}
		}
	}
	
};

class Letter
{
public:
	Quadratic_Equation qe;
	Solve solve;
	std::string name;
	Letter(const Quadratic_Equation qe, const Solve solve, const std::string name)
	{
		this->qe = qe;
		this->name = name;
		this->solve = solve;
	}
};
class Teacher
{

	class Result
	{
	public:
		std::string name;
		int count_of_good_solves;

	};
	std::vector<Result> results;

public:
	std::queue<Letter> letters;
	void check_letters()
	{
		while (!letters.empty())
		{
			bool is_students_name_in_result = false;
			for (int i = 0; i < results.size(); ++i)
			{
				if (results.at(i).name == letters.front().name)
				{
					is_students_name_in_result = true;
					results.at(i).count_of_good_solves += letters.front().qe.check_solve(letters.front().solve);
				}
			}
			if (!is_students_name_in_result)
			{
				Result result;
				result.name = letters.front().name;
				result.count_of_good_solves = letters.front().qe.check_solve(letters.front().solve);
				results.insert(results.end(), result);
			}
			letters.pop();
		}
	}
	void print_results()
	{
		for (int i = 0; i < this->results.size(); ++i)
		{
			std::cout << results.at(i).name << " " << results.at(i).count_of_good_solves << std::endl;
		}
	}
};

class Student 
{

	enum class Type
	{
		GOOD,
		MIDDLE,
		BAD
	};
	Type type;

	Solve bad_solve()
	{
		//srand(time(NULL));
		Solve result;
		result.count_of_x = rand() % 3;
		if (result.count_of_x == 0)
			return result;
		if (result.count_of_x == 1)
		{
			result.x1 = rand() % 100;
			return result;
		}
		if (result.count_of_x == 2)
		{
			result.x2 = rand() % 100;
			result.x1 = rand() % 100;
			return result;
		}
	}

	Solve students_solve(Quadratic_Equation qe)
	{
		//srand(time(NULL));
		Solve result;
		if (this->type == Type::GOOD)
		{
			result = qe.good_solve();
			return result;
		}
		if (this->type == Type::MIDDLE)
		{
			bool chance = (bool)(rand() % 2);
			if (chance)
			{
				result = qe.good_solve();
				return result;
			}
			else
			{
				result = this->bad_solve();
				return result;
			}
		}
		if (this->type == Type::BAD)
		{
			result.count_of_x = 1;
			result.x1 = 0;
			return result;
		}
	}

public:
	std::string name;

	Student(const char* name)
	{
		//srand(time(NULL));
		this->type = (Type)(rand() % 3);
		this->name = name;
	}
	
	void send_to_teacher(const Quadratic_Equation eq, Teacher& teacher)
	{
		Solve solve = this->students_solve(eq);
		Letter letter(eq, solve, this->name);
		teacher.letters.push(letter);
	}
};

