import java.util.Arrays;
import java.util.Comparator;

class Leetcode1235Solution {
	int[][] getSortedIntervals(int n, int[] startTime, int[] endTime, int[] profit) {
		int[][] intervals = new int[n][3];

		for (int i = 0; i < n; i++) {
			intervals[i][0] = startTime[i];
			intervals[i][1] = endTime[i];
			intervals[i][2] = profit[i];
		}

		Arrays.sort(intervals, new Comparator<int[]>() {
			public int compare(int[] o1, int[] o2) {
				return o1[0] - o2[0];
			}
		});

		return intervals;
	}

	int lowerBound(int val, int startPos, int[][] intervals) {
		int s = startPos, e = intervals.length - 1, res = intervals.length;

		while (s <= e) {
			int mid = s + (e - s) / 2;
			if (intervals[mid][0] < val) {
				s = mid + 1;
			} else {
				res = mid;
				e = mid - 1;
			}
		}

		return res;
	}

	public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
		int n = startTime.length;

		int[][] intervals = getSortedIntervals(n, startTime, endTime, profit);

		int dp[] = new int[n + 1];
		dp[n] = 0;
		dp[n - 1] = intervals[n - 1][2];

		for (int i = n - 2; i >= 0; i--) {
			int idx = lowerBound(intervals[i][1], i + 1, intervals);
			dp[i] = Math.max(dp[i + 1], intervals[i][2] + dp[idx]);
		}

		return dp[0];
	}
}

public class Leetcode1235 {

	public static void main(String[] args) {
		Leetcode1235Solution sol = new Leetcode1235Solution();

		int startTime[] = { 4, 2, 4, 8, 2 };
		int endTime[] = { 5, 5, 5, 10, 8 };
		int profit[] = { 1, 2, 8, 10, 4 };

		System.out.println(sol.jobScheduling(startTime, endTime, profit));
	}

}
