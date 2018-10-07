#include "String.h"
#include <conio.h>

int main() {
    String str1("Hello ");
    String str2("World");
    String str3 = str1 + str2;
    str2.PrintString();
    str3.PrintString();
    // str1.PrintString();

    _getch();
    return 0;
}
