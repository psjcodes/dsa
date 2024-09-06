#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void printVector(vector<T>& vec) {
    int n = vec.size();
    for (T& val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

template <typename T>
void bubbleSort(vector<T>& vec) {
    int n = vec.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
        }
    }
}

int main() {
    vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << "Before sorting: ";
    printVector(vec);

    bubbleSort(vec);

    cout << "After sorting: ";
    printVector(vec);
}