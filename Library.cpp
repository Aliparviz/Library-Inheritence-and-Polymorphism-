#ifndef _LC_
#define _LC_

#include "Library.hpp"
bool Library::check_is_new_std(std::string id, std::string name)
{
	if ((name == "") || (id == ""))
	{
		std::cout << "Empty field" << std::endl;
		exit(EXIT_SUCCESS);
		return false;
	}
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].getname() == name)
		{
			std::cout << "Name already exists" << std::endl;
			exit(EXIT_SUCCESS);
			return false;
		}
	}
	for (int i = 0; i < professors.size(); i++)
	{
		if (professors[i].getname() == name)
		{
			std::cout << "Name already exists" << std::endl;
			exit(EXIT_SUCCESS);
			return false;
		}
	}
	return true;
}
bool Library::check_is_new_prof(std::string name)
{
	if (name == "")
	{
		return false;
	}
	for (int i = 0; i < professors.size(); i++)
	{
		if (professors[i].getname() == name)
		{
			std::cout << "Name already exists" << std::endl;
			exit(EXIT_SUCCESS);
			return false;
		}
	}
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].getname() == name)
		{
			std::cout << "Name already exists" << std::endl;
			exit(EXIT_SUCCESS);
			return false;
		}
	}
	return true;
}
bool Library::check_is_new_doc(std::string name)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].gettitle() == name)
		{
			std::cout << "A document with the specified name already exists" << std::endl;
			exit(EXIT_SUCCESS);
			return false;
		}
	}
	for (int i = 0; i < refrences.size(); i++)
	{
		if (refrences[i].gettitle() == name)
		{
			std::cout << "A document with the specified name already exists" << std::endl;
			exit(EXIT_SUCCESS);
			return false;
		}
	}
	for (int i = 0; i < magazines.size(); i++)
	{
		if (magazines[i].gettitle() == name)
		{
			std::cout << "A document with the specified name already exists" << std::endl;
			exit(EXIT_SUCCESS);
			return false;
		}
	}
	return true;
}
Document *Library::find_doc_from_name(std::string doc_title)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].gettitle() == doc_title)
		{
			return &books[i];
		}
	}
	for (int i = 0; i < magazines.size(); i++)
	{
		if (magazines[i].gettitle() == doc_title)
		{
			return &magazines[i];
		}
	}
	for (int i = 0; i < refrences.size(); i++)
	{
		if (refrences[i].gettitle() == doc_title)
		{
			return &refrences[i];
		}
	}
	return NULL;
}
Document *Library::find_doc_from_my_documents(Human *me, std::string document_title)
{
	for (int i = 0; i < me->get_my_docs().size(); i++)
	{
		if (me->get_my_docs()[i]->gettitle() == document_title)
		{
			return me->get_my_docs()[i];
		}
	}
	return NULL;
}
Human *Library::find_person_from_name(std::string name)
{
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].getname() == name)
		{
			return &students[i];
		}
	}
	for (int i = 0; i < professors.size(); i++)
	{
		if (professors[i].getname() == name)
		{
			return &professors[i];
		}
	}
}
int Library::cal_penalty_of_book(int delay_days)
{
	int penalty = 0;
	for (int i = 0; i < delay_days; i++)
	{
		if (i < 7)
		{
			penalty += 2000;
		}
		else if (i >= 7 && i < 21)
		{
			penalty += 3000;
		}
		else if (i >= 21)
		{
			penalty += 5000;
		}
	}
	return penalty;
}
int Library::cal_penalty_of_magazine(int delay_days, int year)
{
	int penalty = 0;
	if (year < 1390)
	{
		for (int i = 0; i < delay_days; i++)
		{
			penalty += 2000;
		}
	}
	else
	{
		for (int i = 0; i < delay_days; i++)
		{
			penalty += 3000;
		}
	}
	return penalty;
}
int Library::cal_penalty_of_refrence(int delay_days)
{
	int penalty = 0;
	for (int i = 0; i < delay_days; i++)
	{
		if (i < 3)
		{
			penalty += 5000;
		}
		else
		{
			penalty += 7000;
		}
	}
	return penalty;
}
int Library::cal_penalty(Document *doc, int today)
{
	if (doc->get_pass_day() - today >= 0)
	{
		return 0;
	}
	int delay_days = today - doc->get_pass_day();
	if (doc->gettype() == "Book")
	{
		return cal_penalty_of_book(delay_days);
	}
	else if (doc->gettype() == "Refrence")
	{
		return cal_penalty_of_refrence(delay_days);
	}
	else if (doc->gettype() == "Magazine")
	{
		return cal_penalty_of_magazine(delay_days, doc->getyear());
	}
}
std::vector<Document *> Library::remove_from_my_docs(Human *me, Document *doc)
{
	std::vector<Document *> updated_docs;
	for (int i = 0; i < me->get_my_docs().size(); i++)
	{
		if (me->get_my_docs()[i]->gettitle() == doc->gettitle())
		{
			continue;
		}
		else
		{
			updated_docs.push_back(me->get_my_docs()[i]);
		}
	}
	return updated_docs;
}
/////////////////////////////////////////////////////////////////////////////////
void Library::add_student_member(std::string student_id, std::string student_name)
{
	if (check_is_new_std(student_id, student_name))
	{
		students.push_back(Student(student_id, student_name, today));
	}
}
void Library::add_prof_member(std::string prof_name)
{
	if (check_is_new_prof(prof_name))
	{
		professors.push_back(Professor(prof_name, today));
	}
}
void Library::add_book(std::string book_title, int copies)
{
	if (check_is_new_doc(book_title))
	{
		books.push_back(Book(book_title, copies));
	}
}
void Library::add_magazine(std::string magazine_title, int year, int number, int copies)
{
	if (number <= 0)
	{
		std::cout << "Invalid number" << std::endl;
		exit(EXIT_SUCCESS);
		return;
	}
	if (year <= 0)
	{
		std::cout << "Invalid year" << std::endl;
		exit(EXIT_SUCCESS);
		return;
	}
	if (check_is_new_doc(magazine_title))
	{
		magazines.push_back(Magazine(magazine_title, year, number, copies));
	}
}
void Library::add_reference(std::string reference_title, int copies)
{
	if (check_is_new_doc(reference_title))
	{
		refrences.push_back(Refrence(reference_title, copies));
	}
}
void Library::borrow(std::string member_name, std::string document_title)
{
	Document *doc = find_doc_from_name(document_title);
	Human *receiver = find_person_from_name(member_name);

	if ((receiver->show_my_type() == "Professor" && receiver->get_received_docs_num() >= 5) ||
		(receiver->show_my_type() == "Student" && receiver->get_received_docs_num() >= 2))
	{
		std::cout << "Maximum number of allowed borrows exceeded" << std::endl;
		exit(EXIT_SUCCESS);
		return;
	}
	for (int i = 0; i < receiver->get_my_docs().size(); i++)
	{
		if (receiver->get_my_docs()[i]->gettitle() == document_title)
		{
			std::cout << "You have not borrowed this document" << std::endl;
			exit(EXIT_SUCCESS);
			return;
		}
	}
	doc->borrowed();
	doc->set_date(today);
	receiver->add_doc(doc);
	receiver->add_one_doc();
	doc->reduce_copy();
}
void Library::extend(std::string member_name, std::string document_title)
{
	Human *receiver = find_person_from_name(member_name);
	Document *doc = find_doc_from_my_documents(receiver, document_title);

	if (doc == NULL)
	{
		std::cout << "You have not borrowed this document" << std::endl;
		exit(EXIT_SUCCESS);
		return;
	}
	if (doc->gettype() == "magazine")
	{
		std::cout << "You can’t renew magazine" << std::endl;
		exit(EXIT_SUCCESS);
		return;
	}
	if ((doc->gettype() == "Book" && doc->get_ex_counter() >= 2) ||
		(doc->gettype() == "Refrence" && doc->get_ex_counter() >= 2))
	{
		std::cout << "You can’t renew a document more than two times" << std::endl;
		exit(EXIT_SUCCESS);
		return;
	}
	if (doc->get_receive_day() == today)
	{
		std::cout << "You can’t extend and borrow a document on the same day" << std::endl;
		exit(EXIT_SUCCESS);
		return;
	}
	if (doc->get_pass_day() < today)
	{
		std::cout << "You can’t renew a document after receiving a penalty" << std::endl;
		exit(EXIT_SUCCESS);
		return;
	}

	doc->extend_pass_day();
	doc->add_ex_counter();
}
void Library::return_document(std::string member_name, std::string document_title)
{
	Human *receiver = find_person_from_name(member_name);
	Document *doc = find_doc_from_my_documents(receiver, document_title);
	if (doc == NULL)
	{
		std::cout << "You have not borrowed this document" << std::endl;
		exit(EXIT_SUCCESS);
		return;
	}
	receiver->update_docs(remove_from_my_docs(receiver, doc));
	int penalty_of_this_book = cal_penalty(doc, today);
	receiver->add_penalty(penalty_of_this_book);
	receiver->reduce_num_doc();
	doc->add_copy();
}
int Library::get_total_penalty(std::string member_name)
{
	Human *debter = find_person_from_name(member_name);

	for (int i = 0; i < debter->get_my_docs().size(); i++)
	{
		debter->add_penalty(cal_penalty(debter->get_my_docs()[i], today));
	}
	return debter->get_total_penalty();
}
std::vector<std::string> Library::available_titles()
{
	std::vector<std::string> titles;
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getcopies() > 0)
		{
			titles.push_back(books[i].gettitle());
		}
	}
	for (int i = 0; i < refrences.size(); i++)
	{
		if (refrences[i].getcopies() > 0)
		{
			titles.push_back(refrences[i].gettitle());
		}
	}
	for (int i = 0; i < magazines.size(); i++)
	{
		if (magazines[i].getcopies() > 0)
		{
			titles.push_back(magazines[i].gettitle());
		}
	}
}
int Library::time_pass(int days)
{
	if (days < 0)
	{
		std::cout << "Invalid day" << std::endl;
		exit(EXIT_SUCCESS);
		return -1;
	}
	else
	{
		today += days;
		return 1;
	}
}

#endif