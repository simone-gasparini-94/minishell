## Description
Simplified shell that replicates many fundamental behaviours of **Bash**.

It uses the [readline](https://www.man7.org/linux/man-pages/man3/readline.3.html) API for input handling. Its memory leaks are not fixed.

This project is a collaboration with [Dante Uccello](https://github.com/duccello).

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
