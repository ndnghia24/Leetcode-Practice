#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y, id, angle;
};

int area(Point a, Point b, Point c) {
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
}

// Brute force solution
void solution1(vector<Point>& points) {
    int n = points.size();

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int left = 0, right = 0;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                int a = area(points[i], points[j], points[k]);
                if (a < 0) left++;
                else if (a > 0) right++;
            }
            if (left == right) {
                cout << points[i].id << " " << points[j].id;
                return;
            }
        }
    }
}

double angle(Point p, Point c) {
    if (p.x == c.x && p.y == c.y) return -1;
    return atan2(c.y - p.y, c.x - p.x);
}

bool compare(Point a, Point b, Point c) {
    return angle(a, c) < angle(b, c);
}

void solution2(vector<Point>& points) {
    // Tìm điểm có tung độ nhỏ nhất
    Point min_y = points[0];
    int min_index = 0;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].y < min_y.y) {
            min_y = points[i];
            min_index = i;
        }
    }
    points.erase(points.begin() + min_index);
    sort(points.begin(), points.end(), [&](Point a, Point b) {
        return compare(a, b, min_y);
    });

    for (int i = 0; i < points.size(); i++) {
        cout << points[i].id << " ";
    }
    cout << min_y.id << " " << points[points.size()/2].id;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

vector<Point> convexHull(vector<Point> points) {
    int n = points.size();
    if (n < 3) return {};

    vector<Point> hull;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    int p = l, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        p = q;
    } while (p != l);

    return hull;
}

void solution3(vector<Point>& points) {
    vector<Point> hull = convexHull(points);
    
    for (int i = 1; i < hull.size(); i++) {
        int left = 0, right = 0;
        for (int k = 0; k < points.size(); k++) {
            if (k == 0 || k == i) continue;
            int a = area(points[0], points[i], points[k]);
            if (a < 0) left++;
            else if (a > 0) right++;
        }
        if (left == right) {
            cout << points[0].id << " " << points[i].id;
            return;
        }
    }
}


int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].id = i+1;
    } 
    solution3(points);

    system("pause");
    return 0;
}