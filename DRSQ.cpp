#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000; // Maximum possible size of the array
vector<long long> segTree(4 * MAX_N); // Segment tree to store range sums
vector<int> arr; // The input array
int n, q; // Number of elements and number of queries

// Function to build the segment tree
void build(int node, int start, int end) {
    if (start == end) {
        // Leaf node, store the array value
        segTree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        // Recursively build the left and right halves
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        // Internal node stores the sum of both halves
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

// Function to update the value at index `idx` to `val`
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        // If we reach the leaf node, update the value
        segTree[node] = val;
    } else {
        int mid = (start + end) / 2;
        // Check whether to update in left or right subtree
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        // Recalculate the sum at the current node
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

// Function to get the sum of values in range [l, r]
long long query(int node, int start, int end, int l, int r) {
    if (r < start || l > end) return 0; // Completely outside the range
    if (l <= start && end <= r) return segTree[node]; // Completely inside the range

    int mid = (start + end) / 2;
    // Partial overlap, check both left and right halves
    return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

int main() {
    cin >> n >> q; // Read number of elements and queries
    arr.resize(n); // Resize array to hold 'n' elements

    for (int i = 0; i < n; i++) cin >> arr[i]; // Read array elements

    build(1, 0, n - 1); // Build the segment tree

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            // Update query: update the value at position k to u
            int k, u;
            cin >> k >> u;
            update(1, 0, n - 1, k - 1, u); // Convert 1-based index to 0-based
        } else if (type == 2) {
            // Range sum query: get sum of values in range [a, b]
            int a, b;
            cin >> a >> b;
            cout << query(1, 0, n - 1, a - 1, b - 1) << "\n"; // Convert 1-based to 0-based
        }
    }

    return 0;
}
