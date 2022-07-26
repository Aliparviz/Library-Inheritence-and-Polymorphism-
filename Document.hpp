#ifndef _DH_
#define _DH_

#include<iostream>
#include<vector>
#include<string>

class Document
{
protected:
	std::string title;
	int copies;
	int receive_day;
	int extend_counter;
	int pass_day;
	int return_day;
public:
	std::string gettitle();
	int getcopies() ;
	void borrowed();
	void set_date(int today);
	int get_receive_day() ;
	int get_pass_day() ;
	void add_ex_counter() ;
	void extend_pass_day() ;
	void cal_return_day(int today);
	int get_return_day() ;
	void reduce_copy() ;
	int get_ex_counter() ;
	void add_copy() ;
	virtual int getyear() = 0;
	virtual std::string gettype() = 0;
};
class Book : public Document
{
public:
	Book(std::string name, int copies_num);
	std::string gettype() ;
	int getyear();
};
class Magazine : public Document
{
private:
	int number, year;
public:
	Magazine(std::string magazine_title, int _year, int _number, int _copies);
	std::string gettype() ;
	int getyear();
};
class Refrence : public Document
{
public:
	Refrence(std::string reference_title, int _copies);
	std::string gettype() ;
	int getyear() ;
};
#endif