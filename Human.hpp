#ifndef _HH_
#define _HH_

#include"Document.hpp"

class Human
{
protected:
	std::string name;
	int day_of_joint;
	std::vector<Document*> my_docs;
	int received_docs_num;
	int total_penalty;
public:
	std::string getname();
	void add_doc(Document* doc);
	void add_penalty(int penalty);
	virtual std::string show_my_type() = 0;
	virtual void add_one_doc();
	virtual void reduce_num_doc();
	void update_docs(std::vector<Document*>docs);
	int get_received_docs_num();
	int get_total_penalty();
	std::vector<Document*> get_my_docs();
};


class Student : public Human
{
private:
	std::string id;
public:
	Student(std::string _id, std::string _name, int day_of_add);
	std::string getid();
	std::string show_my_type();
};
class Professor : public Human
{
public:
	Professor(std::string _name, int day_of_add);
	std::string show_my_type();
};
#endif