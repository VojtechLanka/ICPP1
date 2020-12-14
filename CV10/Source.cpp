#define _CRTDBG_MAP_ALLOC
#define connectNodes(a,b) a->connect(b); b->connect(a)
#define connectNetwork(a,b,c) connectNodes(a,b); c->connect(a); c->connect(b)
#include "Hub.h"
#include "Network.h"
#include "Node.h"

using namespace std;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Network* network = new Network{ };

	Hub* hub1 = new Hub{ 8 };
	Hub* hub2 = new Hub{ 8 };
	Hub* hub3 = new Hub{ 8 };
	Hub* hub4 = new Hub{ 16 };
	Hub* hub5 = new Hub{ 24 };

	Node* node1 = new Node{ "a1" };
	Node* node2 = new Node{ "a2" };
	Node* node3 = new Node{ "a3" };

	connectNetwork(node1, hub1, network);
	connectNetwork(node2, hub3, network);
	connectNetwork(node3, hub5, network);
	connectNetwork(hub1, hub2, network);
	connectNetwork(hub2, hub3, network);
	connectNetwork(hub1, hub4, network);
	connectNetwork(hub4, hub5, network);
	connectNetwork(hub5, hub2, network);

	node1->prepMsgForSend("a2", "ping");
	node1->prepMsgForSend("a3", "ping");

	for (int i = 0; i < 100; i++) {
		network->moveAll();
	}

	return 0;
	_CrtDumpMemoryLeaks();
}

