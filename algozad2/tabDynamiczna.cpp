#include "tabDynamiczna.h"
#include <iostream>
#include <string>

using namespace std;

tabDynamiczna::tabDynamiczna() {
	realRozm = 0;
	maxRozm = 100;
	tab = new int[maxRozm];
}

tabDynamiczna::~tabDynamiczna()
{
	delete tab;
}

void tabDynamiczna::dodaj(int dane) {
	if (realRozm >= maxRozm) {
		realokacja();
	}
	tab[realRozm] = dane;
	realRozm++;
}

int tabDynamiczna::zwrocDana(int index) {
	if (index >= realRozm) {
		cout << "Niepowodzenie" << endl;
		return 0;
	}
	return tab[index];
}

void tabDynamiczna::podmiana(int index, int dane) {
	if (index >= realRozm) {
		cout << "Niepowodzenie" << endl;
		return;
	}

	tab[index] = dane;
}

void tabDynamiczna::czyszczenie() {
	delete tab;
	realRozm = 0;
	maxRozm = 100;
	tab = new int[maxRozm];
}

string tabDynamiczna::zwrocTab() {
	string reprezentacja;
	reprezentacja += to_string(realRozm) + '/' + to_string(maxRozm) + '\n';

	return reprezentacja;
}

void tabDynamiczna::sort() {
	for (int i = 0; i < realRozm; i++) {
		int sprawdzenie = 0;
		for (int j = 1; j < realRozm - i; j++) {
			if (tab[j - 1] > tab[j]) {
				swap(tab[j - 1], tab[j]);
				sprawdzenie = 1;
			}
		}
		if (sprawdzenie == 0)
			return;
	}
}

void tabDynamiczna::realokacja() {
	maxRozm = maxRozm * 2;
	int* temp = new int[maxRozm];
	for (int i = 0; i < realRozm; i++) {
		temp[i] = tab[i];
	}

	delete tab;

	tab = temp;
}