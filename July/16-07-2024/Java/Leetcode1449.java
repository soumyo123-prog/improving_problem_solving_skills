import java.util.HashMap;

public class Leetcode1449 {
	int compare(int[] n1, int[] n2) {
		int len1 = 0, len2 = 0;
		for (int i = 1; i <= 9; i++) {
			len1 += n1[i];
			len2 += n2[i];
		}

		if (len1 > len2)
			return -1;
		if (len2 > len1)
			return 1;

		for (int i = 9; i >= 1; i--) {
			if (n1[i] > n2[i])
				return -1;
			if (n2[i] > n1[i])
				return 1;
		}

		return 0;
	}

	String getNumber(int[] num) {
		StringBuilder sb = new StringBuilder();
		for (int i = 9; i >= 1; i--) {
			for (int j = 1; j <= num[i]; j++) {
				sb.append(i);
			}
		}
		if (sb.length() == 0) {
			sb.append(0);
		}
		return sb.toString();
	}

	public String largestNumber(int[] cost, int target) {
		HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();
		for (int i = 0; i < 9; i++) {
			mp.put(cost[i], i + 1);
		}

		int[][] dp = new int[target + 1][10];
		for (int i = 0; i <= target; i++) {
			for (int j = 0; j <= 9; j++) {
				dp[i][j] = 0;
			}
			if (mp.containsKey(i)) {
				dp[i][mp.get(i)] = 1;
				dp[i][0] = 1;
			}
		}
		dp[0][0] = 1;

		for (int i = 2; i <= target; i++) {

			for (int j = 9; j >= 1; j--) {

				if (i - cost[j - 1] < 0) {
					continue;
				}
				if (dp[i - cost[j - 1]][0] == 0) {
					continue;
				}

				int[] comp = new int[10];
				for (int k = 0; k <= 9; k++) {
					comp[k] = dp[i - cost[j - 1]][k];
				}
				comp[j]++;

				if (compare(dp[i], comp) == 1) {
					for (int k = 1; k <= 9; k++) {
						dp[i][k] = comp[k];
					}
				}
			}

			for (int j = 1; j <= 9; j++) {
				if (dp[i][j] > 0) {
					dp[i][0] = 1;
					break;
				}
			}
		}

		return getNumber(dp[target]);
	}
}
