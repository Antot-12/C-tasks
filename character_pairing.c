#include <stdio.h>
#include <string.h>

int main() {
    char name[2][20] = { {""},{""} };
    int j, len;
    printf("Enter your name, please: \n");
    scanf("%s", &name[0]);
    scanf("%s", &name[1]);
    if (strlen(name[0]) > strlen(name[1]))
        len = strlen(name[0]);
    else
        len = strlen(name[1]);
    for (j = 0; j < len; j++) 
    {
        printf("%c %c\n", name[0][j], name[1][j]);
    }
    return 0;
}