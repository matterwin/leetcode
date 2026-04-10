#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countOfPairs(int n, int x--, int y--) {
        vector<int> ans(n, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int direct = j - i;
                int viaXY = abs(i - x) + 1 + abs(j - y);
                int viaYX = abs(i - y) + 1 + abs(j - x);
                
                int dist = min(direct, min(viaXY, viaYX));
                
                ans[dist - 1] += 2;
            }
        }
        return ans;
    }
};
