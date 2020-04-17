<p align="center">
  <img src="http://www.holbertonschool.com/holberton-logo.png" alt="Holberton School logo">
</p>

# Simple Shell project 0x16.c - Zeus -

This is a simple UNIX command interpreter based on bash and Sh.

## Overview

**Zeus** is a sh-compatible command language interpreter that executes commands read from the standard input or from a file.

### Invocation

Usage: **Zeus** 
Zeus is started with the standard input connected to the terminal. To start, compile all .c located in this repository by using this command: 
```
gcc -Wall -Werror -Wextra -pedantic *.c -o Zeus
./Zeus
```

**Zeus** is allowed to be invoked interactively and non-interactively. If **Zeus** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:
```
$ echo "echo 'holberton'" | ./Zeus
'holberton'
$
```

When **Zeus** is invoked with standard input connected to a terminal (determined by isatty(3), the interactive mode is opened. **Zeus** Will be using the following prompt `:v: `.

Example:
```
$./Zeus
:v:
```

### Environment

Upon invocation, **Zeus** receives and copies the environment of the parent process in which it was executed. This environment is an array of *name-value* strings describing variables in the format *NAME=VALUE*. A few key environmental variables are:

#### HOME
The home directory of the current user and the default directory argument for the **cd** builtin command.

```
$ echo "echo $HOME" | ./Zeus
/home/vagrant
```

#### PWD
The current working directory as set by the **cd** command.

```
$ echo "echo $PWD" | ./Zeus
/home/vagrant/Holberton/simple_shell
```

#### PATH
A colon-separated list of directories in which the shell looks for commands. A null directory name in the path (represented by any of two adjacent colons, an initial colon, or a trailing colon) indicates the current directory.

```
$ echo "echo $PATH" | ./Zeus
/home/vagrant/.vscode-server/bin/a9f8623ec050e5f0b44cc8ce8204a1455884749f/bin:/home/vagrant/.vscode-server/bin/a9f8623ec050e5f0b44cc8ce8204a1455884749f/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
```



## Authors & Copyrights

* [AntonioEstela](https://github.com/AntonioEstela)
* [21Insight](https://github.com/21Insight)

## More information

**Zeus** is a simple shell unix command interpreter that is part of the holberton low level programming module at Holberton School and is intended to emulate the basics **sh** shell. All the information given in this README is based on the **Zeus** and **bash** man (1) pages.