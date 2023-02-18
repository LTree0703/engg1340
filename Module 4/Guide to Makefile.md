# 4a. Guide to Makefile

## Compilation process

*\*\* `hello.cpp` will be used as an example to show the compilation and makefile processes.*

    // hello.cpp
    # include <iostream>  // header
    using namespace std;
    
    int main()
    {
        cout << "hello, world" << endl;
    }

There are, in total, 4 steps to compile a `.c` or `.cpp` program into an executable file, which includes:

1. Pre-processing

    Process pre-processing headers (lines starting with #) to generate an expanded source code.

    *A file with extension name `.i` will be created.*

    To create a `.i` file : `g++ -E -o hello.i hello.c`

2. Compilation

    Compile expanded source code to **assembly code** that depends on the machine it is executed.

    *A file with extension name `.s` will be created.*

    To create a `.s` file: `g++ -S -o hello.s hello.c`

3. Assembly

    Converts assembly code into **machine code**, in the form of an object code file.

    *A file with extension name `.o` (object file) will be created.*

    To create an object file: `g++ -c hello.c`

    By typing the command above, an object file called `hello.o` will be created, which is already an executable file. But when more programs (including `.c++` and `.h` files) are to be compiled in the same time, the object file will be used to connect with one another, producing an executable file with no extension name or `.out` (in this case the name of the executable file would be `hello/hello.out`).

4. Linking

    Links object codes with libraries to create an executable file.

    It is the main duty of `makefile`.

***

## General rule of makefile

    target: prerequisites ... (dependency list)
        command ...

*(Remark: we can use  a `\` sign to represent `\n` in makefile for better readability)*

### Here's an example: 

    gcd.o: gcd.cpp gcd.h
        g++ -c gcd.cpp


1. In the first line of the rule, it first gives the name of a file to be generated, which is called the target. In our example, we are specifying a target called `gcd.o`. The target must be followed by a colon (:).

2. After the target (and the colon), we specify a list of files that the target depends on. In our example, the target `gcd.o` depends on `gcd.cpp` and `gcd.h`.

3. The second part of a rule gives the commands to generate the target from the files it depends on. Each command must start with a **tab**. Note that we cannot use spaces to replace it. There can be more than one commands used to generate the target. Those commands will be executed one after the other in order to generate the target. So in our example, when we want to generate target `gcd.o`, we will execute `g++ -c gcd.cpp`.

## How does `make` tool works

1. It first looks at the dependency list of the target. If any of the files in the dependency list is not up to date, `make` will make those files recursively first. A file is not up to date if:

(1) it does not exist;

(2) if its last modification time is older than the last modification time of its dependency.

For example, when we make `gcd_main.o`, the make tool will check whether gcd_main.cpp and `gcd.h` are up to date. If not, it makes the corresponding files.

2. After checking the dependency, `make` checks if the target exists or is up to date by comparing the modification time-stamp between the target and the sources. If no, `make` executes the commands specified in the rules to generate the target. Notice that if the target is up to date, no action is done. It is fine because the target exists and is newer than its dependency. Hence regenerating the target is just a waste of time.

*Notice that the above procedure will regenerate the minimum number of files when a source file is changed.*

**\*Also, if the commands in `makefile` are written badly that the object files cannot be created, executing `make` command will only result in error messages. Hence writing a good `makefile` is important for projects involving many source codes.**

## Tricks with `make`

1. Declaring Variables

```
TARGET = gcd                                # variable 1
OBJECTS = gcd.o gcd_main.o                  # variable 2

$(TARGET): $(OBJECTS)
    g++ $(OBJECTS) -o $(TARGET)
```

**Special Variables:**
| Variables | Description |
|:---------:|-------------|
|`$@`       |The target   |
|`$^`       |All prerequisites |
|`$<`       |The leftmost item in prerequisite|

2. Using phony targets

We can also create phony target (fake target) that is not really used to generate the target. When we make these targets, the commands will be executed, and it serves as a short hand for those commands. For example, it is common to have targets like clean or tar, as follows.

    clean:
        rm -f gcd gcd.o gcd_main.o gcd.tgz
    tar:
        tar -czvf gcd.tgz *.cpp *.h
    .PHONY: clean tar

When we type the command `make clean`, assuming there is no file named clean in the current directory, the command will be executed.
***Essentially, it replaces the long command with the
shorter one make clean.***

Similarly, when we execute the command `make tar`, the command   will be executed. That `tar` command essentially forms a compressed collection of all `.cpp` and `.h` files into the file `gcd.tgz`.
This usage has a pitfall. If a file named clean really exists in the current directory, make will find that clean is up to date and will not execute the command. We can solve this problem by specifying that target clean is a `.PHONY` target. Targets listed in `.PHONY` target will still be generated even if it is up to date.

<br>

***

## References:

https://ithelp.ithome.com.tw/articles/10257387

https://seisman.github.io/how-to-write-makefile/introduction.html#make
