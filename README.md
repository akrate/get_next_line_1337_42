Get Next Line
Description
The get_next_line project provides a custom implementation for reading one line at a time from a file or standard input. It works with a file descriptor (fd) and handles the accumulation of data in memory to ensure that lines can be read until the end of the file or input is reached. This is useful for processing files line by line efficiently.

The code supports reading from any file descriptor and processes input in chunks using a buffer of configurable size (BUFFER_SIZE), which allows for scalable memory usage.
