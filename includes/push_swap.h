/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:21:17 by takira            #+#    #+#             */
/*   Updated: 2022/12/14 22:21:18 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/libgnl/get_next_line.h"
# include "../lib/libftprintf/ft_printf.h"

# define SUCCESS	1
# define FAILURE	0

# define PASS		1
# define FAIL		0

typedef struct s_info		t_info;
typedef	struct s_stack		t_stack;
typedef struct s_op_list	t_op_list;

typedef enum e_op_cmd		t_op;
typedef enum e_push_op_stk	t_p_stk;
typedef enum e_rot_op_stk	t_r_stk;

enum e_op_cmd
{
	E_SA,
	E_SB,
	E_SS,
	E_PA,
	E_PB,
	E_RA,
	E_RB,
	E_RR,
	E_RRA,
	E_RRB,
	E_RRR
};

enum e_push_op_stk
{
	E_PUSH_A2B,
	E_PUSH_B2A
};

enum e_rot_op_stk
{
	E_STK_A,
	E_STK_B
};

struct s_stack
{
	int				raw_value;
	int				val;
	struct s_stack	*prev;
	struct s_stack	*next;
};

struct s_op_list
{
	enum e_op_cmd		cmd;
	struct s_op_list	*next;
};

struct s_info
{
	struct s_stack		*stk_a;
	struct s_stack		*stk_b;
	struct s_op_list	*op_list;
	size_t				num_cnt;
	int					*sorted_array;
	bool				is_sorted;
};

/* ft_stack.c */
t_stack	*create_stack_elem(int num);
void	ft_stack_iter(t_stack *stk, void (*f)(void *));
void	ft_stack_clear(t_stack **stk);
t_stack	*get_last_elem(t_stack *elem);

/* ft_stack_add.c */
void	add_left(t_stack *elem, t_stack **stk);
void	add_right(t_stack *elem, t_stack **stk);
t_stack	*pop_left(t_stack **stk);
t_stack	*pop_right(t_stack **stk);

/* ft_stack_get.c */
size_t	get_stack_size(t_stack *stk);
int		get_max_val(t_stack *stk);
int		get_min_val(t_stack *stk);
int		get_val_idx(t_stack *stk, int val);
int		get_bottom_val(t_stack *stk);

/* operation_controller.c */
void	operation_controller(t_info *info, t_op cmd);

/* operation_single.c */
void	swap(t_info *info, t_op cmd, bool is_add_op);
void	push(t_info *info, t_op cmd, bool is_add_op);
void	rotate(t_info *info, t_op cmd, bool is_add_op);
void	reverse_rotate(t_info *info, t_op cmd, bool is_add_op);

/* operation_double.c */
void	ss(t_info *info);
void	rr(t_info *info);
void	rrr(t_info *info);

/* operatoin_cmd.c */
int		add_cmd_to_list(t_op_list **list, t_op cmd);
char	*get_cmd(t_op cmd);
void	print_cmd_list(t_op_list *list);
t_op	get_ri_cmd(t_p_stk op_stk, size_t rx_times, size_t y_insert_idx);
size_t	get_cmd_list_size(t_op_list *list);

/* preprocess.c */
int		*get_sorted_array(t_info *info);
void	get_compressed_dimension(t_info *info);
bool	check_arg_valid(t_info *info);
bool	check_input_sorted(t_info *info);

/* exec_sort.c */
void	exec_sort(t_info *info);
void	sort_a_a2z_small_case(t_info *info, size_t size);

/* get_cost.c */
size_t	get_cost_x_to_y(int num, t_stack *stk_x, t_stack *stk_y, int is_sort_a2z);
size_t	get_r_times(t_stack *stk, int num);
size_t	get_insert_idx(t_stack *stk, int num, int is_a2z);
size_t	get_rx_times(t_info *info, int num, t_p_stk op_stk);
size_t	get_y_insert_idx(t_info *info, int num, t_p_stk op_stk, int is_a2z);
size_t	get_ri_times(size_t rx_times, size_t y_insert_idx);


/* optimize_cmd.c */
void	optimize_cmd(t_info *info);

/* utils.c */
int		max_int(int a, int b);
int		min_int(int a, int b);

/* print.c */
void	print_stacks(t_info *info, char *str);
void	print_stack_value(t_stack *stk, char *str);
void	print_stacks_val_and_ptr(t_info *info, char *str);
void	print_num_array(int *array, size_t elem_cnt, char *str);
void	print_cmd_list_with_msg(t_op_list *list, char *msg);

#endif
