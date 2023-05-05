#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
// You can add more libraries here (if needed)
using namespace std;
// Define the classes and member functions here
struct Student {
	int id;
	string name;
	Student() {
		id = 0;
		name = "invalid";
	};
	Student(int inputid, string inputname) {
		id = inputid;
		name = inputname;
	};
};

class Table {
public:
	void InsertStudent(Student x, int y);
	void SearchbyID(int x);
	void SearchbyGrade(int y);
	void Statistics();
	void PrintAll();
	// You can add more member functions to help your implementation.
private:
	/* The data type is decided by your records; */ 
	map<Student, int> records;
	vector<int> grades; // for statistics purpose only
};

bool operator < (const Student&a, const Student&b) {
	// overload the less-than operator for sort() to work with user-defined classes
	if (a.id < b.id) return true;
	else return false;
}

// insert one record in to the stored records
void Table::InsertStudent(Student x, int y) {
	// Check for duplicates
	map<Student, int>::iterator itr;
	for (itr = records.begin(); itr != records.end(); itr++)
	{
		if ((*itr).first.id == x.id)
		{
			cout << "Student exists." << endl;
			return;
		}
	}
	// Add record into map
	records[x] = y;
	grades.push_back(y);
}

// return the name and grade of the student with id x
void Table::SearchbyID(int x) {
	map<Student, int>::iterator itr;
	for (itr = records.begin(); itr != records.end(); itr++)
	{
		if ((*itr).first.id == x)
		{
			cout << (*itr).first.name << endl;
			cout << (*itr).second << endl;
			return;
		}
	}
	cout << "No such student." << endl;
}

// return the id and name of the student with grade y
void Table::SearchbyGrade(int y) {
	map<Student, int>::iterator itr;
	bool found = false;
	for (itr = records.begin(); itr != records.end(); itr++)
	{
		if ((*itr).second == y)
		{
			found = true;
			cout << (*itr).first.id << " " << (*itr).first.name << endl;
		}
	}
	if (!found)
	{
		cout << "No such record." << endl;
	}
}

// Print the maximum, minimum, and median of grades
void Table::Statistics() {
	if (!grades.empty())
	{
		sort(grades.begin(), grades.end());
		cout << "Maximum " << grades.back() << endl;
		int mid = grades.size() / 2;
		float median = 0.0;
		if (grades.size() % 2 == 0) // even size
		{
			median = (grades[mid] + grades[mid-1]) / 2.0;
		}
		else
		{
			median = grades[mid];
		}
		cout << "Median " << median << endl;
		cout << "Minimum " << grades.front() << endl;
	}
	else
	{
		cout << "Maximum 0" << endl;
		cout << "Median 0" << endl;
		cout << "Minimum 0" << endl;
	}

}

// Print all records in the ascending order of id
void Table::PrintAll() {
	map<Student, int>::iterator itr;
	for (itr = records.begin(); itr != records.end(); ++itr)
	{
		cout << (*itr).first.id << " " << (*itr).first.name << " " << (*itr).second << endl;
	}
}


int main() {
	Table t;
	string command;
	int id;
	string name;
	int grade;
	
	while (cin >> command) {
		if (command == "InsertStudent") {
			cin >> id >> name >> grade;
			Student s = {id, name};
			t.InsertStudent(s, grade);
		}
		else if (command == "SearchbyID") {
			cin >> id;
			t.SearchbyID(id);
		}
		else if (command == "SearchbyGrade") {
			cin >> grade;
			t.SearchbyGrade(grade);
		}
		else if (command == "PrintAll") {
			t.PrintAll();
		}
		else if (command == "Statistics") {
			t.Statistics();
		}
		else if (command == "exit") {
			break;
		}
	}

	return 0;
}
