#include "Pipe.h"

Node::Node(const int aX, const int aY, Type aType) {
	if (aX < 0 && aY < 0) {
		throw std::invalid_argument("Index out ouf bounds.");
	}
	x = aX;
	y = aY;
	type = aType;
}

Node::~Node() {
}

bool Node::isConnected(const IPipe* pipe) const {
	switch (getType()) {
	case EAST_WEST:
		if (y == 0 || y == pipe->getSize() - 1 || pipe->getPipeNode(x, y - 1)->getType() == NOTHING ||
			pipe->getPipeNode(x, y + 1)->getType() == NOTHING) {
			return false;
		}
		break;
	case NORTH_SOUTH:
		if (x == 0 || x == pipe->getSize() - 1 || pipe->getPipeNode(x - 1, y)->getType() == NOTHING ||
			pipe->getPipeNode(x + 1, y)->getType() == NOTHING) {
			return false;
		}
		break;
	case NORTH_SOUTH_EAST_WEST:
		if (y == 0 || y == pipe->getSize() - 1 || x == 0 || x == pipe->getSize() - 1 ||
			pipe->getPipeNode(x, y - 1)->getType() == NOTHING || pipe->getPipeNode(x, y + 1)->getType() == NOTHING ||
			pipe->getPipeNode(x - 1, y)->getType() == NOTHING || pipe->getPipeNode(x + 1, y)->getType() == NOTHING) {
			return false;
		}
		break;
	case SOUTH_EAST_WEST:
		if (y == 0 || y == pipe->getSize() - 1 || x == pipe->getSize() - 1 || pipe->getPipeNode(x, y - 1)->getType() == NOTHING ||
			pipe->getPipeNode(x, y + 1)->getType() == NOTHING || pipe->getPipeNode(x + 1, y)->getType() == NOTHING) {
			return false;
		}
		break;
	case NOTHING:
		return false;
		break;
	default:
		throw "Unknow pipe type.";
		break;
	}
	return true;
}

const Type Node::getType() const {
	return type;
}


Pipe::Pipe(const int aSize) {
	if (aSize < 1) {
		throw std::invalid_argument("Invalid size.");
	}
	size = aSize;
	for (size_t i = 0; i < aSize; i++) {
		matrix.insert(matrix.begin(), std::vector<APipeNode*>());
	}
}

Pipe::~Pipe() {
}

void Pipe::addPipeNode(const int x, const int y, APipeNode* Node) {
	matrix.at(x).insert(matrix.at(x).end(), Node);
}

const APipeNode* Pipe::getPipeNode(int x, int y) const {
	if (matrix.size() < x || matrix.at(x).size() < y || x < 0 || y < 0) {
		throw std::invalid_argument("Index out of range.");
	}

	return matrix.at(x).at(y);
}

bool Pipe::isPipeOk() const {
	for (int i = 0; i < size; i++) {
		std::vector<APipeNode*> row = matrix.at(i);
		for (int j = 0; j < size; j++) {
			if (row.at(j)->isConnected(this) == false) {
				return false;
			}
		}
	}
	return true;
}

const int Pipe::getSize() const {
	return size;
}

std::ifstream& operator >> (std::ifstream& input, Pipe& a) {
	char c = 0;
	APipeNode* newNode = nullptr;
	int xNext = -1;

	std::string line;

	while (std::getline(input, line)) {
		int i = 0;
		++xNext;
		int yNext = 0;

		for (i = 0; i < line.length(); i++) {
			c = line.at(i);
			switch (c) {
			case '-':
				newNode = new Node(xNext, yNext, EAST_WEST);
				break;
			case 'I':
				newNode = new Node(xNext, yNext, NORTH_SOUTH);
				break;
			case '+':
				newNode = new Node(xNext, yNext, NORTH_SOUTH_EAST_WEST);
				break;
			case 'O':
				newNode = new Node(xNext, yNext, NOTHING);
				break;
			case 'T':
				newNode = new Node(xNext, yNext, SOUTH_EAST_WEST);
				break;
			}
			a.addPipeNode(xNext, yNext++, newNode);
		}
	}

	return input;
}
