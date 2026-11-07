# Simple Calculator

A command-line calculator written in C. It shows a menu, asks for two numbers and prints the result of the chosen operation, until the user quits.

## Compilation

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator
```

## Usage

```
./calculator
```

```
Simple calculator
1) Add
2) Substract
3) Multiply
4) Divide
0) Quit
Choice: 1
A: 10
B: 4
Result: 14
```

| Choice | Operation | Result |
|---|---|---|
| 1 | A + B | integer |
| 2 | A - B | integer |
| 3 | A * B | integer |
| 4 | A / B | decimal |
| 0 | Quit | prints `Bye!` |

## Number handling

- **Input:** A and B must be integers (negative numbers are accepted). Any other input (`abc`, `12abc`, `2.5`) is refused with `Only digit accepted`, and the number is asked again.
- **Addition, subtraction, multiplication:** the result is an integer.
- **Division:** the result is a decimal, so that `10 / 4` gives `2.5` and not `2`.
- **Division by zero:** if B is 0, the program prints `Error: division by zero` and returns to the menu.

## Files

| File | Description |
|---|---|
| `calculator.c` | Source code: `read_number` (reads a valid integer) and `main` (menu and operations) |
| `README.md` | This file |

## Author

SgtJeanSerge
