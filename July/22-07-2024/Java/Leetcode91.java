import java.util.Arrays;

class Leetcode91Solution {
	public int numDecodings(String s) {
		int n = s.length();

		int dp[] = new int[n + 1];
		Arrays.fill(dp, 0);

		dp[n] = 1;

		if (s.charAt(n - 1) != '0') {
			dp[n - 1] = 1;
		}

		for (int i = n - 2; i >= 0; i--) {
			if (s.charAt(i) == '0') {
				continue;
			}

			dp[i] += dp[i + 1];

			if (s.charAt(i) == '1') {
				dp[i] += dp[i + 2];
			}

			if (s.charAt(i) == '2' && s.charAt(i + 1) <= '6') {
				dp[i] += dp[i + 2];
			}
		}

		return dp[0];
	}
}

public class Leetcode91 {

	public static void main(String[] args) {

		String s = "2611055971756562";

		Leetcode91Solution sol = new Leetcode91Solution();

		System.out.println(sol.numDecodings(s));

	}

}
