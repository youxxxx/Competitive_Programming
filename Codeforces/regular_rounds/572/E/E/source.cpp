#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
	int n;
	set<int> num;
	set<int>::iterator it;
	vector<int> arr;
	int p, k;
	int i;
	int input;
	int a, b;

	scanf("%d %d %d", &n, &p, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);

		num.insert(input);
	}

	for (i = 0; i < n; i++)
	{
		a = arr[i];


	}

	return 0;
}