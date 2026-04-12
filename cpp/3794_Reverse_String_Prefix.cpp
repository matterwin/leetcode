class Solution {
public:
    string reversePrefix(string s, int k) {
        int i = 0;
        while (i < k) {
            char c = s[i];
            s[i] = s[k];
            s[k] = c;
            ++i;
            --k;
        }
        return s;
    }
};
