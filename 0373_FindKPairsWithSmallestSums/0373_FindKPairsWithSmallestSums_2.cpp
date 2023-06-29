#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <queue>

using namespace std;

// using AI3 = array<int, 3>;
#define AI3 array<int, 3>

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<AI3, vector<AI3>, greater<>> pq;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> res;
        set<pair<int, int>> visited;

        pq.push({nums1[0] + nums2[0], 0, 0});
        visited.insert({0,0});

        while(res.size() < k && pq.size() > 0) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            res.push_back({nums1[i], nums2[j]});

            if(i + 1 < n1 && visited.find({i + 1, j}) == visited.end()) {
                pq.push({nums1[i + 1] + nums2[j], i + 1, j});
                visited.insert({i + 1, j});
            }

            if(j + 1 < n2 && visited.find({i, j + 1}) == visited.end()) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
        }

        return res;
    }
};

int main() {
    return 0;
}