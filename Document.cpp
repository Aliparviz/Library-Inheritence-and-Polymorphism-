#ifndef _DC_
#define _DC_

#include "Document.hpp"

std::string Document::gettitle() { return title; }
int Document::getcopies(){return copies;}
void Document::borrowed()
{
		copies -= 1;
}
void Document::set_date(int today)
{
	receive_day = today;
	pass_day = today + 10;
}
int Document::get_receive_day() { return receive_day; }
int Document::get_pass_day() { return pass_day; }
void Document::add_ex_counter() { extend_counter++; }
void Document::extend_pass_day() { pass_day += 10; }
void Document::cal_return_day(int today)
{
    return_day = today;
}
int Document::get_return_day() { return return_day; }
void Document::reduce_copy() { copies--; }
int Document::get_ex_counter() { return extend_counter; }
void Document::add_copy() { copies++; }

Book::Book(std::string name, int copies_num)
{
	title = name;
	copies = copies_num;
	extend_counter = 0;
}
std::string Book::gettype() { return "Book"; }
int Book::getyear() { return 0; }

Magazine::Magazine(std::string magazine_title, int _year, int _number, int _copies)
{
	title = magazine_title;
	year = _year;
	number = _number;
	copies = _copies;
	extend_counter = 0;
}
std::string Magazine::gettype() { return "Magazine"; }
int Magazine::getyear() { return year; }

Refrence::Refrence(std::string reference_title, int _copies)
{
	title = reference_title;
	copies = _copies;
	extend_counter = 0;
}
std::string Refrence::gettype() { return "Refrence"; }
int Refrence::getyear() { return 0; }
#endif