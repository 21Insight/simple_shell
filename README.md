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

### Command Execution

After receiving a command, **Zeus** tokenizes it into words using `" "` as a delimiter. The first word is considered the command and all remaining words are considered arguments to that command. **Zeus** then proceeds with the following actions:
1. If the first character of the command is neither a slash (`/`) nor dot (`.`), the shell searches for it in the list of shell builtins. If there exists a builtin by that name, the builtin is invoked.
2. If the first character of the command is none of a slash (`/`), dot (`.`), nor builtin, **Zeus** searches each element of the **PATH** environmental variable for a directory containing an executable file by that name.
3. If the first character of the command is a slash (`/`) or dot (`.`) or either of the above searches was successful, the shell executes the named program with any remaining given arguments in a separate execution environment.

### Exit Status 

**Zeus** returns the exit status of the last command executed, with zero indicating success and non-zero indicating failure.
If a command is not found, the return status is 127.
All builtins return zero on success.

### Signals

While running in interactive mode, **Zeus** ignores the keyboard input ctrl+c. Alternatively, an input of End-Of-File ctrl+d will exit the program.

User hits ctrl+d in the foutrh command.
```
$ ./Zeus
:v: ^C
:v: ^C
:v: ^C
:v: ^C
:v: ^C
:v:
```

### Variable Replacement

**Zeus** interprets the `$` character for variable replacement.

#### $ENV_VARIABLE
`ENV_VARIABLE` is substituted with its value.

Example:
```
$ echo "echo $PWD" | ./Zeus
/home/vagrant/Holberton/simple_shell
```

#### $?
`?` is substitued with the return value of the last program executed.

Example:
```
$ echo "echo $?" | ./Zeus
0
```

#### $$
The second `$` is substitued with the current process ID.

Example:
```
$ echo "echo $$" | ./Zeus
1834
```

### Builtin Commands

#### exit
  * Usage: `exit [STATUS]`
  * Exits the shell.
  * The `STATUS` argument is the integer used to exit the shell.
  * If no argument is given, the command is interpreted as `exit 0`.

Example:
```
$ ./Zeus
$ exit
```

#### env
  * Usage: `env`
  * Prints the current environment.

Example:
```
$ ./Zeus
$ env
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
SSH_CONNECTION=10.0.2.2 50105 10.0.2.15 22
LESSCLOSE=/usr/bin/lesspipe %s %s
LANG=C.UTF-8
AMD_ENTRYPOINT=vs/server/remoteExtensionHostProcess
COLORTERM=truecolor
APPLICATION_INSIGHTS_NO_DIAGNOSTIC_CHANNEL=true
XDG_SESSION_ID=3
USER=vagrant
PWD=/home/vagrant/Holberton/simple_shell
HOME=/home/vagrant
TERM_PROGRAM=vscode
SSH_CLIENT=10.0.2.2 50105 22
TERM_PROGRAM_VERSION=1.44.1
XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
VSCODE_IPC_HOOK_CLI=/tmp/vscode-ipc-1bd28d49-d0b1-4691-851d-63c4250833a3.sock
MAIL=/var/mail/vagrant
TERM=xterm-256color
SHELL=/bin/bash
SHLVL=4
PIPE_LOGGING=true
LOGNAME=vagrant
XDG_RUNTIME_DIR=/run/user/1000
PATH=/home/vagrant/.vscode-server/bin/a9f8623ec050e5f0b44cc8ce8204a1455884749f/bin:/home/vagrant/.vscode-server/bin/a9f8623ec050e5f0b44cc8ce8204a1455884749f/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
LESSOPEN=| /usr/bin/lesspipe %s
VERBOSE_LOGGING=true
_=./Zeus
```

## Authors & Copyrights

* [AntonioEstela](https://github.com/AntonioEstela)
* [21Insight](https://github.com/21Insight)

## More information

**Zeus** is a simple shell unix command interpreter that is part of the holberton low level programming module at Holberton School and is intended to emulate the basics **sh** shell. All the information given in this README is based on the **Zeus** and **bash** man (1) pages.
