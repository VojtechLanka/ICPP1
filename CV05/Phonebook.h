#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include "Person.h"

namespace Model {
	struct Node {
		Node(Entity::Person data);
		virtual ~Node() {};
		Entity::Person data;
		Node* next;
	};

	class Phonebook {
	public:
		Phonebook();
		~Phonebook();
		void addPerson(Entity::Person person);
		std::string findPhoneNumber(std::string name) const;
		std::string findPhoneNumber(int id) const;
	private:
		Node* first, * current;
	};
}

#endif //PHONEBOOK_H