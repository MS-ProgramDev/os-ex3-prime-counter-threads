# OS Exercise 3 - Counting Prime Numbers with Threads (C, Linux)

This project is an academic programming assignment in Operating Systems.  
It demonstrates thread creation, synchronization using mutex locks, and thread management in C on Linux.  
Each thread calculates the number of prime numbers in a specific sub-range of a given numeric range.

---

## Project Details

The program accepts three integer arguments:
- The first two arguments define the numerical range (low-high).
- The third argument specifies the step (range size) for each thread.

The computation is distributed among multiple threads, each counting primes within its allocated sub-range. The results from each thread are aggregated to report the total number of prime numbers found.

---

## Provided Files (Do not modify)

- `ex3_q1_given.c`, `ex3_q1_given.h`:  
  Contain predefined helper functions for thread handling and reporting.

---

## Implementation Files

- `ex3_q1.c`: Main driver code implementing thread creation and synchronization logic.
- `my_libary_fun.c/h`: Utility functions for checking prime numbers, thread counting logic, and synchronization mechanisms.
- `Makefile`: Used to compile the program.

---

## Compilation

Compile the project using:
```bash
make
```

This will generate the executable `ex3_q1`.

---

## Usage

Run the executable with three arguments:
```bash
./ex3_q1 <low> <high> <step>
```

Example:
```bash
./ex3_q1 1 100 10
```

This command counts prime numbers between 1 and 100, with each thread handling a range of 10 numbers.

---

## Author

Maor Sapo – Third-year Computer Science student, passionate about system programming and Linux environments.

---

## License

This project is for educational purposes only.
