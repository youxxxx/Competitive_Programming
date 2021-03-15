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
	string largestMerge(string word1, string word2) {
		int n = word1.size();
		int m = word2.size();

		/*

		vector<pair<char, int>> arr1, arr2;

		char ch1 = word1[0];
		char ch2 = word2[0];

		arr1.push_back({ ch1,1 });
		arr2.push_back({ ch2,1 });

		for (int i = 1; i < n; i++) {
			if (word1[i] != ch1) {
				ch1 = word1[i];

				arr1.push_back({ ch1,1 });
			}

			else {
				arr1.back().second++;
			}
		}

		for (int i = 1; i < m; i++) {
			if (word2[i] != ch2) {
				ch2 = word2[i];

				arr2.push_back({ ch2,1 });
			}

			else {
				arr2.back().second++;
			}
		}

		n = arr1.size();
		m = arr2.size();
		*/

		int ptr1 = 0, ptr2 = 0;

		string sol;

		while (ptr1 < n&&ptr2 < m) {
			int end1 = ptr1 + 1;
			int end2 = ptr2 + 1;

			while (end1 < n&&end2 < m && word1[end1 - 1] == word2[end2 - 1]) {
				end1++;
				end2++;
			}

			if (word1[end1 - 1] == word2[end2 - 1]) {
				if (end1 == n&&end2 == m) {
					sol.push_back(word1[ptr1++]);
				}

				else if (end1 == n) {
					if (word2[end2] >= word2[end2 - 1]) {
						sol.push_back(word2[ptr2++]);
					}

					else {
						sol.push_back(word1[ptr1++]);
					}
				}

				else if (end2 == m) {
					if (word1[end1] >= word1[end1 - 1]) {
						sol.push_back(word1[ptr1++]);
					}

					else {
						sol.push_back(word2[ptr2++]);
					}
				}

			}

			else {
				if (word1[end1 - 1] > word2[end2 - 1]) {
					sol.push_back(word1[ptr1++]);
				}

				else {
					sol.push_back(word2[ptr2++]);
				}
			}
		}

		while (ptr1 < n) {
			sol.push_back(word1[ptr1++]);
		}

		while (ptr2 < m) {
			sol.push_back(word2[ptr2++]);
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}
