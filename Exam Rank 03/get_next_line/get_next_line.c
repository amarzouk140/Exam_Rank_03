#include "get_next_line.h"

char *get_next_line(int fd)
{
    int i;
    int bytes;
    char *buffer;
    char reading;

    if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
        return (NULL);
    i = 0;
    bytes = read(fd, &reading, 1);
    buffer = malloc(sizeof(char *) * (size_t)BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    while (bytes > 0)
    {
        buffer[i++] = reading;
        if(reading == '\n')
            break;
        bytes = read(fd, &reading, 1);
    }
    if((bytes <= 0) && (i == 0))
        return (free(buffer), NULL);
    buffer[i] = '\0';
    return (buffer);
}

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *test = get_next_line(fd);
    free(test);
    
//     while(test)
//     {
//         printf("%s\n", test);
//         free(test);
//         test = get_next_line(fd);
//     }
}