//keyword found = Cdiiddwpgswtgt
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 

int ftputnb(int nb, int fd)
{
    if (nb > 9)
        ftputnb(nb / 10, fd);
    write(fd, &"0123456789"[nb % 10], 1);
    return 0;
}

int main()
{
    char *str = "cdiiddwpgswtgt";
    char *alphabet = "abcdefghijklmnopqrstuvwxyz";
    char tmp[15];
    int i;

    int fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1)
    {
        printf("Error: open() failed\n");
        return 1;
    }

    if (!str)
    {
        printf("Error: str is NULL\n");
        return 1;
    }
    for (int k = 0; k <= 26; k++)
    {
        i = 0;
        while (str && str[i] && i <= 13)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                if (str[i] + k > 122)
                {
                    if(str[i] + k == 123)
                        tmp[i] = 'a';
                    else
                        tmp[i] = 'a' + (str[i] + k - 123);
                }
                else
                    tmp[i] = str[i] + k;
            }
            i++;
        }
        tmp[i] = '\0';
    }
    return 0;
}