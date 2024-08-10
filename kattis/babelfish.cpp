#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(void) {
    
    unordered_map<string, string> translations;
    string line;
    while (getline(cin, line) && !line.empty()) {
        int spacePos = line.find(' ');
        translations.insert({line.substr(spacePos + 1), line.substr(0, spacePos)});
    }
    
    while (cin >> line) {
        auto it = translations.find(line);
        if (it != translations.end()) cout << it->second << endl;
        else cout << "eh" << endl;
    }
    
    return 0;
}