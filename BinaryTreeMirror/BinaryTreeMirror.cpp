#include"iostream"
#include"vector"
using namespace std;

struct TreeNode {	// struct of TreeNode
	int val;
	struct TreeNode *left;	// left child
	struct TreeNode *right;	// right child
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot != NULL) {
			// Recursion
			Mirror(pRoot->left);
			Mirror(pRoot->right);
			// Exchange position of left and right child of root
			TreeNode *tmp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = tmp;
		}
	}
};

int main() {
	// Manually print is silly but now I'm sleepy...2016 1210 0126

	// Create the Origin Tree Manually
	TreeNode *OriRoot = new TreeNode(8);
	TreeNode *One_left = new TreeNode(6);
	OriRoot->left = One_left;
	TreeNode *One_right = new TreeNode(10);
	OriRoot->right = One_right;
	TreeNode *Two_leftleft = new TreeNode(5);
	One_left->left = Two_leftleft;
	TreeNode *Two_leftright = new TreeNode(7);
	One_left->right = Two_leftright;
	TreeNode *Two_rightleft = new TreeNode(9);
	One_right->left = Two_rightleft;
	TreeNode *Two_rightright = new TreeNode(11);
	One_right->right = Two_rightright;
	
	// Print the Original Tree Manually
	cout << "The original tree is:" << endl;
	cout << OriRoot->val << endl;
	cout << One_left->val << " " << One_right->val << endl;
	cout << Two_leftleft->val << " " << Two_leftright->val << " " << Two_rightleft->val << " " << Two_rightright->val << endl;

	// Obtain the Result Tree
	Solution Mi;
	Mi.Mirror(OriRoot);

	// Print the Mirror Tree Manually
	cout << "The mirror tree is:" << endl;
	cout << OriRoot->val << endl;
	cout << OriRoot->left->val << " " << OriRoot->right->val << endl;
	cout << OriRoot->left->left->val << " " << OriRoot->left->right->val << " " 
		 << OriRoot->right->left->val << " " << OriRoot->right->right->val << endl;

	system("pause");
}