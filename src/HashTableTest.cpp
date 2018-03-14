/*

 * Vincent Ha

 * CIS 22C, Winter 2017

 */

#include <iostream>
#include <string>
#include "HashTable.h"
using namespace std;

int main() {
	cout << "HashTable Test" << endl;
	cout << "--------------" << endl;
	cout << endl;

	HashTable ht;
	Book pp("Pride and Prejudice", "Jane Austen", 1234567, 4.95);
	cout << "Searching for Pride and Prejudice in empty hashtable (Should return index of -1): ";
	cout << ht.search(pp) << endl;
	cout << "Finding hash of same book (Should return 2): ";
	string name = pp.get_title() + pp.get_author();
	cout << ht.hash(name) << endl;
	cout << "Trying to remove from an empty hashtable (Would throw an assertion):" << endl;
	//ht.remove(pp);

	Book c("Contact", "Carl Sagan", 99993339, 9.95);
	Book hg("The Hunger Games", "Suzanne Collins", 12388888, 13.55);
	Book hp("Harry Potter", "J.K. Rowlings", 55555678, 12.99);
	Book mhc("The Man in the High Castle", "Philip K Dick", 95959595, 15.95);
	Book bh("Bleak House", "Charles Dickens", 473890238, 8.00);

	ht.insert(pp);
	ht.insert(c);
	ht.insert(hg);
	ht.insert(mhc);
	ht.insert(bh);

	cout << "Using printTable(): " << endl;
	ht.printTable();
	cout << "Making a copy of the previous hashtable. Using printTable() (Should print same results):" << endl;
	HashTable ht2(ht);
	ht2.printTable();
	cout << "Using printBucket() at index -1 (Would throw assertion):" << endl;;
	//ht.printBucket(-1);
	cout << "Using printBucket() at index 10 (Would also throw assertion): ";
	//ht.printBucket(10);
	cout << "Using printBucket() at index 1:" << endl;
	ht.printBucket(1);
	cout << "Using printBucket() at index 9:" << endl;
	ht.printBucket(9);
	cout << "Using countBucket() at index -1 (Would throw an assertion):" << endl;
	//cout << ht.countBucket(-1) << endl;
	cout << "Using countBucket() at index 10 (Would throw an assertion)" << endl;
	//cout << ht.countBucket(10) << endl;
	cout << "Using countBucket() at index 9 (Should return 2): ";
	cout << ht.countBucket(9) << endl;
	cout << "Removing The Hunger Games from the first list:" << endl;
	ht.remove(hg);
	ht.printTable();
	cout << "Checking contents of second HashTable (Should still have Hunger Games):" << endl;
	ht2.printTable();

}

/*
Output

HashTable Test
--------------

Searching for Pride and Prejudice in empty hashtable (Should return index of -1): -1
Finding hash of same book (Should return 2): 2
Trying to remove from an empty hashtable (Would throw an assertion):
Using printTable():
<----------------------->
Bucket: 0
Bleak House by Charles Dickens
$8.00
ISBN: 473890238

Number of books at this bucket: 1
<----------------------->

<----------------------->
Bucket: 2
Pride and Prejudice by Jane Austen
$4.95
ISBN: 1234567

Number of books at this bucket: 1
<----------------------->

<----------------------->
Bucket: 4
Contact by Carl Sagan
$9.95
ISBN: 99993339

Number of books at this bucket: 1
<----------------------->

<----------------------->
Bucket: 9
The Hunger Games by Suzanne Collins
$13.55
ISBN: 12388888

Number of books at this bucket: 2
<----------------------->

Using printBucket() at index -1 (Would throw assertion):
Using printBucket() at index 10 (Would also throw assertion): Using printBucket() at index 1:
Printing index: 1

There is nothing stored in this index.
Using printBucket() at index 9:
Printing index: 9

The Hunger Games by Suzanne Collins
$13.55
ISBN: 12388888


The Man in the High Castle by Philip K Dick
$15.95
ISBN: 95959595


Using countBucket() at index -1 (Would throw an assertion):
Using countBucket() at index 10 (Would throw an assertion)
Using countBucket() at index 9 (Should return 2): 2
Removing The Hunger Games from the list:
<----------------------->
Bucket: 0
Bleak House by Charles Dickens
$8.00
ISBN: 473890238

Number of books at this bucket: 1
<----------------------->

<----------------------->
Bucket: 2
Pride and Prejudice by Jane Austen
$4.95
ISBN: 1234567

Number of books at this bucket: 1
<----------------------->

<----------------------->
Bucket: 4
Contact by Carl Sagan
$9.95
ISBN: 99993339

Number of books at this bucket: 1
<----------------------->

<----------------------->
Bucket: 9
The Man in the High Castle by Philip K Dick
$15.95
ISBN: 95959595

Number of books at this bucket: 1
<----------------------->

 *
 */
