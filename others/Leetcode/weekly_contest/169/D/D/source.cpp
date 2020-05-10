#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
	bool isSolvable(vector<string>& words, string result) {
		bool used[256] = { 0, };
		int n;
		string letters;
		vector<int> perm;
		long long val[256] = { 0, };
		long long pos[256] = { 0, };
		vector<int> prev;

		for (int i = 0; i < 10; i++) {
			perm.push_back(i);
			prev.push_back(-1);
		}

		n = words.size();

		for (int i = 0; i < n; i++)	{
			for (int j = 0; j < words[i].size(); j++){
				if (!used[words[i][j]]) {
					used[words[i][j]] = true;
					letters.push_back(words[i][j]);
				}

				pos[words[i][j]] += (long long)pow(10.0, words[i].size() - j - 1);
			}
		}

		for (int i = 0; i < result.size(); i++) {
			if (!used[result[i]]) {
				used[result[i]] = true;
				letters.push_back(result[i]);
			}

			pos[result[i]] -= (long long)pow(10.0, result.size() - i - 1);
		}

		do {
			bool valid = true;
			bool same = true;

			for (int i = 0; i < letters.size(); i++)
			{
				if (prev[i] != perm[i]) {
					same = false;

					break;
				}
			}

			if (!same) {
				for (int i = 0; i < letters.size(); i++) {
					val[letters[i]] = perm[i];
				}

				for (int i = 0; i < n; i++) {
					if (val[words[i].front()] == 0) {
						valid = false;
						break;
					}
				}

				if (!(!valid || val[result.front()] == 0))
				{
					long long sum = 0;

					for (int i = 0; i < letters.size(); i++) {
						sum += pos[letters[i]] * val[letters[i]];
					}

					if (!sum) {
						return true;
					}
				}
			}

			for (int i = 0; i < letters.size(); i++) {
				prev[i] = letters[i];
			}
		} while (next_permutation(perm.begin(), perm.end()));

		return false;
	}
};

int main()
{
	Solution s;
	vector<string> words = {"SEND", "MORE"};

	s.isSolvable(words,"MONEY");

	return 0;
}