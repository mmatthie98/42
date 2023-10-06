The aim of this project was to reimplement shell pipes in C. This allowed me to familiarize myself with the fork() function.

This function allows you to create new processes (child processes), which have the same attributes as their parents and follow the same code.

I used it for multipipes: as long as I'm not at the last command, I create a child process to execute the command and place the output in a pipe, retrieve the input in the pipes and continue recursively.

To lauch the project u had to make in the folder and : ./pipex infile "cmd" "cmd" outfile.