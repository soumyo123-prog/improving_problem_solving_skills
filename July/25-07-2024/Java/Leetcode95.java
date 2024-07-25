import java.util.ArrayList;
import java.util.List;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode() {
	}

	TreeNode(int val) {
		this.val = val;
	}

	TreeNode(int val, TreeNode left, TreeNode right) {
		this.val = val;
		this.left = left;
		this.right = right;
	}
}

class Leetcode95Solution {
	ArrayList<TreeNode> f(int s, int e) {
		if (s == e) {
			ArrayList<TreeNode> withVal = new ArrayList<TreeNode>();
			withVal.add(new TreeNode(e));
			return withVal;
		}

		if (s > e) {
			ArrayList<TreeNode> withoutVal = new ArrayList<TreeNode>();
			withoutVal.add(new TreeNode());
			return withoutVal;
		}

		ArrayList<TreeNode> res = new ArrayList<TreeNode>();

		for (int i = s; i <= e; i++) {
			ArrayList<TreeNode> left = f(s, i - 1);
			ArrayList<TreeNode> right = f(i + 1, e);
			for (int j = 0; j < left.size(); j++) {
				for (int k = 0; k < right.size(); k++) {
					res.add(new TreeNode(i, left.get(j), right.get(k)));
				}
			}
		}

		return res;
	}

	public List<TreeNode> generateTrees(int n) {
		TreeNode t1 = new TreeNode(), t2 = new TreeNode();

		System.out.println(t1.equals(t2));

		return f(1, n);
	}
}

public class Leetcode95 {

	public static void main(String[] args) {

		Leetcode95Solution sol = new Leetcode95Solution();

		List<TreeNode> ans = sol.generateTrees(3);

	}

}
