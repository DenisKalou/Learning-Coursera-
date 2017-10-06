#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Student { // structure of student data
	string first_name;
	string second_name;
	int day;
	int month;
	int year;
};

int main() {
	string path = "input.txt"; // path to file
	ifstream input(path);
	int n, m;
	input >> n; // students quantity
	vector<Student> students(n); // students data
	for (int i = 0; i < n; ++i){ // reading input students data from file
		input >> students[i].first_name;
		input >> students[i].second_name;
		input >> students[i].day;
		input >> students[i].month;
		input >> students[i].year;
	}
	input >> m; // operational command quantity
	for (int i = 0; i < m; ++i){ // operational command usage and result
		string operational_command;
		int code;
		input >> operational_command // reading operational command name
		>> code; // reading operational command code
		--code;
		if (operational_command == "name"){
			cout << students[code].first_name
					<<  " " << students[code].second_name
					<< endl;
		} else if (operational_command == "date"){
			cout << students[code].day
					<< "." << students[code].month
					<< "." << students[code].year
					<< endl;
		} else {
			cout << "bad request" << endl;
		}
	}
	return 0;
}
