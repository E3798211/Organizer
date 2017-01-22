#include <iostream>
#include "Funcs.h"

using namespace std;

int main()
{
    string a;
    string* b = new string [100];
    //a = UserEnter();
    b = StrToWord(UserEnter());
    cout << b[0] << endl;
    cout << b[1] << endl;
    cout << b[2] << endl;
    cout << b[3] << endl;
    //PasswordCheck();
    //cout << a;

    //CORRECT UserEnter() - FIRST SYMBOL MUST BE ALNUM, NOT SPACE
    //StrToWord() DOESNT SEE LAST WORD
}

