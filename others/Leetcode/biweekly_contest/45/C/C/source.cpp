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
	int minimumLength(string s) {
		const int n = s.size();

		int ptr1 = 0, ptr2 = n - 1;

		while (ptr1 < ptr2 && s[ptr1] == s[ptr2]) {
			const char cur = s[ptr1];

			while (ptr1 < ptr2&&s[ptr1] == cur) {
				ptr1++;
			}

			while (ptr1 < ptr2&&s[ptr2] == cur) {
				ptr2--;
			}

			if (s[ptr1] == cur) {
				return 0;
			}
		}

		return ptr2 - ptr1 + 1;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}