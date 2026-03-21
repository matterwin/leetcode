#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find(int x, unordered_map<int, int>& parent)
    {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }
    bool unite(int x, int y, unordered_map<int, int>& parent)
    {
        int px = find(x, parent);
        int py = find(y, parent);

        if (px == py)
            return true;

        if (px < py)
            parent[px] = py;
        else 
            parent[py] = px;

        return false;
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        unordered_map<int, int> parent;
        for (int _n : nums)
            parent[_n] = _n;

        // O(n) space
        vector<int> snums = nums;
        // O(nlogn) time
        sort(snums.begin(), snums.end());

        int i = 0, j = 1;
        // O(n) time
        while (j < n)
        {
            if (abs(snums[i] - snums[j]) <= limit)
                unite(snums[i], snums[j], parent);

            ++i;
            ++j;
        }

        // sanity check
        for (int _n : nums)
            cout << "parent of " << _n << ": " << find(_n, parent) << endl;

        unordered_map<int, pair<vector<int>, int>> mp;
        for (int v : nums)
        {
            int root = find(v, parent);
            mp[root].first.push_back(v);
        }

        for (auto& [key, val] : mp)
        {
            int parent = key;
            vector<int>& children = val.first;
            int iter = val.second;
            sort(children.begin(), children.end());
        }

        for (i = 0; i < n; ++i)
        {
            int cur = nums[i];
            int pcur = find(cur, parent);
            vector<int>& children = mp[pcur].first;
            int& iter = mp[pcur].second;
            nums[i] = children[iter++];
        }

        return nums;
    }
};

