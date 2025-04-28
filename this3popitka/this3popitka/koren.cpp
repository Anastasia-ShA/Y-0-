#include "FileName.h"

int main() {
    int deistvie;
    setlocale(0, "Russian");
    do {
        cout << "\n\nПоиск корней y=0 на отрезке.\nФунции:\n0. Вернуться в глаавное меню\n1. Полином степени N: a0+a1*x+a2*x^2+...aN*x^N" <<
            "\n2. Степенная: A*x^B+C\n3. Показательная: A*B^(C*x)+D\n4. Логарифмическая: A*ln(B*x)+C\n5. Синусоида: A*sin(B*x+C)+D" <<
            "\n6. Косинусоида: A*cos(B*x+C)+D\n";
        cin >> deistvie;

        switch (deistvie) {
        case 1:
            polinom();
            findAllKorny(a, b, podshett_polinom);
            break;
        case 2:
            stepennaya();
            findAllKorny(a, b, podshett_stepennoy);
            break;
        case 3:
            pokazatelnaya();
            findAllKorny(a, b, podshett_pokazatelnoy);
            break;
        case 4:
            logarifmisheskaya();
            findAllKorny(a, b, podshett_logarifmichesok);
            break;
        case 5:
            sinusoidnaya();
            findAllKorny(a, b, podshett_sinusoidnaya, 100000);
            break;
        case 6:
            kosinusoida();
            findAllKorny(a, b, podshett_kosinusoida, 100000);
            break;
        default:
            break;
        }
    } while (deistvie != 0);
}