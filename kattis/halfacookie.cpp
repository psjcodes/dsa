#include <iostream>
#include <cmath>
#include <numbers>

using namespace std;

int main(void) {
    
    double r = 0, x = 0, y = 0;
    while (cin >> r >> x >> y) {
        double h = r - sqrt(x * x + y * y);
        if (h < 0) {
            cout << "miss" << endl;
            continue;
        }
        double rSq = r * r;
        double rMinH = r - h;
        double smallArea = rSq * acos(1 - h / r) - rMinH * sqrt(rSq - rMinH * rMinH);
        double bigArea = std::numbers::pi * rSq - smallArea;
        cout << bigArea << " " << smallArea << endl;
    }
    
    return 0;
}