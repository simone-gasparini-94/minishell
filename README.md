*This project has been created as part of the 42 curriculum in collaboration with [Dante Uccello](https://github.com/duccello)*

## Description
Simplified shell that replicates many fundamental behaviours of **Bash**.

It uses the [readline](https://www.man7.org/linux/man-pages/man3/readline.3.html) API for input handling.

*Note: some functions of the readline API leak memory, these leaks are not explicitly cleaned in this project.*

## Features
- Built-in commands:
	- `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- External commands
- `'` (single quotes) and `"` (double quotes)
- Redirections (`<`, `>`, `<<`, `>>`)
- Pipes (`|`)
- Environment variables (`$HOME`, etc.)
- Exit status tracking (`$?`)
- Signals (`Ctrl-C`, `Ctrl-D`, and `Ctrl-\`)
