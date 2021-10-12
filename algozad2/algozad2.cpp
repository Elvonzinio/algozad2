#include <iostream>
#include <string>
#include <time.h>
#include "tabDynamiczna.h"

using namespace std;


int main()
{
	srand(time(NULL));

	tabDynamiczna tablica;

	const int liczbaDanych = pow(10, 7);

	double maxTimePerElement = 0.0;

	clock_t begin, end, beginElement, endElement;
	double time_spent;
	begin = clock();

	for (int i = 0; i < liczbaDanych; i++) {
		int losowa = rand();
		beginElement = clock();
		tablica.dodaj(losowa);
		endElement = clock();
		double timePerElement = endElement - beginElement;
		if (timePerElement > maxTimePerElement) {
			maxTimePerElement = timePerElement;
			cout << "Nowy najgorszy czas: " << i << endl;
		}
	}

	end = clock();

	cout << tablica.zwrocTab() << endl;

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	cout << time_spent;

	return 0;
}
