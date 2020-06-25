#pragma once
#include <iostream>
using namespace std;
using std::string;

class StringBag
{
public:
	StringBag()
	{
		//set up an empty bad that can contain up to 10 strings
		capacity = 10;
		contents = new string[capacity];
		size = 0;
	}
	StringBag(int initialCapacity)
	{
		//set up an empty bag to contain up to 'initial capacity' strings
		capacity = initialCapacity;
		contents = new string[capacity];
		size = 0;
	}

	void Add(string newString)
	{
		if (size < capacity)
		{
			contents[size] = newString;
			size++;
		}
	}

private:

	string* contents;
	int size;
	int capacity;
};

