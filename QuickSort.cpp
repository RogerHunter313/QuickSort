#include <iostream>
using namespace std;

//void swap(int* a, int* b) { //if we used pointers
//    int t = *a;
//    *a = *b;
//    *b = t;
//}


int partition(int a[], int s, int e) {
    int pivot = a[e];
    int i = s;

    for (int j = s; j <= e - 1; j++) {
        //if current element is smaller than the pivot
        if (a[j] < pivot) {
             // increment index of smaller element, this only increments if a value less the pivot is found
                 // thus we are keeping track of where are pivot will be inserted
                 //CAREFUL, where i++ is placed changes most of the code
            swap(a[i], a[j]);
            i++;
        }
    }
    //finished scanning, let's place the pivot and return the position of the pivot
    swap(a[i], a[e]); //placing pivot in correct position
    // above, all the values less than pivot have been swapped in the front of the array
    return i; //returns position of pivot

}

void quickSort(int a[], int s, int e) {
    if(s>=e) {
        return;
    }
    int p = partition(a,s,e);
    quickSort(a, s, p-1);
    quickSort(a, p+1, e);

}

void printArray(int a[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {

    int a[] = {8, 5, 2, 1, 7, 3, 4};
    int n = sizeof(a)/sizeof(a[0]);
    quickSort(a, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(a, n);

    return 0;
}
