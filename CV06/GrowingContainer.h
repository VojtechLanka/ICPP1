#ifndef GROWING_CONTAINER_H
#define GROWING_CONTAINER_H
#include <iostream>

template <typename DataType, int initSize = 5, int growingCoefficient = 2>
class GrowingContainer {
public:
	GrowingContainer();
	~GrowingContainer();
	bool isFreeSpaceInArray() const;
	void add(const DataType& data);
	DataType& operator [](int index);
	DataType operator [](int index)const;
	unsigned int count() const;
	void addTo(int index, const DataType& data);
	void remove(int index);
private:
	DataType* dataArray;
	unsigned arraySize;
	unsigned validNodesCount;
	void expandArray();
};

template <typename DataType, int initSize, int growingCoefficient>
GrowingContainer<DataType, initSize, growingCoefficient>::GrowingContainer()
{
	arraySize = initSize;

	dataArray = new DataType[initSize];
	arraySize = initSize;
	validNodesCount = 0;
}
template <typename DataType, int initSize, int growingCoefficient>
GrowingContainer<DataType, initSize, growingCoefficient>::~GrowingContainer()
{
	delete[] dataArray;
}

template<typename DataType, int initSize, int growingCoefficient>
bool GrowingContainer<DataType, initSize, growingCoefficient>::isFreeSpaceInArray() const
{
	return validNodesCount < arraySize;
}

template<typename DataType, int initSize, int growingCoefficient>
void GrowingContainer<DataType, initSize, growingCoefficient>::add(const DataType& data)
{
	if (!isFreeSpaceInArray())
	{
		expandArray();
	}
	dataArray[validNodesCount] = data;
	validNodesCount++;
}

template<typename DataType, int initSize, int growingCoefficient>
inline DataType& GrowingContainer<DataType, initSize, growingCoefficient>::operator [](int index)
{
	if (index >= validNodesCount)
	{
		throw std::out_of_range("Index is out of range");
	}
	return dataArray[index];
}

template<typename DataType, int initSize, int growingCoefficient>
inline DataType GrowingContainer<DataType, initSize, growingCoefficient>::operator [](int index) const
{
	if (index >= validNodesCount)
	{
		throw std::out_of_range("Index is out of range");
	}
	return dataArray[index];
}

template<typename DataType, int initSize, int growingCoefficient>
unsigned int GrowingContainer<DataType, initSize, growingCoefficient>::count() const
{
	return  validNodesCount;
}

template<typename DataType, int initSize, int growingCoefficient>
void GrowingContainer<DataType, initSize, growingCoefficient>::addTo(int index, const DataType& data)
{
	if (index >= validNodesCount)
	{
		throw std::out_of_range("Index is out of range");
	}
	if (!isFreeSpaceInArray())
	{
		expandArray();
	}
	DataType oldData = dataArray[index];
	dataArray[index] = data;

	for (int i = index; i < validNodesCount; i++)
	{
		DataType tmp = dataArray[i + 1];
		dataArray[i + 1] = oldData;
		oldData = tmp;
	}
	validNodesCount++;
}

template<typename DataType, int initSize, int growingCoefficient>
void GrowingContainer<DataType, initSize, growingCoefficient>::remove(int index)
{
	if (index >= validNodesCount)
	{
		throw std::out_of_range("Index is out of range");
	}

	for (int i = index; i < validNodesCount; i++)
	{
		dataArray[i] = dataArray[i + 1];
	}
	validNodesCount--;
}

template<typename DataType, int initSize, int growingCoefficient>
void GrowingContainer<DataType, initSize, growingCoefficient>::expandArray()
{
	arraySize = arraySize * growingCoefficient;
	DataType* newArray = new DataType[arraySize];
	for (int i = 0; i < (arraySize / growingCoefficient); i++)
	{
		newArray[i] = dataArray[i];
	}
	delete[] dataArray;
	dataArray = newArray;
}

#endif // !GROWING_CONTAINER_H