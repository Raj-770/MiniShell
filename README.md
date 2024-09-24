<div align="center">
  <h1>
    🐚 Minishell
  </h1>
  <p>
    <b><i>A custom shell environment designed to emulate basic features of traditional UNIX shells</i></b>
  </p>
  <p>
    Developed using&nbsp&nbsp
    <a href="https://skillicons.dev">
      <img src="https://skillicons.dev/icons?i=c,vscode,git" />
    </a>
  </p>
</div>

<br />

## Table Of Contents
- [Features](#features)
- [Installation](#installation)
- [Contributors](#contributors)
- [License](#license)

## Features
- **Command Execution:** Ability to execute standard Unix/Bash commands.
- **Built-in commands:** Includes multiple built-ins such as:
  - `cd` with only a relative or absolute path.
  - `pwd` with no options.
  - `echo` with option -n.
  - `env` with no options or arguments.
  - `exit` with no options.
  - `unset` with no options.
  - `export` with no options.
- **Command History:** Keeps track of previous commands by using the up & down arrow keys.
- **Expansion:** Our program interprets and handles environment variable expansion within quotes. Within single quotes its interpreted as a literal value while in double quotes it expands (if its a valid `env` variable), mirroring Bash's behaviour. It also supports expansion in heredocs.
- **Signal Handling:** Includes features like interrupt (`Ctrl+C`), quit (`Ctrl+\`), and EOF (`Ctrl+D`). The signals behave similar to bash.
- **Error Handling:** Includes protection for `malloc()`, `pipe()`, `fork()` and more. It also provides clear error messages (E.g. command not found, syntax error, no permission, malloc fail etc..).
- **Redirection And Piping:** Supports intput, output, heredoc, and append redirection (`>`, `<`, `<<`, `>>`). It also supports piping (`|`) allow to command chaining.
- **Memory Management:** Our program frees and  cleansup any memory/file descriptors upon termination, ensuring system stability.
- **Tab Completion:** Auto complete file names by using tab. Also by pressing tab in the prompt displays the current directories files/folders.
- **Documentation:** All functions have doxygen comments to ensure readability and to better understand the underlying logic at a glance.

## Installation
1. Clone the repository
```bash
git clone <reopsitory url>
```
2. Enter the directory and run make
```bash
cd <path to the clone repo>
make
```
3. Run the program
> NOTE: If you are on Linux you must un-comment the `#include <wait.h>` library located: `./includes/includes.h`
```
./minishell
```

## Contributors
- [Raj-770](https://github.com/Raj-770)
- [sshahary](https://github.com/sshahary)

## Liencse
[MIT](https://choosealicense.com/licenses/mit/)
