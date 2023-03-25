# Bash Shell $$

## Basic Commands
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
10. `cp`: copy the contents of the source file($1) to the target file($2)

## File Operations
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

## Shell Scripting
1. `read`: read input from stdin
2. string operation
    - `${#a}`: length of string a
    - `${a:6:3}`: get the substring of a from position 6 with a length of 3
    - `${a/$from/$to}`: returns the string formed by replacing the first occurrence of `from` with `to`.
3. `${10}`: get command line argument `10` from stdin
4. for loop structure
    ```
    for stuff in $(command)/file...
    do
        #command
    done
    ```
5. if statement structure
    ```
    if [# condition]; then
        # command
    elif [# condition]; then
        # command
    else
        # command
    fi
    ```
6. Comparison statements
    - comparing integers: use `-eq`, `-ne`, `-ge`, `-le`, `-gt`, `-lt`
    - comparing strings: use `==`, `!=`, `\>`, `\<`
7. File/Directory Checking
    - `-e $file`: true iff the file exists
    - `-d $file`: true iff the file is a directory
    - `-f $file`: true iff the file is a file
    - `-s $file`: true iff the file has a size > 0
    - `-r $file`: true iff the file is readable
    - `-w $file`: true iff the file is writable
    - `-x $file`: true iff the file is executable


## Regular Expression
1. `.`: match any character
2. `?`: match character with **zero or one occurrence**
3. `+`: match character with **one or more occurrences**
4. `*`: match character with **zero or more occurrences**
5. `^`: match the beginning of a line only
6. `$`: match the end of a line only
7. `[]`: character enclosed will be matched. This can be a single or a range of characters
8. `\`: Use this to escape the special meaning of a metacharacter.
9. `{n}`: match character with **n occurrences**
10. `{n,}`: match character with **n or more occurrences**
11. `{n,m}`: match character with **n to m occurrences**




