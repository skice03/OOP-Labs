#include <iostream>
#include <list>

using namespace std;

typedef struct PERSON
{
	int age;
	string name;
} Person;

struct AgeCompare
{
	bool operator()(Person a, Person b)
	{
		return a.age > b.age;
	}
};

struct NameCompare
{
	bool operator()(Person a, Person b)
	{
		return a.name < b.name;
	}
};

int main()
{
	Person a, b, c, d;
	a.name = "Marinel";
	a.age = 20;
	b.name = "Bancu";
	b.age = 21;
	c.name = "Barbu";
	c.age = 19;
	d.name = "Dani";
	d.age = 23;

	list<Person> persons = {a, b, c, d};

	persons.sort(AgeCompare());

	cout << "By age\n";
	for (auto elem : persons)
		cout << elem.name << " " << elem.age << endl;

	cout << "\n\nBy name\n";

	persons.sort(NameCompare());

	for (auto elem : persons)
		cout << elem.name << " " << elem.age << endl;
	return 0;
}
