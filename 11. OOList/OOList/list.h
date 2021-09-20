#pragma once
#include <cstddef>

class Rec {
	friend class list;
	protected:
		char* id;
		char firstname[15];
		char lastname[15];
		Rec* previous;
		Rec* next;

	public:
		void SetData(char* id_in, char* fn, char* ln);
		Rec(char* i, char* fn, char* ln);
		Rec(void);
		void operator=(const Rec& r);
		Rec(const Rec& r);
		void Print();
		~Rec();
};

class list:public Rec {
	friend class Rec;
	protected:
		char* id;
		char firstname[15];
		char lastname[15];
		Rec* first;
		Rec* last;
		Rec* current;
		Rec* hold;
		int capacity = 0;

	public:
		list(void);
		void operator=(list l);
		int AddItem(Rec r);
		int DeleteItem(char* delid);
		void PrintList(int order);
	
};