#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	string freqAlphabets(string s) {
		int n;
		vector<int> arr;

		n = s.size();

		int cur = 0;

		for (int i = 0; i < n; i++) {

			if (s[i] == '#')
			{
				continue;
			}

			else if (i < n - 1 && s[i + 1] == '#') {
				arr.back() = arr.back() * 10 + (s[i] - '0');
			}

			else {
				arr.push_back(s[i] - '0');
			}
		}

		string rvalue;

		for (int i = 0; i < arr.size(); i++)
		{
			rvalue.push_back(arr[i] + 'a' - 1);
		}

		return rvalue;
	}
};

int main()
{
	Solution s;



	return 0;
}