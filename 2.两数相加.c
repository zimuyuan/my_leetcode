/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* la = l1;
    struct ListNode* lb = l2;
    
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* ret = node;
    int c = 0;

    while(1)
    {

        if (NULL!= la)
        {
            c += la->val;
            la = la->next;
        }

        if (NULL!= lb)
        {
            c += lb->val;
            lb = lb->next;
        }

        node->val = c % 10;
        c /= 10;

        if((NULL== la) && (NULL== lb) && (0 == c))
        {
            node->next = NULL;
            break;
        }

        node->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        node = node->next;
    }

    return ret;
}
