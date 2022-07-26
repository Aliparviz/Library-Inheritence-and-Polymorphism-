//بسم الله الرحمن الرحیم
#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Document
{
protected:
	string title;
	int copies;
	int receive_day;
	int extend_counter;
	int pass_day;
	int return_day;
public:
	string gettitle() { return title; }
	int getcopies() { return copies; }
	void borrowed()
	{
		copies -= 1;
	}
	void set_date(int today)
	{
		receive_day = today;
		pass_day = today + 10;
	}
	int get_receive_day() { return receive_day; }
	int get_pass_day() { return pass_day; }
	void add_ex_counter() { extend_counter++; }
	void extend_pass_day() { pass_day += 10; }
	void cal_return_day(int today)
	{
		return_day = today;
	}
	int get_return_day() { return return_day; }
	void reduce_copy() { copies--; }
	int get_ex_counter() { return extend_counter; }
	void add_copy() { copies++; }
	virtual int getyear() = 0;
	virtual string gettype() = 0;
};
class Human
{
protected:
	string name;
	int day_of_joint;
	vector<Document*> my_docs;
	int received_docs_num;
	int total_penalty;
public:
	string getname() { return name; }
	void add_doc(Document* doc)
	{
		my_docs.push_back(doc);
	}
	void add_penalty(int penalty)
	{
		total_penalty += penalty;
	}
	virtual string show_my_type() = 0;
	virtual void add_one_doc() { received_docs_num++; }
	virtual void reduce_num_doc() { received_docs_num--; }
	void update_docs(vector<Document*>docs) { my_docs = docs; }
	int get_received_docs_num() { return received_docs_num; }
	int get_total_penalty()
	{
		return total_penalty;
	}
	vector<Document*> get_my_docs() { return my_docs; }
};
class Student : public Human
{
private:
	string id;
public:
	Student(string _id, string _name, int day_of_add)
	{
		id = _id;
		name = _name;
		day_of_joint = day_of_add;
		received_docs_num = 0;
		total_penalty = 0;
	}
	string getid() { return id; }
	string show_my_type() { return "Student"; }
};
class Professor : public Human
{
public:
	Professor(string _name, int day_of_add)
	{
		day_of_joint = day_of_add;
		name = _name;
		received_docs_num = 0;
	}
	string show_my_type() { return "Professor"; }
};
class Book : public Document
{
public:
	Book(string name, int copies_num)
	{
		title = name;
		copies = copies_num;
		extend_counter = 0;
	}
	string gettype() { return "Book"; }
	int getyear() { return NULL; }
};
class Magazine : public Document
{
private:
	int number, year;
public:
	Magazine(string magazine_title, int _year, int _number, int _copies)
	{
		title = magazine_title;
		year = _year;
		number = _number;
		copies = _copies;
		extend_counter = 0;
	}
	string gettype() { return "Magazine"; }
	int getyear() { return year; }

};
class Refrence : public Document
{
public:
	Refrence(string reference_title, int _copies)
	{
		title = reference_title;
		copies = _copies;
		extend_counter = 0;
	}
	string gettype() { return "Refrence"; }
	int getyear() { return NULL; }
};
class Library
{
private:
	vector<Student>students;
	vector<Professor>professors;
	vector<Book>books;
	vector<Magazine>magazines;
	vector<Refrence>refrences;
	int today = 0;
public:
	bool check_is_new_std(string id, string name)
	{
		if ((name == "") || (id == ""))
		{
			cout << "Empty field" << endl;
			return false;
		}
		for (int i = 0; i < students.size(); i++)
		{
			if (students[i].getname() == name)
			{
				cout << "Name already exists" << endl;
				exit(EXIT_SUCCESS);
				return false;
			}
		}
		for (int i = 0; i < professors.size(); i++)
		{
			if (professors[i].getname() == name)
			{
				cout << "Name already exists" << endl;
				exit(EXIT_SUCCESS);
				return false;
			}
		}
		return true;
	}
	bool check_is_new_prof(string name)
	{
		if (name == "")
		{
			return false;
		}
		for (int i = 0; i < professors.size(); i++)
		{
			if (professors[i].getname() == name)
			{
				cout << "Name already exists" << endl;
				exit(EXIT_SUCCESS);
				return false;
			}
		}
		for (int i = 0; i < students.size(); i++)
		{
			if (students[i].getname() == name)
			{
				cout << "Name already exists" << endl;
				exit(EXIT_SUCCESS);
				return false;
			}
		}
		return true;
	}
	bool check_is_new_doc(string name)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].gettitle() == name)
			{
				cout << "A document with the specified name already exists" << endl;
				exit(EXIT_SUCCESS);
				return false;
			}
		}
		for (int i = 0; i < refrences.size(); i++)
		{
			if (refrences[i].gettitle() == name)
			{
				cout << "A document with the specified name already exists" << endl;
				exit(EXIT_SUCCESS);
				return false;
			}
		}
		for (int i = 0; i < magazines.size(); i++)
		{
			if (magazines[i].gettitle() == name)
			{
				cout << "A document with the specified name already exists" << endl;
				exit(EXIT_SUCCESS);
				return false;
			}
		}
		return true;
	}
	Document* find_doc_from_name(string doc_title)
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
	Document* find_doc_from_my_documents(Human* me, string document_title)
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
	Human* find_person_from_name(string name)
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
	int cal_penalty_of_book(int delay_days)
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
	int cal_penalty_of_magazine(int delay_days, int year)
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
			for (int i = 0; i<delay_days; i++)
			{
				penalty += 3000;
			}
		}
		return penalty;
	}
	int cal_penalty_of_refrence(int delay_days)
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
	int cal_penalty(Document* doc, int today)
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
	vector<Document*> remove_from_my_docs(Human* me, Document* doc)
	{
		vector<Document*> updated_docs;
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
	void add_student_member(string student_id, string student_name)
	{
		if (check_is_new_std(student_id, student_name))
		{
			students.push_back(Student(student_id, student_name, today));
		}
	}
	void add_prof_member(string prof_name)
	{
		if (check_is_new_prof(prof_name))
		{
			professors.push_back(Professor(prof_name, today));
		}
	}
	void add_book(string book_title, int copies)
	{
		if (check_is_new_doc(book_title))
		{
			books.push_back(Book(book_title, copies));
		}
	}
	void add_magazine(string magazine_title, int year, int number, int copies)
	{
		if (number <= 0)
		{
			cout << "Invalid number" << endl;
			exit(EXIT_SUCCESS);
			return;
		}
		if (year <= 0)
		{
			cout << "Invalid year" << endl;
			exit(EXIT_SUCCESS);
		}
		if (check_is_new_doc(magazine_title))
		{
			magazines.push_back(Magazine(magazine_title, year, number, copies));
		}
	}
	void add_reference(string reference_title, int copies)
	{
		if (check_is_new_doc(reference_title))
		{
			refrences.push_back(Refrence(reference_title, copies));
		}
	}
	void borrow(string member_name, string document_title)
	{
		Document* doc = find_doc_from_name(document_title);
		Human* receiver = find_person_from_name(member_name);

		if ((receiver->show_my_type() == "Professor" && receiver->get_received_docs_num() >= 5) ||
			(receiver->show_my_type() == "Student" && receiver->get_received_docs_num() >= 2))
		{
			cout << "Maximum number of allowed borrows exceeded" << endl;
			exit(EXIT_SUCCESS);
			return;
		}
		for (int i = 0; i < receiver->get_my_docs().size(); i++)
		{
			if (receiver->get_my_docs()[i]->gettitle() == document_title)
			{
				cout << "You have not borrowed this document" << endl;
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
	void extend(string member_name, string document_title)
	{
		Human* receiver = find_person_from_name(member_name);
		Document* doc = find_doc_from_my_documents(receiver, document_title);

		if (doc == NULL)
		{
			cout << "You have not borrowed this document" << endl;
			exit(EXIT_SUCCESS);
			return;
		}
		if (doc->gettype() == "magazine")
		{
			cout << "You can’t renew magazine" << endl;
			exit(EXIT_SUCCESS);
			return;
		}
		if ((doc->gettype() == "Book" && doc->get_ex_counter() >= 2) ||
			(doc->gettype() == "Refrence" && doc->get_ex_counter() >= 2))
		{
			cout << "You can’t renew a document more than two times" << endl;
			exit(EXIT_SUCCESS);
			return;
		}
		if (doc->get_receive_day() == today)
		{
			cout << "You can’t extend and borrow a document on the same day" << endl;
			exit(EXIT_SUCCESS);
			return;
		}
		if (doc->get_pass_day() < today)
		{
			cout << "You can’t renew a document after receiving a penalty" << endl;
			exit(EXIT_SUCCESS);
			return;
		}

		doc->extend_pass_day();
		doc->add_ex_counter();
	}
	void return_document(string member_name, string document_title)
	{
		Human* receiver = find_person_from_name(member_name);
		Document* doc = find_doc_from_my_documents(receiver, document_title);
		if (doc == NULL)
		{
			cout << "You have not borrowed this document" << endl;
			exit(EXIT_SUCCESS);
			return;
		}
		receiver->update_docs(remove_from_my_docs(receiver, doc));
		int penalty_of_this_book = cal_penalty(doc, today);
		receiver->add_penalty(penalty_of_this_book);
		receiver->reduce_num_doc();
		doc->add_copy();
	}
	int get_total_penalty(string member_name)
	{
		Human* debter = find_person_from_name(member_name);

		for (int i = 0; i < debter->get_my_docs().size(); i++)
		{
			debter->add_penalty(cal_penalty(debter->get_my_docs()[i], today));
		}
		return debter->get_total_penalty();
	}
	vector<string> available_titles()
	{
		vector<string>titles;
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
	int time_pass(int days)
	{
		if (days < 0)
		{
			cout << "Invalid day" << endl;
			exit(EXIT_SUCCESS);
			return -1;
		}
		else
		{
			today += days;
			return 1;
		}
	}
};



int main()
{
	Library ut_lib;
    ut_lib.add_student_member("0","std1");
    ut_lib.add_book("book1",3);
    ut_lib.add_book("book1",3);
    cout<<ut_lib.get_total_penalty("std1")<<'\n';
	return 0;
}