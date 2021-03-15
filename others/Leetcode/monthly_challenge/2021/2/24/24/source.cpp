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

class Solution {
public:
	int scoreOfParentheses(string S) {
		const int n = S.size();
		stack<int> s;

		s.push(0);

		for (int i = 0; i < n; i++) {
			if (S[i] == '(') {
				s.push(0);
			}

			else {
				const int temp = s.top();
				s.pop();

				s.top() += temp * 2 + !temp;
			}
		}

		return s.top();
	}
};

int main()
{
	//freopen("input.txt","r",stdin);
}