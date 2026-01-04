#include "push_swap.h"

static void ft_reverse_rotate(t_stack **head)
{
    t_stack     *last_node; 

    // Safety check
    if (NULL == head || NULL == *head || NULL == (*head)->next)
        return; 

    // 1. Find the last node
    last_node = ft_stacklast(*head); 

    // 2. Detach from the back
    // The node BEFORE the last one (prev) must now point to NULL (become the new tail)
    last_node->prev->next = NULL; 

    // 3. Attach to the front
    last_node->next = *head;    // Old last points to old head
    (*head)->prev = last_node;  // Old head points back to old last

    // 4. Update the actual Head pointer
    *head = last_node; 
    
    // 5. Clean up the new Head's history
    (*head)->prev = NULL; 
}

void rra(t_stack **a, bool print)
{
    ft_reverse_rotate(a);
    if (print)
        ft_printf("rra\n");
}

void rrb(t_stack **b, bool print)
{
    ft_reverse_rotate(b);
    if (print)
        ft_printf("rrb\n");
}

void rrr(t_stack **a, t_stack **b, bool print)
{
    ft_reverse_rotate(a);
    ft_reverse_rotate(b);
    if (print)
        ft_printf("rrr\n");
}