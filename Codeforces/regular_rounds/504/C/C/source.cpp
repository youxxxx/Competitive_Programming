#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int s, k;
	int level = 0;
	char input[200001];
	int index;
	int chunk = 0;
	bool deletion;
	int left;
	string str;
	string::iterator it;

	scanf("%d %d", &s, &k);

	scanf("%s", input);
	str = input;

	left = s - k;

	if (s == k)
	{
		printf("%s", str.c_str());

		return 0;
	}

	it = str.begin();

	deletion = false;

	for (it = str.begin(); it != str.end();it++)
	{
		if (*it == '(')
		{
			level++;

			if (deletion)
			{
				index = it - str.begin();

				if (chunk * 2 <= left)
				{
					str.erase(index - chunk * 2, chunk * 2);

					left -= chunk * 2;

					it -= chunk * 2;
				}

				else
				{
					str.erase(index - chunk * 2 + (chunk - left / 2), left);

					it -= left;

					left = 0;
				}

				if (left == 0)
				{
					break;
				}

				deletion = false;

				chunk = 0;
			}
		}

		else
		{
			chunk++;
			level--;

			deletion = true;
		}
	}

	if (left > 0 && it == str.end())
	{
		index = str.end() - str.begin();

		str.erase(index - chunk * 2 + (chunk - left / 2), left);

		left = 0;
	}

	printf("%s", str.c_str());

	return 0;
}