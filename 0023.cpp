/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	class my_cmp
	{
	public:
		bool operator()(ListNode* a, ListNode* b)
		{
			return a->val > b->val;
		}
	};
public:
	ListNode * mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, my_cmp> q;
		for (auto pnode : lists)
			if (pnode)
				q.push(pnode);
		ListNode* res = NULL, *e = NULL;
		while (!q.empty())
		{
			ListNode* temp = q.top();
			q.pop();
			if (!res)
				res = e = temp;
			else
			{
				e->next = temp;
				e = e->next;
			}
			temp = temp->next;
			if (temp)
				q.push(temp);
		}
		return res;
	}
};
