#include <bits/stdc++.h>
void first_iteration(std::string & str, int & i, char & stateCH)
{
    i--;
    stateCH = str[i];
    str[i] = 'X';
    i++;
    str[i] = stateCH;
}

int main(int argc, char **argv)
{
    std::string str = "BBB010011BBBBBBB";

    int i = 0;
    char stateCH;
    while (str[i++]=='B');
    while (str[i]!='B')i++;
    first_iteration(str,i,stateCH);
    while (true)
    {
        while(str[i--]!='X');
        while (str[i]=='X')i--;
        stateCH = str[i];
        if (stateCH=='B')
            break;
        str[i] = 'X';
        while(str[i++]=='X');
        while(str[i]!='B')i++;
        str[i] = stateCH;
    }



    std::cout << str << std::endl;
    return 0;
}
