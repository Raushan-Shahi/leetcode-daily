// Given a linked list, swap every two adjacent nodes and return its head. 
// You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

// Example 1:


// Input: head = [1,2,3,4]
// Output: [2,1,4,3]


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // if list is null or contains one element then return the list itself (null => null & `1` => `1`)
        if (!head or !head->next)
            return head;

        // Adding dummy head
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        head = dummyHead;

        // Adding dummy tail
        ListNode *dummyTail = new ListNode(-1);
        ListNode *ptr = head;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = dummyTail;

        // assigning prev, cur and next for first iteration
        ListNode *prev = head, *cur = head->next, *next = head->next->next;
        while (next and next->val != -1)
        {
            // Check above image
            ListNode *nextCur = next->next; // 1
            prev->next = next; // 2
            cur->next = next->next; // 3
            next->next = cur; // 4

            prev = cur; // 5
            cur = nextCur; // 6
            next = cur->next; // 7
        }   

        // Remove dummy tail
        ListNode *remove = head;
        while(remove->next->val != -1)
            remove = remove->next;
        remove->next = NULL;

        // remove dummy head
        return head = head->next;
    }
};