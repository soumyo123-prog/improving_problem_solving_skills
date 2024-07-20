class Leetcode198Solution {
	int f(int i, int n, int[] nums, int[] dp) {
		if (i >= n) {
			return 0;
		}

		if (dp[i] != -1) {
			return dp[i];
		}

		int a1 = f(i + 1, n, nums, dp);
		int a2 = nums[i] + f(i + 2, n, nums, dp);
		return dp[i] = Math.max(a1, a2);
	}

	public int rob(int[] nums) {
		if (nums.length == 1) {
			return nums[0];
		}

		int d1 = nums[0], d2 = Math.max(nums[0], nums[1]);
		for (int i = 2; i < nums.length; i++) {
			int t;
			if (d1 + nums[i] > d2) {
				t = d1 + nums[i];
			} else {
				t = d2;
			}
			d1 = d2;
			d2 = t;
		}

		return d2;
	}
}

public class Leetcode198 {

	public static void main(String[] args) {
		int[] nums = { 2, 7, 9, 3, 1 };

		Leetcode198Solution sol = new Leetcode198Solution();
		System.out.println(sol.rob(nums));
	}

}
