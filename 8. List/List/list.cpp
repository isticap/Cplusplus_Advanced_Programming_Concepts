#include <iostream>
#include "list.h"
using namespace std;

static int capacity = 0;
Rec* first = NULL;
Rec* last = NULL;
Rec* current;
Rec* hold;
Rec* next;

int AddItem(Rec r) 
{
	Rec* newRec = new Rec;

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
	//ADDING TO NON-EMPTY LIST END
	
	

	
	
	
	// ID CHECK START
	/*cout << IDCheck(r) << endl;
	if (IDCheck(r))
	{
		return 0;
	}*/
	// ID CHECK END

	// ADD SECOND ITEM
	//if (first == last)
	//{
	//	newRec->previous = last;
	//	newRec->next = NULL;
	//	last->next = newRec;
	//	newRec->id = new char[strlen(r.id) + 1];
	//	strcpy_s(newRec->id, strlen(r.id) + 1, r.id);
	//	strcpy_s(newRec->firstname, strlen(r.firstname) + 1, r.firstname);
	//	strcpy_s(newRec->lastname, strlen(r.lastname) + 1, r.lastname);
	//	last = newRec;
	//	capacity++;
	//	cout << first->lastname << endl;
	//	cout << last->lastname << endl;
	//	
	//	// SORT ALGORITHM
	//	current = first;
	//	while (true)
	//	{
	//		int i = 0;
	//		while (last->lastname[i++])
	//		{
	//			bool order = toupper(last->lastname[i]) < toupper(current->lastname[i]);
	//			if (order)
	//			{
	//				first = last;
	//				last = current;
	//				break;
	//			}
	//		}
	//		break;
	//	}
	//	// SORT ALGORITHM

	//	cout << first->lastname << endl;
	//	cout << last->lastname << endl;
	//	return 1;
	//}
}

int DeleteItem(char* delid)
{
	if (capacity == 0)
	{
		//cout << "no items in list" << endl;
		return 0;
	}
	if (capacity == 1)
	{
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
		if (current == NULL && strcmp(current->id, delid) != 0)
		{
			return 0;
		}
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

// PRINT METHOD WORKS AS EXPECTED. COULD BE CONDENSED.
void PrintList(int order)
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