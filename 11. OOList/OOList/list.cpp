#include "list.h"
#include <cstddef>
#include <string.h>
#include <iostream>
using namespace std;



void Rec::SetData(char* id_in, char* fn, char* ln)
{
	if (id_in != NULL)
	{
		id = new char[strlen(id_in) + 1];
		strcpy_s(id, strlen(id_in) + 1, id_in);
		strcpy_s(firstname, strlen(fn) + 1, fn);
		strcpy_s(lastname, strlen(ln) + 1, ln);
	}
}

Rec::Rec(char* i, char* fn, char* ln)
{
	if (i != NULL)
	{
		id = new char[strlen(i) + 1];
		strcpy_s(id, strlen(i) + 1, i);
		strcpy_s(firstname, strlen(fn) + 1, fn);
		strcpy_s(lastname, strlen(ln) + 1, ln);
	}
}

Rec::Rec(void)
{
	id = NULL;
}

void Rec::operator=(const Rec& r)
{
	if (this->id != NULL)
	{
		delete[] id;
	}
	if (r.id != NULL)
	{
		this->id = new char[strlen(r.id) + 1];
		strcpy_s(this->id, strlen(r.id) + 1, r.id);
		strcpy_s(this->firstname, strlen(r.firstname)+1, r.firstname);
		strcpy_s(this->lastname, strlen(r.lastname) + 1, r.lastname);
	}
	else
	{
		this->id = NULL;
	}
}

Rec::Rec(const Rec& r)
{
	if (r.id != NULL)
	{
		this->id = new char[strlen(r.id) + 1];
		strcpy_s(this->id, strlen(r.id) + 1, r.id);
		strcpy_s(this->firstname, strlen(r.firstname) + 1, r.firstname);
		strcpy_s(this->lastname, strlen(r.lastname) + 1, r.lastname);
	}
	else
	{
		this->id = NULL;
	}
}

void Rec::Print()
{
	if (id != NULL)
	{
		cout << id << " " << firstname << " " << lastname << endl;
	}
}

Rec::~Rec()
{
	delete[] id;
	id = NULL;
}

///////////////////////////////// LIST ////////////////////////////////////
list::list(void)
{
	first = NULL;
	last = NULL;
}

void list::operator= (list l) {
	Rec* current = l.first;

	for (int i = 0; i < capacity; i++) {
		DeleteItem(first->id);
	}
	
	for (int i = 0; i < l.capacity; i++) {
		AddItem(*current);
		current = current->next;
	}
}


int list::AddItem(Rec r)
{
	Rec* newRec= new Rec;

	// ADDING TO EMPTY LIST START
	if (first == NULL)
	{
		first = newRec;
		newRec->previous = NULL;
		newRec->id = new char[strlen(r.id) + 1];
		strcpy_s(newRec->id, strlen(r.id) + 1, r.id);
		strcpy_s(newRec->firstname, strlen(r.firstname) + 1, r.firstname);
		strcpy_s(newRec->lastname, strlen(r.lastname) + 1, r.lastname);
		newRec->next = NULL;
		last = newRec;
		capacity++;
		return 1;
	}
	// ADDING TO EMPTY LIST END

	//ID CHECK START
	current = first;
	while (true)
	{
		if (strcmp(current->id, r.id) == 0)
		{
			return 0;
		}
		current = current->next;
		if (current == NULL)
		{
			break;
		}
	}
	//ID CHECK END

	// ADDING TO NON-EMPTY LIST START
	current = first;
	char uppercase1[15], uppercase2[15];
	strcpy_s(uppercase1, strlen(r.lastname) + 1, r.lastname);
	for (int i = 0; i < strlen(uppercase1); i++)
	{
		uppercase1[i] = toupper(uppercase1[i]);
	}
	while (true)
	{
		strcpy_s(uppercase2, strlen(current->lastname) + 1, current->lastname);
		for (int i = 0; i < strlen(uppercase2); i++)
		{
			uppercase2[i] = toupper(uppercase2[i]);
		}
		if (strcmp(uppercase1, uppercase2) > 0) {
			hold = current;
			current = current->next;
			if (current == NULL)
			{
				break;
			}
		}
		else
		{
			break;
		}
	}

	if (current == NULL)
	{
		newRec->next = NULL;
		newRec->previous = last;
		last->next = newRec;
		newRec->id = new char[strlen(r.id) + 1];
		strcpy_s(newRec->id, strlen(r.id) + 1, r.id);
		strcpy_s(newRec->firstname, strlen(r.firstname) + 1, r.firstname);
		strcpy_s(newRec->lastname, strlen(r.lastname) + 1, r.lastname);
		last = newRec;
		capacity++;
		return 1;
	}
	else
	{
		if (current == first)
		{
			newRec->next = first;
			newRec->id = new char[strlen(r.id) + 1];
			strcpy_s(newRec->id, strlen(r.id) + 1, r.id);
			strcpy_s(newRec->firstname, strlen(r.firstname) + 1, r.firstname);
			strcpy_s(newRec->lastname, strlen(r.lastname) + 1, r.lastname);
			newRec->previous = NULL;
			first->previous = newRec;
			first = newRec;
			capacity++;
			return 1;
		}
		newRec->next = current;
		newRec->previous = hold;
		hold->next = newRec;
		current->previous = newRec;
		newRec->id = new char[strlen(r.id) + 1];
		strcpy_s(newRec->id, strlen(r.id) + 1, r.id);
		strcpy_s(newRec->firstname, strlen(r.firstname) + 1, r.firstname);
		strcpy_s(newRec->lastname, strlen(r.lastname) + 1, r.lastname);
		hold = newRec;
		capacity++;
		return 1;
	}
}

int list::DeleteItem(char* delid)
{
	if (capacity == 0)
	{
		//cout << "no items in list" << endl;
		return 0;
	}
	if (capacity == 1)
	{
		// remove head
		if (strcmp(delid, first->id) == 0)
		{
			delete[] first->id;
			delete first;
			first = last = NULL;
			capacity--;
			return 1;
		}
		return 0;
	}
	current = first;

	while (true)
	{
		if (current == NULL)
		{
			return 0;
		}
		if (current == first && strcmp(current->id, delid) == 0)
		{
			current = first;
			first = first->next;
			first->previous = NULL;
			delete[] current->id;
			delete current;
			capacity--;
			return 1;
		}
		//if (current == NULL && strcmp(current->id, delid) != 0)
		
		if (current->next == NULL && strcmp(current->id, delid) == 0)
		{
			hold->next = NULL;
			delete[] last->id;
			delete last;
			last = hold;
			capacity--;
			return 1;
		}
		if (strcmp(current->id, delid) == 0)
		{
			hold->next = current->next;
			current->previous = hold;
			delete[] current->id;
			delete current;
			capacity--;
			return 1;
		}
		hold = current;
		current = current->next;
	}
	return 0;
}

void list::PrintList(int order)
{
	if (capacity == 0)
	{
		cout << "nothing to print" << endl;
		return;
	}
	current = first;
	if (capacity == 1)
	{
		cout << current->id << " ";
		cout << current->firstname << " ";
		cout << current->lastname << " ";
		cout << current->previous << " " << endl;  //  address of previous item
		cout << current << " ";   // address of item
		cout << current->next << " " << endl;  //  address of next item
		return;
	}
	if (order == 0)
	{
		current = first;
		int i = 0;
		while (capacity > 1)
		{
			cout << current->id << " ";
			cout << current->firstname << " ";
			cout << current->lastname << " ";
			cout << current->previous << " " << endl;  //  address of previous item
			cout << current << " ";   // address of item
			cout << current->next << " " << endl;  //  address of next item
			current = current->next;
			if (++i == capacity)
			{
				break;
			}
		}
	}
	if (order == 1)
	{
		current = last;
		int i = 0;
		while (capacity > 1)
		{
			cout << current->id << " ";
			cout << current->firstname << " ";
			cout << current->lastname << " ";
			cout << current->previous << " " << endl;  //  address of previous item
			cout << current << " ";   // address of item
			cout << current->next << " " << endl;  //  address of next item
			current = current->previous;
			if (++i == capacity)
			{
				break;
			}
		}
	}
}