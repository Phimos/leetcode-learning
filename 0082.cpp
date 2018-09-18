/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
	ListNode * helper(ListNode * head)
	{
		while (head&&head->next&&head->val == head->next->val)
		{
			while (head&&head->next&&head->val == head->next->val)
			{
				head = head->next;
			}
			head = head->next;
		}
		return head;
	}
public:
	ListNode * deleteDuplicates(ListNode* head) {
		head = helper(head);
		if (head && head->next)
		{
			ListNode *pre = head, *pnode = head->next;
			while (pnode&&pnode->next)
			{
				if (pnode->val == pnode->next->val)
				{
					pre->next = helper(pnode);
					pnode = pre->next;
				}
				else
				{
					pre = pre->next;
					pnode = pnode->next;
				}
			}
		}
		return head;
	}
};
