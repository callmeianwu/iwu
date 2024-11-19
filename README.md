<div align="center">

```
╭━━━╮╱╱╱╱╱╭━━━╮╱╱╱╱╭━━━╮
┃╭━╮┃╱╱╱╱╱┃╭━╮┃╱╱╱╱┃╭━╮┃
┃┃╱┃┣━╮╭━╮┃┃╱┃┣━╮╭━┫┃╱┃┃
┃┃╱┃┃╭╮┫╭╯┃┃╱┃┃╭╮┫╭┫┃╱┃┃
┃╰━╯┃┃┃┃┃╱┃╰━╯┃┃┃┃┃┃╰━╯┃
╰━━━┻╯╰┻╯╱╰━━━┻╯╰┻╯╰━━━╯
```

# IWU - RPN-Based Programming Language 🚀

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
![Version](https://img.shields.io/badge/version-1.0.0-blue)
![Stack Based](https://img.shields.io/badge/paradigm-stack_based-purple)

*Where RPN meets modern programming* 🌟

[Installation](#installation) • [Language Guide](#language-guide) • [Examples](#examples) • [Contributing](#contributing)

</div>

## 🎯 About IWU

IWU is a stack-based programming language that uses Reverse Polish Notation (RPN) for calculations. It combines the elegance of postfix notation with easy-to-use functions and a straightforward printing system.

## 🚀 Key Features

### 📐 RPN (Reverse Polish Notation) Based
```ruby
3 4 + 2 *    # (3 + 4) * 2 = 14
5 2 / 6 -    # (5 / 2) - 6 = -3.5
```

### 📦 Variable Declaration
```ruby
i x = 4          # Initialize variable 'x'
i y = 3 4 +      # Initialize 'y' with an RPN expression
y = x y +        # Update existing variable
```

### 🔧 Built-in Functions
```ruby
sum 1 2 3 4      # Calculate sum of numbers
max 10 20 5      # Find maximum value
min 5 8 2        # Find minimum value
```

### 🖨️ Print Commands
```ruby
pl x = 5         # Prints the line "x = 5"
pr x             # Prints the value of x
pl pr x          # Prints line with result (e.g., "x = 5 -> 5")
```

## 💻 Installation

```bash
# Compile the interpreter
g++ iwu.cpp -o iwu

# Run your IWU program
./iwu your_program.txt
```

## 📖 Language Guide

### Syntax Rules

1. **RPN Calculations**
   - All mathematical expressions use postfix notation
   - Operators: `+`, `-`, `*`, `/`
   - Example: `5 3 + 2 *` equals `(5 + 3) * 2`

2. **Variables**
   - Must be declared with `i` prefix
   - Can be updated after declaration
   - Example:
     ```ruby
     i x = 5          # Declaration
     x = x 2 +        # Update
     ```

3. **Print Commands**
   - `pl` - Print the entire line
   - `pr` - Print the result
   - Can be combined: `pl pr x`

4. **Comments**
   - Use `//` for line comments
   - No space required between `//` and comment text

## 🌟 Examples

### Basic Calculations
```ruby
3 4 + 2 *           # Stack-based calculation
i result = 10 2 *   # Store in variable
pl pr result        # Print result
```

### Function Usage
```ruby
i x = 5
i y = 4
y = sum x y         # Use sum function
pl pr y             # Show result
```

### Complex Program
```ruby
i a = 10
i b = 5
i c = a b + 2 *     # RPN expression
pl pr c             # Print result
sum a b c           # Use built-in function
```

## ⚠️ Important Notes

1. Function names (`sum`, `min`, `max`, `pl`, `pr`) cannot be used as variable names
2. All calculations must follow RPN syntax
3. Variable declarations must use the `i` prefix
4. Comments start with `//` and continue to end of line

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## 📜 License

MIT License - See LICENSE file for details

<div align="center">

### Built with 💻 by developers, for RPN enthusiasts

</div>
