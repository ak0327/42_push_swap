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

# include "./../lib/libft/libft.h"
# include "./../lib/libgnl/get_next_line.h"
# include "./../lib/libftprintf/ft_printf.h"

# define PASS			1
# define FAIL			0
# define ALREADY_SORTED	2

typedef struct s_info		t_info;
typedef struct s_stack_elem	t_stack;
typedef struct s_op_list	t_op_list;
typedef struct s_cost		t_cost;

typedef enum e_op_cmd		t_op;
typedef enum e_push_op_stk	t_push_stk;
typedef enum e_shift_type	t_op_type;
typedef enum e_init_push	t_init_push;

enum e_op_cmd
{
	E_SA = 0,
	E_SB = 1,
	E_SS = 2,
	E_PA = 3,
	E_PB = 4,
	E_RA = 5,
	E_RB = 6,
	E_RR = 7,
	E_RRA = 8,
	E_RRB = 9,
	E_RRR = 10,
	E_ERROR = 11
};

enum e_init_push
{
	E_TOP,
	E_MIDDLE
};

enum e_push_op_stk
{
	E_PUSH_A2B,
	E_PUSH_B2A
};

enum e_shift_type
{
	E_RX_RY,
	E_RX_RRY,
	E_RRX_RY,
	E_RRX_RRY
};

struct s_stack_elem
{
	int					raw_value;
	int					val;
	struct s_stack_elem	*prev;
	struct s_stack_elem	*next;
};

struct s_op_list
{
	enum e_op_cmd		cmd;
	struct s_op_list	*next;
};

struct s_cost
{
	enum e_shift_type	shift_type;
	size_t				out_idx;
	size_t				in_idx;
	size_t				out_frm_bottom;
	size_t				in_frm_bottom;
	size_t				size_x;
	size_t				size_y;
	size_t				cost_rx_ry;
	size_t				cost_rx_rry;
	size_t				cost_rrx_ry;
	size_t				cost_rrx_rry;
};

struct s_info
{
	struct s_stack_elem	*stk_a;
	struct s_stack_elem	*stk_b;
	struct s_op_list	*op_list;
	size_t				input_num_cnt;
	int					*sorted_array_m;
	bool				is_already_sorted;
	struct s_cost		*cost_m;
};

/* init.c */
void	init_calc_cost_params(t_info *info);
t_info	*init_params(int argc);

/* get_input_nums */
int		get_input_nums(char ***argv, t_info *info);

/* ft_stack.c */
t_stack	*create_stack_elem(int num);
t_stack	*get_last_elem(t_stack *elem);
void	ft_stack_clear(t_stack **stk);

/* ft_stack_operation.c */
void	add_right(t_stack *elem, t_stack **stk);
void	add_left(t_stack *elem, t_stack **stk);
t_stack	*pop_left(t_stack **stk);
t_stack	*pop_right(t_stack **stk);

/* ft_stack_get.c */
size_t	get_stack_size(t_stack *stk);
int		get_max_val(t_stack *stk);
int		get_min_val(t_stack *stk);

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
void	print_op_list(t_op_list *list, bool is_print_cnt);
void	cmd_list_clear(t_op_list **list);
size_t	get_oplist_size(t_op_list *list);

/* preprocess.c */
int		*get_sorted_array(t_info *info);
void	compress_dimension(t_info *info);
int		check_arg_valid(t_info *info);

/* exec_sort.c */
void	exec_sort(t_info *info, t_init_push pattern);

/* push_num_controller.c */
void	push_a2b_opt_elem_for_z2a(t_info *info);
void	push_b2a_opt_elem_for_a2z(t_info *info);

/* push_num_x2y.c */
void	push_num_x2y(t_info *info, int n, t_push_stk op_stk, t_op_type op_type);

/* get_cost.c */
size_t	calc_x2y_cost_controller(t_info *info, int push_num, t_push_stk op_stk);

/* get_cost_helper.c */
size_t	calc_cost_rx_ry(t_info *info);
size_t	calc_cost_rx_rry(t_info *info);
size_t	calc_cost_rrx_ry(t_info *info);
size_t	calc_cost_rrx_rry(t_info *info);
void	get_cost_params(t_info *info, int push_num, t_push_stk op_stk);

/* get_idx.c */
size_t	get_in_idx(t_stack *stk, int num, int is_a2z);
int		get_val_idx(t_stack *stk, int val);

/* optimize_cmd.c */
void	optimize_cmd(t_info *info);

/* utils.c */
int		max_int(int a, int b);
int		min_int(int a, int b);
size_t	get_min_in_four_nums(size_t x, size_t y, size_t z, size_t n);
void	free_and_exit_with_msg_fd(t_info *info, int exit_no, char *msg, int fd);
void	free_allocs(t_info *info);

/* print.c */
void	print_stacks(t_info *info, char *str);
void	print_stack_value(t_stack *stk, char *str);
void	print_stacks_val_and_ptr(t_info *info, char *str);
void	print_num_array(int *array, size_t elem_cnt, char *str);
void	print_cmd_list_with_msg(t_op_list *list, char *msg);

#endif
