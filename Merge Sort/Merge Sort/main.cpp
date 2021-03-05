#include <iostream>

void merge(int nArray[], int nArrayStart, int nMidpoint, int nArrayEnd){

    int* L = new int [nMidpoint - nArrayStart + 1];
    int* R = new int[nArrayEnd - nMidpoint];

    for (int i = 0; i < nMidpoint - nArrayStart + 1; i++)
        L[i] = nArray[nArrayStart + i];
    for (int i = 0; i < nArrayEnd - nMidpoint; i++)
        R[i] = nArray[nMidpoint + 1 + i];

    int i = 0;

    int j = 0;

    int k = nArrayStart;

    //  merge two arrays
    while (i < (nMidpoint - nArrayStart + 1) && j < ( nArrayEnd - nMidpoint)){
        if (L[i] <= R[j]) {
            nArray[k] = L[i];
            i++;
        }
        else {
            nArray[k] = R[j];
            j++;
        }
        k++;
    }
    
    // fill the elements left
    while (i < (nMidpoint - nArrayStart + 1)) {
        nArray[k] = L[i];
        i++;
        k++;
    }
    while (j < (nArrayEnd - nMidpoint)) {
        nArray[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int nArray[], int nArrayStart, int nArrayEnd) {
    if (nArrayStart < nArrayEnd) {

        int nMidpoint = (nArrayStart + nArrayEnd) / 2;
        //recursively repeat for smaller arrays
        mergeSort(nArray, nArrayStart, nMidpoint);
        mergeSort(nArray, nMidpoint + 1, nArrayEnd);
        // merge on the way back
        merge(nArray, nArrayStart, nMidpoint, nArrayEnd);
    }
    //return if array is in pairs
    return;
}

int main() {
	int nArray[10] = { 1, 8, 2, 36, 82, 2, 0, 5, 36, 12 };

	int nSizeOfArray = sizeof(nArray) / sizeof(nArray[0]);

	for (int i = 0; i < nSizeOfArray; i++) {
		std::cout << nArray[i] << "\t";
	}
	std::cout << "\n";

    //start sorting
    mergeSort(nArray, 0, nSizeOfArray - 1);

	for (int i = 0; i < nSizeOfArray; i++) {
		std::cout << nArray[i] << "\t";
	}

	return 0;
}

