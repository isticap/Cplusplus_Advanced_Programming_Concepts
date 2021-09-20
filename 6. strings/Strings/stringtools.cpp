#include <iostream>
using namespace std;

void GetInput(char *ptrArr[])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "enter string " << i+1 << ": " << endl;
		char buffer[1000];
		cin.getline(buffer, 1000,'\n');
		char *str = new char[strlen(buffer) + 1];
		strcpy_s(str, strlen(buffer)+1, buffer);
		ptrArr[i] = str;
	}
	cout << endl;
}

void DisplayStrings(char* ptrArr[]) 
{
	for (int i = 0; i < 3; i++)
	{
		cout << ptrArr[i] << endl;
	}
}

void ShowLens(char* ptrArr[])
{
	for (int i = 0; i < 3; i++)
	{
		cout << strlen(ptrArr[i]) << endl;
	}
}

void Sort(char* ptrArr[])
{
	char* temp;
	int ret = strcmp(ptrArr[0], ptrArr[1]);
	if (ret > 0)
	{
		temp = ptrArr[0];
		ptrArr[0] = ptrArr[1];
		ptrArr[1] = temp;
	}
	ret = strcmp(ptrArr[1], ptrArr[2]);
	if (ret > 0)
	{
		temp = ptrArr[1];
		ptrArr[1] = ptrArr[2];
		ptrArr[2] = temp;
	}
	ret = strcmp(ptrArr[0], ptrArr[2]);
	if (ret > 0)
	{
		temp = ptrArr[0];
		ptrArr[0] = ptrArr[2];
		ptrArr[2] = temp;
	}
}

int AlphaChars(char* ptrArr[])
{
	int totalAlphaChars = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < strlen(ptrArr[i]); j++)
		{
			if (isalpha(ptrArr[i][j]))
			{
				totalAlphaChars++;
			}
		}
	}
	return totalAlphaChars;
}

void Search(char* ptrArr[], char const* keyword)
{
	int strfound = 0;
	for (int i = 0; i < 3; i++)
	{
		char* found = strstr(ptrArr[i], keyword);
		if (found)
		{
			strfound++;
			cout << ptrArr[i] << endl;
		}
	}
	if (!strfound)
	{
		cout << "string was not found" << endl;
	}
	else
	{
		cout << "string was found in the above strings " << strfound << " times." << endl;
	}
	
}