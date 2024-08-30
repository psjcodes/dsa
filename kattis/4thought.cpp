#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int mul(int x, int y) {
    return x * y;
}

int divi(int x, int y) {
    return x / y;
}

int main(void) {

    int k;
    cin >> k;

    unordered_map<string, function<int(int x, int y)>, string> ops = {
        {"+", add},
        {"-", sub},
        {"*", mul},
        {"/", divi}
    };

    vector<function<int(int x, int y)>> funcs = {add, sub, mul, divi};

    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        bool allBreak = false;
        for (int p = 0; p < ops.size() && !allBreak; ++p) {
            for (int q = 0; q < ops.size() && !allBreak; ++q) {
                for (int r = 0; r < ops.size(); ++r) {
                }
            }
        }
        if (!allBreak) {
            cout << "no solution" << endl;
        }
    }

    return 0;
}