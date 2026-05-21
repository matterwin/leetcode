#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int titleToNumber(string columnTitle) {
		int ret = 0;
        for (char c : columnTitle) {
            int val = (c - 'A') + 1;
            ret = ret * 26 + val;
        }
		return ret;
    }
};

