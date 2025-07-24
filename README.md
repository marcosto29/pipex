# Pipex

Pipex is an interesting project which simulates the execution of Unix terminal commands located in PATH with the help of C.

## Main flux

The main objective of the program is to find and execute Unix commands submitted by the user. The specific approach developed allows the user to use as many pipes and execute as many commands as desired. It also includes interesting features, such as the implementation of the "here_doc" functionality. The user can decide whether to use standard input (sdI)/terminal or use an existing input file.

To achieve the desire program it uses the execve function, this can result on different problems since as written on the manual, the process which calls execve will die to replace it with the new one. As mentioned this can result on data loss problems.

Because of this, the main process relies on different features given by the fork and pipe functions. With the correct use of these functions, the main process can behave like a tree, creating branches to execute different commands and taking the output of these executions by reading a communication pipe.

![alt text](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 1")
