#include<iostream>
using namespace std;

int firstocc(int arr[], int s, int e, int key) {
    if (e >= s) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key && (mid == 0 || arr[mid - 1] != key)) {
            return mid;
        } else if (arr[mid] < key) {
            return firstocc(arr, mid + 1, e, key);
        } else {
            return firstocc(arr, s, mid - 1, key);
        }
    }
    return -1;
}

int lastocc(int arr[], int s, int e, int key) {
    if (e >= s) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key && (mid == e || arr[mid + 1] != key)) {
            return mid;
        } else if (arr[mid] <= key) {
            return lastocc(arr, mid + 1, e, key);
        } else {
            return lastocc(arr, s, mid - 1, key);
        }
    }
    return -1;
}

int main() {
    int arr[5] = {2,3,5,5,6};
    cout << firstocc(arr,0,4,5) << endl;
    cout << lastocc(arr,0,4,5) << endl;
}