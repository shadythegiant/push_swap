_This project has been created as part of the 42 curriculum by azahidi._

# Push_swap

## Description

**Push_swap** is a highly structured algorithmic project involving stack manipulation and sorting. The goal is to write a program in C called `push_swap` which calculates and displays the shortest sequence of instructions needed to sort a given stack of integers.

The project focuses on:

- **Complexity:** Finding the most efficient sorting algorithm for optimized data sorting.
- **Rigor:** Strictly adhering to the "Norm" and memory management rules.
- **C Proficiency:** Utilizing basic algorithms and stack manipulation.

---

### The Rules

You operate with two stacks, named `a` and `b`:

- **Stack a:** Contains a random amount of negative and/or positive numbers which cannot be duplicated.
- **Stack b:** Initially empty.

The allowable operations to sort the stack are:

| Operation           | Description                                         |
| ------------------- | --------------------------------------------------- |
| **sa / sb / ss**    | Swap the first two elements of stack a, b, or both. |
| **pa / pb**         | Push the top element from one stack to the other.   |
| **ra / rb / rr**    | Rotate the stack up (first becomes last).           |
| **rra / rrb / rrr** | Reverse rotate the stack down (last becomes first). |

---

## Implementation & Algorithms

This project implements a highly optimized hybrid algorithm combining **Longest Increasing Subsequence (LIS)** and the **Turk Algorithm**.

### 1. The Pre-Sort Phase: LIS (Longest Increasing Subsequence)

Instead of blindly pushing numbers to Stack B, the program first analyzes Stack A to identify the longest chain of numbers that are _already_ sorted relative to each other.

- **Logic:** It calculates the LIS using an O(N²) dynamic programming approach.
- **Action:** Nodes part of the LIS are kept in Stack A (rotated to the bottom). All other "unsorted" nodes are pushed to Stack B.
- **Benefit:** This ensures Stack A remains a sorted "skeleton," significantly reducing the work needed later.

### 2. The Sort Phase: The Turk Algorithm

Once Stack B is filled with the unsorted numbers, the algorithm moves them back to A using a "Cheapest Move" cost calculation.

- **Target Calculation:** For every node in B, we calculate the best target position in A (the smallest number bigger than the node being pushed).
- **Cost Analysis:** We calculate the cost to move both the node (in B) and its target (in A) to the top of their respective stacks.
- **Optimization:** The calculator identifies "synergies." If both nodes need to rotate UP (`ra` + `rb`) or DOWN (`rra` + `rrb`), we use simultaneous operations (`rr` or `rrr`), effectively halving the cost for those moves.

### 3. Small Sort Optimizations

- **Size 3:** Hard-coded simple sort.
- **Size 5:** Includes a "circular sort" check. If rotating the smallest number to the top solves the sort immediately, no further operations are performed.

---

## Instructions

### Compilation

The project utilizes a `Makefile` for compilation. Use the following rules:

- `make` - Compiles the mandatory `push_swap` executable.
- `make bonus` - Compiles the `checker` executable (if applicable).
- `make clean` - Removes object files.
- `make fclean` - Removes object files and the executables.
- `make re` - Recompiles the project from scratch.

### Execution

**1. The `push_swap` program:**
Run the program with a list of integers as arguments.

```bash
./push_swap 2 1 3 6 5 8
```

**2. Using the `checker` program (if bonus compiled):**
To verify that the sorting instructions are correct, you can pipe the output of `push_swap` into `checker`:

```bash
./push_swap 2 1 3 | ./checker 2 1 3
```

If the output is `OK`, the sequence of operations correctly sorts the stack.

---

### Testing & Verification

The Makefile includes several custom rules to facilitate testing and benchmarking:

- `make run_3` - Runs `push_swap` with 3 random numbers and counts the instructions.
- `make run_5` - Runs `push_swap` with 5 random numbers and counts the instructions.
- `make run_100` - Generates 100 random numbers, runs them through `push_swap`, and outputs the operation count (Target: < 700 ops).
- `make run_500` - Generates 500 random numbers, runs them through `push_swap`, and outputs the operation count (Target: < 5500 ops).
- `make leaks` - Runs `valgrind` with full leak checking flags on a 500-number test case to ensure memory safety.
- `make run_checker` - Generates 500 random numbers and pipes the `push_swap` output into the `checker` program to verify the sort is "OK".

### Argument Handling

The program includes a robust parser capable of handling:

- **Mixed formats:** `./push_swap 1 2 "3 4 5" 6`
- **Multiple spaces:** `./push_swap " 12 43 "`
- **Input validation:** Checks for non-integers, duplicates, and integer overflow.

---

## Resources & References

- **Longest Increasing Subsequence:** [GeeksforGeeks - LIS](https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/)
- **Turk Algorithm Reference:** [Medium Article on Turk Algo](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- **Visualizer:** [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer) - Essential for debugging and verifying move counts.

---

## AI Usage

AI Assistant (Gemini) was utilized in this project for the following tasks:

- **Algorithm Optimization:**
  - Refining the `ft_set_price` function to replace naive sum calculations with `max()` logic for simultaneous rotations (`rr`/`rrr`), reducing operation count by ~20%.
  - Optimizing `sort_five` to detect circularly sorted stacks, reducing moves from 6 to 1 in best-case scenarios.

- **Debugging & Logic Correction:**
  - Identified and fixed a "Phantom Submodule" issue with git repositories for libft and printf.
  - Corrected the "Keep 3" bug in the LIS logic which prevented the stack from fully emptying non-LIS nodes.
  - Fixed "Dangling Else" logic errors in cost calculation.

- **Code Refactoring (Norminette):**
  - Assisted in splitting complex functions (like `calculate_lis_indices` and `ft_set_price`) into static helper functions to strictly adhere to the 42 Norm (25-line limit per function).

- **Concept Visualization:**
  - Provided step-by-step traces and analogies ("Island Hopping" for LIS, "The Accountant" for Cost Calculation) to explain algorithmic complexity.
