    #include <iostream>
    #include <vector>
    #include<limits>
    using namespace std;

    int main() {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n);
        vector<vector<int>> point(n);

        int t = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < t; j++) {
                int a;
                cin >> a;
                matrix[i].push_back(a);
                point[i].push_back(INT_MIN);
            }
            t++;
        }

        point[0][0] = matrix[0][0];

        if (n == 1) {
            cout << matrix[0][0] << endl;
            return 0;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int p1 = INT_MIN,p2 = INT_MIN;
                if (j - 1 >= 0) {
                    p1 = point[i-1][j-1];
                }
                if (j < matrix[i-1].size())
                    p2 = point[i-1][j];
                point[i][j] = max(p1,p2) + matrix[i][j];
            }
        }

        int ans = INT_MIN;

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < point[i].size(); j++) {
        //         cout << point[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        for (int i = 1; i < n; i++) {
            if (point[n-1][i] > ans) ans = point[n-1][i];
        }

        cout << ans << endl;
    }