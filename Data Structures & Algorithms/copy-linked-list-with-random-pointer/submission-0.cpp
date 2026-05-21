/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        /*
    *The whole Idea is to convert the original LL to a hashmap, and use those
    *original nodes to construct a new LL SIMULTANEOUSLY. 
    *Hashmap is OLDaddress : NEWnode pairs
    *By the end of creating the new LL, These new nodes will contain different
    *'next' ptrs to each other, but the old numeric values for 'random' addresses.  
    *I need to walk thru the new LL and cross reference the old random addresses
    *with the pairs in the hashmap and link them up (random ptr with new node)
    *simultaneously, the nodes are updated to the new ones
        */
        // we will use 3 storages incld original LL, and 2 walks.
        // walk1: assign all nodes into hashmap, generate new LL. 
        //      : key = OLD addresses.
        //      : Value = NEW node.      
        // walk2: thru new LL, assign random by cross-referencing hashmap.
        //      :check if 'random' matches any key, if so
        //       assign its hashmap NEW node address (&) to 'random'
        Node *copyHead = nullptr;
        Node **indirectCpy = &copyHead;
        Node **indirectOri = &head;
        unordered_map<Node*, Node*> nodesMap;
        
        // head->()->()->
        // head->()->      'next' exists by default.
        while(*indirectOri != nullptr){
            // create new node from original:
            *indirectCpy = new Node( (*indirectOri)->val );
            // save random pointer temporarily in the new node to use later
            (*indirectCpy)->random = (*indirectOri)->random;
            // add a new map entry:
            nodesMap[*indirectOri] = *indirectCpy; //old address : new node
            // advance master pointers:
            indirectCpy = &((*indirectCpy)->next);
            indirectOri = &((*indirectOri)->next);
        }
        // atp we will have the desired hashmap and new list complete.
        // cross-reference by iterating thru new LL.
        indirectCpy = &copyHead;
        while(*indirectCpy!=nullptr){
            if((*indirectCpy)->random != nullptr){
                (*indirectCpy)->random = nodesMap[(*indirectCpy)->random];
                //above: node's random ptr points to address of the new node.
                // random should initially contain the old address corresponding 
                // to the new node.
            }
            indirectCpy = &((*indirectCpy)->next);
        }
        return copyHead;

    }
};
