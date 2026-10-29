# get_next_line

A function that reads a file descriptor one line at a time, built at École 42 (Brussels).

```c
char *get_next_line(int fd);
```

Each call returns the next line (with its `\n`), or `NULL` at end of file or on error. The buffer size is set at compile time.

The bonus version (`*_bonus.c`) handles several file descriptors at once with a single static variable per fd.

## Use

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```
