/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		ListNode *pre, *p=head, *q=head;
		while (n--)
		{
			q = q->next;
		}
		if (q == NULL)
		{
			head = head->next;
		}
		else
		{
			p = p->next;
			q = q->next;
			pre = head;
			while (q)
			{
				pre = pre->next;
				p = p->next;
				q = q->next;
			}
			pre->next = p->next;
		}
		return head;
	}
};
