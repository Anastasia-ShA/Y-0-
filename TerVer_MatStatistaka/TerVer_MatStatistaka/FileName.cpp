#include <locale.h>
#include "sami_function.h"
#include <stdio.h>
	


int main() {
	int deistvie;
	setlocale(0, "Russian");
	extern int kolvo_slychaynix_velichin;
	extern double* Xi;
	extern double* Pi;

	do
	{
		cout << "\nКалькулятор теории вероятности и мат статистики.";
		cout << "\nФункции: \n0. Вернуться в главное меню\n1. Вероятность m/n\n2. Дисперсия для дискретного рапределения величин\n3. Мат ожидание для дискретного распределения величин\n";
		cin >> deistvie;
		switch (deistvie)
		{
		case 1: veroyatnostM_N(); break;
		case 2:
			cout << "Введите количество случайных величин:";
			praviolnost_Vvoda_int(kolvo_slychaynix_velichin);
			if (Xi != nullptr) delete[] Xi;
			if (Pi != nullptr) delete[] Pi;
			Xi = new double[kolvo_slychaynix_velichin];
			Pi = new double[kolvo_slychaynix_velichin];
			dispersia();
			break;
		case 3:
			cout << "Введите количество случайных величин:";
			praviolnost_Vvoda_int(kolvo_slychaynix_velichin);
			if (Xi != nullptr) delete[] Xi;
			if (Pi != nullptr) delete[] Pi;
			Xi = new double[kolvo_slychaynix_velichin];
			Pi = new double[kolvo_slychaynix_velichin];
			matOshidanie();
			break;
		default:
			break;
		}
	} while (deistvie!=0);
	if (Xi != nullptr) delete[] Xi;
	if (Pi != nullptr) delete[] Pi;
}