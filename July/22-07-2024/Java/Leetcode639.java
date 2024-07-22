
class Leetcode639Solution {
	final int MOD = 1000000007;

	public int numDecodings(String s) {
		int n = s.length();

		long dp[] = new long[n + 1];

		dp[n] = 1;

		if (s.charAt(n - 1) == '0') {
			dp[n - 1] = 0;
		} else {
			dp[n - 1] = 1;
		}

		if (s.charAt(n - 1) == '*') {
			dp[n - 1] = 9;
		}

		for (int i = n - 2; i >= 0; i--) {
			dp[i] = 0;

			if (s.charAt(i) == '0') {
				continue;
			}

			if (s.charAt(i) == '*' && s.charAt(i + 1) == '*') {

				dp[i] += (9 * dp[i + 1]) % MOD;
				dp[i] += (15 * dp[i + 2]) % MOD;

			} else if (s.charAt(i) == '*') {

				dp[i] += (9 * dp[i + 1]) % MOD;
				dp[i] += dp[i + 2] % MOD;

				if (s.charAt(i + 1) <= '6') {
					dp[i] += dp[i + 2] % MOD;
				}

			} else if (s.charAt(i + 1) == '*') {

				dp[i] += dp[i + 1] % MOD;

				if (s.charAt(i) == '1') {
					dp[i] += 9 * dp[i + 2] % MOD;
				} else if (s.charAt(i) == '2') {
					dp[i] += 6 * dp[i + 2] % MOD;
				}

			} else {

				dp[i] += dp[i + 1] % MOD;

				if (s.charAt(i) == '1') {
					dp[i] += dp[i + 2] % MOD;
				} else if (s.charAt(i) == '2' && s.charAt(i + 1) <= '6') {
					dp[i] += dp[i + 2] % MOD;
				}

			}

			dp[i] %= MOD;
		}

		return (int) dp[0];
	}
}

public class Leetcode639 {

	public static void main(String[] args) {

		Leetcode639Solution sol = new Leetcode639Solution();

		String s = "*0**0";

		System.out.println(sol.numDecodings(s));

	}

}
