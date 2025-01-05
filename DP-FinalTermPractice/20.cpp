#include<bits/stdc++.h>
using namespace std;

long long factorial[1001];

void factorialGenerate(int n) {
    factorial[0] = 1;
    for(int i = 1; i <= n; i++) {
        factorial[i] = factorial[i-1] * i;
    }
}

void find_rank(vector<int> perm) {
    int n = perm.size();
    long long rank = 1;
    for(int i = 0; i < n; i++) {
        int rank_i = 0;
        for(int j = i+1; j < n; j++) {
            if(perm[j] < perm[i]) {
                rank_i++;
            }
        }
        rank += rank_i * factorial[n-i-1];
    }
    cout << rank << endl;
}

void find_permutation(int n, long long rank) {
    if (rank > factorial[n]) {
        return;
    }
    vector<int> numbers(n);
    for(int i = 0; i < n; i++) {
        numbers[i] = i+1;
    }
    vector<int> perm(n);
    for(int i = 0; i < n; i++) {
        long long fact = factorial[numbers.size()-1];
        
        int index = (rank-1) / fact;
        perm[i] = numbers[index];
        numbers.erase(numbers.begin() + index);
        rank -= index * fact;
    }
    for(int i = 0; i < n; i++) {
        cout << perm[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> perm(n);
    for(int i = 0; i < n; i++) {
        cin >> perm[i];
    }
    long long rank;
    cin >> rank;

    factorialGenerate(n);
    find_rank(perm);
    find_permutation(n, rank);

    system("pause");
    return 0;
}