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
    bool hasCycle(ListNode* head) {
        //visited set and curr declared.
        std::unordered_set<ListNode*> visited;
        ListNode *curr = head;

        // iterate and add to a 'visited' map
        while (curr != nullptr){
            // already exists in map:
            if(visited.contains(curr)){
                return true;
            }           
            visited.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};
