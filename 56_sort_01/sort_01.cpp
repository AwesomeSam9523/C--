#include<iostream>
using namespace std;

void sort_01(int *arr, int n) {
    int low = 0, mid = 0, high = n-1;
    for (int i = 0; i < n; i++) {
        int temp = arr[i];
        if (arr[i] == 0) {
            arr[i] = arr[left];
            arr[left] = temp;
            left++;
        } else {
            arr[i] = arr[right];
            arr[right] = temp;
            right--;
        }
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort_01(arr, n);
    printArray(arr, n);
    delete []arr;
    return 0;
}