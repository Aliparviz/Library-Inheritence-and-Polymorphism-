#ifndef _LH_
#define _LH_

#include"Human.hpp"
class Library
{
private:
	std::vector<Student>students;
	std::vector<Professor>professors;
	std::vector<Book>books;
	std::vector<Magazine>magazines;
	std::vector<Refrence>refrences;
	int today = 0;
public:
	bool check_is_new_std(std::string id, std::string name);
	bool check_is_new_prof(std::string name);
	bool check_is_new_doc(std::string name);
	Document* find_doc_from_name(std::string doc_title);
	Document* find_doc_from_my_documents(Human* me, std::string document_title);
	Human* find_person_from_name(std::string name);
	int cal_penalty_of_book(int delay_days);
	int cal_penalty_of_magazine(int delay_days, int year);
	int cal_penalty_of_refrence(int delay_days);
	int cal_penalty(Document* doc, int today);
	std::vector<Document*> remove_from_my_docs(Human* me, Document* doc);
	/////////////////////////////////////////////////////////////////////////////////
	void add_student_member(std::string student_id, std::string student_name);
	void add_prof_member(std::string prof_name);
	void add_book(std::string book_title, int copies);
	void add_magazine(std::string magazine_title, int year, int number, int copies);
	void add_reference(std::string reference_title, int copies);
	void borrow(std::string member_name, std::string document_title);
	void extend(std::string member_name, std::string document_title);
	void return_document(std::string member_name, std::string document_title);
	int get_total_penalty(std::string member_name);
	std::vector<std::string> available_titles();
	int time_pass(int days);
};
#endif	