This project was a big part of 42, we took 5 months to complete because there's a huge amount to do.

We had to implement a shell like bash in C, we did pipes, redirects, environment variables and some built-in functions like export, unset, exit, etc. It was a lot of stuff to do.

The amount of information was enormous, it was one of the first group jobs. I learned a few tricks of teamwork and improved my skills of explanation, understanding and patience.

To start this project, you need to install readline with : "brew install readline". After that, it will give you the path to readline and you'll have to change the Makefile on lines 61-62.

LIBS    =   -L/usr/local/opt/readline/lib -lreadline

HEADERS =   -I/usr/local/opt/readline/include

just change the path </usr/local/opt/readline/lib> and <usr/local/opt/readline/include>