#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	int n;
	int input;
	vector<int> arr;
	vector<int> div, div2;
	int ptr1 = 0, ptr2 = 0, ptrm;
	int i;
	int max;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	max = arr.back();

	arr.pop_back();

	for (i = 2; i <= (int)sqrt((double)max); i++)
	{
		if (!(max%i))
		{
			div.insert(div.begin(), i);
			div2.push_back(max / i);
		}
	}

	ptrm = arr.size() - 1;

	for (i = 0; i < div2.size(); i++)
	{
		if (arr[ptrm] > div2[i])
		{
			break;
		}

		ptrm--;
	}

	if (i != div2.size())
	{
		printf("%d %d\n", max, arr[ptrm]);

		return 0;
	}

	for (i = 0; i < div.size(); i++)
	{
		if (arr[ptrm] > div[i])
		{
			break;
		}

		ptrm--;
	}

	printf("%d %d\n", max, arr[ptrm]);

	return 0;
}