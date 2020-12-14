#include "Hub.h"

Hub::Hub(int aMaxConnectedNodes) {
	maxConnectedNodes = aMaxConnectedNodes;
	connectedNodes = new ANetworkNode * [maxConnectedNodes];
	for (size_t i = 0; i < maxConnectedNodes; i++) {
		connectedNodes[i] = nullptr;
	}
}

Hub::~Hub() {
	delete[] connectedNodes;
}

void Hub::move() {
	while (!incomingMessages.isEmpty()) {
		MessagePort * messagePort = incomingMessages.pop();
		processIncomingMsg(messagePort);
	}
}

void Hub::connect(ANetworkNode* aANetworkNode) {
	for (int i = 0; i < maxConnectedNodes; i++) {
		if (connectedNodes[i] == nullptr) {
			connectedNodes[i] = aANetworkNode;
			break;
		}
	}
}

void Hub::processIncomingMsg(MessagePort * aMessagePort) {
	if (processedMessages.contains(aMessagePort->message)) {
		return;
	}

	for (int i = 0; i < maxConnectedNodes; i++) {
		if (connectedNodes[i] != nullptr) {
			if (connectedNodes[i] != aMessagePort->port) {
				connectedNodes[i]->addIncomingMessage(aMessagePort->message, this);
			}
		}
	}
	processedMessages.insert(aMessagePort->message);
}
