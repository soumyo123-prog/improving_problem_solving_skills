import java.util.Scanner;

class Uva348Solution {
	String getParenthesis(int i, int j, int[][] bp) {
		if (i == j) {
			return String.format("A%d", i + 1);
		}

		StringBuilder sb = new StringBuilder("(");

		sb.append(getParenthesis(i, bp[i][j], bp));
		sb.append(" x ");
		sb.append(getParenthesis(bp[i][j] + 1, j, bp));
		sb.append(")");

		return sb.toString();
	}

	public String getMinCost(int n, long[][] dim) {

		long dp[][] = new long[n][n];

		int bp[][] = new int[n][n];

		for (int i = 0; i < n - 1; i++) {

			dp[i][i] = 0;
			dp[i][i + 1] = dim[i][0] * dim[i + 1][0] * dim[i + 1][1];

			bp[i][i] = -1;
			bp[i][i + 1] = i;

		}

		bp[n - 1][n - 1] = -1;
		dp[n - 1][n - 1] = 0;

		for (int len = 3; len <= n; len++) {
			for (int i = 0; i + len - 1 < n; i++) {

				int j = i + len - 1;

				dp[i][j] = Integer.MAX_VALUE;

				for (int k = i; k < j; k++) {

					long kthOper = dp[i][k] + dp[k + 1][j] + dim[i][0] * dim[k + 1][0] * dim[j][1];

					if (kthOper < dp[i][j]) {
						dp[i][j] = kthOper;
						bp[i][j] = k;
					}

				}

			}
		}

		return getParenthesis(0, n - 1, bp);

	}
}

public class Uva348 {

	public static void main(String[] args) {

		Uva348Solution sol = new Uva348Solution();

		Scanner sc = new Scanner(System.in);

		int cs = 0;

		while (true) {

			int n = sc.nextInt();

			if (n == 0) {
				break;
			}

			cs++;

			long[][] dim = new long[n][2];

			for (int i = 0; i < n; i++) {
				dim[i][0] = sc.nextLong();
				dim[i][1] = sc.nextLong();
			}

			String res = String.format("Case %d: %s", cs, sol.getMinCost(n, dim));
			System.out.println(res);

		}

	}

}
