#include "../../../util.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
int __checkEnd(struct ListNode *list, int n)
{
    struct ListNode *current = list;
    for(int i=0; i<n ;i++)
    {
        if(!(current->next))
            return 1;
        current = current->next;
    }
    return 0;
}
void __removeNode(struct ListNode* preNode, struct ListNode* current)
{
    preNode->next = current->next;
    free(current);
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* current = head;
    struct ListNode* preNode = head;
    while(current)
    {
        if (__checkEnd(current, n))
        {
            if (current == head)
            {
                head = current->next;
                free(current);
            }
            else
            {
                __removeNode(preNode, current);  
            }       
            break;
        }
        preNode = current;
        current = current->next;
    }

    return (head);
}