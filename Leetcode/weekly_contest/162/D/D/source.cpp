#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution
{
public:
	int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
	{
		int n, m;
		int tot[26] = { 0, };
		int use[15][26] = { 0, };
		int lmax = 0;

		n = words.size();
		m = letters.size();

		for (int i = 0; i < m; i++)
		{
			tot[letters[i] - 'a']++;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < words[i].size(); j++)
			{
				use[i][words[i][j] - 'a']++;
			}
		}

		int ub;

		ub = (1 << n);

		for (int i = 1; i < ub; i++)
		{
			int cur[26] = { 0, };

			for (int j = 0; j < n; j++)
			{
				int bit;

				bit = (i >> j) % 2;

				if (bit)
				{
					for (int k = 0; k < 26; k++)
					{
						cur[k] += use[j][k];
					}
				}
			}

			bool valid = true;

			int cand = 0;

			for (int j = 0; j < 26; j++)
			{
				if (cur[j] > tot[j])
				{
					valid = false;

					break;
				}

				else
				{
					cand += cur[j] * score[j];
				}
			}

			if (valid&&cand > lmax)
			{
				lmax = cand;
			}
		}

		return lmax;
	}
};

int main()
{
	Solution s;

	vector<string> words = { "dog", "cat", "dad", "good" };
	vector<char> letters = { 'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o' };
	vector<int> score = { 1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	s.maxScoreWords(words,letters,score);

	return 0;
}