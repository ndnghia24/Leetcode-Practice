#include <iostream>
#include <vector>
using namespace std;

// Cho dãy số nguyên a1,a2,…,an. Tìm một đoạn con có đúng k phần tử liên tiếp sao cho ước chung lớn nhất 
// của các phần tử này là lớn nhất.

void input(vector<int>& arr, int& n)
{
	for (int i = 0; i < n; i++) cin >> arr[i];
}
int gcd(int a, int b) 
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

// Brute Force solution
// O(n^2) Time
int solution1(vector<int> arr, int n, int k)
{
	int max = 0;
	for (int i = 0; i < n - k + 1; i++)
	{
		int ucln = arr[i];
		for (int j = i + 1; j < i + k; j++)
		{
			ucln = gcd(ucln, arr[j]);
		}
		if (ucln > max) max = ucln;
	}
	return max;
}

const int MAXN = 1e5 + 5;
int segTree[4*MAXN];

// O(n) Time
void buildTree(vector<int>& arr, int segTreeIndex, int low, int high) {
    if (low == high) {
        segTree[segTreeIndex] = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    buildTree(arr, 2*segTreeIndex+1, low, mid);
    buildTree(arr, 2*segTreeIndex+2, mid+1, high);

    segTree[segTreeIndex] = gcd(segTree[2*segTreeIndex+1], segTree[2*segTreeIndex+2]);
}

// O(logn) Time
int query(int segTreeIndex, int low, int high, int queryLow, int queryHigh) {
    if (low > queryHigh || high < queryLow) {
        return 0;
    }

    if (low >= queryLow && high <= queryHigh) {
        return segTree[segTreeIndex];
    }

    int mid = (low + high) / 2;
    int leftQuery = query(2*segTreeIndex+1, low, mid, queryLow, queryHigh);
    int rightQuery = query(2*segTreeIndex+2, mid+1, high, queryLow, queryHigh);

    return gcd(leftQuery, rightQuery);
}

// Segment Tree solution
// O(n) + O(nlogn) = O(nlogn) Time
int solution2(vector<int>& arr, int n, int k) {
    buildTree(arr, 0, 0, n-1);

    int maxGCD = 0;
    for (int i = 0; i <= n-k; i++) {
        maxGCD = max(maxGCD, query(0, 0, n-1, i, i+k-1));
    }

    return maxGCD;
}


int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	input(arr, n);

	cout << solution1(arr, n, k) << endl;
	cout << solution2(arr, n, k) << endl;
	
	system("pause");
	return 0;
}	