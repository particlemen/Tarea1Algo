#include <iostream>
#include <fstream>
#include <string>
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
	//std::cout << "Iteracion numero " << n_hijos - 1 << " voy con " << Datos->CurPer << "\n";
	double rango_p_hijo = (Datos->der - Datos->izq) / n_hijos; //Largo de rango que abarca cada hijo
	double newizq = Datos->izq, newder; //Limites auxiliares que se usaran al probar nodos
	//std::cout << "Rango por hijo igual a " << rango_p_hijo << " \n";
	if (rango_p_hijo < 1) { //Llegamos a la hoja
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
	std::ofstream archivo_salida;
	std::ifstream archivo_entrada;
	std::string linea;
	archivo_salida.open ("output.txt");//abrimos el archivo de salida
	archivo_entrada.open ("input.txt");//abrimos el archivo de entrada
	int count = 0;
	getline(archivo_entrada, linea);//se omite la primera linea del input
	getline(archivo_entrada, linea);//leemos la primera linea del input que contiene el string
	Perm Test;
	Test.izq = 0;
	Test.CurPer = "";
	if (count%2 == 0) {/*linea par valor string */
		Test.Original = linea;
		}
	getline(archivo_entrada, linea);// se obtiene la linea con el valor de k
	std::string::size_type sz;
	Test.k = std::stoi(linea,&sz);//pasamos de string a int el valor de k
	count+=2;
	Test.der = factorial(Test.Original.size());
	PerRec(&Test);
	archivo_salida << Test.CurPer<<"\n";/*escribo en el archivo output*/
	getline(archivo_entrada, linea);//leo la siguiente linea
	while (linea != "") {
			Test.izq = 0;
			Test.CurPer = "";
			if (count%2 == 0) {/*linea par valor del string */
				Test.Original = linea;
			}
			getline(archivo_entrada, linea); /*se obtiene la linea con el valor de k */
			std::string::size_type sz;
			Test.k = std::stoi(linea,&sz);
			count+=2;
			Test.der = factorial(Test.Original.size());
			PerRec(&Test);
			archivo_salida << Test.CurPer << "\n";/*escribo en el archivo*/
			getline(archivo_entrada, linea); /*siguente linea contiene el string */

}
archivo_salida.close();
archivo_entrada.close();
}
