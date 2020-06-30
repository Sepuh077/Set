#pragma once
#include <fstream>
#include <iostream>
class Set
{
	int* num;
	int n;
	static int count;
	void sett(Set& a);
	friend std::istream& operator>>(std::istream& in, Set& a);
	friend std::ostream& operator<<(std::ostream& out, const Set& a);
public:
	Set(int a = 0);
	Set(int* a, int n);
	Set(const Set& a);
	static int SetCount();
	Set operator=(const Set& a);
	bool operator==(const Set& a) const;
	bool operator!=(const Set& a) const;
	int setSize() const;
	void push_back(int k);
	bool isBelong(int k) const;
	void remove(int k);
	Set operator+(const Set& a);
	Set operator-(const Set& a);
	Set operator*(const Set& a);
	Set& operator+=(const Set& a);
	Set& operator-=(const Set& a);
	Set& operator*=(const Set& a);
	int maxMember();

	~Set();
};

inline std::istream& operator>>(std::istream& in, Set& a) {
	in >> a.n;
	a.num = new int[a.n];
	for (int i = 0; i < a.n; i++) {
		in >> a.num[i];
	}
	a.sett(a);
	return in;
}
inline std::ostream& operator<<(std::ostream& out, const Set& a){
	for (int i = 0; i < a.n; i++) {
		out << a.num[i] << " ";
	}
	out << std::endl;
	return out;
}