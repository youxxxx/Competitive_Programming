#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int n;
	int i;
	string s;
	char *input;

	input = new char[200001];

	scanf("%d", &n);

	scanf("%s", input);

	s = input;

	for (i = 0; i < n - 1; i++)
	{
		if (s[i + 1] < s[i])
		{
			s.erase(s.begin() + i);

			break;
		}
	}

	if (i == n - 1)
	{
		s.pop_back();
	}

	printf("%s", s.c_str());

	return 0;
}