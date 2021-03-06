/*

 * Vincent Ha

 * CIS 22C, Winter 2017

 */

#include <iostream>
#include <iomanip>
#include "Book.h"

Book::Book():title(""), author(""), isbn(0), price(0.0){};

Book::Book(string t, string a, unsigned i, double p) {
    title = t;
    author = a;
    isbn = i;
    price = p;
}

/**Access Functions*/

string Book::get_title() {
    return title;
}

string Book::get_author() {
    return author;
}

unsigned Book::get_isbn() {
    return isbn;
}

double Book::get_price() {
    return price;
}

/**Manipulation Procedures*/

void Book::set_title(string t){
    title = t;
}

void Book::set_author(string a) {
    author = a;
}

void Book::set_isbn(unsigned i) {
    isbn = i;
}

void Book::set_price(double p) {
    price = p;
}

/**Additional Functions*/
ostream& operator<<(ostream& os, const Book& book){
	os << book.title << " by " << book.author << endl;
	os << "$" << fixed << setprecision(2) << book.price << endl;
	os << "ISBN: " << book.isbn << endl;
	return os;
}

bool Book::operator==(const Book& book) {
    return (title == book.title && author==book.author);
}

bool Book::operator<(const Book& book){
	if(title == book.title){
		if(author == book.author)
			return false;
		else
			return author < book.author;
	}
	else
		return title < book.title;
}

bool Book::operator>(const Book& book){
	if(title == book.title){
			if(author == book.author)
				return false;
			else
				return author > book.author;
		}
		else
			return title > book.title;
}
