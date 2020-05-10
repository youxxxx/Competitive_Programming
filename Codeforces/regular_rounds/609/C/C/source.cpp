#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int n, k;
	string s, t;
	char input[200001];

	scanf("%d %d", &n, &k);

	scanf("%s", input);
	s = input;
	t = s;
	
	for (int i = 0; i < k; i++)
	{
		for (int j = i + k; j < n; j += k)
		{
			t[j] = t[i];
		}
	}

	if (t >= s)
	{
		printf("%d\n%s\n", n, t.c_str());

		return 0;
	}

	for (int i = k - 1; i >= 0; i--)
	{
		if (t[i] != '9')
		{
			t[i]++;

			break;
		}

		t[i] = '0';
	}

	for (int i = 0; i < k; i++)
	{
		for (int j = i + k; j < n; j += k)
		{
			t[j] = t[i];
		}
	}

	printf("%d\n%s\n", n, t.c_str());

	return 0;
}