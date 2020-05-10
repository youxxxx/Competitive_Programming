#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int removePalindromeSub(string s) {
		
		if (s.empty())
		{
			return 0;
		}

		bool palindrome = true;;

		for (int i = 0; i <= s.size() / 2; i++) {
			if (s[i] != s[s.size() - 1 - i])
			{
				palindrome = false;

				break;
			}
		}

		if (palindrome)
		{
			return 1;
		}

		return 2;
	}
};

int main()
{
	Solution s;

	s.removePalindromeSub("ababbabbabbababbabba");

	return 0;
}