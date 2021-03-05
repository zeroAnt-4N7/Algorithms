#include <iostream>

int main() {
	int nArray[10] = { 1, 8, 2, 36, 82, 2, 0, 5, 36, 12 };

	int nSizeOfArray = sizeof(nArray) / sizeof(nArray[0]);

	for (int i = 0; i < nSizeOfArray; i++) {
		std::cout << nArray[i] << "\t";
	}
	std::cout << "\n";

	for (int i = 0; i < nSizeOfArray; i++) {
		int min = i;
		for (int j = i+1; j < nSizeOfArray; j++) {
			if (nArray[j] < nArray[min]) {
				min = j;
			}
		}
		int k = nArray[min];
		nArray[min] = nArray[i];
		nArray[i] = k;
	}

	for (int i = 0; i < nSizeOfArray; i++) {
		std::cout << nArray[i] << "\t";
	}

	return 0;
}