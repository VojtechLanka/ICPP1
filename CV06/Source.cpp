#include <string>
#include <iostream>
#include "GrowingContainer.h"

void printGrowingContainerInformation(GrowingContainer<std::string, 5, 2> * growingContainer) {
	std::cout << "Current Count: " << growingContainer->count() << std::endl;
	std::cout << "Is there free space: " << growingContainer->isFreeSpaceInArray() << std::endl;
}

void printGrowingContainerItems(GrowingContainer<std::string, 5, 2> * growingContainer) {
	std::cout << "Current items: " << std::endl;
	for (int i = 0; i < growingContainer->count(); i++)
	{
		std::cout << (*growingContainer)[i] << std::endl;
	}
}

int main() {
	GrowingContainer<std::string, 5, 2> growingContainer = GrowingContainer<std::string, 5, 2>();
	
	std::cout << "Adding 10 strings" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		growingContainer.add("String number: " + std::to_string(i));
	}

	printGrowingContainerInformation(&growingContainer);

	std::cout << "Adding 1 string" << std::endl;
	growingContainer.add("String number: " + std::to_string(growingContainer.count() + 1));

	printGrowingContainerInformation(&growingContainer);
	printGrowingContainerItems(&growingContainer);

	std::cout << "Removing item on index 6" << std::endl;
	growingContainer.remove(6);

	printGrowingContainerItems(&growingContainer);

	std::cout << "Adding item to index 8" << std::endl;
	growingContainer.addTo(8, "New string");

	printGrowingContainerItems(&growingContainer);

	return 0;
}