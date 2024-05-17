//42hDRfypTqqnw

#include <stdio.h>

int main()
{
    int i = 0;
    char *str = "42hDRfypTqqnw";
    char tmp[14];
    while (str[i] && i < 13)
    {
        tmp[i] = str[i] + 35;
        i++;
    }
    tmp[i] = '\0';
    printf("%s\n", tmp);
    return 0;

}