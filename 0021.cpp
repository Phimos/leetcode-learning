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
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode * temp, *head = l1;
		if (l1==NULL)
			return l2;
		while (l2)
		{
			if (l1->val <= l2->val)
			{
				if (l1->next == NULL || l1->next->val > l2->val)
				{
					temp = l2;
					l2 = l2->next;
					temp->next = l1->next;
					l1->next = temp;
				}
				else
				{
					l1 = l1->next;
				}
			}
			else
			{
				temp = l2;
				l2 = l2->next;
				temp->next = l1;
				l1 = head = temp;
			}
		}
		return head;
	}
};
