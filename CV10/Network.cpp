#include "Network.h"

int Network::getNewId() {
	return idMessage++;
}

void Network::connect(ANetworkNode* aANetworkNode) {
	if (!networkNodes.contains(aANetworkNode)) {
		networkNodes.insert(aANetworkNode);
	}
}

void Network::moveAll() {
	networkNodes.processNode([](ANetworkNode* aNetworkNode) {
		aNetworkNode->move();
		});
}
