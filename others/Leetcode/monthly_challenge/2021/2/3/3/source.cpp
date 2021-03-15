#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		set<ListNode*> list;

		if (!head) {
			return false;
		}

		list.insert(head);

		ListNode *cur = head->next;

		while (cur) {
			const set<ListNode*>::iterator ret = list.find(cur);

			if (ret != list.end()) {
				return true;
			}

			list.insert(cur);

			cur = cur->next;
		}

		return false;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}