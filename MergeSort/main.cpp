#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10000;

void printArr(int* arr, int len) {
    for (int i = 0; i < len; i++) 
        cout << arr[i] << " ";
    cout << "\n";
}
void MergeSort(int* arr, int front, int end);
void Merge(int* arr, int front, int mid, int end);

int main() {
    int num;
    cout << "How many numbers? ";
    cin >> num;

    cout << "Enter the array: ";
    int* arr = new int[num];
    for (int i = 0; i < num; i++) 
        cin >> arr[i];
    MergeSort(arr, 0, num - 1);

    cout << "Sorted: ";
    printArr(arr, num);

    return 0;
}

void MergeSort(int* arr, int front, int end) {
    if (front < end) {
        int mid = (front + end) / 2;
        MergeSort(arr, front, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, front, mid, end);
    }
}

void Merge(int* arr, int front, int mid, int end) {
    int l = 0, r = 0; //keep track of the processing index of left & right
    int fine = front - 1;
    vector<int> left, right; //left: front ~ mid; right: mid + 1 ~ end
    for (int i = front; i < mid + 1; i++) 
        left.push_back(arr[i]);
    for (int i = mid + 1; i < end + 1; i++)
        right.push_back(arr[i]);
    left.push_back(MAX);
    right.push_back(MAX);

    bool done = false;
    while (!done) {
        if (left[l] == right[r] && left[l] == MAX)
            done = true;
        else if (left[l] < right[r]) {
            fine++;
            arr[fine] = left[l];            
            l++;
        }
        else {
            fine++;
            arr[fine] = right[r];
            r++;
        }
    }
}