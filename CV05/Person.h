#ifndef PERSON_H
#define PERSON_H

#include <string>

namespace Entity {
	class Person {
	public:
		Person();
		Person(int id, std::string name, std::string phone);
		virtual ~Person() {};
		int getId() const;
		std::string getName() const;
		std::string getPhone() const;
	private:
		int id;
		std::string name;
		std::string phone;
	};
}

#endif //PERSON_H