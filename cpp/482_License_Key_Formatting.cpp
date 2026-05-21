#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string clean;

        for (char c : s)
            if (c != '-')
                clean += toupper(c);

        string ans;
        int cnt = 0;

        for (int i = clean.size() - 1; i >= 0; --i) {
            ans += clean[i];
            ++cnt;

            if (cnt == k && i != 0) {
                ans += '-';
                cnt = 0;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
