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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* pRoot = NULL;
        ListNode* pCurrent = NULL;
        while (l1 && l2) {
            //l1 + l2 + carry
            sum = l1->val + l2->val + sum;
            //save the unit
            ListNode* pTmp = new ListNode(sum % 10);
            //save the carry
            sum = sum / 10;
            //this is the 1st node
            if (!pCurrent) {
                pCurrent = pTmp;
                pRoot = pCurrent;
            }
            //not the 1st node
            else {
                pCurrent->next = pTmp;
                pCurrent = pTmp;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        //append all left nodes behind the current node
        ListNode* pLeftRoot = l1 ? l1 : l2;
        if (pLeftRoot) {
            if (pCurrent) {
                pCurrent->next = pLeftRoot;
                //consider the carray bit
                while (sum && pCurrent->next) {
                    sum += pCurrent->next->val;
                    pCurrent->next->val = sum % 10;
                    sum = sum / 10;
                    pCurrent = pCurrent->next;
                }
                if (sum) {
                    pCurrent->next = new ListNode(sum);
                }
            }
            //if l2 is empty, use the whole l1 as result
            else {
                pRoot = l1;
            }
        }
        else if (sum) {
            pCurrent->next = new ListNode(sum);
        }
        return pRoot;
    }
};
