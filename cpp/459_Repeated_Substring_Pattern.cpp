class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for (int len = 1; len <= n / 2; ++len) {
            if (n % len != 0) continue;

            string pattern = s.substr(0, len);
            bool ok = true;

            for (int i = len; i < n; i += len) {
                if (s.substr(i, len) != pattern) {
                    ok = false;
                    break;
                }
            }

            if (ok) return true;
        }

        return false;
    }
};

or 

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 1) return false;
        string ss = s + s;
        ss = ss.substr(1, ss.size() - 2);
        if (ss.find(s) != string::npos)
            return true;
        return false;
    }
};


