#include<string>
#include<vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int ptr;
	int i, j;
	int cnt = 0;
	int order[26] = { -1, };
	bool correct;

	for (i = 0; i < skill.size(); i++)
	{
		order[skill[i] - 'A'] = i;
	}

	for (i = 0; i < skill_trees.size(); i++)
	{
		ptr = 0;
		correct = true;

		for (j = 0; j < skill_trees[i].size(); j++)
		{
			if (skill[ptr] == skill_trees[i][j])
			{
				ptr++;
			}

			else if (order[skill_trees[i][j] - 'A'] != -1 && order[skill_trees[i][j] - 'A'] > ptr)
			{
				correct = false;

				break;
			}

			if (ptr == skill.size())
			{
				break;
			}
		}

		if (correct)
		{
			cnt++;
		}
	}

	answer = cnt;

	return answer;
}

int main()
{
	string input1 = "CBD";
	vector<string> input2 = { "BACDE", "CBADF", "AECB", "BDA" };

	solution(input1, input2);

	return 0;
}