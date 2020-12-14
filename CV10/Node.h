#ifndef NODE_H
#define NODE_H

#include "ANetworkNode.h"

struct Node : ANetworkNode {
public:
	Node(std::string adresa);
	~Node();
	void prepMsgForSend(std::string aTarget, std::string aContent);
	virtual void move() override;
	virtual void connect(ANetworkNode* aNetworkNode) override;
private:
	virtual void processIncomingMsg(MessagePort* aMessagePort) override;
	std::string address;
	ANetworkNode* connectedNode;
	Queue<Message*> outgoingMessages;
};

#endif // !NODE_H