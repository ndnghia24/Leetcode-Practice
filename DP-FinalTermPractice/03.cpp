#include<bits/stdc++.h>
using namespace std;

// Brute force solution
void solution1(vector<int>& a, vector<int>& b) {
    int min_abs_sum = INT_MAX, min_i = 0, min_j = 0;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            if(abs(a[i] + b[j]) < min_abs_sum) {
                min_abs_sum = abs(a[i] + b[j]);
                min_i = i;
                min_j = j;
            }
        }
    }
    cout << min_i + 1 << " " << min_j + 1 << endl;
}

// Binary search solution
void solution2(vector<int>& a, vector<int>& b) {
    vector<pair<int, int>> a_pairs(a.size()), b_pairs(b.size());
    for(int i = 0; i < a.size(); i++) a_pairs[i] = {a[i], i};
    for(int i = 0; i < b.size(); i++) b_pairs[i] = {b[i], i};
    
    sort(a_pairs.begin(), a_pairs.end());
    sort(b_pairs.begin(), b_pairs.end());

    int min_abs_sum = INT_MAX, min_i = 0, min_j = 0;
    for(int i = 0; i < a_pairs.size(); i++) {
        int j = lower_bound(b_pairs.begin(), b_pairs.end(), make_pair(-a_pairs[i].first, -a_pairs[i].second)) - b_pairs.begin();
        if(abs(a_pairs[i].first + b_pairs[j].first) < min_abs_sum) {
            min_abs_sum = abs(a_pairs[i].first + b_pairs[j].first);
            min_i = a_pairs[i].second;
            min_j = b_pairs[j].second;
        }
    }
    cout << min_i + 1 << " " << min_j + 1 << endl;
}

// Two pointers solution
void solution3(vector<int>& a, vector<int>& b) {
    vector<pair<int, int>> a_pairs(a.size()), b_pairs(b.size());
    for(int i = 0; i < a.size(); i++) a_pairs[i] = {a[i], i};
    for(int i = 0; i < b.size(); i++) b_pairs[i] = {b[i], i};
    
    sort(a_pairs.begin(), a_pairs.end());
    sort(b_pairs.begin(), b_pairs.end());

    int min_abs_sum = INT_MAX, min_i = 0, min_j = 0;
    int i = 0, j = b_pairs.size() - 1;
    while(i < a_pairs.size() && j >= 0) {
        if(abs(a_pairs[i].first + b_pairs[j].first) < min_abs_sum) {
            min_abs_sum = abs(a_pairs[i].first + b_pairs[j].first);
            min_i = a_pairs[i].second;
            min_j = b_pairs[j].second;
        }

        if(a_pairs[i].first + b_pairs[j].first < 0) {
            i++;
        } else {
            j--;
        }
    }
    cout << min_i + 1 << " " << min_j + 1 << endl;
}

// Tìm hiểu cách sử dụng CTDL...

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int j = 0; j < m; j++) {
        cin >> b[j];
    }

    solution1(a, b);
    solution2(a, b);
    solution3(a, b);

    system("pause");
    return 0;
}