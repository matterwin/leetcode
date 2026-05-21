class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> ret(n);
		for (int i = 1; i <= n; ++i) {
			string val;
			if (i % 3 == 0) {
				if (i % 5 == 0) val = "FizzBuzz";
				else val = "Fizz";
			}
			else if (i % 5 == 0) val = "Buzz";
			else val = to_string(i);

			ret[i - 1] = val;
		}
		return ret;
	}
};

