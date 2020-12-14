#include "ANetworkNode.h"

ANetworkNode::~ANetworkNode() {
}

void ANetworkNode::addIncomingMessage(Message* aMessage, ANetworkNode* aPort) {
	incomingMessages.insert(new MessagePort(aMessage, aPort));
}
