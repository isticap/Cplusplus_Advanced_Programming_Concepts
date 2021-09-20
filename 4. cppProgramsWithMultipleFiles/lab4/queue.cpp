//this is queue.cpp
#include <cstddef>
#include "queue.h"
#include <iostream>
using namespace std;

static int queue[10];
static int sizee = 0;
static int front = queue[0];

int Enqueue(int num)
{
	if (sizee < 10)
	{
		for (int i = 0; i <= sizee; i++)
		{
			if (num == queue[i])
			{
				return -62;
			}
		}
		queue[sizee++] = num;
		return 0;	
	}
	return -58;
}

int Dequeue(int &num)
{
	if (IsEmpty())
	{
		return -64;
	}
	else
	{
		num = queue[0];
		for (int i = 0; i <= sizee; i++)
		{
			queue[i] = queue[i+1];
		}
		sizee--;
		return 0;
	}
}

int IsEmpty()
{
	return sizee == 0;
}

int Exists(int num)
{
	if (IsEmpty())
	{
		return 0;
	}
	for (int i = 0; i <= sizee; i++)
	{
		if (queue[i] == num)
		{
			return 1;
		}
	}
	return 0;
}

void Clear(void)
{
	for (int i = 0; i <= sizee; i++)
	{
		queue[i] = NULL;
	}
	sizee = 0;
}

void Print(void)
{
	for (int i = 0; i < sizee; i++)
	{
		cout << queue[i] << " ";
	}
	cout << endl;
}

int Duplicate(void)
{
	int num = queue[0];
	if (IsEmpty())
	{
		return -78;
	}
	if (sizee+1 > 10)
	{
		cout << "overflow error" << endl;
		return -81;
	}
	else
	{
		for (int i = sizee; i >= 1; i--)
		{
			queue[i] = queue[i - 1];
		}
		sizee++;
		queue[0] = num;
		return 0;
	}
	
}

int Mul(void)
{
	if (sizee <= 1)
	{
		return -79;
	}
	if (sizee + 1 > 10)
	{
		cout << "overflow error" << endl;
		return -81;
	}
	int num = queue[0] * queue[1];
	if (Exists(num))
	{
		return -82;
	}
	for (int i = sizee; i >= 1; i--)
	{
		queue[i] = queue[i - 1];
	}
	sizee++;
	queue[0] = num;
	return 0;
}

int Reverse(void)
{
	int temp[10];
	for (int i = sizee-1, j=0; i >= 0; i--)
	{
		temp[j++] = queue[i];
	}
	for (int i = 0; i < sizee; i++)
	{
		queue[i] = temp[i];
	}
	return 0;
}

int Peek(int& num)
{
	if (IsEmpty())
	{
		return -88;
	}
	num = queue[0];
	return 0;
}

