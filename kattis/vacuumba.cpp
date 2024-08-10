#include <iostream>
#include <cmath>
#include <numbers>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;

        double dist = 0, angle = 90, rot = 0;
        double x = 0, y = 0;
        for (int j = 0; j < m; ++j) {
            cin >> rot >> dist;
            angle += rot;
            x += dist * cos(angle * std::numbers::pi / 180);
            y += dist * sin(angle * std::numbers::pi / 180);
        }
        
        cout << x << " " << y << endl;
    }
    
    return 0;
}