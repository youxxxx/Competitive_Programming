#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
	int safe(int x, int n)
	{
		return x >= 0 && x < n;
	}
	bool canReach(vector<int>& arr, int start) {
		bool visited[50001] = { 0, };
		int n;

		n = arr.size();

		if (arr[start] == 0) {			
			return true;
		}

		visited[start] = true;
		
		stack<int> s;
		s.push(start);

		while (!s.empty()) {
			int next;
			int x;
			
			x = s.top();
			s.pop();

			if (arr[x] == 0) {
				return true;
			}

			next = x - arr[x];

			if (safe(next, n) && !visited[next]) {
				visited[next] = true;

				s.push(next);
			}

			next = x + arr[x];

			if (safe(next, n) && !visited[next]) {
				visited[next] = true;

				s.push(next);
			}
		}

		return false;
	}
};

int main()
{
	Solution s;

	return 0;
}