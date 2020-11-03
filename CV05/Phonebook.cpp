#include <stdexcept>
#include "Phonebook.h"

using namespace Model;
Phonebook::Phonebook() {
	first = NULL;
	current = NULL;
}

Phonebook::~Phonebook() {
	Node* current = first;
	Node* next = first->next;
	while (current != nullptr) {
		delete current;
		current = next;
		next = current->next;
	}
}

Node::Node(Entity::Person person) {
	this->data = person;
	this->next = nullptr;
}

void Phonebook::addPerson(Entity::Person person) {
	Node* tmp = new Node(person);
	tmp->next = NULL;

	if (first == NULL) {
		first = tmp;
		current = tmp;
	}
	else {
		current->next = tmp;
		current = current->next;
	}
}
std::string Phonebook::findPhoneNumber(std::string name) const {
	if (name.empty()) {
		throw std::invalid_argument("Name is empty");
	}

	Node* tmp = first;
	while (tmp != nullptr) {
		if (tmp->data.getName() == name) {
			return tmp->data.getPhone();
		}
		tmp = tmp->next;
	}

	throw std::logic_error(std::string("Could not find phone number of person with name: ") + name);
}

std::string Phonebook::findPhoneNumber(int id) const {
	if (id < 0) {
		throw std::invalid_argument(std::string("Id is negative: ") + std::to_string(id));
	}

	Node* tmp = first;
	while (tmp != nullptr) {
		if (tmp->data.getId() == id) {
			return tmp->data.getPhone();
		}
		tmp = tmp->next;
	}

	throw std::logic_error(std::string("Could not find phone number of person with id: ") + std::to_string(id));
}

