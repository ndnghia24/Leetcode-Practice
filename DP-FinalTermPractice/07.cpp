#include <bits/stdc++.h>
using namespace std;

// Save maxLeft and maxRight for each position
int trap1(vector<int>& h) {
    int n = h.size();
    vector<int> maxLeft(n, 0);
    vector<int> maxRight(n, 0);
    int sum = 0;

    for (int i = 1; i < n; i++) {
        maxLeft[i] = max(maxLeft[i - 1], h[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        maxRight[i] = max(maxRight[i + 1], h[i + 1]);
    }
    for (int i = 0; i < n; i++) {
        int minH = min(maxLeft[i], maxRight[i]);
        if (minH > h[i]) {
            sum += minH - h[i];
        }
    }
    return sum;
}

// 2 pointers
int trap2(vector<int>& h) {
    int l = 0;
    int r = h.size() - 1;
    int sum = 0;
    int maxLeft = h[l], maxRight = h[r];
    int curLeft, curRight;

    while (l < r) {
        if (h[l] < h[r]) {
            curLeft = h[l];
            if (curLeft < maxLeft) 
                sum += maxLeft - curLeft;
            else
                maxLeft = curLeft;
            l++;
        }
        else {
            curRight = h[r];
            if (curRight < maxRight) 
                sum += maxRight - curRight;
            else
                maxRight = curRight;
            r--;
        }
    }
    return sum;
}

int main() 
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    cout << trap1(h) << endl;

    system("pause");
    return 0;
}
