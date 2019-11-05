#include<cstdio>
#include<vector>

using namespace std;

bool rec(vector<int> &arr, int n, int cur, int val)
{
	bool res = false;

	if (cur == n)
	{
		if (val == 0)
		{
			return true;
		}

		return false;
	}

	res = res || rec(arr, n, cur + 1, (val + arr[cur]) % 360);
	res = res || rec(arr, n, cur + 1, (val + 360 - arr[cur]) % 360);

	return res;
}

int main()
{
	vector<int> arr;
	int n;
	int input;
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	if (rec(arr, n, 0, 0))
	{
		printf("YES\n");
	}

	else
	{
		printf("NO\n");
	}

	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll n;
cin>>n;
ll arr[n];
for(ll i=0;i<n;i++)
cin>>arr[i];
vector<ll> vec;
vec.push_back(arr[0]);
vec.push_back(-1*arr[0]);
for(ll i=1;i<n;i++)
{
ll t=vec.size();

for(ll j=0;j<t;j++)
{
vec.push_back(vec[j]+arr[i]);
vec[j]=vec[j]-arr[i];
}
}

for(ll i=0;i<vec.size();i++)
{
if(vec[i]%360==0)
{
cout<<"YES"<<endl;

return 0;
}
}

cout<<"NO";
}
*/

/*
#include<bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

int n;
int ara[1000];
int sub[10000];

void call(int k)
{
	if (k == n)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (sub[i])ans += ara[i];
			else ans -= ara[i];
		}

		if (ans % 360 == 0)
		{
			cout << "YES\n";
			exit(0);
		}
		return;
	}
	sub[k] = 1;
	call(k + 1);
	sub[k]--;
	call(k + 1);
}

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ara[i];
	}
	call(0);
	cout << "NO\n";
	return 0;
}
*/

/*
#include<bits/stdc++.h>
#define ll long long
#define loop(i,a,b) for(ll i=a;i<b;i++)

using namespace std;

int main()
{
	ios::sync_with_stdio(0);

	ll n;
	cin >> n;
	ll a[n];

	loop(i, 0, n)
	{
		cin >> a[i];
	}

	ll x = 1;

	for (ll i = 1; i <= n; i++)
		x = x * 2;

	string s[x];
	loop(i, 0, x)
		s[i] = std::bitset<32>(i).to_string();

	string ss[x];
	loop(i, 0, x)
	{
		string str(s[i], 31 - (n - 1), n);
		ss[i] = str;
	}
	loop(i, 0, x)
	{
		ll res = 0;
		for (ll j = 0; j<ss[i].size(); j++)
		{
			if (ss[i][j] == '1')
				res += a[j];
			else
			{
				res -= a[j];
			}
		}

		if (res == 0 || res == -360 || res == 360)
			cout << "YES" << endl;
		return 0;
	}

	cout << "NO" << endl;
}
*/