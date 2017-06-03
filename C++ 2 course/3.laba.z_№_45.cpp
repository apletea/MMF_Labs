#include <string.h>
#include <iostream>
#include <cstring>
#include <clocale>
#include <fstream>
#include <stdlib.h>
#include <cmath>
using namespace std;
const int N = 1000;
char *strk = new char[N];

void showtask();

void fin(char *ps, int length);

void watchstr(char *ps);

void strget (char *ps);

void numssum (int len, int tmplen, int &sum, char * maxslovo, int &maxsumma, char *ps );

void maketask1 (char *ps);

void PrintMenu();

int menu ();

int chooseMenu();

/*45. (*) В строке найти сумму цифр, содержащихся во всех словах и слово с максимальной суммой цифр.*/

int main(){
    setlocale(LC_ALL,"Russia");
    while (1){
        menu();
    }
}

int menu (){
        PrintMenu();
        chooseMenu();
}
void PrintMenu(){
        cout << "Введите 1, чтобы просмотреть текст задания." << endl;//+
		cout << "Введите 2, чтобы получить строку из файла." << endl;//+
		cout << "Введите 3, чтобы просмотреть строку." << endl;
		cout << "Введите 4, чтобы самостоятельно ввести строку." << endl;
		cout << "Введите 5, чтобы выполнить задание." << endl;
		cout << "Введите 6, чтобы хотите выйти из программы." << endl;
}

int chooseMenu(){
        char *pstr = strk;
        int status = 0;
        cin >> status;
        switch (status)
        {
            case 1:{showtask();      break;}
            case 2:{fin(pstr, N);    break;}
            case 3:{watchstr(pstr);  break;}
            case 4:{strget(pstr);    break;}
            case 5:{maketask1(pstr); break;}
            case 6:{return 1;}
            default: cout << "Введите число заново" << endl;break;
        }

}

void showtask() {
    cout << "В строке найти сумму цифр, содержащихся во всех словах и слово с максимальной суммой цифр."<< endl;
}

void fin(char *ps, int length){
    ifstream fin("file.txt");
    fin.getline(ps, length);
}

void watchstr(char *ps){
    cout << ps << endl;
}

void strget (char *ps){
    cout << "Введите вашу строку" << endl;
    cin.get();
    cin.getline(strk, N);
}

void maketask1 (char *ps){
    char* maxslovo = new char[255];
    int maxsumma = 0;
    char sym1[] = ",.!?:;-+()*?%№=_&^$#/|\[]{}<>'~`@ ";
    char *tmp = ps;
    int sum = 0,tmplen = 0,len = 0;
    do {
        len = strcspn(tmp, sym1);
        numssum(len, tmplen, sum, maxslovo,maxsumma, ps);
        tmplen = tmplen + len + 1;
        tmp = tmp + len + 1;
    } while (*tmp);
    cout << "сумма цифр в строке: " << sum << endl;
    cout << "слово с наибольшей суммой цифр  " << maxslovo << endl;

}

void numssum (int len, int tmplen, int &sum, char * maxslovo, int &maxsumma, char *ps ){
    int peresum = 0;
    char* slovo = new char [N];
    strncpy(slovo, ps+tmplen, len);
    *(slovo+len)='\0';
    char * symbol;
    for (int i = 1; i < 10; i++ ){
        char * tmpslovo = slovo;
        while (1){
            char *cifra ;
            char symbola = i+48;
            cifra = strchr(tmpslovo,symbola);
            if (cifra!=NULL) {peresum = peresum + i;tmpslovo = cifra+1;}
            else {break;}
        }
    }
    sum = sum + peresum;
    if (peresum > maxsumma){strncpy(maxslovo, ps+tmplen,len); maxsumma = peresum; }
}

