#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int *team;
bool *taken;

class dlist
{
public:
	int skill;
	dlist *prev;
	dlist *next;
	dlist *head;

	dlist(dlist *h = NULL, dlist *p = NULL, int s = -1)
	{
		prev = p;
		next = NULL;
		head = h;
		skill = s;

		if (p != NULL)
		{
			prev->next = this;
		}
	}

	~dlist()
	{
		if (prev != NULL)
		{
			prev->next = next;
		}

		if (next != NULL)
		{
			next->prev = prev;
		}
	}

	dlist* insert(dlist *h, dlist *p, int s)
	{
		dlist *temp;

		temp = new dlist(h, p, s);

		return temp;
	}

	void removek(int k, int coach)
	{
		int i;
		dlist *temp;

		for (i = 0; i < k; i++)
		{
			if (prev == head)
			{
				break;
			}

			temp = prev;

			team[temp->skill] = coach;

			taken[temp->skill] = true;

			delete temp;
		}

		for (i = 0; i < k; i++)
		{
			if (next == NULL)
			{
				break;
			}

			temp = next;

			team[temp->skill] = coach;

			taken[temp->skill] = true;

			delete temp;
		}
	}
};

int main()
{
	int n, k;
	vector<int> arr;
	dlist **loc;
	dlist *ptr;
	dlist *temp;
	dlist *h;
	int i;
	int input;
	int coach = 0;

	scanf("%d %d", &n, &k);

	h = new dlist;
	loc = new dlist*[n];
	team = new int[n];
	taken = new bool[n];
	ptr = h;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);

		input--;

		ptr = ptr->insert(h, ptr, input);

		loc[input] = ptr;

		taken[i] = false;
	}

	for (i = n - 1; i >= 0; i--)
	{
		if (taken[i])
		{
			continue;
		}

		temp = loc[i];

		temp->removek(k, coach + 1);

		team[i] = coach + 1;

		taken[i] = true;

		coach = !coach;

		delete temp;
	}

	for (i = 0; i < n; i++)
	{
		printf("%d", team[arr[i] - 1]);
	}

	return 0;
}