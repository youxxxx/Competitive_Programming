#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

class Solution {
public:
	int isPrefixOfWord(string sentence, string searchWord) {
		const int n = sentence.size();
		const int m = searchWord.size();

		int cnt = 1;
		int idx = 0;

		for (int i = 0; i < n; i++)
		{
			if (sentence[i] == ' ')
			{
				cnt++;

				idx = 0;
			}

			else if (idx == 0)
			{
				if (sentence[i] == searchWord[0])
				{
					idx++;
				}

				else
				{
					idx = -1;
				}
			}

			else if (idx != -1)
			{
				if (sentence[i] == searchWord[idx])
				{
					idx++;
				}
			}

			if (idx == m)
			{
				return cnt;
			}
		}

		return -1;
	}
};

using namespace std;

int main()
{

	return 0;
}