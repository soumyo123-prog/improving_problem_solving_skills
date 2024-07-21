class Leetcode1359Solution {
	final int MOD = 1000000007;

	int getSum(int remSpaces) {
		int res = (remSpaces * (remSpaces - 1)) / 2;
		return res;
	}

	public int countOrders(int n) {
		int remSpaces = 2 * n;

		long ans = 1;

		while (remSpaces > 0) {
			int j = getSum(remSpaces);
			ans *= j % MOD;
			ans %= MOD;
			remSpaces -= 2;
		}

		return (int) ans;
	}
}

public class Leetcode1359 {

	public static void main(String[] args) {
		Leetcode1359Solution sol = new Leetcode1359Solution();

		System.out.println(sol.countOrders(1));
		System.out.println(sol.countOrders(2));
		System.out.println(sol.countOrders(3));
	}

}
