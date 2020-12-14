#pragma once
#ifndef A_NETWORK_NODE_H
#define A_NETWORK_NODE_H

#include "Queue.h"
#include "Message.h"
#include "MessagePort.h"

struct ANetworkNode {
public:
	virtual ~ANetworkNode();
	void addIncomingMessage(Message* aMessage, ANetworkNode* aPort);
	virtual void move() = 0;
	virtual void connect(ANetworkNode* aNetworkNode) = 0;
protected:
	virtual void processIncomingMsg(MessagePort * aMessagePort) = 0;
	Queue<MessagePort*> incomingMessages;
};

#endif // !A_NETWORK_NODE_H