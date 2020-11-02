#include <string>
#include <iostream>
#include "Person.h"
#include "Phonebook.h"

int main() {
	Entity::Person person1 = Entity::Person(1, "Ladislav Vlasaty", "375 701 356");
	Entity::Person person2 = Entity::Person(2, "Michal Dousa", "471 340 836");

	Model::Phonebook* phonebook = new Model::Phonebook();
	phonebook->addPerson(person1);
	phonebook->addPerson(person2);

	try {
		std::cout << "Number of person with id 2: " << phonebook->findPhoneNumber(2) << std::endl;
		std::cout << "Number of person with name Ladislav Vlasaty: " << phonebook->findPhoneNumber("Ladislav Vlasaty") << std::endl;

		std::cout << "Number of person with id -2: " << phonebook->findPhoneNumber(-2) << std::endl;
		//std::cout << "Number of person with name Lad: " << phonebook->findPhoneNumber("Lad") << std::endl;
		//std::cout << "Number of person with name Lukas Duffek: " << phonebook->findPhoneNumber("Lukas Duffek") << std::endl;
	}
	catch (const std::exception& exc) {
		std::cout << "Exception occured: " << std::endl;
		std::cerr << exc.what();
		putchar('\n');
	}
}