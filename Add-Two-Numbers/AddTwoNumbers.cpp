//Add Two Numbers
//Author: Leonard Pan

#include <iostream>
using namespace std;


typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *lNext = l1, *rNext = l2;
        ListNode *mNext = NULL, *mLast = NULL, *mHead = NULL;
        int carry = 0, value = 0;
        while(lNext || rNext || carry){
            value = ((lNext != NULL? lNext->val:0 )
                    + (rNext != NULL? rNext->val:0 )
                    + carry) % 10;
            carry =  ((lNext != NULL? lNext->val:0 )
                    + (rNext != NULL? rNext->val:0 )
                    + carry) / 10;
            mNext = new ListNode(value);
            if(NULL == mLast){
                mLast = mNext;
            	mHead = mNext;
            }
            else{
                mLast->next = mNext;
    			mLast = mNext;
        	}
        	if(lNext) lNext = lNext->next;
        	if(rNext) rNext = rNext->next;
        }
        return mHead;
    }
};

int main() {
    // Start typing your code here...
	Solution *sol = new Solution();
	ListNode *left = new ListNode(9);
	left->next = new ListNode(9);
	ListNode *right = new ListNode(1);
	ListNode *merged = sol->addTwoNumbers(left, right);

    return 0;
}