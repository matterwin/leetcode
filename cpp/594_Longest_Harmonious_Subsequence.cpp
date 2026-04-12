class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ret = 0;
        for (int n : nums) mp[n]++;

        for (auto const& [val, count] : mp)
            if (mp.find(val + 1) != mp.end())
                ret = max(ret, count + mp[val + 1]);

        return ret;
    }
};
