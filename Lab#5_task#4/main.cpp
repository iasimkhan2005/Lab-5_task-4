// create int main() that manages Book class and a Library class that manages multiple Book instances

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book
{
private:
	string title;
	string author;

public:

	Book(string book_title, string book_author) :title(book_title), author(book_author) {};
	//method to perform getTitle function

	void setTitle(string title) {

		this->title = title;
	}

	string getTitle() {

		return this->title;
	}

	void setAuthor(string author) {

		this->author = author;
	}

	string getAuthor() {

		return this->author;

	}


};

class Library
{
private:
	vector<Book> books;
	string name;
public:

	Library(string name) {};

	string getName() {

		return this->name;
	}
	void setName(string name) {
		this->name = name;
	}
	void addBook(string title, string author) {

		this->books.push_back(Book(title, author));

		cout << "Book Added" << endl;

		cout << "Title: " << this->books[this->books.size() - 1].getTitle() << endl;
		cout << "Author: " << this->books[this->books.size() - 1].getAuthor() << endl;
		cout << endl;


	}
	void removeBook(string title) {

		for (int i = 0; i < this->books.size(); i++) {
			if (this->books[i].getTitle() == title) {
				this->books.erase(this->books.begin() + i);
				cout << "Book Removed" << endl;
				cout << "Title: " << this->books[this->books.size() - 1].getTitle() << endl;
				cout << "Author: " << this->books[this->books.size() - 1].getAuthor() << endl;
				cout << endl;
				break;
			}

		}
	}
	void printallbooks() {

		for (int i = 0; i < this->books.size(); i++) {
			cout << "Title: " << this->books[i].getTitle() << endl;
			cout << "Author: " << this->books[i].getAuthor() << endl;
			cout << endl;

		}
	}
};
void userInterface(Library& lib) {
	// Task: Implement user commands to interact with the library system 

	cout << "Enter command (add, remove, list): ";
	string command;
	getline(cin, command);

	if (command == "add") {
		cout << "Enter title: ";
		string title;
		getline(cin, title);
		cout << "Enter author: ";
		string author;
		getline(cin, author);
		lib.addBook(title, author);
		cout << endl;
	}
	else if (command == "remove") {
		cout << "Enter title: ";
			
		string title;
		getline(cin, title);
		lib.removeBook(title);
		cout << endl;

	}
	else if (command == "list") {
		lib.printallbooks();
	}
	else if (command == "exit") {
		cout << "Exiting..." << endl;
		exit(0);
	}
	else {
		cout << "Invalid command" << endl;
	}
		
		

}

int main() {
	//add book to list	
	Book book1 = Book("has", "abc");
	Book book2 = Book("saf", "def");



	Library library1 = Library("abc");
	library1.addBook(book1.getTitle(), book1.getAuthor());
	library1.addBook(book2.getTitle(), book2.getAuthor());
	library1.printallbooks();
	
	Library myLibrary =Library("abc");
	userInterface(myLibrary);  // Implement this function 
	return 0;



}