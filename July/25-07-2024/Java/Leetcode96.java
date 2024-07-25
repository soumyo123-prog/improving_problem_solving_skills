import java.util.Arrays;

class Leetcode96Solution {
	int f(int s, int e, int[] dp) {
		if (s >= e) {
			return 1;
		}

		if (dp[e - s + 1] != -1) {
			return dp[e - s + 1];
		}

		int ans = 0;
		for (int i = s; i <= e; i++) {
			ans += f(s, i - 1, dp) * f(i + 1, e, dp);
		}
		return dp[e - s + 1] = ans;
	}

	public int numTrees(int n) {
		int[] dp = new int[n + 1];
		Arrays.fill(dp, 0);

		dp[0] = 1;
		dp[1] = 1;

		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				dp[i] += dp[j - 1] * dp[i - j];
			}
		}

		return dp[n];
	}
}

public class Leetcode96 {

	public static void main(String[] args) {

		Leetcode96Solution sol = new Leetcode96Solution();

		System.out.println(sol.numTrees(3));

	}

}
