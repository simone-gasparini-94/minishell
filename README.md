## Description
Simplified shell that replicates many fundamental behaviours of *bash*.
It uses the *readline* API for input handling.

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
