'''
Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

'''

class Solution {
public:
    map<Node*, Node*> m; // Adress of a node in the original list -> Adress of the node's copy
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        Node* newNode = new Node(head->val);
        m.emplace(head, newNode);
        if(head->next)
            newNode->next = copyRandomList(head->next);
		// At this point copies of all nodes have already been created because of the recursive call above
        newNode->random = head->random ? m[head->random] : NULL;
        return newNode;
    }
};