# Simple Terminal Calculator

A lightweight, high-performance math expression evaluator built in C++. It uses a custom **Lexer**, **Recursive Descent Parser**, and an **Abstract Syntax Tree (AST)** to process mathematical expressions with proper operator precedence.

## 🚀 Features

* **Dual Mode:** Use it as a one-off command-line tool or an interactive shell.
* **AST-Based:** Correctly handles operator precedence (multiplication before addition).
* **Clean Output:** Uses standard base-10 formatting for results.
* **Zero Dependencies:** Pure C++ using only the standard library.

---

## 🛠 Usage

### 1. Interactive Mode

Run the program without arguments to enter the REPL (Read-Eval-Print Loop).

```bash
$ ./calc
> 5 + 5
 = 10
> 10 * 2 + 3
 = 23
> [Press Enter to Exit]

```

### 2. Direct Command Mode

Pass an expression as a string argument for a quick calculation.

```bash
$ ./calc "20 / 4 + 7"
12

```

---

## 🏗 Architectural Flow

The calculator processes your input through three distinct stages:

1. **Lexer:** Breaks the raw string into tokens (Numbers, Operators, Parentheses).
2. **Parser:** Organizes tokens into an **AST** based on mathematical grammar.
3. **Evaluator:** Recursively traverses the tree to produce the final `float` result.

---

## 🔨 Building with CMake

This project uses CMake for a portable build process. Follow these steps to build the executable:

```bash
# 1. Create a build directory
mkdir build && cd build

# 2. Configure the project
cmake ..

# 3. Build the executable
cmake --build .

```

The resulting `calc` binary will be located in the `build` directory.

---

## ⚠️ Notes

* **Precision:** Uses `float` for evaluations.
* **Error Handling:** Returns `NaN` (Not a Number) if the parser fails to generate a valid root.
* **Exiting:** In interactive mode, simply press `Enter` on an empty line to quit.

### Author & License

Maks Makuta © 2026  
No License - fell free to use that code in any way you need