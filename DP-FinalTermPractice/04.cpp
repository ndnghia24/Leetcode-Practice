#include<bits/stdc++.h>
using namespace std;

long long merge(vector<int>& arr, int l, int mid, int r) {
    int i = l, j = mid, k = 0;
    vector<int> temp(r - l);
    long long inv_count = 0;

    while(i < mid && j < r) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += mid - i;
        }
    }

    while(i < mid) {
        temp[k++] = arr[i++];
    }

    while(j < r) {
        temp[k++] = arr[j++];
    }

    for(i = l, k = 0; i < r;) {
        arr[i++] = temp[k++];
    }

    return inv_count;
}

// MergeSort count solution
long long mergeSort(vector<int>& arr, int l, int r) {
    if(r - l <= 1) {
        return 0;
    }

    int mid = l + (r - l) / 2;
    long long inv_count = 0;

    inv_count += mergeSort(arr, l, mid);
    inv_count += mergeSort(arr, mid, r);
    inv_count += merge(arr, l, mid, r);

    return inv_count;
}

// Brute force solution
long long bruteForce(vector<int>& arr) {
    long long inv_count = 0;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[i] > arr[j]) {
                inv_count++;
            }
        }
    }

    return inv_count;
}

// Có thể sử dụng AVL
// Đếm số lượng phần tử trong AVL mà lớn hơn phần tử hiện tại. Số lượng này chính là số lượng inversion của phần tử hiện tại.
// Thêm phần tử hiện tại vào AVL.


struct Node {
    int key;
    int size;
    Node* left, *right;
};

Node* newNode(int key) {
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    node->size = 1;
    return node;
}

Node* insert(Node* node, int key, int &result) {
    if(node == NULL) return newNode(key);
    if(key < node->key) {
        node->left = insert(node->left, key, result);
        result += 1 + (node->right ? node->right->size : 0);
    } else {
        node->right = insert(node->right, key, result);
    }
    node->size = 1 + (node->left ? node->left->size : 0) + (node->right ? node->right->size : 0);
    return node;
}

// countInversions
int solution3(vector<int>& arr) {
    int result = 0;
    Node* root = newNode(arr[0]);
    for(int i = 1; i < arr.size(); i++) {
        insert(root, arr[i], result);
        cout << result << endl;
    }
    return 0;
}


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << bruteForce(arr) << "\n";
    cout << mergeSort(arr, 0, n) << "\n";
    cout << solution3(arr) << "\n";

    system("pause");
    return 0;
}