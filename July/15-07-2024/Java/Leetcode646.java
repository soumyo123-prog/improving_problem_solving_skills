import java.util.Arrays;
import java.util.Comparator;

public class Leetcode646 {
    Comparator<int[]> comparator = new Comparator<>() {
        public int compare(int[] p1, int[] p2) {
            return p1[1] - p2[1];
        }
    };

	
	int f(int i, int[] lastPair, int[][] pairs, int[] dp) {
		if (i == pairs.length) {
			return 0;
		}
		
		if (dp[i] != -1) {
			return dp[i];
		}
		
		if (lastPair.length == 0) {
			dp[i] = Math.max(1 + f(i+1, pairs[i], pairs, dp), f(i+1, lastPair, pairs, dp));
		} else if (lastPair[1] < pairs[i][0]) {
			dp[i] = Math.max(1 + f(i+1, pairs[i], pairs, dp), f(i+1, lastPair, pairs, dp));
		} else {
			dp[i] = f(i+1, lastPair, pairs, dp);
		}
		return dp[i];
	}

	public int findLongestChain(int[][] pairs) {
		Arrays.sort(pairs, comparator);
		
		int n = pairs.length;
		
		int[] dp = new int[n];
		
		dp[n-1] = 1;
		
		for (int i=n-2; i>=0; i--) {
			dp[i] = 0;
			for (int j=i+1; j<n; j++) {
				dp[i] = Math.max(dp[i], dp[j]);
				if (pairs[i][1] < pairs[j][0]) {
					dp[i] = Math.max(dp[i], 1 + dp[j]);
				}
			}
		}
		
		return dp[0];
    }
}
