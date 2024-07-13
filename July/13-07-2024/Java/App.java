
public class App {

	public static void main(String[] args) {
		int amounts[] = {5, 3, 10};
		int coins[][] = {{1, 2, 5}, {2}, {10}};
		
		Leetcode518 tc1 = new Leetcode518(), tc2 = new Leetcode518(), tc3 = new Leetcode518();
		
		System.out.println(tc1.change(amounts[0], coins[0]));
		System.out.println(tc2.change(amounts[1], coins[1]));
		System.out.println(tc3.change(amounts[2], coins[2]));
	}

}
