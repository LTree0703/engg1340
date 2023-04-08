/*
Checkpoint 9.2: Shopping List
Write a program to manage a shopping list. Each shopping list item is represented by a string stored in a container. Your design requires a print function that prints out the contents of the shopping list.

    The print function prints "Items: " followed by items each separated by a comma-space (", ").

Using a vector to hold the shopping list items, write a print function to print out the contents of a vector of strings. Test your print function with the main program that does the following:

    Create an empty vector. Print it.
    Append the items, "eggs," "milk," "sugar," "chocolate," and "flour" to the list. Print it.
    Remove the last element from the vector. Print it.
    Append the item, "coffee" to the vector. Print it.
    Write a loop that searches for the item, "sugar" and replaces it with "honey." Print the vector.
    Write a loop that searches for the item, "milk," and then remove it from the vector. Print the vector.

This question is copied from http://halpernwightsoftware.com/stdlib-scratch/exercises.html and is to test your knowledge of vector manipulation. You are advised to follow the instruction to make changes to the vector instead of hard-coding the output.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_vector(vector<string> &shopping_list)
{
    vector<string>::iterator itr;
    cout << "Item: ";
    if (shopping_list.empty())
    {
        cout << endl;
        return;
    }
    for (itr = shopping_list.begin(); itr+1 != shopping_list.end(); itr++)
    {
        cout << *itr << ", ";
        
    }
    cout << *(shopping_list.end()-1) << endl;
}

int main()
{
    vector<string> shopping_list;
    print_vector(shopping_list);

    shopping_list.insert(shopping_list.end(), {"eggs", "milk", "sugar", "chocolate", "flour"});
    print_vector(shopping_list);

    shopping_list.pop_back();
    print_vector(shopping_list);

    shopping_list.push_back("coffee");
    print_vector(shopping_list);

    for (int i = 0; i < shopping_list.size(); i++)
    {
        if (shopping_list[i] == "sugar")
        {
            shopping_list[i] = "honey";
        }
    }
    print_vector(shopping_list);
    
    for (int i = 0; i < shopping_list.size(); i++)
    {
        if (shopping_list[i] == "milk")
        {
            shopping_list.erase(shopping_list.begin()+i);
        }
    }
    print_vector(shopping_list);

    return 0;
}