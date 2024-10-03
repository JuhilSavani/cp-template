# Competitive Programming Template

---

This repository contains a comprehensive C++ template designed for competitive programming. The template includes useful macros, typedefs, and frequently used algorithms to make problem-solving more efficient and structured during contests.

## Features

- **Type Definitions:** Commonly used types such as `ll`, `ull`, `pii`, `pll`, etc.
- **Macros:** A wide range of macros to simplify loops, I/O operations, and container manipulations.
- **Debugging Helpers:** Easy-to-use debugging tools for printing variables during execution, so you can quickly track down issues.
- **Utility Functions:** Includes implementations of binary search, prime checking, prime factorization, and more.
- **Fast I/O Setup:** Optimized input/output setup for faster execution during competitive programming contests.

## Usage

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/JuhilSavani/cp-template.git
   ```

2. **Use the Template**:
   - Copy the `main.cpp` file into your working directory for competitive programming contests.
   - Start coding in the `solve()` function for each problem.

## Macros and Functions Overview

### Common Macros

- `fori(n)`, `forj(n)`, `f(i, x, n)` – Looping macros.
- `sz(cn)` – Returns the size of a container.
- `unq(v)` – Removes duplicate elements from a vector.
- `pb`, `pf`, `pp` – Shortcuts for push_back, push_front, and pop_back, respectively.

### Utility Functions

- `safe_lcm(a, b)` – Returns the LCM of two numbers, ensuring it doesn't overflow.
- `binarySearch(v, q)` – Performs a binary search on a sorted vector `v` for value `q`.
- `isPrime(n)` – Checks if a number is prime using the 6k ± 1 optimization.
- `primeFactors(n)` – Returns the unique prime factors of `n`.

### Debugging Tools

- `dbg(x...)` – Prints variables for debugging purposes.
- `dbgcs(cs, x...)` – Prints variables for a specific test case `cs`.

## Contribution

Feel free to contribute to this repository by adding more useful macros, functions, or improving the template.

---
