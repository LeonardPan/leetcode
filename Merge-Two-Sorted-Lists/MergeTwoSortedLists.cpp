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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pRoot = nullptr;
        ListNode* pCurrent = nullptr;
        while(l1 && l2) {
            //pSmall => the smaller node
            ListNode* pSmall;
            if(l1->val < l2->val) {
                pSmall = l1;
                l1 = l1->next;
            }
            else {
                pSmall = l2;
                l2 = l2->next;
            }
            if(pCurrent) {
                pCurrent->next = pSmall;
                pCurrent = pSmall;
            }
            //it is the 1st node
            else {
                pCurrent = pSmall;
                pRoot = pSmall;
            }
        }
        //deal with the left list
        ListNode* pListLeft = l1 ? l1 : l2;
        if(pListLeft) {
            if(pCurrent) {
                pCurrent->next = pListLeft;
            }
            else {
                pRoot = pListLeft;
            }
        }
        return pRoot;
    }
};
