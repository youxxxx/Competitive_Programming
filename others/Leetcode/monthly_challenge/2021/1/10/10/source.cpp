#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

#define N 100000
#define MOD 1000000007

class Solution {
public:
	Solution() {
		memset(tree, 0, sizeof(tree));
	}

	long long tree[N + 2];

	void add(int idx, long long val) {
		for (; idx <= N; idx += (-idx)&idx) {
			tree[idx] += val;
		}
	}

	long long get(int idx) {
		int rvalue = 0;

		for (; idx; idx -= (-idx)&idx) {
			rvalue += tree[idx];
		}

		return rvalue;
	}

	long long psum(int r, int l) {
		return get(r) - get(l);
	}

	int createSortedArray(vector<int>& instructions) {
		long long sol = 0;
		const int n = instructions.size();
		vector<int> arr;

		for (int i = 0; i < n; i++) {
			sol = (sol + min(get(instructions[i] - 1), i - get(instructions[i]))) % MOD;

			add(instructions[i], 1);
		}

		return (int)sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}