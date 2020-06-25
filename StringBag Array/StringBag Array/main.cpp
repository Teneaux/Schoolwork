#include <iostream>
#include "StringBag.h"
using namespace std;

int main(int argc, char* argv[])
{
	cout << "Using default constructor" << endl;

	StringBag bag1;

	cout << "bag1 size (should be 0): " << bag1.Size() << endl;
	cout << "bag1 capacity (should be 10): " << bag1.GetCapacity() << endl;

	cout << "Using single-argument constructor" << endl;
	StringBag bag2(27);

	cout << "bag2 size (should be 0): " << bag2.Size() << endl;
	cout << "bag2 capacity (should be 27): " << bag2.GetCapacity() << endl;

	cout << "Testing destructor" << endl;
	StringBag* bag3 = new StringBag(1000000);
	delete bag3;

	cout << "Adding \"Test1\" to bag1." << endl;
	bag1.Add("Test1");

	for (int i = 0; i < bag1.Size(); ++i)
	{
		cout << "In bag1: " << bag1.At(i) << endl;
	}

	cout << "Adding an array of strings to bag2" << endl;
	string stringArray[] = { "Array1", "Array2", "Array3" };
	bag2.Add(stringArray, 3);

	for (int i = 0; i < bag2.Size(); ++i)
	{
		cout << "In bag2: " << bag2.At(i) << endl;
	}

	cout << "Removing \"Array2\" from bag2" << endl;
	bag2.Remove("Array2");

	for (int i = 0; i < bag2.Size(); ++i)
	{
		cout << "In bag2: " << bag2.At(i) << endl;
	}

	if (bag2.Contains("Array1"))
		cout << "bag2 contains \"Array1\"." << endl;
	else
		cout << "bag2 does not contain \"Array1\"." << endl;

	if (bag2.Contains("Not In Bag"))
		cout << "bag2 contains \"Not In Bag\"." << endl;
	else
		cout << "bag2 does not contain \"Not In Bag\"." << endl;

	cout << "Finding \"Array3\" in bag2: " << bag2.Find("Array3") << endl;
	cout << "Finding \"Not In Bag\" in bag2 (should be -1): " << bag2.Find("Not In Bag") << endl;

	cout << "Adding \"Array3\" several times to bag1" << endl;
	bag1.Add("Array3");
	bag1.Add("Array3");
	bag1.Add("Array3");

	cout << "The string \"Array3\" occurs " << bag1.CountOccurrences("Array3") << " times in bag1." << endl;
	cout << "The string \"BadString\" occurs " << bag1.CountOccurrences("BadString") << " times in bag1." << endl;

	cout << "Union of bag1 and bag2:" << endl;
	bag1.Union(&bag2);

	for (int i = 0; i < bag1.Size(); ++i)
	{
		cout << "In bag1: " << bag1.At(i) << endl;
	}


	cout << "Adding bag2 into bag1:" << endl;
	bag1.Add(&bag2);

	for (int i = 0; i < bag1.Size(); ++i)
	{
		cout << "In bag1: " << bag1.At(i) << endl;
	}


	cin.get();
	return 0;
}