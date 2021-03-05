#include <iostream>

int main() {
	int nArray[10] = { 45, 3, 65, 56, 34, 123, 56, 9, 23, 0 };
	
	int nFinder = 56;

	int nArraySize = sizeof(nArray) / sizeof(nArray[0]);

	int nArr[10], counter = 0;

	for (int i = 0; i < nArraySize; i++) 
		if ((counter < 10) && (nArray[i] == nFinder)) {
			nArr[counter] = i;
			counter++;
		}
	

	for (int i = 0; i < counter; i++)
		std::cout << nArr[i] << "\t";

	return 0;
}