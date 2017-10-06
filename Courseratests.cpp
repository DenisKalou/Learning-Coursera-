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
//	string path = "input.txt"; // path to file
//	ifstream input(path);
	unsigned int n, m;
	string first_name, second_name;
	int day, month, year;
	cin >> n; // students quantity
	vector<Student> students(n); // students data
	for (size_t i = 0; i < n; ++i){ // reading input students data from file
		cin >> first_name >> second_name >> day >> month >> year;
		if(first_name.size() > 0 && first_name.size() < 16
				&& second_name.size() > 0 && second_name.size() < 16
				&& day >= 0 && day <= 1000000000
				&& month >= 0 && month <= 1000000000
				&& year >= 0 && year <= 1000000000){
			students[i] = { first_name, second_name, day, month, year };
		}
	}
	cin >> m; // operational command quantity
	for (size_t i = 0; i < m; ++i){ // operational command usage and result
		string operational_command;
		unsigned int code;
		cin >> operational_command >> code;// reading operational command name
		code--;
		if (operational_command == "name" && code > 0 && code < students.size()){
			cout << students[code].first_name
					<<  " " << students[code].second_name
					<< endl;
		} else if (operational_command == "date" && code > 0 && code < students.size()){
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

