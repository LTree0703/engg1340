# Bash Commands

### Basic Commands
1. `cd`: change working directory
2. `ls`: list files
    - `-l`: list details of files
    - `-a`: list all files
3. `rm`: remove
    - `-f`: force remove
    - `-r`: remove everything in the directory (dependencies)
        - similar to `rmdir`
4. `mkdir`: create directory
5. `touch`: create file or directory
6. `mv`: move file or directory to another location
7. `pwd`: print working directory
8. `chmod`: change permissions of files or directories (user, other, group)
9. `echo`: print on terminal

### File Operations
1. `cat`: show file contents
2. `tr`: transform one character to another character
    - `-d`: delete the target character
3. `cut`: extract the specified character/word from the file
    - `-d`: specify the delimiter character (default is tab `\t`)
    - `-f`: specify which line to extract (starting from 1)
    - `-c`: specify which character to extract (starting from 1)
4. `grep`: selecting lines that match the specified pattern
    - `-E`: interpret pattern using **extended regular expression**
    - `-c`: only a count of selected lines is written to stdout
5. `sort`: sort the file contents (default is in alphabetically ascending order)
    - `-r`: sort in descending order
    - `-n`: sort in numerically ascending order
    - `-u`: sort and eliminate duplicate lines (same as `uniq`)
6. `uniq`: eliminate adjacent duplicate lines
7. `wc`: display the number of lines, words, and bytes contained in each input file
    - `-c`: only display the number of bytes(characters)
    - `-l`: only display the number of lines
    - `-w`: only display the number of words
7. `head`: show the first 10 lines of a file
    - `-n $(num)`: show the first `num` lines of the file
    - `-c $(num)`: show the first `num` characters of the file

### Bash Scripting
1. `read`: read input from stdin
2. for loop structure
    ```
    for stuff in $(command)/file...
    do
        #command
    done
    ```
3. if statement structure
    ```
    if [# condition]; then
        # command
    elif [# condition]; then
        # command
    else
        # command
    fi
    ```
4. Comparison statements
    - comparing integers: use `-eq`, `-gt`, `-lt`
    - comparing strings: use `=`, `>`, `<`



