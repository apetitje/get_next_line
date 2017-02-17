# get_next_line

Stocks a malloced string for each line of a file or standard input, 
then returns 1 while reading, 0 when finished reading and -1 in case of error.

int get_next_line(const int fd, char **line)
