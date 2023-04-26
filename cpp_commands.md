# C++ Notes ++

**Notes for ENGG1340/COMP2113**

## **Content**

[\<iostream>](#iostream) \
[\<string>](#string) \
[\<fstream>](#fstream) \
[\<sstream>](#sstream) \
[\<iomanip>](#iomanip) \
[STL \<vector>](#vector) \
[STL \<list>](#list) \
[STL \<map>](#map) \
[ STL \<algorithm>](#algorithm)

---

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
<center>-- END OF NOTE --</center>