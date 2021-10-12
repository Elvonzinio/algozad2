#include <string>

using namespace std;

class tabDynamiczna
{
public:
	int realRozm = 0;
	int maxRozm = 100;
	int* tab;

	tabDynamiczna();

	~tabDynamiczna();

	void dodaj(int dane);

	int zwrocDana(int index);

	void podmiana(int index, int dane);

	void czyszczenie();

	string zwrocTab();

	void sort();

	void realokacja();
};

