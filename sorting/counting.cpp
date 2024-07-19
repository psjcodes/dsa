#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int>& vec) {
    int n = vec.size();
    for (int& val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

void countingSort(vector<int>& vec) {
    int n = vec.size();
    int k = *max_element(vec.begin(), vec.end());
    vector<int> book(k + 1);

    for (int& val : vec) {
        ++book[val];
    }

    for (int i = 1; i < k + 1; ++i) {
        book[i] += book[i - 1];
    }

    vector<int> out(n);
    
    for (int j = n - 1; j >= 0; --j) {
        out[book[vec[j]] - 1] = vec[j];             
        --book[vec[j]];                                        
    }

    vec = out;
}

int main() {
    vector<int> vec = {5, 4, 4, 0, 2, 3, 3, 0, 0, 4, 5};

    cout << "Before sorting: ";
    printVector(vec);

    countingSort(vec);

    cout << "After sorting: ";
    printVector(vec);
}