#include "bits/stdc++.h"
using namespace std;
const int MAX = 100;
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low]; 
    int i = low;
    int j = high;
    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);  
    return j;  
}
void qs(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high); 
        qs(arr, low, pIndex - 1);  
        qs(arr, pIndex + 1, high); 
    }
}
vector<int> quickSort(vector<int>& arr) {
    qs(arr, 0, arr.size() - 1); 
    return arr;
}
int main() {
    vector<int> arr = {99, 98, 97, 96, 95};
    int n = arr.size();
    cout << "The marks of students Before Using Quick Sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    arr = quickSort(arr);
    cout << "The marks of students After Using Quick Sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    cout << "The top 5 students:" << "\n";
    int topStudents = min(5, n); 
    for (int i = 0; i < topStudents; i++) {
        cout << "Rank " << i + 1 << ": " << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}

