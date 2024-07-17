public class Leetcode416 {
	public boolean canPartition(int[] nums) {
		int n = nums.length;

		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += nums[i];
		}

		if (sum % 2 != 0) {
			return false;
		}

		boolean[][] dp = new boolean[n + 1][sum / 2 + 1];
		for (int i = 0; i <= n; i++) {
			dp[i][0] = true;
		}
		for (int i = 1; i <= sum / 2; i++) {
			dp[0][i] = false;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= sum / 2; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j - nums[i - 1] >= 0) {
					dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
				}
			}
		}

		return dp[n][sum / 2];
	}
}
