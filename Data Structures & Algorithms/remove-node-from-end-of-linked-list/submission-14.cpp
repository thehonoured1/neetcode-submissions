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
// n = 1 is the end of the list.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int length = 1; // see constraint

        while(curr->next != nullptr){
            curr = curr->next;
            length++;
        }

        // curr is at the end now. we now have full length
        // remove nth from end node:
        int nth = length-n+1;
        if(length == 1){   // list of length 1
            head = nullptr;
            return nullptr;
        }
        //list of length 2:
        curr = head->next;
        ListNode* prev = head;
        if(length == 2){
            if(n==2){ 
                prev = nullptr;
                return curr;
            }
            if(n==1){
                curr = nullptr;
                return prev;
            }
        }
        // list of length 3 and above:
        for(int i=2; i<nth ; i++){ //iterate to nth: i stops at nth, curr is at nth
            curr = curr->next;
            prev = prev->next;
        }
        // curr now at nth, remove:
        prev->next = curr->next;
        curr = nullptr;
        return head;
    }
};
