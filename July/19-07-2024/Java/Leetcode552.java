class Leetcode552Solution {
	private final int MOD = 1000000007;

	public int checkRecord(int n) {
		long[][] prev = new long[2][3];
		long[][] curr = new long[2][3];

		for (int j = 0; j <= 1; j++) {
			for (int k = 0; k <= 2; k++) {
				prev[j][k] = 0;
				curr[j][k] = 0;
			}
		}

		prev[1][0] = 1;
		prev[0][0] = 1;
		prev[0][1] = 1;

		for (int i = 2; i <= n; i++) {
			curr[0][0] = (prev[0][0] + prev[0][1] + prev[0][2]) % MOD;
			curr[0][1] = prev[0][0] % MOD;
			curr[0][2] = prev[0][1] % MOD;
			curr[1][0] = (prev[0][0] + prev[0][1] + prev[0][2] + prev[1][0] + prev[1][1] + prev[1][2]) % MOD;
			curr[1][1] = prev[1][0] % MOD;
			curr[1][2] = prev[1][1] % MOD;

			for (int j = 0; j <= 1; j++) {
				for (int k = 0; k <= 2; k++) {
					prev[j][k] = curr[j][k];
				}
			}
		}

		long ans = 0;
		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j <= 2; j++) {
				ans += prev[i][j];
			}
		}
		ans %= MOD;

		return (int) ans;
	}
}

public class Leetcode552 {

	public static void main(String[] args) {
		Leetcode552Solution sol = new Leetcode552Solution();

		int n = 10101;

		System.out.println(sol.checkRecord(n));
	}

}
