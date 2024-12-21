#include "goods.h"

int goods::getid() {
	return id;
}

int goods::getquantity() {
	return quantity;
}

int goods::getstorage_time() {
	string s = getentry_date();
	return daysSinceToday(s);
}

int goods::gettime_to_exp() {
	string s = getexpired_date();
	return daysSinceToday(s)*(-1);
}

string goods::getname() {
	return name;
}

string goods::getentry_date() {
	return entry_date;
}

string goods::getexpired_date() {
	return expired_date;
}

void goods::setid(int x) {
	this->id = x;
}

void goods::setquantity(int y) {
	this->quantity = y;
}

void goods::setstorage_time(int z) {
	this->storage_time = z;
}

void goods::settime_to_exp(int t) {
	this->time_to_exp = t;
}

void goods::setname(string a) {
	this->name = a;
}

void goods::setentry_date(string b) {
	this->entry_date = b;
}

void goods::setexpired_date(string c) {
	this->expired_date = c;
}

int daysSinceToday(const string& dateStr) {
	int day, month, year;
	char delimiter;
	istringstream dateStream(dateStr);
	dateStream >> day >> delimiter >> month >> delimiter >> year;

	tm date = {};
	date.tm_mday = day;
	date.tm_mon = month - 1;
	date.tm_year = year - 1900;
	time_t date_time_t = mktime(&date);
	time_t now_time_t = time(nullptr);

	auto difference = difftime(now_time_t, date_time_t);
	return static_cast<int>(difference / (60 * 60 * 24));
}