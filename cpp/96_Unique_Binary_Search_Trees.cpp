#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int build(int l, int r) {
		if (l > r) return 1;

		int count = 0;

		for (int root = l; root <= r; ++root) {
			int leftTrees = build(root, r - 1);	
			int rightTrees = build(root + 1, r);	

			count += (leftTrees * rightTrees);
		}

		return count;
	}
	int numTrees(int n) {
		return build(1, n);	
	}
};
