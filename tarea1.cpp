#include <iostream>

class Perm{

public:
	double izq;
	double der;
	std::string CurPer;
	std::string Original;
	int k;
};

void PerRec(Perm *Datos){
	int n_hijos = Datos->CurPer.size() + 1; //Obtengo numero de hijos
	std::cout << "Iteracion numero " << n_hijos - 1 << " voy con " << Datos->CurPer << "\n";
	double rango_p_hijo = (Datos->der - Datos->izq) / n_hijos; //Largo de rango que abarca cada hijo
	double newizq = Datos->izq, newder; //Limites auxiliares que se usaran al probar nodos
	std::cout << "Rango por hijo igual a " << rango_p_hijo << " \n";
	if (int(rango_p_hijo) == 0) { //Llegamos a la hoja
		std::cout << "Chao lo Vimo\n";
		return;
	}
	for (int i = 0; i<n_hijos; i++){ //Reviso cada hijo mio
		newder = newizq + rango_p_hijo; //Muevo el limite de la derecha
		if ((newizq <= Datos->k) && (newder >= Datos->k)){ //Bingo
			Datos->izq = newizq; //Reemplazo en la clase
			Datos->der = newder; //Reemplazo en la clase
			char ci = Datos->Original[n_hijos - 1]; //Caracter a insertar en la palabra decodificada
			Datos->CurPer.insert(i,1,ci); //Inserto este caracter
			PerRec(Datos); //Fiush
			break;
		}
		else{
			newizq = newder; //Muevo el limite de la izquierda
		}
	}
	return;
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
	std::cout << factorial(4);
	Perm Test;
	Test.izq = 0;
	Test.CurPer = "";
	Test.Original = "QAZCDETGBMJUYHNVFRWSXIKLOP";
	Test.der = factorial(Test.Original.size());
	Test.k = 165423;
	std::cout << "It Begins \n";
	PerRec( &Test );
	std::cout << "Finalmente tengo " << Test.CurPer << " \n";
}
