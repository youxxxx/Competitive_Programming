#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

#define MOD 1000000007

long long perm[2001];

long long exp(long long base, long long pw) {
	long long rvalue = 1;

	while (pw) {
		if (pw % 2) {
			rvalue = rvalue*base%MOD;
		}

		base = base*base%MOD;
		pw /= 2;
	}

	return rvalue;
}

long long div(long long val) {
	return exp(val, MOD - 2);
}

class node {
public:
	int val;
	long long weight;
	node *left;
	node *right;

	node(int val_input) {
		val = val_input;
		left = NULL;
		right = NULL;
		weight = 0;
	}

	void insert(int newval) {
		if (newval < val) {
			if (left == NULL) {
				left = new node(newval);
				return;
			}

			left->insert(newval);
		}

		else {
			if (right == NULL) {
				right = new node(newval);
				return;
			}

			right->insert(newval);
		}
	}

	void dfs(long long &result) {
		if (left == NULL && right == NULL) {
			weight = 1;

			return;
		}

		if (left == NULL) {
			right->dfs(result);

			weight = right->weight + 1;

			return;
		}

		if (right == NULL) {
			left->dfs(result);

			weight = left->weight + 1;

			return;
		}

		left->dfs(result);
		right->dfs(result);

		weight = left->weight + right->weight + 1;

		result = result * (perm[weight - 1] * div(perm[left->weight]) % MOD*div(perm[right->weight]) % MOD) % MOD;
	}
};

class tree {
public:
	node *root;

	tree(int val) {
		root = new node(val);
	}

	void insert(int val) {
		root->insert(val);
	}

	void dfs(long long &result) {
		root->dfs(result);
	}
};

class Solution {
public:
	int numOfWays(vector<int>& nums) {
		perm[0] = perm[1] = 1;

		for (long long i = 2; i <= 2000; i++) {
			perm[i] = perm[i - 1] * i%MOD;
		}

		tree t(nums[0]);

		const int n = nums.size();

		for (int i = 1; i < n; i++) {
			t.insert(nums[i]);
		}

		long long sol = 1;

		t.dfs(sol);

		return (sol + MOD - 1) % MOD;
	}
};

int main()
{
	Solution s;
	vector<int> arr = { 3,1,2,5,4,6 };

	s.numOfWays(arr);

	return 0;
}