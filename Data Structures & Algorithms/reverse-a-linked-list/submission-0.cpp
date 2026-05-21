/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    //return |              argument (ptr)
    ListNode* reverseList(ListNode* head) {
        if(head ==  NULL){
            return NULL;
        }
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *temp;

        while(true){
                        
            if(curr->next == NULL){
                curr->next = prev;
                break;
            }
            temp = curr->next;//next node secured.
            curr->next = prev;//reverse ptr direction.

            prev = curr;//shift pointers forward.
            curr = temp;
        }
        return curr;
    }
};
