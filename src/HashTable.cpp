/*

* Vincent Ha

* CIS 22C, Winter 2017

*/
#include <iostream>
#include <string>
#include <algorithm>
#include "assert.h"
#include "HashTable.h"
using namespace std;

HashTable::HashTable(){}

HashTable::HashTable(const HashTable& ht){
	for(int a = 0; a < SIZE; a++){
		List<Book> copy(ht.Table[a]);
		if(!copy.isEmpty()){
			copy.startIterator();
			while(!copy.offEnd()){
				Table[a].insertLast(copy.getIterator());
				copy.advanceIterator();
			}
		}
	}
}

HashTable::~HashTable(){}

int HashTable::hash(string key){
	    int index, sum = 0;
	    for(int i = 0; i < key.length(); i++)
	        sum += (int) key[i]; //summing the ASCII values for each character in the string
	    index = sum % SIZE; //dividing the summed ASCII values by 35 && storing remainder as my index
	    return index;
}

int HashTable::countBucket(int index){
	assert(index >= 0);
	assert(index < SIZE);
	int count = 0;
	Table[index].startIterator();
	while(!Table[index].offEnd()){
		count++;
		Table[index].advanceIterator();
	}
	return count;
}

int HashTable::search(Book b){
	string name = b.get_title() + b.get_author();
	int index = hash(name);
	if(!Table[index].isEmpty()){
		Table[index].startIterator();
		while(!Table[index].offEnd()){
			if(Table[index].getIterator().get_isbn() == b.get_isbn())
				return index;
			Table[index].advanceIterator();
		}
	}

	return -1;
}

void HashTable::insert(Book b){
	string name = b.get_title() + b.get_author();
	int index = hash(name);
	Table[index].insertLast(b);
}

void HashTable::remove(Book b){
	assert(search(b) != -1);
	string name = b.get_title() + b.get_author();
	int index = hash(name);
	Table[index].startIterator();
	while(!Table[index].offEnd()){
		if(Table[index].getIterator().get_isbn() == b.get_isbn()){
			Table[index].removeIterator();
			break;
		}
		Table[index].advanceIterator();
	}
}

void HashTable::printBucket(int index){
	assert(index >= 0);
	assert(index < SIZE);
	cout << "Printing index: " << index << endl;
	cout << endl;

	if(Table[index].isEmpty())
		cout << "There is nothing stored in this index." << endl;
	else{
		Table[index].startIterator();
		while(!Table[index].offEnd()){
			cout << Table[index].getIterator() << endl;
			cout << endl;
			Table[index].advanceIterator();
		}
	}
}

void HashTable::printTable(){
	for(int i = 0; i < SIZE; i++){
		if(Table[i].isEmpty())
			continue;
		cout << "<----------------------->" << endl;
		cout << "Bucket: " << i << endl;
		cout << Table[i].getFirst() << endl;
		cout << "Number of books at this bucket: ";
		cout << countBucket(i) << endl;
		cout << "<----------------------->" << endl;
		cout << endl;
	}
}
