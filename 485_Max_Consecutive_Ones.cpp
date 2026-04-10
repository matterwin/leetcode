class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                ++cnt;
                ret = max(ret, cnt);
            }
            else cnt = 0;
        }
        return ret;
    }
};

