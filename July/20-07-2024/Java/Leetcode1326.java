import java.util.Arrays;
import java.util.Comparator;

class Leetcode1326Solution {

	public int minTaps(int n, int[] ranges) {
		int[][] intervals = new int[n + 1][2];
		for (int i = 0; i <= n; i++) {
			intervals[i][0] = i - ranges[i];
			intervals[i][1] = i + ranges[i];
		}

		Arrays.sort(intervals, new Comparator<int[]>() {
			public int compare(int[] o1, int[] o2) {
				return o1[0] - o2[0];
			}
		});

		int minLeft = Math.max(0, intervals[0][0]);
		int maxRight = Math.min(n, intervals[0][1]);
		int ans = 1;

		if (minLeft > 0) {
			return -1;
		}

		int i = 1;
		while (i <= n && intervals[i][0] <= 0) {
			maxRight = Math.max(maxRight, Math.min(n, intervals[i][1]));
			i++;
		}

		i--;

		while (maxRight < n && i <= n) {
			int t = maxRight;
			while (i <= n && intervals[i][0] <= t) {
				if (intervals[i][0] != intervals[i][1]) {
					maxRight = Math.max(maxRight, Math.min(n, intervals[i][1]));
				}
				i++;
			}
			if (t == maxRight) {
				return -1;
			}
			ans++;
		}

//		for (int i = 0; i <= n; i++) {
//			System.out.println(String.format("%d %d", intervals[i][0], intervals[i][1]));
//		}

		return ans;
	}
}

public class Leetcode1326 {

	public static void main(String[] args) {
		int n = 8;
		int ranges[] = { 4, 0, 0, 0, 4, 0, 0, 0, 4 };

		Leetcode1326Solution sol = new Leetcode1326Solution();

		System.out.println(sol.minTaps(n, ranges));
	}

}
