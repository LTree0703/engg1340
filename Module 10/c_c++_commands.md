# C & C++ Notes

**Notes for ENGG1340/COMP2113**

## **Content**
**Section 1: C++ Basics**

[\<iostream>](#iostream) \
[\<string>](#string) \
[\<fstream>](#fstream) \
[\<sstream>](#sstream) \
[\<iomanip>](#iomanip) \
[STL \<vector>](#vector) \
[STL \<list>](#list) \
[STL \<map>](#map) \
[ STL \<algorithm>](#algorithm)

**Section 2: C Basics**

[\<stdio.h>](#stdio.h) \
[\<string.h>](#string.h) \
[\<stdlib.h>](#stdlib.h) 

<br>

# Section 1: C++ Basics

**<h3 id='iostream'> \<iostream></h3>**

1. `getline(cin, string)`: extract input line to string
2. `cout << showpoint/noshowpoint;`: display decimal points with padding zeros
3. `cout << fixed;`: write floating point numbers as fixed decimal
4. `cout << scientific;`: write float in scientific notation 


**<h3 id='string'> \<string> (string.h)</h3>**

1. `str.length()` - returns length of the string.
2. `str.empty()` - returns whether the string is empty.
3. `str.substr(start, end)` - returns a substring (from `start` index to `end` index, default the last char).
4. `str.find(target_str)` - finds the first occurrence of `target_str` in the string. (returns the position, -1 if not found)
5. `str.rfind(target_str)` - finds the last occurrence of content in the string. (returns the position, -1 if not found)
6. `str.insert(pos, str2)` - inserts `str2` into the string at position `pos`.
7. `str.erase(pos, n)` - erases `n` characters from the string, starting at the position `pos`.
8. `str.replace(pos, n, str2)` - replaces `n` characters of the string, starting at the position `pos`, by the content specified in `str2`.


**<h3 id='cmath'> \<cmath> (math.h)</h3>**

**<h3 id='fstream'> \<fstream></h3>**

1. Declare a file variable

        ifstream fin; // input file
        ofstream fout; // output file
        fin.open("input.txt"); fout.open("output.txt");

    Note: if no file named "output.txt", it will be created, otherwise the contents of the existing file will be eraseed. To keep the content of the existing file and append new data to it, supply the constant value `ios::app` as the second argument to the member function.
       
2. Read file and store in variables

        if (fin.fail())
        {
            return;
        }
        else
        {
            string temp;
            while (fin >> temp) // stops when meet ' '
            {
                cout << temp << endl;
            }
            // OR
            while (getline(fin, temp)) // stops when meet '\n'
            {
                cout << temp << endl;
            }
        }

3. Write to a file

        if (fout.fail())
        {
            return;
        }
        else
        {
            fout << temp << endl;
        }

4. Closing a file

        fin.close(); fout.close(); 

**<h3 id='sstream'> \<sstream></h3>**

***A library very similar to \<fstream> (extract data from a string)***

        istringstream iss(str);
        string temp;
        while (iss >> temp) 
            cout << temp << endl; 

**<h3 id='iomanip'> \<iomanip></h3>**

1. `setprecision(n)`: show n significant digits
2. `setw(n)`: output a string or a number in `n` columns (the output is `right-justified`)
3. `setfill(char)`: With `setw`, if the specified number of columns > the required number of columns, the unused columns are filled with spaces. We may use `setfill` to fill the unused columns with other characters.
4. `cout << left/right`: set the output to be left/right justified

**<h3 id='cstdlib'> \<cstdlib> (stdlib.h)</h3>**

**<h3 id='vector'> STL \<vector></h3>**

        vector<int> numbers; // a linked list
1. `numbers.push_back(i)`: add an item `i` to the end of the vector
2. `numbers.size()`: number of items in the vector
3. `numbers.pop_back()`: remove the last item from vector
4. `numbers.front()`
5. `numbers.back()`


**<h3 id='list'> STL \<list></h3>**

        list<int> numbers; // a doubly-linked list

1. `numbers.push_back(i)`
2. `numbers.pop_back()`
3. `numbers.push_front(i)`
4. `numbers.pop_front()`
5. `numbers.front()`
6. `numbers.back()`
7. `numbers.size()`

**<h3 id='map'> STL \<map></h3>**

        map<char, int> yeet; // a balanced binary search tree

1. `yeet[key]`: access the value by key(i.e., the `char` in the above example)
2. `yeet.count(key)`:  Given any `key`, this function returns the number of pairs in the map with this key.
3. `yeet.size()`: return the number of pairs in the map

**<h3 id='algorithm'> STL \<algorithm></h3>**

1. using iterators (i.e., pointers iterating over the container)

        vector<int>::iterator itr1;
        list<int>::iterator itr2;
        map<char, int>::iterator itr3;

1. `sort(begin, end)`: sort items in the range [begin, end) into ascending order (the last item is not included in the sorting)

**Sorting objects in user-defined clases**

        bool operator <(const Struct& a, const Struct& b) {
            // define yourself how to make comparisons
            if (a.obj < b.obj) return true;
            if (a.obj > b.obj) return false;
            return a.subject.size() < b.subject.size();
        }

<br>

# Section 2: C Basics

**<h3 id='stdio.h'> \<stdio.h> </h3>**
1. Format specifiers:

        %d -> int
        %f -> float/double
        %c -> char
        %s -> string
        %g -> Remove trailing zeros for float and double

        %8s -> format width of the string (right-justified)

2. `scanf("%d", &var)`: read user input (using pass by reference)

***Note: for reading an array (e.g. a string), we don't need to put & as the array is itself a pointer pointing to the first element of that array***

3. `printf("%d", var)`: print variable on screen

### **\*Pass by reference in C**

        swap(&a, &b);
        void swap (double *a, double *b){
                double temp = *a; // deference the addresses
                *a=*b;
                *b=temp;
        }

**<h3 id='string.h'> \<string.h> </h3>**

--> char s[] string; // an array of char = string 

1. `strcpy(char s1[], char s2[])`: copy char array s2 to s1

2. `strcat(char s1[], char s2[])`: append s2 after the end of s1 -> s1 += s2

3. `strcmp(char s1[], char s2[])`: return negative if s1 < s2, return 0 if s1 == s2, return positive if s1 > s2

4. `strlen(char s1[])`: return the length of string

**<h3 id='stdlib.h'> \<stdlib.h> </h3>**

**aka. dynamic memory management**

1. `void *malloc(int size)`: return a pointer to the allocated memory (pointer not defined as a particular type)

2. `int sizeof()`: return the size of a specific data type (self-defined as well)

3. `void free(void *ptr)`: free the memory allocated


### **\*struct and typedef**

        struct student {
                char name[20];
                int uid;
        }; typedef struct student Student;
**Note: struct constructors are merely a feature of c++ but not c (i.e. c does not support object-oriented programming)**

<br>
<center>-- END OF NOTE --</center>