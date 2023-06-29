#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct T {
    int i;
    int j;
    int sum;
    T(int i, int j, int sum) : i(i), j(j), sum(sum) {}  // for priority_queue
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        auto compare = [=](const T a, const T b) { return a.sum > b.sum;};
        priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);

        for(int i = 0; i < k && i < nums1.size(); i++)
            minHeap.emplace(i, 0, nums1[i] + nums2[0]);

        while(!minHeap.empty() && res.size() < k) {
            const auto [i, j, _] = minHeap.top();
            minHeap.pop();
            res.push_back({nums1[i], nums2[j]});
            if(j + 1 < nums2.size())
                minHeap.emplace(i, j + 1, nums1[i] + nums2[j + 1]);
        }

        return res;
    }
};

int main() {
    return 0;
}