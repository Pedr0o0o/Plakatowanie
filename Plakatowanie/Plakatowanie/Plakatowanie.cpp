#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

int numberOFposters = 0;

int poster(int start, int end, uint32_t* tab, int min) {

	if (start == end && tab[end] > 0) {
		numberOFposters += 1;
		return 0;
	}

	if (min == INT_MAX) return 0;

	for (unsigned int i = start; i <= end; i++) {
		tab[i] -= min;
	}

	numberOFposters += 1;

	for (unsigned int i = start; i <= end; i++) {

		uint32_t minP = INT_MAX;

		if ((tab[i] > 0 && i == start) || (tab[i] > 0 && tab[i - 1] < 1)) {
			for (unsigned int j = i; j <= end; j++) {

				if (tab[j] < minP && tab[j] > 0) {
					minP = tab[j];
				}

				if ((tab[j] > 0 && j == end) || (tab[j] > 0 && tab[j + 1] < 1)) {
					poster(i, j, tab, minP);
					i = j;
					break;
				}
			}
		}
	}

	return 0;
}



int main(void) {
	ios_base::sync_with_stdio(false);

	int size, rsize = 0;
	cin >> size;


	uint32_t min = INT_MAX;

	int length;
	uint32_t* hightTab = new uint32_t[size];

	cin >> length >> hightTab[0];

	for (unsigned int i = 1; i < size; i++) {

		int hight;
		cin >> length >> hight;

		if (hight != hightTab[rsize]) {
			rsize++;
			hightTab[rsize] = hight;

			if (hight < min && hight > 0) {
				min = hight;
			}
		}


	}

	poster(0, rsize, hightTab, min);
	cout << numberOFposters;


	delete[] hightTab;


	return 0;
}