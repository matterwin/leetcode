#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	unordered_map<string, vector<int>> memo;

	vector<int> solve(string expr) {
		if (memo.count(expr)) return memo[expr];

		vector<int> res;

		for (int i = 0; i < expr.size(); ++i) {
			char c = expr[i];

			if (c == '+' || c == '-' || c == '*') {
				string leftStr = expr.substr(0, i);
				string rightStr = expr.substr(i + 1);

				vector<int> left = solve(leftStr);
				vector<int> right = solve(rightStr);

				for (int a : left) {
					for (int b : right) {
						if (c == '+') res.push_back(a + b);
						else if (c == '-') res.push_back(a - b);
						else res.push_back(a * b);
					}
				}
			}
		}

		if (res.empty()) res.push_back(stoi(expr));

		return memo[expr] = res;
	}

	vector<int> diffWaysToCompute(string expr) {
		return solve(expr);
	}
};
