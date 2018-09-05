#include "TBitField.h"
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	TBitField A(7),B(35);
	cout << A.GetLength() << endl;
	A.SetBit(5);
	B.SetBit(2);
	B.SetBit(5);
	cout << A << endl;
	cout << B << endl;
	cout << (~B) << endl;
	cout << (A|B)<<endl;
	B.ClrBit(2);
	cout << B << endl;
	TBitField D(7);
	cin >> D;
	cout << D << endl;
	D = (A | B);
	cout << (D) << endl;
	cout << (~D) << endl;
	_getch();
	return 0;
}