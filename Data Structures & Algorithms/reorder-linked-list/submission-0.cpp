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
    void reorderList(ListNode* head) {
        // IDEA: 
        // get the halfway point of the LL
        // use a stack (append to head) to put contents in reverse order
        // fill the answer list according to instructions until halfway point.

        //iterate and generate the stack
        int totalNodes = 0;
        ListNode **indirect = &head;
        ListNode *stackHead = nullptr;
        while(*indirect != nullptr){
            ListNode *node = new ListNode((*indirect)->val); //next pointer created in else
            if(stackHead == nullptr){
                stackHead = node;
                totalNodes++;
                indirect = &((*indirect)->next);
            }
            else{
                node->next = stackHead;
                stackHead = node;
                indirect = &((*indirect)->next); //move the indirect pointer to next position in original LL.                
                totalNodes++;
            }
        } 
        int halfwayPoint =  (totalNodes-1)/2;
        //now stackhead points to the last value of the original LL
        // Reinsert values to the LL, up to halfway point (middle for odd lists, middle+1 for even)
        indirect = &(head->next);
        int count = 0;
        //store original pointer in temp, to be copied to addedNode->next
        ListNode *temp = nullptr;
        ListNode *stacktemp = nullptr;

        while(count < halfwayPoint){
            // h-->()->     ()->()->()
            //         h-->()->()->...   this node's next ptr needs to copy the previous's
            //       ^              'master' ptr 'indirect
            temp = (*indirect);
            
            *indirect = stackHead; //redirect curr ptr to the stack head node
            stacktemp =  stackHead->next;  //store link to the stack list
            stackHead->next = temp; //redirect current stack head node back to the main list.
            /* NOTE: temp and stacktemp point to nodes, and should be treated as such */

            stackHead = stacktemp;
            indirect = &((*indirect)->next->next); //move indirect to next
            count++;
        }  
        // 2. Account for the even-number boundary node
        if (totalNodes > 0 && totalNodes % 2 == 0) {
            indirect = &((*indirect)->next);
        }
        *indirect = nullptr; //cutoff the old nodes.  
    }
};
