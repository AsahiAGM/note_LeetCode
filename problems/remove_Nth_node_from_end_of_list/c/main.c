#include "../../../util.h"

struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

int main(void)
{
    struct ListNode* pre;
    struct ListNode* cur;
    struct ListNode* head;

    pre = NULL;
    for(int i=1; i<=1; i++)
    {
        cur = malloc(sizeof(struct ListNode));
        cur->val = i;
        cur->next = NULL;
        if(i==1)
            head = cur;
        if(pre)
            pre->next = cur;
        pre = cur;
    }

    print_llist(head);
    printf("↓\n");
    head = removeNthFromEnd(head, 1);
    print_llist(head);
    if (head)
        list_free(head);

    pre = NULL;
    for(int i=1; i<=2; i++)
    {
        cur = malloc(sizeof(struct ListNode));
        cur->val = i;
        cur->next = NULL;
        if(i==1)
            head = cur;
        if(pre)
            pre->next = cur;
        pre = cur;
    }

    print_llist(head);
    printf("↓\n");
    head = removeNthFromEnd(head, 2);
    print_llist(head);
    if (head)
        list_free(head);
    
    return 0;
}