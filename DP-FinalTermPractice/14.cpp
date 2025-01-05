#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y, id;
};

int areaTriangle(Point& a, Point& b, Point& c) {
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y- b.y)) / 2;
}

int area(vector<Point>& points) {
    int res = 0;
    for (int i = 0; i < points.size(); ++i) {
        res += points[i].x * points[(i+1)%points.size()].y;
        res -= points[i].y * points[(i+1)%points.size()].x;
    }
    return abs(res) / 2;
}

// Brute force
void solution1(vector<Point>& points) {
    int n = points.size();
    int total_area = area(points);
    int min_diff = INT_MAX;
    pair<int, int> res;
    
    for (int i = 0; i < n; i++) {
        int half_area = 0;
        for (int j = i+2; j < n; j++) {
            half_area += abs(areaTriangle(points[i], points[j-1], points[j]));
            int cur_diff = abs(total_area - 2 * half_area);
            
            if (cur_diff < min_diff) {
                min_diff = cur_diff;
                res = {i, j};
            }

            if (half_area > total_area / 2) { break; }
        }
    }
    cout << res.first+1 << " " << res.second+1 << endl;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    solution1(points);

    system("pause");
    return 0;
}