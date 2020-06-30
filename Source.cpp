#include <iostream>
#include "Set.h"

using namespace std;

int main() {
	int m = 2, subSet = 0, index = 0;
	//cin >> n;
	Set* a = new Set[m];
	Set b;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++) {
		int k = 0;
		for (int j = 0; j < m; j++) {
			if (i != j) {
				b = a[i] - a[j];
				if (b.setSize() == 0) {
					k++;
				}
			}
		}
		if (k >= subSet) {
			subSet = k;
			index = i;
		}
	}
	cout << a[index];
	return 0;
}