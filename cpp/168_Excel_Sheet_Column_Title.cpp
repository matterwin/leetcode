#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string convertToTitle(int colNum) {
		string ret = "";

		while (colNum > 0) {
            colNum--;
			ret.push_back('A' + (colNum % 26));
			colNum /= 26;
		}

        reverse(ret.begin(), ret.end());
		return ret;
	}
};

