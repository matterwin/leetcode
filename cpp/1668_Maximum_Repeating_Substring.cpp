#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRepeating(string sequence, string word) {
		int ss = sequence.size(), ws = word.size();
		int ret = 0;

		for (int i = 0; i < ss; ++i) {
			int len = 0;

			while (i + (len + 1) * ws <= ss && 
					sequence.substr(i + len * ws, ws) == word)
				++len;

			ret = max(ret, len);
		}

		return ret;
    }
};
