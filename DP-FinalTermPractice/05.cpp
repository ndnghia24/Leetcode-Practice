#include<bits/stdc++.h>
using namespace std;

vector<int> bruteForceSearch(string A, string B) {
    vector<int> result;
    int n = A.size();
    int m = B.size();

    for(int i = 0; i <= n - m; i++) {
        int j;
        for(j = 0; j < m; j++) {
            if(A[i + j] != B[j])
                break;
        }
        if(j == m)
            result.push_back(i + 1);
    }

    return result;
}

vector<int> computeLPSArray(string B) {
    int len = 0;
    int i = 1;
    vector<int> lps(B.size());
    lps[0] = 0;

    while(i < B.size()) {
        if(B[i] == B[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// KMP Search solution
vector<int> KMPSearch(string A, string B) {
    vector<int> lps = computeLPSArray(B);
    vector<int> result;
    int i = 0;
    int j = 0;

    while(i < A.size()) {
        if(B[j] == A[i]) {
            j++;
            i++;
        }

        if(j == B.size()) {
            result.push_back(i - j + 1);
            j = lps[j - 1];
        } else if(i < A.size() && B[j] != A[i]) {
            if(j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return result;
}

string toLower(string str) {
    for(int i = 0; i < str.size(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

int main() {
    string A, B;
    cin >> A >> B;
    A = toLower(A);
    B = toLower(B);

    vector<int> positions2 = bruteForceSearch(A, B);
    for(int i = 0; i < positions2.size(); i++) {
        cout << positions2[i] << " ";
    }

    vector<int> positions = KMPSearch(A, B);
    for(int i = 0; i < positions.size(); i++) {
        cout << positions[i] << " ";
    }

    system("pause");
    return 0;
}