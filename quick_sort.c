#include "push_swap.h"

void reverse_rotate_multiple(t_stack *stack, void (*rr_func)(t_stack *), int times)
{
    while (times-- > 0)
        rr_func(stack);
}


int find_low_pivot(t_stack *stack, int size)
{
    int *tmp = malloc(sizeof(int) * size);
    if (!tmp)
        exit(1);

    int i = 0;
    while (i < size)
    {
        tmp[i] = stack->arr[i]; 
        i++;
    }

    i = 0;
    while (i < size - 1)
    {
        int j = i + 1;
        while (j < size)
        {
            if (tmp[i] > tmp[j])
            {
                int t = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = t;
            }
            j++;
        }
        i++;
    }

    int pivot = tmp[size / 4]; 

    free(tmp);
    return pivot;
}
int find_upper_pivot(t_stack *stack, int size)
{
    int *tmp = malloc(sizeof(int) * size);
    if (!tmp)
        exit(1);

    int i = 0;
    while (i < size)
    {
        tmp[i] = stack->arr[i]; 
        i++;
    }

    i = 0;
    while (i < size - 1)
    {
        int j = i + 1;
        while (j < size)
        {
            if (tmp[i] > tmp[j])
            {
                int t = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = t;
            }
            j++;
        }
        i++;
    }

    int pivot = tmp[(size * 3)/ 4]; 

    free(tmp);
    return pivot;
}
int find_pivot(t_stack *stack, int size)
{
    int *tmp = malloc(sizeof(int) * size);
    if (!tmp)
        exit(1);

    int i = 0;
    while (i < size)
    {
        tmp[i] = stack->arr[i]; 
        i++;
    }

    i = 0;
    while (i < size - 1)
    {
        int j = i + 1;
        while (j < size)
        {
            if (tmp[i] > tmp[j])
            {
                int t = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = t;
            }
            j++;
        }
        i++;
    }

    int pivot = tmp[size / 2];  // 중간값 (median)

    free(tmp);
    return pivot;
}



void sort_a_quick(t_stack *a, t_stack *b, int size)
{
    if (size == 2 && a->arr[0] > a->arr[1])
    {
        sa(a);
        return;
    }    
    if (size <= 1 || is_sorted_size(a, size))
        return;

    if (a->size == 3)
    {
        sort_three_a(a);
        return;
    }
    if (size <= 3) 
    {
        sort_three_a_limited(a);
        return;
    }
    int pivot = find_pivot(a, size);
    // ft_printf("pivot (a) = %i\n", pivot);
    int pushed = 0, rotated = 0;
    int i = 0;
    while (i < size)
    {
        if (a->arr[0] < pivot)
        {
            pb(a, b);
            pushed++;
        }
        else
        {
            ra(a);
            rotated++;
        }
        i++;
    }

    reverse_rotate_multiple(a, rra, rotated);    

if (size - pushed > 0)
    sort_a_quick(a, b, size - pushed);
    	// ft_printf("a_pushed[%d]\n",pushed);
if (pushed > 0)
    {
    sort_b_quick(a, b, pushed);
    }
}

void sort_b_quick(t_stack *a, t_stack *b, int size)
{
    if (size <= 0)
        return;

    if (size == 1)
    {
        pa(a, b);
        return;
    }
    if (size == 2)
    {
        if (b->arr[0] < b->arr[1])
            sb(b);
        pa(a, b);
        pa(a, b);
        return;
    }
    if (b->size == 3 && size == 3)
    {
        sort_three_b(b);
        pa(a,b);
        pa(a,b);
        pa(a,b);
        return;
    }
    if (size <= 3)
    {
        sort_three_b_limited(b);
        while (size-- > 0)
            pa(a, b);
        return;
    }
    int pivot = find_pivot(b, size);
    // ft_printf("pivot (b) = %i\n", pivot);
    int i = 0, pushed = 0; int rotate = 0;
    while (i < size)
    {
        if (b->arr[0] >= pivot)
        {
            pa(a, b);
            pushed++;
        }
        else
        {
            rb(b);
            rotate++;
        }
        i++;
    }
    while (rotate-- > 0)
        rrb(b);
        i = 0;
	while(i < a->size)
	{
		// ft_printf("a[%d] = %i\n",i, a->arr[i]);
		i++;
	}
    if (pushed > 0)
    {
        sort_a_quick(a, b, pushed);
    }
    if (size - pushed > 0)
        sort_b_quick(a, b, size - pushed);
}

void sort_three_a_limited(t_stack *a)
{
    int x = a->arr[0];
    int y = a->arr[1];
    int z = a->arr[2];

    if (x > y && y > z) // 3 2 1
    {
        sa(a);
        ra(a);
        sa(a);
        rra(a);
        sa(a);
    }
    else if (x > y && y < z && x > z) // 3 1 2
    {
        sa(a);
        ra(a);
        sa(a);
        rra(a);
    }
    else if (x < y && y > z && x > z)
    {
        ra(a);
        sa(a);
        rra(a);
        sa(a);
    }
    else if (x > y && y < z && x < z)
    {
        sa(a);
    }
    else if (x < y && y < z)
    {
        // already sorted
    }
    else if (x < y && y > z && x < z) // 1 3 2
    {
        ra(a);
        sa(a);
        rra(a);
    }
}

void sort_three_b_limited(t_stack *b)
{
    int a = b->arr[0];
    int b1 = b->arr[1];
    int c = b->arr[2];

    if (a < b1 && b1 < c) // 1 2 3 → 내림차순으로 3 2 1 만들기
    {
        sb(b);
        rb(b);
        sb(b);
        rrb(b);
        sb(b);
    }
    else if (a < b1 && b1 > c && a < c) // 1 3 2
    {
        sb(b);
        rb(b);
        sb(b);
        rrb(b);
    }
    else if (a > b1 && b1 < c && a < c) // 2 1 3
    {
        rb(b);
        sb(b);
        rrb(b);
        sb(b);
    }
    else if (a < b1 && b1 > c && a > c) // 2 3 1
    {
        sb(b);
    }
    else if (a > b1 && b1 > c) // 3 2 1 (정렬 완료)
    {
        // do nothing
    }
    else if (a > b1 && b1 < c && a > c) // 3 1 2
    {
        rb(b);
        sb(b);
        rrb(b);
    }
}

void sort_first(t_stack *a, t_stack *b, int size)
{
 int up_pi = find_upper_pivot(a,size);
 int lo_pi = find_low_pivot(a,size);
    int upper = 0, low = 0;
    int i = 0;
    while (i < size)
    {
        if (a->arr[0] < lo_pi )
        {
            pb(a, b);
            rb(b);
            low++;
        }
        else if (a->arr[0] < up_pi)
        {
            pb(a,b);
            upper++;
        }
        else
        {
            ra(a);
        }
        i++;
    }

    if (size - (upper + low) > 0)
        sort_a_quick(a, b, size - (upper + low) );
    if (upper > 0)
        sort_b_quick(a, b, upper);
    if (low > 0)
        sort_b_quick(a,b, low);
}