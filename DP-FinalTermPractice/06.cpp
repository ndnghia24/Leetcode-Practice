#include <bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<vector<int>> lists) {
    map<int, int> countMap;
    for (const auto& list : lists) {
        for (const auto& num : list) {
            if (countMap.find(num) == countMap.end()) {
                countMap[num] = 1;
            } else {
                countMap[num]++;
            }
        }
    }

    vector<int> result;
    for (const auto& pair : countMap) {
        for (int i = 0; i < pair.second; i++) {
            result.push_back(pair.first);
        }
    }

    return result;
}

int main() {
    int k;
    cin >> k;
    vector<vector<int>> lists(k);
    for (int i = 0; i < k; i++) {
        int n;
        while (cin >> n) {
            lists[i].push_back(n);
            if (cin.get() == '\n') break;
        }
    }

    vector<int> result = countingSort(lists);
    for (const auto& num : result) {
        cout << num << " ";
    }

    system("pause");
    return 0;
}