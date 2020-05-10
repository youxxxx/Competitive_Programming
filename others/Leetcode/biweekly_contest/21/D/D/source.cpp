#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int lmax;

	pair<pair<int, int>,int> rec(TreeNode *cur){

		pair<pair<int, int>, int> l = { { -40001, -40001 }, 0 }, r = { { -40001,-40001 },0 };

		if (cur->left) {
			l = rec(cur->left);
		}

		if (cur->right) {
			r = rec(cur->right);
		}

		if (l.second == -2000000001 || r.second == -2000000001)
		{
			pair<pair<int, int>, int> rvalue = { { 0,0 },-2000000001 };

			return rvalue;
		}

		pair<pair<int, int>, int> rvalue = { {0,0},-2000000001 };

		if ((l.first.first == -40001 || l.first.second < cur->val) && (r.first.first == -40001 || r.first.first > cur->val)) {
			rvalue.second = l.second + r.second + cur->val;

			if (rvalue.second > lmax) {
				lmax = rvalue.second;
			}

			if (l.first.first == -40001) {
				rvalue.first.first = cur->val;
			}

			else {
				rvalue.first.first = l.first.first;
			}

			if (r.first.second == -40001) {
				rvalue.first.second = cur->val;
			}

			else {
				rvalue.first.second = r.first.second;
			}

			return rvalue;
		}

		else {
			return rvalue;
		}
	}

	int maxSumBST(TreeNode* root) {
		lmax = 0;

		rec(root);

		return lmax;
	}
};

int main()
{
	Solution s;
}