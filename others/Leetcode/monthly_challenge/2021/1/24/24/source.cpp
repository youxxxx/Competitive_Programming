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
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class comp {
public:
	bool operator() (const ListNode *a, const ListNode *b) {
		return a->val > b->val;
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *head, *ptr;

		ptr = head = new ListNode();


		const int n = lists.size();

		priority_queue<ListNode*, vector<ListNode*>, comp> pq;

		for (int i = 0; i < n; i++) {
			if (lists[i]) {
				pq.push(lists[i]);
			}
		}

		while (!pq.empty()) {
			const ListNode *cur = pq.top();
			pq.pop();

			if (cur->next) {
				pq.push(cur->next);
			}

			ptr->next = new ListNode(cur->val);
			ptr = ptr->next;
		}

		ptr = head;
		head = head->next;
		delete ptr;

		return head;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}