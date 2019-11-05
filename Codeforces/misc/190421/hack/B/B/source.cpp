#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define vi vector<int>
#define pi pair<int,int>
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define ll long long 

template <typename A, typename B>
istream& operator >> (istream& input, pair<A, B>& x) {
	input >> x.F >> x.S;
	return input;
}

template <typename A>
istream& operator >> (istream& input, vector<A>& x) {
	for (auto& i : x)
		input >> i;
	return input;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

int mul(int a, int b)
{
	return (a * 1ll * b) % mod;
}

int add(int a, int b)
{
	a += b;
	if (a >= mod)return a - mod;
	return a;
}
int powz(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1)res = mul(res, a);
		b /= 2;
		a = mul(a, a);
	}
	return res;
}

void solve()
{
	string s;
	cin >> s;
	int cnt = 0;
	int n = s.length();
	string z = "";
	for (int i = 0; i<n; i++)
	{

		if (s[i] == 'a') { cnt++; continue; }
		z += s[i];
	}
	if (cnt == n) { cout << s; return; }
	if (s.length() & 1) { cout << ":("; return; }
	else {
		int flag = 0;
		for (int i = 0; i<z.length() / 2; i++)
		{
			if (z[i] != z[i + z.length() / 2])flag++;
		}
		if (flag) { cout << ":("; return; }
		string ans = "";
		for (int i = z.length() - 1; i >= z.length() / 2; i--)
		{
			if (s[n - (z.length() - i)] != z[i])flag++;

		}
		if (flag) {
			cout << ":(";
			return;
		}
		else
		{
			for (int i = 0; i<n - z.length() / 2; i++)ans += s[i];
			cout << ans;
		}
	}


}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin>>t;
	while (t--)
	{
		solve();
	}

	return 0;
}