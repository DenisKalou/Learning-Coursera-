// Ðåàëèçóéòå ôóíêöèè è ìåòîäû êëàññîâ è ïðè íåîáõîäèìîñòè äîáàâüòå ñâîè
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <iomanip>
#include <exception>

using namespace std;

class Date {
public:
	Date(){

	}
	Date(int new_year, int new_month, int new_day){
		if (new_month <= 0 || new_month > 12){
			string error = "Month value is invalid: " + to_string(new_month);
			throw runtime_error(error);
		} else if (new_day <=0 || new_day > 31){
			string error = "Day value is invalid: " + to_string(new_day);
			throw runtime_error(error);
		}
		year = new_year;
		month = new_month;
		day = new_day;
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
	void PrintDate() const{
			cout << setw(4) << setfill('0')
					<< to_string(year)
					<< "-" << setw(2) << setfill('0')
					<< to_string(month)
					<< "-" << setw(2) << setfill('0')
					<< to_string(day);
	}
private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs){
	return (lhs.GetYear() < rhs.GetYear()) ? true
			: (lhs.GetMonth() < rhs.GetMonth()) ? true
					: lhs.GetDay() < rhs.GetDay();
}

class Database {
public:
	void PrintAllDates(){
		for (const auto& item : database){
			item.first.PrintDate();
			cout << " " << item.second << endl;
		}
	}
	void AddEvent(const Date& date, const string& event){
		database[date] = event;
	}
	bool DeleteEvent(const Date& date, const string& event){
		//if (database.find(event) = 0){
			//throw runtime_error("Event not found");
		//}
		//cout << "Deleted successfully" << endl;
	}
	int  DeleteDate(const Date& date){
	}

	//Find(const Date& date) const;

	void Print() const;
private:
	map<Date, string> database;
};

int main() {
	Database db;
	db.AddEvent({88, 6, 1}, "Denis's birthday");
	Date b;
	b = {3, 11, 2};
	db.AddEvent(b, "baba");
	//db.DeleteDate(b);
	string command;
	while (getline(cin, command)) {
		if (command == "Add"){

		} else if (command == "Del"){

		} else if (command == "Find"){

		} else if (command == "Print"){
			db.PrintAllDates();
		}
		try{
			Date a = {1001, 12, 31};
			Date b = {100, 12, 10};
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
	}

	return 0;
}
