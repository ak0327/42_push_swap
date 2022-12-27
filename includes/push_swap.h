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

typedef enum e_op_cmd		t_op_cmd;
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
	int					a_min;
	int					a_max;
	int					b_min;
	int					b_max;


};

t_stack	*create_stack_elem(int num);
void	add_left(t_stack *elem, t_stack **stk);
void	add_right(t_stack *elem, t_stack **stk);
t_stack	*pop_left(t_stack **stk);
t_stack	*pop_right(t_stack **stk);
size_t	get_stack_size(t_stack *stk);
void	ft_stack_iter(t_stack *stk, void (*f)(void *));
void	print_stack_value(t_stack *stk, char *str);
void	ft_stack_clear(t_stack **stk);

void	operation_controller(t_info *info, t_op_cmd cmd);

int		add_cmd_to_list(t_op_list **list, t_op_cmd cmd);

int		*get_sorted_array(t_info *info);
bool	check_arg_valid(t_info *info);
bool	check_input_sorted(t_info *info);

void	get_compressed_dimension(t_info *info);

void	exec_sort(t_info *info);
void	sort_a_a2z_small_case(t_info *info, size_t size);

void	optimize_cmds(t_info *info);

char	*get_cmd(t_op_cmd cmd);

void	print_stacks(t_info *info, char *str);
void	print_stacks_val_and_ptr(t_info *info, char *str);
void	print_num_array(int *array, size_t elem_cnt, char *str);
void	print_cmd_list_with_msg(t_op_list *list, char *msg);

void	print_cmd_list(t_op_list *list);


#endif
