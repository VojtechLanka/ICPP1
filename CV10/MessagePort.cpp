#include "MessagePort.h"

MessagePort::MessagePort() {
	message = new Message();
	port = nullptr;
}

MessagePort::MessagePort(Message* aMessage, ANetworkNode* aPort) {
	message = aMessage;
	port = aPort;
}
