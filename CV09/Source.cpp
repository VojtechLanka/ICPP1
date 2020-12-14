#include "Pipe.h"
#include <iostream>

using namespace std;

int main() {
	std::ifstream file("pipeline.txt", std::ifstream::in);
	string line;
	std::getline(file, line);
	int size = stoi(line);
	Pipe pipe = Pipe(size);
	file >> pipe;
	cout << (pipe.isPipeOk() ? "Pipe is Ok." : "Something is wrong with this pipeline.") << endl;
	system("pause");
	return 0;
}
