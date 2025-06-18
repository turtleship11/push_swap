#include "push_swap.h"

void reverse_rotate_multiple(t_stack *stack, void (*rr_func)(t_stack *), int times)
{
    while (times-- > 0)
        rr_func(stack);
}

void sort_a_quick(t_stack *a, t_stack *b, int size)
{
    if (size == 2 && a->arr[0] > a->arr[1])
    {
        if (b->arr[0] < b->arr[1])
            ss(a,b);
        else
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
        sort_three_a_limited(a,b);
        return;
    }
    if (size == 4)
    {
        sort_four_a(a,b);
        return;
    }
    int pivot;
    // if (size <= 6)
    //     pivot = find_third_largest_pivot(a, size);
    // else
        pivot = find_upper_pivot(a, size);
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
if (pushed > 0)
    {
    sort_b_quick(a, b, pushed);
    }
}

void sort_b_quick(t_stack *a, t_stack *b, int size)
{
    if (size <= 0)
        return;
    if (is_sorted_desc(b,size))
    {
        while (size-- > 0)
            pa(a, b);
        return;
    }
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
    if (size == 3)
    {
        sort_three_b_limited(a,b);
        return;
    }
    if (size == 4)
    {
        sort_four_b(a,b);
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

    if (pushed > 0)
    {
        sort_a_quick(a, b, pushed);
    }
    if (size - pushed > 0)
        sort_b_quick(a, b, size - pushed);
}

void sort_three_a_limited(t_stack *a, t_stack *b)
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
        if (b->arr[0] < b->arr[1])
            ss(a,b);
        else
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
void sort_three_b_limited(t_stack *a, t_stack *b)
{
    int a1 = b->arr[0];
    int b1 = b->arr[1];
    int c = b->arr[2];

    if (a1 < b1 && b1 < c) 
    {
        rb(b);
        sb(b);
        pa(a,b);      
        pa(a,b);          
        rrb(b);
        pa(a,b);
    }
    else if (a1 < b1 && b1 > c && a1 < c) // 1 3 2
    {
        sb(b);
        pa(a,b);
        sb(b);
        pa(a,b);
        pa(a,b);
    }
    else if (a1 > b1 && b1 < c && a1 < c) // 2 1 3
    {
        rb(b);
        sb(b);
        pa(a,b);        
        rrb(b);
        pa(a,b);
        pa(a,b);
    }
    else if (a1 < b1 && b1 > c && a1 > c) // 2 3 1
    {
        sb(b);
        pa(a,b);
        pa(a,b);
        pa(a,b);
    
    }
    else if (a1 > b1 && b1 > c) // 3 2 1 
    {
        // do nothing
        pa(a,b);
        pa(a,b);
        pa(a,b);
    }
    else if (a1 > b1 && b1 < c && a1 > c) // 3 1 2
    {
        pa(a,b);
        sb(b);
        pa(a,b);
        pa(a,b);
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
        if (a->arr[0] <= lo_pi)
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
        sort_a_norra(a, b, size - (upper + low));
    if (upper > 0)
        sort_b_quick(a, b, upper);
    if (low > 0)
        sort_b_norrb(a,b, low);
}

void sort_a_norra(t_stack *a, t_stack *b, int size)
{
    if (size == 2 && a->arr[0] > a->arr[1])
    {
        if (b->arr[0] < b->arr[1])
            ss(a,b);
        else
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
        sort_three_a_limited(a,b);
        return;
    }
    if (size == 4)
    {
        sort_four_a(a,b);
        return;
    }
    int pivot;
    pivot = find_pivot(a, size);
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

if (size - pushed > 0)
    sort_a_norra(a, b, size - pushed);
if (pushed > 0)
    {
    sort_b_quick(a, b, pushed);
    }
}

void sort_b_norrb(t_stack *a, t_stack *b, int size)
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
    if (size == 3)
    {
        sort_three_b_limited(a,b);
        return;
    }
    if (size == 4)
    {
        sort_four_b(a,b);
        return;
    }
    int pivot = find_upper_pivot(b, size);
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

    if (pushed > 0)
    {
        sort_a_quick(a, b, pushed);
    }
    if (size - pushed > 0)
        sort_b_norrb(a, b, size - pushed);
}


void sort_four_a(t_stack *a, t_stack *b)
{
    int min_index = find_min_index(a, 4); // 0~3 중 가장 작은 수 위치
    int count = 0;
    if (min_index == 1)
    {
        sa(a);
    }
    else if (min_index == 2)
    {
        ra(a);
        count++;        
        sa(a);
    }
    else if (min_index == 3)
    {
        ra(a);
        count++;
        ra(a);
        count++; 
        sa(a);
    }
    pb(a, b);  // 최소값 하나를 b로 보냄 (정렬에서 제외)
    while (count--> 0)
        rra(a);

    sort_three_a_limited(a,b); // 나머지 3개 정렬 (이미 구현됨)

    pa(a, b);  // 최소값 다시 맨 앞으로
}
int find_min_index(t_stack *a, int size)
{
    int min = a->arr[0];
    int idx = 0;
    for (int i = 1; i < size; i++)
    {
        if (a->arr[i] < min)
        {
            min = a->arr[i];
            idx = i;
        }
    }
    return idx;
}

void sort_four_b(t_stack *a, t_stack *b)
{
    int max_index = find_max_index(b, 4); 
    int count = 0;

    if (max_index == 1)
        sb(b);
    else if (max_index == 2)
    {
        rb(b);
        count++;
        sb(b);
    }
    else if (max_index == 3)
    {
        rb(b);
        count++;
        rb(b);
        count++;
        sb(b);
    }
    pa(a, b); 
    while(count --> 0)
        rrb(b);
    sort_three_b_limited(a, b);
}

int find_max_index(t_stack *b, int size)
{
    int max = b->arr[0];
    int idx = 0;
    for (int i = 1; i < size; i++)
    {
        if (b->arr[i] > max)
        {
            max = b->arr[i];
            idx = i;
        }
    }
    return idx;
}

void sort_five_a(t_stack *a, t_stack *b)
{
    int min_index;
    int count = 0;

    // 첫 번째 최소값 찾아서 b로
    min_index = find_min_index(a, 5);
    if (min_index == 1)
        sa(a);
    else if (min_index == 2)
    {
        ra(a); count++;
        sa(a);
    }
    else if (min_index == 3)
    {
        ra(a); count++;
        ra(a); count++;
        sa(a);
    }
    else if (min_index == 4)
    {
        ra(a); count++;
        ra(a); count++;
        ra(a); count++;
        sa(a);
    }

    pb(a, b);
    while (count-- > 0)
        rra(a);

    // 두 번째 최소값 찾아서 b로
    min_index = find_min_index(a, 4);
    count = 0;
    if (min_index == 1)
        sa(a);
    else if (min_index == 2)
    {
        ra(a); count++;
        sa(a);
    }
    else if (min_index == 3)
    {
        ra(a); count++;
        ra(a); count++;
        sa(a);
    }

    pb(a, b);
    while (count-- > 0)
        rra(a);

    // 남은 3개 정렬
    sort_three_a_limited(a, b);

    // b에 있던 두 개 다시 가져오기 (작은 값부터 들어옴)
    pa(a, b);
    pa(a, b);
}
