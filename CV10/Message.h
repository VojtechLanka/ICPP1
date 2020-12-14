#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

struct Message {
	int id;
	std::string addressOrigin;
	std::string addressTarget;
	std::string content;
	Message();
	Message(int aId, std::string aAddressOrigin, std::string aAddressTarget, std::string aContent);
};

#endif // !MESSAGE_H