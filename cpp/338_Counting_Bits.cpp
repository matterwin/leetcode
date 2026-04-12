class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1, 0);

        for (int i = 1; i < n + 1; ++i) {
            // 0: 0
            // 1: 1
            // ----
            // 2: 10
            // 3: 11
            // ----
            // 4: 100
            // 5: 101
            // 6: 110
            // 7: 111
            // ----
            // 8: 1000
            // ...

            ret[i] = ret[i >> 1] + (i & 1);
        }
        return ret;
    }
};
