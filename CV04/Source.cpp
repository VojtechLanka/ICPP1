#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "IComparable.h"
#include "MyTime.h"
#include "MyDate.h"
#include "MyDateTime.h"

enum class CompareType { Time, Date, DateTime };

void sortArray(IComparable** arr, int size, CompareType type) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			int result = 0;
			switch (type)
			{
			case CompareType::Time:
				result = ((MyTime*)arr[j + 1])->compareTo(arr[j]);
				break;
			case CompareType::Date:
				result = ((MyDate*)arr[j + 1])->compareTo(arr[j]);
				break;
			case CompareType::DateTime:
				result = ((MyDateTime*)arr[j + 1])->compareTo(arr[j]);
				break;
			}
			if (result == -1) {
				IComparable* tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void outputArray(IComparable** vArray, int size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << vArray[i]->toString() << std::endl;

	}
}

int main() {
	srand(time(NULL));
	IComparable** timeArray = new IComparable * [10];
	IComparable** dateArray = new IComparable * [10];
	IComparable** dateTimeArray = new IComparable * [10];

	for (size_t i = 0; i < 10; i++)
	{
		MyTime* time = new MyTime(rand() % 22 + 1, rand() % 59, rand() % 59);
		MyDate* date = new MyDate(rand() % 30, rand() % 12, (rand() % 20) + 2000);
		timeArray[i] = time;
		dateArray[i] = date;
		dateTimeArray[i] = new MyDateTime(date, time);
	}
	std::cout << "Unsorted Time" << std::endl;
	outputArray(timeArray, 10);
	sortArray(timeArray, 10, CompareType::Time);
	std::cout << std::endl;
	std::cout << "Sorted Time" << std::endl;
	outputArray(timeArray, 10);

	std::cout << "---------------" << std::endl;

	std::cout << "Unsorted Date" << std::endl;
	outputArray(dateArray, 10);
	sortArray(dateArray, 10, CompareType::Date);
	std::cout << std::endl;
	std::cout << "Sorted Date" << std::endl;
	outputArray(dateArray, 10);

	std::cout << "---------------" << std::endl;

	std::cout << "Unsorted Date Time" << std::endl;
	outputArray(dateTimeArray, 10);
	sortArray(dateTimeArray, 10, CompareType::DateTime);
	std::cout << std::endl;
	std::cout << "Sorted Date Time" << std::endl;
	outputArray(dateTimeArray, 10);

}