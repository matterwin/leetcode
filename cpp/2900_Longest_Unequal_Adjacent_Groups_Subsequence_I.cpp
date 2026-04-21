#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
		vector<string> ret;
		int cur_val = groups[0];
		ret.push_back(words[0]);
		for (int i = 1; i < groups.size(); ++i) {
			if (!cur_val && groups[i] || 
                cur_val && !groups[i]) {
				ret.push_back(words[i]);
				cur_val = groups[i];
			}
		}

		return ret;
    }
};

