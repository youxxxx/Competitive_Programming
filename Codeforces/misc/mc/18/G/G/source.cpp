#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	char input[100001];
	string s;
	vector<int> present;
	int cur = 0;
	int total = 0;
	int n, l, r;
	int i;
	
	scanf("%d", &n);

	scanf("%s", input);

	s = input;

	for (i = 0; i < n; i++)
	{
		cur |= 1 << (s[i] - 'a');

		present.push_back(cur);
	}

	cur = present[n - 1];

	for (i = 0; i < 26; i++)
	{
		total += cur % 2;

		cur >> 1;
	}


}