*This project has been created as part of the 42 curriculum by obehlil.*

# Push_swap

Push_swap is a highly efficient algorithm project that focuses on sorting data on a stack, with a limited set of instructions, and the lowest possible number of actions. To succeed, you have to manipulate various sorting algorithms and choose the most appropriate solution for an optimized data sorting.

## Description

The goal of this project is simple: sort a list of integers using two stacks and a specific set of operations. You start with stack **A** filled with a random amount of negative and/or positive numbers which cannot be duplicated, and stack **B** is empty.

The objective is to sort the numbers in ascending order into stack **A** using the following operations:
- **sa/sb/ss**: Swap the first two elements at the top of stack A/B or both.
- **pa/pb**: Push the first element from the top of one stack to the other.
- **ra/rb/rr**: Shift up all elements of stack A/B or both by 1. The first element becomes the last one.
- **rra/rrb/rrr**: Shift down all elements of stack A/B or both by 1. The last element becomes the first one.

### Performance Targets
- **100 numbers**: Less than 700 operations.
- **500 numbers**: Less than 5500 operations.

## Instructions

### Compilation

The project includes a `Makefile` with the standard rules: `all`, `clean`, `fclean`, and `re`. To compile, run:

```bash
make
```

This will produce the `push_swap` executable.

### Execution

To run the program, pass a list of integers as arguments:

```bash
./push_swap 4 67 3 87 23
```

You can also pass the numbers as a single string:

```bash
./push_swap "4 67 3 87 23"
```

### Verification

To verify if the output correctly sorts the numbers, you can use the provided `checker_linux` (or the one matching your OS):

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

If the sorting is correct, it will display `OK`.

## Resources

- **Algorithm Inspiration**: The implementation uses a variation of the "Mechanical Turk" algorithm (also known as the "Cheapest Move" or "Cost-based" algorithm), which calculates the cost of moving each element from stack B to its correct position in stack A and executes the most efficient one.
- **42 Subject**: The official project documentation provided by 42.
- **Visualizers**: Various community-made visualizers were used to debug and witness the algorithm's efficiency in real-time.

### AI Usage

Artificial Intelligence was utilized in the following ways during this project:
- **Algorithm Optimization**: AI helped brainstorm the cost calculation logic and the "chunking" strategy for pushing elements from stack A to B.
- **Debugging**: Assisting in identifying edge cases (e.g., INT_MIN/INT_MAX, empty strings, or duplicate handling) and fixing memory leaks.
- **Documentation**: Generating parts of the `README.md` and commenting complex logic in the source code to improve maintainability.
- **Performance Testing**: Designing the `test_performance.sh` script to automate large-scale testing and verify operation counts against 42's benchmarks.

## Usage Example

```bash
$ ./push_swap 2 1 3
sa
$ ./push_swap 5 2 3 1 4
pb
pb
ra
sa
pa
pa
```
