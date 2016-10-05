// BitField2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <bitset>
using namespace std;

class BitField
{
private:
	bitset <64> data;
public:
	BitField();
	void add(int t)
	{
		data[t - 1] = 1;
	}
	template <typename ... S>  //function to input elements into the set
	void add(int t, S... list)
	{
		data[t - 1] = 1;
			add(list...);
	}
	BitField Intersection(BitField a); //and
    BitField Union(BitField a); //or
	BitField Substraction(BitField a); //not
	void Output();
};
BitField::BitField()
{
	data = 0;
}
BitField BitField::Intersection(BitField a)
{
	BitField c;
	c.data = data & a.data;
	return c;
}
BitField BitField::Union(BitField a)
{ 
	BitField c;
	c.data = data | a.data;
	return c;
}
BitField BitField::Substraction(BitField a)
{
	BitField c;
	c.data = data&~(a.data);
	return c;
}

void BitField::Output()
{/*
	for (int i = 0; i < 64; ++i) //display the contents of the bitsets on the console 
	{
		if (data[i] == 1)

			cout << i + 1 << " ";
	}*/
	cout << data << endl; //display the contents of the bitsets

} 


int main()
{
	BitField m, n, s, p, x; //objects declaration
	m.add(9, 7, 8, 23, 33, 1 , 6 , 4, 8, 5, 3, 40, 47, 63, 64);
	n.add(23, 43, 54, 26, 11, 64, 23, 53, 9, 7, 4);
	s = m.Union(n);
	p = m.Intersection(n);  // Perform operations 
	x = m.Substraction(n);

	m.Output();
	cout << endl;       // Output the contents of the data sets
	n.Output();
	cout << endl;
	s.Output();
	cout << endl;
	p.Output();         // Output the contents of the result sets
	cout << endl;
	x.Output();
	cout << endl;
	return 0;
}