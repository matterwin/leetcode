#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isPerfectSquare(int x) {
		if (x < 2) return true;

		long long l = 1, r = x;

		while (l <= r) {
			long long mid = l + (r - l) / 2;
			long long sq = mid * mid;

			if (sq == x) return true;
			else if (sq < x) l = mid + 1;
			else r = mid - 1;
		}
		return false;
	}
};

