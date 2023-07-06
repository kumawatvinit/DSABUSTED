#include <iostream>
#include <vector>
#include <queue>
#include <functional>

int main() {
    std::vector<int> nums = {9, 3, 7, 1, 5};

    // Create the max heap with an inline lambda function as the custom comparator
    std::priority_queue<int, std::vector<int>, std::function<bool(int, int)>> maxHeap(
        [&nums](int i, int j) { return nums[i] < nums[j]; }
    );

    // Insert indices into the max heap
    for (int i = 0; i < nums.size(); ++i) {
        maxHeap.push(i);
    }

    // Print the indices in the max heap
    while (!maxHeap.empty()) {
        int index = maxHeap.top();
        maxHeap.pop();
        std::cout << index << " ";
    }

    return 0;
}
