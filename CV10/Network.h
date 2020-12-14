#ifndef NETWORK_H
#define NETWORK_H

#include "ANetworkNode.h"

struct Network
{

public:
	static int getNewId();
	void connect(ANetworkNode* aANetworkNode);
	void moveAll();

private:
	static int idMessage;
	Queue<ANetworkNode*> networkNodes;
};

#endif // !NETWORK_H