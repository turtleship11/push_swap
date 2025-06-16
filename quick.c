

// #include "push_swap.h"

// void sort_a_quick(t_stack *a, t_stack *b, int size)
// {
//     if (size == 2 && a->arr[0] > a->arr[1])
//     {
//         if (b->size >= 2 && b->arr[0] < b->arr[1])
//             ss(a,b);
//         else
//             sa(a);
//         return;
//     }
//     if (size <= 1 || is_sorted_size(a, size))
//         return;

//     if (size == 3 )
//     {
//         sort_three_a(a);
//         return;
//     }
//     int upper = find_upper_pivot(a,size);

//     int low = find_low_pivot(a,size);

//     int pivot = find_pivot(a, size);
//         // ft_printf("low (a) = %i\n", low);
//         // ft_printf("upper (a) = %i\n", upper);
//         // ft_printf("pivot (a) = %i\n", pivot);
//     int pushed_mid = 0, rotated = 0, pushed_low= 0, pushed_high = 0;
//     int i = 0;
//     if (size >= 99)
//     {
//         while (i < size)
//         {
//             if (a->arr[0] <= low)
//             {
//                 if (b->arr[0] >= low)
//                 {
//                     pb(a, b);
//                     rb(b);
//                     pushed_low++;
//                 }
//                 else
//                 {
//                     pb(a,b);
//                     pushed_low++;;
//                 }
//             }
//             else if (a->arr[0] <= upper)
//             {
//                 pb(a,b);
//                 pushed_mid++;
//             }
//             else
//             {
//                 ra(a);
//                 rotated++;
//             }
//             i++;
//         }
//     }
//     else
//     {
//         while (i < size)
//         {
//             if (a->arr[0] <= pivot)
//             {
//                 pb(a, b);
//                 pushed_mid++;
//             }
//             else
//             {
//                 ra(a);
//                 rotated++;
//             }
//             i++;
//         }
//     }
// 	// int i = 0;
// 	// while(i < a->size)
// 	// {
// 	// 	ft_printf("a[%d] = %i\n",i, a->arr[i]);
// 	// 	i++;
// 	// }
//     // i = 0;
// 	// while(i < b->size)
// 	// {
// 	// 	ft_printf("b[%d] = %i\n",i, a->arr[i]);
// 	// 	i++;
// 	// }
// if (!(a->size > 90) && rotated > 0 && a->size > 5 )
// {
//     reverse_rotate_multiple(a, rra, rotated);    
// }
// if (size - (pushed_mid + pushed_low) > 0)
// {
//     sort_a_quick(a, b, size - (pushed_mid + pushed_low));
// }
// if (pushed_mid > 0)
//     {
//     sort_b_quick(a, b, pushed_mid);
//     }
// if (pushed_low > 0)
//     sort_b_quick(a,b, pushed_low);
// }



// void sort_b_quick(t_stack *a, t_stack *b, int size)
// {
//     if (size <= 0)
//         return;

//     if (size == 1)
//     {
//         pa(a, b);
//         return;
//     }
//     if (is_sorted_desc(b,size))
//     {
//         int s = 0;
//         while (s < size)
//         {
//             pa(a,b);
//             s++;
//         }
//             return;
//     }
//     if (size == 2)
//     {
//         if (a->size >= 2 && a->arr[0] > a->arr[1] && b->arr[0] < b->arr[1])
//             ss(a,b);
//         else if (b->arr[0] < b->arr[1])
//             sb(b);
//         pa(a, b);
//         pa(a, b);
//         return;
//     }
//     if (size == 3)
// {
//     sort_three_b(b);  // size 임시 변경 없이 그냥 상위 3개만 정렬
//     pa(a, b);
//     pa(a, b);
//     pa(a, b);
//     return;
// }
//     // if (size == 3)
//     // {
//     //     int original_size = b->size;
//     //     b->size = 3;
//     //     sort_three_b(b);
//     //     b->size = original_size;
//     //     pa(a,b);
//     //     pa(a,b);
//     //     pa(a,b);
//     //     return;
//     // }

//     int pivot = find_pivot(b, size);
//     // ft_printf("B_pivot (b) = %i\n", pivot);
//     int low = find_low_pivot(b,size);

//     int i = 0, pushed = 0, rota = 0;
//     if (size <= 5)
//     {
//         while (i < size)
//         {
//             if (b->arr[0] >= low)
//             {
//                 pa(a, b);
//                 pushed++;
//             }
//             else
//             {
//                 rb(b);
//                 rota++;
//             }
//             i++;
//         }
//     }
//     else
//     {
//         while (i < size)
//         {
//             if (b->arr[0] >= pivot)
//             {
//                 pa(a, b);
//                 pushed++;
//             }
//             else
//             {
//                 rb(b);
//                 rota++;
//             }
//         i++;
//     }
// }

// if (size > 3 && rota > 0 )
// {
//     while(rota--)
//         rrb(b);
// }
//     if (pushed > 0)
//     {
//         sort_a_quick(a, b, pushed);
//     }
//     if (size - pushed > 0)
//         sort_b_quick(a, b, size - pushed);
// }

// void sort_three_a(t_stack *stack)
// {
//     if (stack->size < 3)
//     {
//         if (stack->size == 2 && stack->arr[0] > stack->arr[1])
//             sa(stack);
//         return;
//     }
//     int a;
//     int b;
//     int c;
//     a = stack->arr[0];
//     b = stack->arr[1];
//     c = stack->arr[2];
    
//     if(a > b && b < c && c > a)
//         sa(stack);
//     else if (a < b && b > c && a > c)
//         rra(stack);
//     else if (a > b && b > c && a > c)
//     {
//         sa(stack);
//         rra(stack);
//     }
//     else if (a < b && b > c && a < c)
//     {
//         sa(stack);
//         ra(stack);
//     }
//     else if (a > b && b < c && a > c )
//         ra(stack);
// }

// void sort_three_b(t_stack *b)
// {
//     int a = b->arr[0];
//     int b_ = b->arr[1];
//     int c = b->arr[2];
//     if (a > b_ && b_ > c) // already sorted
//         return;
//     else if (a > c && c > b_) // a > c > b_
//     {
//         sb(b);
//         rb(b);
//     }
//     else if (b_ > a && a > c) // b_ > a > c
//         sb(b);
//     else if (b_ > c && c > a) // b_ > c > a
//         rb(b);
//     else if (c > a && a > b_) // c > a > b_
//         rrb(b);
//     else if (c > b_ && b_ > a) // c > b_ > a
//     {
//         sb(b);
//         rrb(b);
//     }
// }