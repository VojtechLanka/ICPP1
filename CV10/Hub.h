#ifndef HUB_H
#define HUB_H

#include "ANetworkNode.h"

struct Hub : ANetworkNode {
public:
	Hub(int aMaxConnectedNodes);
	~Hub();
	virtual void move() override;
	virtual void connect(ANetworkNode* aANetworkNode) override;
private:
	virtual void processIncomingMsg(MessagePort * aMessagePort) override;
	ANetworkNode** connectedNodes;
	int maxConnectedNodes;
	Queue<Message*> processedMessages;
};

#endif // !HUB_H