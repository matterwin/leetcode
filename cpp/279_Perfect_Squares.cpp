class Solution {
public:
	int numSquares(int n) {
		// Lagrange's Four Square Theorem states that every natural number can be represented as the sum of four integer squares.
		// Based on this theorem, there are only four possible results for any given integer n:

		// If n itself is a perfect square, then the result is 1.
		// If n can be expressed as the sum of two perfect squares, then the result is 2.
		// If n can be expressed as the sum of three perfect squares, then the result is 3.
		// If none of the above cases apply, then the result is 4.	

		// perfect square
		int r = sqrt(n);
		if (r * r == n) return 1;

		// 2 squares 
		// (for each pair of roots, takeway from n this perfect square)
		// if we can get to a point where the last need sum is a perfect square,
		// then n can be expressed as the sum of 2 perfect squares
		for (int a = 1; a * a <= n; ++a) {
			int b2 = n - a * a;
			int b = sqrt(b2);
			if (b * b == b2) return 2;
		}

		// n = 4^k(8m + 7)
		int x = n;
		while (x % 4 == 0) x /= 4;
		if (x % 8 == 7) return 4;

		return 3;
	}
};
