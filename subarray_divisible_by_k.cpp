
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;//Initialize cnt to 0, which will be used to count the subarrays with a sum divisible by k.
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum % k == 0) ++cnt;
            }
        }
        return cnt;
    }
};

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    Solution solution;
    int result = solution.subarraysDivByK(nums, k);
    cout << result;

    return 0;
}
