#pragma once
#ifndef PIPE_H
#define PIPE_H
#include <vector>
#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

enum Type {
	EAST_WEST,
	NORTH_SOUTH,
	NORTH_SOUTH_EAST_WEST,
	NOTHING,
	CLOSE,
	SOUTH_EAST_WEST
};

struct APipeNode;
struct IPipe {
	virtual ~IPipe() { }
	virtual const APipeNode* getPipeNode(int x, int y) const = 0;
	virtual bool isPipeOk() const = 0;
	virtual const int getSize() const = 0;
};

struct APipeNode {
	virtual ~APipeNode() { }
	virtual bool isConnected(const IPipe* pipe) const = 0;
	virtual const Type getType() const = 0;
	int x = 0;
	int y = 0;
};

class Pipe : public IPipe {
private:
	std::vector<std::vector<APipeNode*>> matrix = std::vector<std::vector<APipeNode*>>();
	int size = 0;
public:
	Pipe(const int aX);
	~Pipe();
	void addPipeNode(const int x, const int y, APipeNode* node);
	const APipeNode* getPipeNode(int x, int y) const;
	bool isPipeOk() const;
	const int getSize() const;
};

std::ifstream& operator >> (std::ifstream& output, Pipe& a);

class Node : public APipeNode {
private:
	Type type;
public:
	Node(const int aX, const int aY, Type aType);
	~Node();
	bool isConnected(const IPipe* pipe) const;
	const Type getType() const;
};

#endif // !PIPE_H
