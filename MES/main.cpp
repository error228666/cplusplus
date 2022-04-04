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
void make_students(std::vector<Student>& students, const char** NAMES, const int count_of_students)
{
	for (int i = 0; i < count_of_students; i++)
	{
		Student student = Student(NAMES[i]);
		students.insert(students.end(), student);
	}
}

void students_doing_eqs_from_file(const char* filename, std::vector<Student> students, Teacher& teacher)
{
	std::ifstream file(filename);
	for (int i = 0; i < count_of_eqs; ++i)
	{
		Quadratic_Equation eq;
		file >> eq.a >> eq.b >> eq.c;
		Solve solve;
		for (int i = 0; i < count_of_students; ++i)
		{
			students.at(i).send_to_teacher(eq, teacher);
		}
	}
	file.close();

}

int main()
{
	srand(time(0));

	std::vector<Student> students;
	
	make_students(students, NAMES, count_of_students);
	
	make_eqs("eqs.txt");
	
	Teacher teacher;

	students_doing_eqs_from_file("eqs.txt", students, teacher);

	teacher.check_letters();

	teacher.print_results();


}