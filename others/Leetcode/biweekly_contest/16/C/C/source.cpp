#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	pair<int,int> rec(TreeNode* cur) {
		if (cur == NULL) {
			return{ 0,0 };
		}

		if (cur->left == NULL&&cur->right == NULL) {
			return{ 1,cur->val };
		}

		pair<int, int> lmax, rmax;

		lmax = rec(cur->left);
		rmax = rec(cur->right);

		if (lmax.first > rmax.first) {
			return{ lmax.first + 1,lmax.second};
		}

		else if (lmax.first < rmax.first) {
			return{ rmax.first + 1,rmax.second};
		}

		else
		{
			return{ lmax.first + 1,lmax.second + rmax.second };
		}
	}

	int deepestLeavesSum(TreeNode* root) {
		return rec(root).second;
	}
};

int main()
{


	return 0;
}