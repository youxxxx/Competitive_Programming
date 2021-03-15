#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

class Solution {
public:
	string arrangeWords(string text) {
		const int n = text.size();

		string cur;
		vector<pair <pair<int,int>, string>> arr;

		for (int i = 0; i < n; i++) {
			if (text[i] == ' ') {
				arr.push_back({ {cur.size(),i}, cur });

				cur.clear();
			}

			else {
				if (text[i] >= 'A'&&text[i] <= 'Z') {
					cur.push_back(text[i] + 32);
				}

				else {
					cur.push_back(text[i]);
				}
			}
		}

		arr.push_back({ { cur.size(),n }, cur });

		sort(arr.begin(), arr.end());

		string sol;

		for (int i = 0; i < arr.size(); i++)
		{
			sol.append(arr[i].second);
			sol.push_back(' ');
		}

		sol.pop_back();
		sol[0] -= 32;

		return sol;
	}
};

int main()
{

	return 0;
}