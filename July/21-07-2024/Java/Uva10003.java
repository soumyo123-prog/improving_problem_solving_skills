import java.util.Arrays;
import java.util.Scanner;

class Uva10003Solution {

	int f(int startIdx, int endIdx, int[] a, int[][] dp) {
		if (startIdx + 1 == endIdx) {
			return 0;
		}

		if (dp[startIdx][endIdx] != -1) {
			return dp[startIdx][endIdx];
		}

		int res = Integer.MAX_VALUE;

		for (int i = startIdx + 1; i < endIdx; i++) {
			res = Math.min(res, a[endIdx] - a[startIdx] + f(startIdx, i, a, dp) + f(i, endIdx, a, dp));
		}

		return dp[startIdx][endIdx] = res;
	}

	public int minCost(int l, int n, int[] a) {
		int[][] dp = new int[n + 5][n + 5];

		for (int i = 0; i <= n; i++) {
			Arrays.fill(dp[i], -1);
		}

		int[] modA = new int[n + 2];
		modA[0] = 0;
		modA[n + 1] = l;
		for (int i = 0; i < n; i++) {
			modA[i + 1] = a[i];
		}

		return f(0, n + 1, modA, dp);
	}

}

public class Uva10003 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while (true) {
			int l = sc.nextInt();

			if (l == 0) {
				break;
			}

			int n = sc.nextInt();

			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = sc.nextInt();
			}

			Uva10003Solution sol = new Uva10003Solution();
			System.out.println(String.format("The minimum cutting is %d.", sol.minCost(l, n, a)));
		}

		sc.close();
	}

}
