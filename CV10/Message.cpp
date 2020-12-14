#include "Message.h"

Message::Message() {
	id = -1;
	addressOrigin = "";
	addressTarget = "";
	content = "";
}

Message::Message(int aId, std::string aAddressOrigin, std::string aAddressTarget, std::string aContent) {
	id = aId;
	addressOrigin = aAddressOrigin;
	addressTarget = aAddressTarget;
	content = aContent;
}