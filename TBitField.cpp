#include "TBitField.h"
#include <iostream>
using namespace std;
int TBitField::GetMemIndex(const int n) const
{
	return (n >> 5);
}
TELEM TBitField::GetMemMask(const int n) const
{
	return 1 << (n & 31);
}
TBitField::TBitField(int Len) :BitLen(Len)
{
	MemLen = (Len + 31) >> 5;
	pMem = new TELEM[MemLen];
	if (pMem != NULL)
		for (int i = 0; i < MemLen; i++)
			pMem[i] = 0;
}
TBitField::TBitField(const TBitField &bf)
{	BitLen = bf.BitLen;
	MemLen = ( BitLen + 31) >> 5;
	pMem = new TELEM[MemLen];
	if (pMem != NULL)
		for (int i = 0; i < MemLen; i++)
			pMem[i] = bf.pMem[i];
}
TBitField::~TBitField()
{
	delete[]pMem;
}
void TBitField::SetBit(const int n)
{
	if ((n>-1) && (n < BitLen))
		pMem[GetMemIndex(n)] |= GetMemMask(n);
}
void TBitField::ClrBit(const int n)
{	
	if ((n>-1) && (n < BitLen))
	pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}
int TBitField::GetBit(const int n) const
{
	if ((n>-1) && (n < BitLen))
		return(pMem[GetMemIndex(n)] & GetMemMask(n)); else return 0;
}
int TBitField::GetLength(void) const
{
	return BitLen;
}
int TBitField::operator ==(const TBitField&op)
{
	int res; res = 1; int i = 0;
	if (BitLen == op.BitLen)
	{
		while ((pMem[i] == op.pMem[i]) && (i < MemLen))
			i++;
	}
	else res = 0;
	return res;
}
TBitField &TBitField::operator=(const TBitField &bf)
{
	if (MemLen != bf.MemLen)
	{
		MemLen = bf.MemLen;
		BitLen = bf.BitLen;
		if (pMem != NULL) delete[]pMem;
		pMem = new TELEM[MemLen];
	}
	if (pMem != NULL)
		for (int i = 0; i < MemLen; i++)
			pMem[i] = bf.pMem[i];
	return(*this);
}
ostream &operator<<(ostream &os, const TBitField &bf)
{	
	for (int j = 0; j < bf.BitLen; j++)
		if (bf.GetBit(j))
			os << 1; else os << 0;
			return os;
}
TBitField TBitField::operator&(const TBitField &bf)
{
	int i, len = BitLen;
	if (bf.BitLen < len) 
		len = bf.BitLen;
	TBitField res(len);
	for (i = 0; i < res.MemLen; i++) 
		res.pMem[i] = pMem[i]; 
	for (i = 0; i < res.MemLen; i++) 
		res.pMem[i] &= bf.pMem[i];
	return res;
}
TBitField TBitField::operator|(const TBitField &bf)
{
	int i, len = BitLen;
	if (bf.BitLen > len) 
		len = bf.BitLen;
	TBitField res(len);
	for (i = 0; i < MemLen; i++)
		res.pMem[i] = pMem[i];
	for (i = 0; i < res.MemLen; i++)
		res.pMem[i] |= bf.pMem[i];
	return res;
}
TBitField TBitField::operator~(void)
{
	int len = BitLen;
	TBitField res(len);
	for (int i = 0; i < MemLen; i++)
		res.pMem[i] = ~pMem[i];
	return res;
}
istream &operator>>(istream &is, TBitField &bf)
{
	int count = 0; int i = 0; char ch;
	do
		is >> ch;
	while (ch == ' ');
	while (1)
	{
		is >> ch;
		if (ch == '0')
			bf.ClrBit(i++);
		else if (ch == '1') bf.SetBit(i++);
		else break;
	}
	return is;
}
