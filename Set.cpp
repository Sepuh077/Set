#include "Set.h"
#include <algorithm>
#include <iostream>


int Set::count = 0;

void Set::sett(Set& a) {
	std::sort(a.num, a.num + n);
}
Set::Set(int a) {
	if (n > 0) {
		delete[] num;
	}
	n = a;
	num = new int[n];
	for (int i = 0; i < n; i++) {
		num[i] = i + 1;
	}
	count++;
}
Set::Set(int* a, int n) {
	if (n > 0) {
		delete[] num;
	}
	this->n = n;
	num = new int[n];
	for (int i = 0; i < n; i++) {
		num[i] = a[i];
	}
	count++;
	sett(*this);
}
Set::Set(const Set& a) {
	if (n > 0) {
		delete[] num;
	}
	n = a.n;
	num = new int[n];
	for (int i = 0; i < n; i++) {
		num[i] = a.num[i];
	}
	count++;
}
Set Set::operator=(const Set& a) {
	if (n > 0) {
		delete[] num;
	}
	n = a.n;
	num = new int[n];
	for (int i = 0; i < n; i++) {
		num[i] = a.num[i];
	}
	sett(*this);
	return *this;
}
bool Set::operator==(const Set& a) const {
	if (n != a.n)
		return 0;
	for (int i = 0; i < n; i++) {
		if (num[i] != a.num[i])
			return 0;
	}
	return 1;
}
bool Set::operator!=(const Set& a) const {
	if (n != a.n)
		return 1;
	for (int i = 0; i < n; i++) {
		if (num[i] != a.num[i])
			return 1;
	}
	return 0;
}
int Set::SetCount(){
	return count;
}
int Set::setSize() const{
	return n;
}
void Set::push_back(int k) {
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = num[i];
	}
	if(n > 0)
		delete[] num;
	num = new int[n + 1];
	for (int i = 0; i < n; i++) {
		num[i] = a[i];
	}
	num[n] = k;
	n++;
	sett(*this);
}
bool Set::isBelong(int k) const{
	for (int i = 0; i < n; i++) {
		if (num[i] == k)
			return 1;
	}
	return 0;
}
void Set::remove(int k) {
	if (isBelong(k)) {
		int* a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = num[i];
		}
		delete[] num;
		int x = n;
		n = 0;
		num = new int[n];
		for (int i = 0; i < x; i++) {
			if (a[i] != k) {
				push_back(a[i]);
			}
		}
	}
}
int Set::maxMember() {
	sett(*this);
	if (n > 0)
		return num[n - 1];
	else {
		return 0;
	}
}
Set Set::operator+(const Set& a){
	Set b(*this);
	return (b += a);
}
Set Set::operator-(const Set& a) {
	Set b(*this);
	return (b -= a);
}
Set Set::operator*(const Set& a) {
	Set b(*this);
	return (b *= a);
}
Set& Set::operator+=(const Set& a) {
	for (int i = 0; i < a.n; i++) {
		if (!isBelong(a.num[i]))
			push_back(a.num[i]);
	}
	sett(*this);
	return *this;
}
Set& Set::operator-=(const Set& a) {
	for (int i = 0; i < a.n; i++) {
		remove(a.num[i]);
	}
	return *this;
}
Set& Set::operator*=(const Set& a) {
	const Set b = *this;
	delete[] num;
	n = 0;
	num = new int[n];
	for (int i = 0; i < a.n; i++) {
		if (b.isBelong(a.num[i]))
			push_back(a.num[i]);
	}
	sett(*this);
	return *this;
}
Set::~Set() {
	delete[] num;
	count--;
}