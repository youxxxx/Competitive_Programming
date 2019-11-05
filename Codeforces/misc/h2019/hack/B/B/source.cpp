#include<iostream>
#include<queue>
using namespace std;

int N, arr[100], chk;
int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	queue<pair<int, int>> qu;
	qu.push(make_pair(360 - arr[0], 1));
	qu.push(make_pair(arr[0], 1));

	while (!qu.empty())
	{
		int pos = qu.front().first, cnt = qu.front().second;
		qu.pop();
		if (pos == 0 && cnt == N)
		{
			chk = 1;
			break;
		}

		if (cnt == N)
			continue;
		if (arr[cnt] + pos >= 360)
			qu.push(make_pair(arr[cnt] + pos - 360, cnt + 1));
		else
			qu.push(make_pair(arr[cnt] + pos, cnt + 1));
		if (pos-arr[cnt] <= 0)
			qu.push(make_pair(pos - arr[cnt] + 360, cnt + 1));
		else
			qu.push(make_pair(pos - arr[cnt], cnt + 1));
	}

	if (chk)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}