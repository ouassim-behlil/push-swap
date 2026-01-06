#include "pushSwap.h"

static bool is_valid_argv(int argc, char **argv)
{
    int i;
    int j;

    j = 1;
    if (argc < 2)
        return (false);
    while (j < argc)
    {
        i = 0;
        while (argv[j][i])
        {
            if (!is_digit(argv[j][i])
                && !is_white_space(argv[j][i])
                && !(argv[j][i] == '-' || argv[j][i] == '+'))
                return (false);
            i++;
        }
        j++;
    }
    return (true);
}

static bool has_duplicates(t_stack *stack)
{
    t_node  *outer;
    t_node  *inner;

    outer = stack->top;
    while (outer)
    {
        inner = outer->next;
        while (inner)
        {
            if (inner->value == outer->value)
                return (true);
            inner = inner->next;
        }
        outer = outer->next;
    }
    return (false);
}

static t_stack  *parse_fill_stack(int argc, char **argv)
{
    t_node  *node;
    t_stack *stack;
    int     value;
    int     error;

    if (argc < 2 || !is_valid_argv(argc, argv))
        return (NULL);
    stack = create_empty_stack();
    if (!stack)
        return (NULL);
    while (--argc > 0)
    {
        value = ft_atoi(argv[argc], &error);
        if (error)
            return (free_stack(stack), NULL);
        node = create_node(value);
        if (!node)
            return (free_stack(stack), NULL);
        push(stack, node);
    }
    if (has_duplicates(stack))
        return (free_stack(stack), NULL);
    return (stack);
}

static t_stack  *split_fill_stack(char **splitted, int word_count)
{
    t_node  *node;
    t_stack *stack;
    int     value;
    int     error;
    int     i;

    if (!splitted)
        return (NULL);
    i = word_count - 1;
    stack = create_empty_stack();
    if (!stack)
        return (NULL);
    while (i >= 0)
    {
        value = ft_atoi(splitted[i], &error);
        if (error)
            return (free_stack(stack), NULL);
        node = create_node(value);
        if (!node)
            return (free_stack(stack), NULL);
        push(stack, node);
        i--;
    }
    if (has_duplicates(stack))
        return (free_stack(stack), NULL);
    return (stack);
}

t_stack *create_fill_stack(int argc, char **argv)
{
    t_stack *stack;
    char    **split;
    int     word_count;

    if (argc < 2)
        return (NULL);
    if (argc == 2)
    {
        word_count = ft_countwords(argv[1], ' ');
        split = ft_split(argv[1], ' ');
        stack = split_fill_stack(split, word_count);
        free_split(split);
        return (stack);
    }
    return (parse_fill_stack(argc, argv));
}
