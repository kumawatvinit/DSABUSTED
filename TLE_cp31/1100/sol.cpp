#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

// Function to parse input and construct the tree
vector<int> readLevelOrder(int height) {
    vector<int> tree;
    for (int i = 0; i < height; ++i) {
        int numNodes = pow(2, i);
        for (int j = 0; j < numNodes; ++j) {
            int val;
            cin >> val;
            tree.push_back(val);
        }
    }
    return tree;
}

// Function to find the leaf nodes in the binary tree
vector<int> findLeafNodes(const vector<int>& tree) {
    vector<int> leafNodes;
    int n = tree.size();
    for (int i = 0; i < n; ++i) {
        if (tree[i] != -1) {
            int leftChildIdx = 2 * i + 1;
            int rightChildIdx = 2 * i + 2;
            if ((leftChildIdx >= n || tree[leftChildIdx] == -1) &&
                (rightChildIdx >= n || tree[rightChildIdx] == -1)) {
                leafNodes.push_back(i);
            }
        }
    }
    return leafNodes;
}

// Function to calculate the distance between two nodes in a binary tree
int calculateDistance(int idx1, int idx2) {
    int distance = 0;
    while (idx1 != idx2) {
        if (idx1 > idx2) idx1 = (idx1 - 1) / 2;
        else idx2 = (idx2 - 1) / 2;
        ++distance;
    }
    return distance;
}

int main() {
    int k, height;
    cin >> k >> height;

    if (height == -1) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> tree = readLevelOrder(height + 1);

    vector<int> leafNodes = findLeafNodes(tree);

    int count = 0;
    for (size_t i = 0; i < leafNodes.size(); ++i) {
        for (size_t j = i + 1; j < leafNodes.size(); ++j) {
            int distance = calculateDistance(leafNodes[i], leafNodes[j]);
            if (distance <= k) {
                ++count;
            }
        }
    }

    cout << count << endl;
    return 0;
}
