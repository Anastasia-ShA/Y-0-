
#include "kombinatorika.h"


int main() {
	setlocale(0, "Russian");
	int deistvie; 
	

	do
	{
		cout << "\n����������� ������ �������������.";
		cout << "\n\b�������: \n0. ��������� � ������� ����\n1. ���������� � �����������\n2. ���������� ��� ����������\n3. ��������� � �����������\n4. ��������� ��� ����������\n5. ������������ ��� ����������\n6. ������������ � ������������\n�������� ����� ��������: ";
		cin >> deistvie;
		switch (deistvie)
		{
		case 1: Razmechenie_S_Povtoreniem(); break;
		case 2:Razmechenie_Bez_Povtoreniy(); break;
		case 3:Sochetanie_S_Povtoreniem(); break;
		case 4:Sochetanie_Bez_Povtoreniy(); break;
		case 5:Perestanovka_Bez_Povtoreniy(); break;
		case 6:Perestanovka_S_Povtoreniyami(); break;
		default:
			break;
		}

	} while (deistvie!=0);



	return 0;
}
