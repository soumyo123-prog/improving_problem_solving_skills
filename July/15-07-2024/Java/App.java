
public class App {

	public static void main(String[] args) {
		int[] c1 = { 4, 3, 2, 5, 6, 7, 2, 5, 5 }, c2 = { 7, 6, 5, 5, 5, 6, 8, 7, 8 },
				c3 = { 2, 4, 6, 2, 4, 6, 4, 4, 4 };
		int t1 = 9, t2 = 12, t3 = 5;

		Leetcode1449 s1 = new Leetcode1449(), s2 = new Leetcode1449(), s3 = new Leetcode1449();

		System.out.println(s1.largestNumber(c1, t1));
//		System.out.println(s2.largestNumber(c2, t2));
//		System.out.println(s3.largestNumber(c3, t3));
	}

}
