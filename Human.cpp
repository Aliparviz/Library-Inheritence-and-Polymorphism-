#ifndef _HC_
#define _HC_

#include "Human.hpp"

std::string Human::getname() { return name; }
void Human::add_doc(Document* doc)
{
	my_docs.push_back(doc);
}
void Human::add_penalty(int penalty)
{
	total_penalty += penalty;
}
void Human::add_one_doc() { received_docs_num++; }
void Human::reduce_num_doc() { received_docs_num--; }
void Human::update_docs(std::vector<Document*>docs) { my_docs = docs; }
int Human::get_received_docs_num() { return received_docs_num; }
int Human::get_total_penalty()
{
	return total_penalty;
}
std::vector<Document*> Human::get_my_docs() { return my_docs; }

Student::Student(std::string _id, std::string _name, int day_of_add)
{
	id = _id;
	name = _name;
	day_of_joint = day_of_add;
	received_docs_num = 0;
	total_penalty = 0;
}
std::string Student::getid() { return id; }
std::string Student::show_my_type() { return "Student"; }

Professor::Professor(std::string _name, int day_of_add)
{
	day_of_joint = day_of_add;
	name = _name;
	received_docs_num = 0;
}
std::string Professor::show_my_type() { return "Professor"; }


#endif