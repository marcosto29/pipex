# Pipex

Pipex is an interesting project which simulates the execution of Unix terminal commands located in PATH with the help of C.

## Main flux

The main objective of the program is to find and execute Unix commands submitted by the user. The specific approach developed allows the user to use as many pipes and execute as many commands as desired. It also includes interesting features, such as the implementation of the "here_doc" functionality. The user can decide whether to use standard input (fdi)/terminal or use an existing input file.

To achieve the desire program it uses the execve function, this can result on different problems since as written on the documentation, the process which calls execve will die to replace it with the new one. As mentioned this can result on data loss problems.

Because of this, the main process relies on different features given by the fork and pipe functions. With the correct use of these functions, the main process can behave like a tree, creating branches to execute different commands and taking the output of these executions by reading a communication pipe.

![alt text](https://github.com/marcosto29/pipex/blob/main/Pipex%20flux.png "Pipex flux")

### Pipe and Fork

As explained above, the main process uses the fork function to fork and create a sub-process with the exact state and information of the parent: variables, useful data, etc. This new child calls the execve function, dying without the risk of killing the parent.

Now, with one main process and one sub-process, the risk of killing the parent is solved. However, without proper communication, creating and running a child that will eventually die is useless. To address this issue, the parent creates a communication pipe before the fork. This pipe allows for simple communication with input and output data. Once the pipe is created and the fork is executed, the child closes the read end, and the parent closes the write end. This way, one of them can only write and one read, achieving the desired state: the child can share information with the parent.

![alt text](https://github.com/marcosto29/pipex/blob/main/Fork_and_pipe.png "Fork and pipe")

With this hierarchy established, the child begins the execution of the code, it now has the command which the user wants to execute and the initial or previous input for the command. Reading the documentation of execve, the arguments needed to properly call the function are: the path to the new program, the arguments and the enviroment.

Normally, when calling a command in the terminal, the user doesn't type the full path, but simply calls the command name, and the terminal is responsible for searching for it in the PATH variable. This program works exactly the same.

### dup2

Once the child program begins execution, the first thing it does, like its parent, is create a pipe and branch to create another child program. This new child program is responsible for searching for the given command in the PATH variable. To do this, it calls the which command.

A final important feature of this program is the way it redirects standard input and output so that the result of a process's execution is not lost. The previously created pipes are very important. Before calling the execve function, the dup2 function redirects standard input and/or output to the pipes. In this way, the result of the execution is sent to the pipes, making them accessible to the respective parents, who can then read them.
