#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void genPs(int open, int close, vector<string>& ret, string& s, int i) {
        if (open < 0 || close < 0 || close < open) return;

        if (open == 0 && close == 0) {
            ret.push_back(s);
            return;
        }

        s[i] = '(';
        genPs(open - 1, close, ret, s, i + 1);

        s[i] = ')';
        genPs(open, close - 1, ret, s, i + 1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string s(n << 1, ' ');
        genPs(n, n, ret, s, 0);
        return ret;
    }
};
