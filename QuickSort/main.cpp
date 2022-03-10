#include <iostream>
using std::cout; using std::cin;

void swap(int* a, int* b);
void QuickSort(int* arr, int len, int start); //start: start position of QuickSort
int partition(int* arr, int len, int start); //return the end of the former partition and partition

int main() {
    int num;
    cout << "How many numbers? ";
    cin >> num;
    int *arr = new int[num];
    cout << "Enter the arrar: ";
    for (int i = 0; i < num; i++) cin >> arr[i];
    
    QuickSort(arr, num, 0);

    cout << "After sorted: \n";
    for (int i = 0; i < num; i++) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void QuickSort(int* arr, int len, int start) {
    if (len <= 1) return;

    int end = partition(arr, len, start); //end position of the former partition
    int len_for = end - start + 1,
        len_lat = len - len_for; //len for/lat: former/latter
    QuickSort(arr, len_for, start); //sort former partition
    QuickSort(arr, len_lat, end + 1); //sort latter partition

    return;
}

int partition(int* arr, int len, int start) {
    if (len <= 1) return start;

    int end = start - 1;
    int* pivot = &arr[start + len - 1]; //front, end: front & end of the former partition,
                                          
    for (int i = start; i < start + len; i++) {
        if (arr[i] < *pivot) {
            end++;
            swap(&arr[i], &arr[end]);
        }
    }
    swap(&arr[end + 1], pivot);

    return end;
}
