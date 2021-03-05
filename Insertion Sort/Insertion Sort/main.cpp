#include <iostream>

int main() {
	int nArray[10] = { 1, 8, 2, 36, 82, 2, 0, 5, 36, 12 };

	int nSizeOfArray = sizeof(nArray) / sizeof(nArray[0]);

	for (int i = 0; i < nSizeOfArray; i++) {
		std::cout << nArray[i] << "\t";
	}
	std::cout << "\n";

	for (int i = 1; i < nSizeOfArray; i++) {
		int key = nArray[i];
		int j = i - 1;
		while (j >= 0 && key <= nArray[j]) {
			nArray[j + 1] = nArray[j];
			j--;
		}
		nArray[j + 1] = key;
	}

	for (int i = 0; i < nSizeOfArray; i++) {
		std::cout << nArray[i] << "\t";
	}

	return 0;
}