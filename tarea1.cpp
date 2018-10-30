#include <iostream>

std::string PerRec(int izq, int der, std::string CurPer, std::string &Original, int pos){
	int n_hijos = CurPer.size() + 1;
	if (izq == der) {
		return CurPer;
	}

}

double factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
	std::string Perro = "Guau\n";
  std::cout << Perro.replace(2,1, "");
	std::cout << factorial(32);
}
