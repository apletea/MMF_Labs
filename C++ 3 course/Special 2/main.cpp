#include <iostream>
#include <cstdlib>

using namespace std;

class FazzyNumber{
    private:
        int number;
        int coeff1;
        int coeff2;
    public:
        FazzyNumber();
        void enterNumber();
        void showNumber ();

        friend FazzyNumber& operator+=(FazzyNumber &left, const FazzyNumber &right);
        friend FazzyNumber& operator-=(FazzyNumber &left, const FazzyNumber &right);
        friend FazzyNumber& operator*=(FazzyNumber &left, const FazzyNumber &right);
};

FazzyNumber::FazzyNumber(){
    number = 0;
    coeff1 = 0;
    coeff2 = 0;
}

void FazzyNumber::enterNumber(){
    int number, coeff1, coeff2;
    cout << "Введите ваше число:\n";
    cin  >> number;
    cout << "Введите первый коеффициент:\n";
    cin  >> coeff1;
    cout << "Введите второй коеффициент:\n";
    cin  >> coeff2;

    this->number = number;
    this->coeff1 = coeff1;
    this->coeff2 = coeff2;
}

void FazzyNumber::showNumber(){
    cout << " (" << this->number - this->coeff1 << ", " <<  this->number << ", " << this->number + this->coeff2 << ")\n";
}

FazzyNumber& operator+=(FazzyNumber &left, const FazzyNumber &right){
    left.number = left.number + right.number;
    left.coeff1 = left.coeff1 + right.coeff1;
    left.coeff2 = left.coeff2 + right.coeff2;

    return left;
}

FazzyNumber& operator-=(FazzyNumber &left, const FazzyNumber &right){
    left.number = left.number - right.number;
    left.coeff1 = left.coeff1 + right.coeff1;
    left.coeff2 = left.coeff2 + right.coeff2;

    return left;
}

FazzyNumber& operator*=(FazzyNumber &left, const FazzyNumber &right){
    left.number = left.number * right.number;
    left.coeff1 = right.number * left.coeff1 + left.number * right.coeff1 + left.coeff1 * right.coeff1;
    left.coeff2 = right.number * left.coeff2 + left.number * right.coeff2 + left.coeff2 * right.coeff2;

    return left;
}

void enterFazzyNumbers(FazzyNumber *fNumbers, int &amount){
    int c;
    cout << "Введите кол-во Fazzy Numbers:\n";
    cin >> c;
    for(int i = amount; i < amount + c; ++i){
        cout << "Введите " << i + 1 << " Fazzy Number:\n";
        fNumbers[i].enterNumber();
    }
    amount += c;
}

void showFazzyNumbers(FazzyNumber *fNumbers, int &amount){
    for(int i = 0; i < amount; ++i){
        cout << i + 1 << " Fazzy Number:\n";
        fNumbers[i].showNumber();
    }
}

void sumNumbers(FazzyNumber *fNumbers, int &amount){
    int i, j;
    cout << "Введите номера двух элементов, который надо сложить:\n";
    cin >> i >> j;
    fNumbers[i - 1] += fNumbers[j - 1];
}

void subtracrNumbers(FazzyNumber *fNumbers, int &amount){
    int i, j;
    cout << "Введите номера двух элементов, который надо вычесть:\n";
    cin >> i >> j;
    fNumbers[i - 1] -= fNumbers[j - 1];
}

void multiplyNumbers(FazzyNumber *fNumbers, int &amount){
    int i, j;
    cout << "Введите номера двух элементов, который надо умножить:\n";
    cin >> i >> j;
    fNumbers[i - 1] *= fNumbers[j - 1];
}

int main()
{
    FazzyNumber *fNumbers = new FazzyNumber[50];
    int amount = 0;

    while(true){
        cout << "\n"
             << " -1) Ввести Fazzy Number\n"
             << " -2) Вывести Fazzy Numbers\n"
             << " -3) Сложить два Fazzy Number\n"
             << " -4) Вычесть два Fazzy Number\n"
             << " -5) Умножить два Fazzy Number\n"
             << " -6) Выход\n";

        int c;
        cin >> c;
        switch(c){
            case 1:
                system("clear");
                enterFazzyNumbers(fNumbers, amount);
                showFazzyNumbers(fNumbers, amount);
                break;
            case 2:
                system("clear");
                showFazzyNumbers(fNumbers, amount);
                break;
            case 3:
                sumNumbers(fNumbers, amount);
                showFazzyNumbers(fNumbers, amount);
                break;
            case 4:
                subtracrNumbers(fNumbers, amount);
                showFazzyNumbers(fNumbers, amount);
                break;
            case 5:
                multiplyNumbers(fNumbers, amount);
                showFazzyNumbers(fNumbers, amount);
                break;
            case 6:
                system("clear");
                cout << "До свидания!\n";
                return 0;
            default:
                cout << "Ошибка!\n";
                break;
        }
    }

    return 0;
}
