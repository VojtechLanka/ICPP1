#ifndef MESSAGE_PORT_H
#define MESSAGE_PORT_H

#include "Message.h"

struct ANetworkNode;

struct MessagePort {
	Message* message;
	ANetworkNode* port;
	MessagePort();
	MessagePort(Message* aMessage, ANetworkNode* aPort);
};

#endif // !MESSAGE_PORT_H