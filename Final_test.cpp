#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

void WrongDateFormat(const string& str){
	stringstream ss;
}

class Date {
public:
	Date(const string& input_string){
		//WrongDateFormat(input_string);
		int new_year, new_month, new_day;
		stringstream ss;
		ss << input_string;
		ss >> new_year;
		ss.ignore(1);
		ss >> new_month;
		ss.ignore(1);
		ss >> new_day;
		if (new_month <= 0 || new_month > 12){
			string error = "Month value is invalid: " + to_string(new_month);
				throw runtime_error(error);
		} else if (new_day <= 0 || new_day > 31){
			string error = "Day value is invalid: " + to_string(new_day);
			throw runtime_error(error);
		}
		year = new_year;
		month = new_month;
		day = new_day;
		stringstream ss2;
		ss2 << setw(4) << setfill('0') << to_string(year) << "-"
				<< setw(2) << setfill('0') << to_string(month) << "-"
				<< setw(2) << setfill('0') << to_string(day);
		ss2 >> date;
	}

	int GetYear() const{
		return year;
	}
	int GetMonth() const{
		return month;
	}
	int GetDay() const{
		return day;
	}
	string GetDate() const{
//		stringstream ss;
//		string str;
//		ss << setw(4) << setfill('0') << to_string(year)
//				<< setw(2) << setfill('0') << to_string(month)
//				<< setw(2) << setfill('0') << to_string(day);
//		ss >> str;
		return date;
	}
private:
	int year = 0;
	int month = 1;
	int day = 1;
	string date = "0000-01-01";
};

bool operator<(const Date& lhs, const Date& rhs){
	return ((lhs.GetYear() < rhs.GetYear())
			|| (lhs.GetYear() == rhs.GetYear()
			&& lhs.GetMonth() < rhs.GetMonth())
			|| (lhs.GetMonth() == rhs.GetMonth()
			&& lhs.GetDay() < rhs.GetDay())) ? true :false;
 }

class Database {
public:
	void AddEvent(const Date& date, const string& event){
		vector<string> temp;
		//temp = database[date];
		//temp.push_back(event);
		//sort(begin(temp), end(temp));
		database[date].push_back(event);
		 //else {
//			tmp.push_back(event);
//			database[date] = tmp;
//		}

	}
	bool DeleteEvent(const Date& date, const string& event);
	int  DeleteDate(const Date& date);

	/* ??? */ Find(const Date& date) const;

	void Print() const{
		for(const auto& date : database){
			cout << date.first.GetDate() << " ";
			for(const auto& event : date.second){
				cout << event << " ";
			}
			cout << endl;
		}
	}
private:
	map<Date, vector<string>> database;
};
void CommandParse(const string& command, Database& db){
	stringstream ss;
	cout << command << endl;
	ss << command;
	string cmd;
 	ss >> cmd;
 	cout << cmd << endl;
	if (cmd == "Add"){
		string date, event;
		ss >> date >> event;
		cout << date << " || " << event << endl;
		db.AddEvent({date}, event);
	} else if (cmd == "Print"){
		db.Print();
	} else if (cmd == "Find"){

	} else if (cmd == "Del"){

	}
}

int main() {
	Database db;
	string command;
	//db.AddEvent({"0-1-2"}, "event");

	while (getline(cin, command)) {
		CommandParse(command, db);
		if (command == "Stop"){
			break;
		}
	}

	return 0;
}
