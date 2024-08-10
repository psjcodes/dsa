#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    string action, name;
    unordered_set<string> logs;
    while (cin >> action >> name) {
        if (action == "entry") {
            if (logs.count(name)) {
                cout << name << " entered (ANOMALY)" << endl;
            } else {
                cout << name << " entered" << endl;
                logs.insert(name);
            }
        }
        else {
            if (logs.count(name)) {
                cout << name << " exited" << endl;
                logs.erase(name);
            } else {
                cout << name << " exited (ANOMALY)" << endl;
            }
        } 
    }
    
    return 0;
}