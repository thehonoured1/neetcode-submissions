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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode newListHead = ListNode(0,nullptr);
        ListNode* newListPtr = &newListHead;
        //loop: compare list1 and list2 elements
        //the smaller pointer gets referenced in the newList,
        //eventually the nodes are merged into a new list.
        while(list1 !=nullptr && list2 != nullptr){

            if(list1->val <= list2->val){
                newListPtr->next = list1;
                 newListPtr = newListPtr->next;
                list1 = list1->next;
                continue;
            }
            if(list1->val >= list2->val){
                newListPtr->next = list2;
                 newListPtr = newListPtr->next;
                list2 = list2->next;
                continue;
            }
        }
       // if(list1==nullptr){ //redundant
                //attach remaining elements of list2
            while(list2 != nullptr){
                newListPtr->next = list2;
                newListPtr = newListPtr->next;
                list2 = list2->next;
            }
        //}
        //if(list2==nullptr){//redundant
                //attach remaining elements of list1
                //failsafe if the above if statement ran already:
            //if(list1==nullptr)
                //return newListHead.next;
            while(list1 != nullptr){
                newListPtr->next = list1;
                newListPtr = newListPtr->next;
                list1 = list1->next;
            }
        //}
        return newListHead.next;
    }
};
