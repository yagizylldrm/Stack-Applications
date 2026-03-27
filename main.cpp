#include "InfixToPostfix.h"
using namespace std;

int main()
{
    InfixToPostfix lab;

    // Test Listesi
    string tests[] = {"5+2*3", "(9-3)/2", "2*3+4*5", "((1+2)*3)-4"};
    int expected[] = {11, 3, 26, 5};

    for (int i = 0; i < 4; i++)
    {
        lab.setInfix(tests[i]);
        lab.convertToPostfix();
        int res = lab.postfixCalculator();

        cout << "Test " << i + 1 << ": " << tests[i] << endl;
        cout << "  Postfix: " << lab.getPostfix() << endl;
        cout << "  Sonuc:   " << res;

        if (res == expected[i]) cout << " [Doğru Sonuç]" << endl;
        else cout << " [Hata! Olması Gereken: " << expected[i] << "]" << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}