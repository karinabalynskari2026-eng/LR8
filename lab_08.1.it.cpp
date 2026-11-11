// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1.   Вияснити, чи є серед цих символів пара сусідніх букв "no" або "on".
// 2.   Замінити кожну пару сусідніх букв "no" трійкою зірочок "***".

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool Exists(char* str)
{
    if (strlen(str) < 2)
        return false;

    for (int i = 0; str[i + 1] != 0; i++)
        if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n'))
            return true;
    return false;
}

char* Change(char* str)
{
    size_t len = strlen(str);

    if (len < 2)
        return str;

    char* tmp = new char[len * 3 / 2 + 1];
    char* t = tmp;

    tmp[0] = '\0';

    size_t i = 0;

    while (i < len && str[i + 1] != 0)
    {
        if (str[i] == 'n' && str[i + 1] == 'o')
        {
            strcat(t, "***");
            t += 3;
            i += 2;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    if (str[i] != 0)
        *t++ = str[i++];
    *t = '\0';

    strcpy(str, tmp);

    return tmp;
}

int main()
{
    char str[151];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (Exists(str))
        cout << "String contains pair 'no' or 'on'" << endl;
    else
        cout << "String does not contain pair 'no' or 'on'" << endl;

    char* dest = new char[151];
    dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}