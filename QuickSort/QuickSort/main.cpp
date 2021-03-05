#include <iostream>

int partition(int nArray[], int nArrayStart, int nArrayEnd)
{
    int pivot = nArray[nArrayEnd];

    int i = (nArrayStart - 1);

    for (int j = nArrayStart; j <= nArrayEnd - 1; j++)
    {
        if (nArray[j] <= pivot) {

            i++;
            std::swap(nArray[i], nArray[j]);
        }
    }
    std::swap(nArray[i + 1], nArray[nArrayEnd]);
    return (i + 1);
}

int partition_r(int nArray[], int nArrayStart, int nArrayEnd)
{
    srand(time(NULL));
    int random = nArrayStart + rand() % (nArrayEnd - nArrayStart);

    std::swap(nArray[random], nArray[nArrayEnd]);

    return partition(nArray, nArrayStart, nArrayEnd);
}


void quickSort(int nArray[], int nArrayStart, int nArrayEnd)
{
    if (nArrayStart < nArrayEnd) {
        int pivot = partition_r(nArray, nArrayStart, nArrayEnd);

        quickSort(nArray, nArrayStart, pivot - 1);
        quickSort(nArray, pivot + 1, nArrayEnd);
    }
    return;
}


int main(){

    int nArray[10] = { 1, 8, 2, 36, 82, 2, 0, 5, 36, 12 };

    int nSizeOfArray = sizeof(nArray) / sizeof(nArray[0]);

    // print original array
    for (int i = 0; i < nSizeOfArray; i++) {
        std::cout << nArray[i] << "\t";
    }
    std::cout << "\n";

    // start sorting 
    quickSort(nArray, 0,  nSizeOfArray - 1);

    // print final array
    for (int i = 0; i < nSizeOfArray; i++) {
        std::cout << nArray[i] << "\t";
    }

    return 0;
}