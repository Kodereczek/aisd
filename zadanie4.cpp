#include <iostream>
#include <time.h>

using namespace std;

unsigned int FibRek(unsigned int n)
{
	if (n < 2) return n;
	else
	{
		return FibRek(n - 1) + FibRek(n - 2);
	}
}

unsigned int FibIte(unsigned int n)
{
	if (n < 2) return n;
	else
	{
		unsigned int
			n1 = 1,
			n2 = 0,
			result;

		for (unsigned int i = 2; i <= n; ++i)
		{
			result = n1 + n2;
			n2 = n1;
			n1 = result;
		}

		return result;
	}
}

int main()
{
	unsigned int
		rek = 40,
		ite = 1000000000;

	cout << "Trwa obliczanie...";

	time_t timeStart = clock();
	cout << "\n\nn" << rek << " = " << FibRek(rek) << "\n";
	cout << "Czas obliczania rekurencyjnie " << rek << " wyrazu to: " << (float)(clock() - timeStart) / CLOCKS_PER_SEC << "s\n\n";

	timeStart = clock();
	cout << "n" << ite << " = " << FibIte(ite) << "\n";
	cout << "Czas obliczania iteracyjnie " << ite << " wyrazu to: " << (float)(clock() - timeStart) / CLOCKS_PER_SEC << "s";

	getchar();

	return 0;
}
