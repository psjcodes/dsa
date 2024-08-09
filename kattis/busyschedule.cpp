#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if (a[2] != b[2]) {
        return a[2] < b[2];
    }
    if (a[0] == 12 && b[0] != 12) {
        return true;
    }
    if (a[0] != 12 && b[0] == 12) {
        return false;
    }
    if (a[0] != b[0]) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int main(void) {
    
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        cin.ignore();
        vector< vector<int> > times(n, vector<int>(3));
        string ts;
        for (int i = 0; i < n; ++i) {
            getline(cin, ts);
            int colon = ts.find(':');
            int space = ts.find(' ');
            times[i][0] = stoi(ts.substr(0, colon));
            times[i][1] = stoi(ts.substr(colon + 1, space));
            times[i][2] = (ts.substr(space + 1) == "p.m.") ? 1 : 0;
        }
        sort(times.begin(), times.end(), cmp);
        for (auto ts : times) {
            string period = (ts[2] == 1) ? " p.m." : " a.m.";
            cout << ts[0] << ":";
            if (ts[1] < 10) {
                cout << "0" << ts[1];
            } else {
                cout << ts[1];
            } 
            cout << period << endl;
        }
        cout << endl;
    }
    
    return 0;
}