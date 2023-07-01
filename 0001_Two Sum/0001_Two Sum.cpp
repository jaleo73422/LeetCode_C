#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map <int, int> hash_map;

        for(int i = 0; i < nums.size(); i++) {
            int tem = target - nums[i];

            if(hash_map.count(tem)) {
                res.push_back(i);
                res.push_back(hash_map[tem]);
                break;
            } else  hash_map[nums[i]] = i;
        }

        return res;
    }
};

int main() {
    return 0;
}