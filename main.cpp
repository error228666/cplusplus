#include "MES.hpp"

const char* NAMES[8] = { "Eroshkin Ivan", "Rubanova Valeria", "Anishenko Mikhail", "Petroshenko Artem", "Boitsov Anton", "Tronyagina Aleksandra", "Krasnikov Roman", "Popov Pavel" };
const int count_of_students = 8;
const int count_of_eqs = 100;

void make_eqs(const char* filename)
{
	std::ofstream file(filename);
	for (int i = 0; i < count_of_eqs; ++i)
	{
		file << rand() % 100 + 1 << " " << rand() % 100 + 1 << " " << rand() % 100 + 1  << std::endl;
	}
	file.close();
}
std::vector<std::unique_ptr<Student>> GenerateStudents(const size_t count) noexcept 
{
	std::vector<std::unique_ptr<Student>> res;
	for (int i = 0; i < count; i++)
	{
		switch (rand() % 3) {
		case 0:
			res.push_back(std::make_unique<Bad_Student>(NAMES[i]));
			break;
		case 1:
			res.push_back(std::make_unique<Middle_Student>(NAMES[i]));
			break;
		case 2:
			res.push_back(std::make_unique<Good_Student>(NAMES[i]));
			break;
		}
	}
	return res;
}

void students_doing_eqs_from_file(const char* filename, std::vector<std::unique_ptr<Student>>& students, Teacher& teacher)
{
	std::ifstream file(filename);
	for (int i = 0; i < count_of_eqs; ++i)
	{
		Quadratic_Equation eq;
		file >> eq.a >> eq.b >> eq.c;
		Solve solve;
		for (int i = 0; i < count_of_students; ++i)
		{
			students.at(i)->send_to_teacher(eq, teacher);
		}
	}
	file.close();

}

int main()
{
	srand(time(0));

	std::vector<std::unique_ptr<Student>> students = GenerateStudents(8);
	
	make_eqs("eqs.txt");
	
	Teacher teacher;

	students_doing_eqs_from_file("eqs.txt", students, teacher);

	teacher.check_letters();

	teacher.print_results();


}