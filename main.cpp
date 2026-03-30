#include "InfixToPostfix.h"
#define SIZE 5
using namespace std;

int main()
{
    InfixToPostfix lab;

    // Binary Test Listesi
    char bin[SIZE][64] = {"011101", "011111", "11001111", "00001111", "10111001"};
    // Beklenen Sonuçlar Listesi
    int bin_expected[] = {29, 31, 207, 15, 185};

    // Binary Çevirme Testi
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\nBinary to integer: " << lab.convertBinaryToInt(bin[i]) << endl;
        cout << "Expected: " << bin_expected[i];
        if (bin_expected[i] == lab.convertBinaryToInt(bin[i])) cout << " [Doğru Sonuç]" << endl;
        else cout << " [Hata! Olması Gereken: " << bin_expected[i] << "]" << endl;
    }

    // Infix'ten Postfix'e Çevirme Test Listesi
    string postfix_convert[SIZE] = {"5+2*3", "(9-3)/2", "2*3+4*5", "((1+2)*3)-4", "((1 + 2) * 3) - 4"};
    // Beklenen Sonuçlar Listesi
    int calc_expected[SIZE] = {11, 3, 26, 5, 5};

    // Infix'ten Postfix'e Çevirme Testi
    for (int i = 0; i < SIZE; i++)
    {
        cout << "-------------------------" << endl;
        lab.setInfix(postfix_convert[i]);
        lab.convertToPostfix();
        int res = lab.postfixCalculator();

        cout << "Test " << i + 1 << ": " << endl;
        lab.showInfix();
        lab.showPostfix();
        cout << "  Sonuc:   " << res;

        if (res == calc_expected[i]) cout << " [Doğru Sonuç]" << endl;
        else cout << " [Hata! Olması Gereken: " << calc_expected[i] << "]" << endl;
    }
    cout << "-------------------------" << endl;

    return 0;
}
