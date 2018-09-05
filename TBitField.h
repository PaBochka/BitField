#include <iostream>
typedef unsigned int TELEM;
using namespace std;
class TBitField
{
private: 
int BitLen; // длина битового поля - макс. к-во битов 
TELEM *pMem;
int MemLen; // к-во эл-тов Мем для представления бит.поля 
// методы реализации 
int GetMemIndex(const int n) const;
TELEM GetMemMask(const int n) const;
public:
	TBitField(int len);
	TBitField(const TBitField &bf);
	~TBitField();
	// доступ к битам
	int GetLength(void) const; // получить длину (к-во битов)
	void SetBit(const int n); // установить бит
	void ClrBit(const int n); // очистить бит
	int GetBit(const int n) const; // получить значение бита
	// битовые операции
	int operator==(const TBitField &bf); // сравнение
	TBitField& operator=(const TBitField &bf); // присваивание
	TBitField operator |(const TBitField &bf); // операция "или"
	TBitField operator &(const TBitField &bf); // операция "и"
	TBitField operator ~(void); // отрицание
	friend istream &operator>>(istream &is, TBitField &bf);
	friend ostream &operator<<(ostream &os, const TBitField &bf);
};