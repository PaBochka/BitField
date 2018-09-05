#include <iostream>
typedef unsigned int TELEM;
using namespace std;
class TBitField
{
private: 
int BitLen; // ����� �������� ���� - ����. �-�� ����� 
TELEM *pMem;
int MemLen; // �-�� ��-��� ��� ��� ������������� ���.���� 
// ������ ���������� 
int GetMemIndex(const int n) const;
TELEM GetMemMask(const int n) const;
public:
	TBitField(int len);
	TBitField(const TBitField &bf);
	~TBitField();
	// ������ � �����
	int GetLength(void) const; // �������� ����� (�-�� �����)
	void SetBit(const int n); // ���������� ���
	void ClrBit(const int n); // �������� ���
	int GetBit(const int n) const; // �������� �������� ����
	// ������� ��������
	int operator==(const TBitField &bf); // ���������
	TBitField& operator=(const TBitField &bf); // ������������
	TBitField operator |(const TBitField &bf); // �������� "���"
	TBitField operator &(const TBitField &bf); // �������� "�"
	TBitField operator ~(void); // ���������
	friend istream &operator>>(istream &is, TBitField &bf);
	friend ostream &operator<<(ostream &os, const TBitField &bf);
};