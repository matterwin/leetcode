#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";

        unsigned int n = num;

        string hex = "0123456789abcdef";
        string ret = "";

        while (n) {
            ret += hex[n & 0xF];
            n >>= 4;
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};
