public class Leetcode790 {
	int MOD = 1000000007;

	int f(int top, int bottom, int n, int[][] dp) {
		if (top > n || bottom > n)
			return 0;
		if (top == n && bottom == n)
			return 1;

		if (dp[top][bottom] != -1)
			return dp[top][bottom];

		int result = 0;

		if (top == bottom) {
			result = (result % MOD + f(top + 1, bottom + 1, n, dp) % MOD) % MOD;
			result = (result % MOD + f(top + 2, bottom + 2, n, dp) % MOD) % MOD;
			result = (result % MOD + f(top + 1, bottom + 2, n, dp) % MOD) % MOD;
			result = (result % MOD + f(top + 2, bottom + 1, n, dp) % MOD) % MOD;
		}

		if (top > bottom) {
			result = (result % MOD + f(top, bottom + 2, n, dp) % MOD) % MOD;
			result = (result % MOD + f(top + 1, bottom + 2, n, dp) % MOD) % MOD;
		}

		if (bottom > top) {
			result = (result % MOD + f(top + 2, bottom, n, dp) % MOD) % MOD;
			result = (result % MOD + f(top + 2, bottom + 1, n, dp) % MOD) % MOD;
		}

		return dp[top][bottom] = result % MOD;
	}
}
