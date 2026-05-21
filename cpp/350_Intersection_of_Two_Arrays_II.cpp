#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> intersect(vector<int>& n1, vector<int>& n2) {
		vector<int> freq(1001, 0);

		for (int n : n1) freq[n]++;

		vector<int> ret;
		for (int n : n2) {
			if (freq[n] > 0) {
				ret.push_back(n);
				--freq[n];
			}
		}
		return ret;
	}
};

