#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> prefixs;
        int sums = 0, counts = 0;

        prefixs[0] = 1;
        
        for(int &i : nums) {
            sums += i;
            if (prefixs.count(sums - k))
                counts += prefixs[sums - k];
            prefixs[sums]++;
        }
        
        return counts;
    }
};

int main() {
    // example 1
    // output = 2
    // vector<int> nums= {1, 1, 1};
    // int k = 2;
    
    // example 2
    // output = 2
    vector<int> nums = {1, 2, 3};
    int k = 3;
    
    Solution sol;
    printf("%d \n", sol.subarraySum(nums, k));

    return 0;
}