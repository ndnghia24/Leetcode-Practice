#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

double solve(Point& a, Point& b, int R) { 
    double d = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    if (d >= 2*R) {
        return 2*M_PI*pow(R, 2);
    } else if (d <= 0) {
        return M_PI*pow(R, 2);
    } else {
        double alpha = 2 * acos((d/2)/R);
        double pizza_part = M_PI*pow(R, 2)*(alpha/(2*M_PI));
        double triangle_part = (d/2)*sqrt(pow(R, 2) - pow(d/2, 2));
        double S = pizza_part - triangle_part;
        return 2*M_PI*pow(R, 2) - 2*S;
    }
}

int main() {
    Point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    int R;
    cin >> R;

    cout << fixed << setprecision(3) << solve(a, b, R) << endl;

    system("pause");
    return 0;
}