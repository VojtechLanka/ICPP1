#include "Node.h"
#include "Network.h"
#include <iostream>

using namespace std;

int Network::idMessage = 0;

Node::Node(std::string aAddress) {
	address = aAddress;
}

Node::~Node() { }

void Node::prepMsgForSend(std::string aTarget, std::string aContent) {
	Message* newMassage = new Message(Network::getNewId(), address, aTarget, aContent);
	outgoingMessages.insert(newMassage);
}

void Node::move() {
	while (!outgoingMessages.isEmpty()) {
		Message* messageToSend = outgoingMessages.pop();
		connectedNode->addIncomingMessage(messageToSend, this);
	}
	while (!incomingMessages.isEmpty()) {
		MessagePort * incomingMessage = incomingMessages.pop();
		processIncomingMsg(incomingMessage);
	}
}

void Node::connect(ANetworkNode* aANetworkNode) {
	connectedNode = aANetworkNode;
}

void Node::processIncomingMsg(MessagePort* aMessagePort) {
	if (aMessagePort->message->addressTarget != address) {
		return;
	}

	cout << address << " RECV id: " << aMessagePort->message->id << " src: " << aMessagePort->message->addressOrigin << " msg:" << aMessagePort->message->addressTarget << endl;

	if (aMessagePort->message->content == "ping") {
		prepMsgForSend(aMessagePort->message->addressOrigin, "pong");
	}
}
