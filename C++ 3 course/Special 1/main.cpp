#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>

using namespace std;

class Vector{
    private:
        int a;
        int b;
        int c;
    public:
        Vector();
        void setVector(int a, int b, int c);
        void getVector();
        int  getFirstCordinate();
        int  getSecondCordinate();
        int  getThirdCordinate();

        friend ostream &operator<<(ostream &stream, Vector &oneVector);
        friend istream &operator>>(istream &stream, Vector &oneVector);
};

Vector::Vector(){
    a = 0;
    b = 0;
    c = 0;
}

void Vector::setVector(int a, int b, int c){
    this->a = a;
    this->b = b;
    this->c = c;
}

void Vector::getVector(){
    cout << "Вектор: ("<< this->a << ", " << this->b << ", " << this->c << ")\n";
}

int Vector::getFirstCordinate(){
   return this->a;
}

int Vector::getSecondCordinate(){
   return this->b;
}

int Vector::getThirdCordinate(){
   return this->c;
}

ostream &operator<<(ostream &stream, Vector &oneVector){
    stream << "Вектор: ("
           << oneVector.getFirstCordinate()  << ", "
           << oneVector.getSecondCordinate() << ", "
           << oneVector.getThirdCordinate()  << ")\n";

    return stream;
}

istream &operator>>(istream &stream, Vector &oneVector){
    cout << "Введите вектор:\n";
    int a, b, c;
    stream >> a >> b >> c;
    oneVector.setVector(a, b, c);

    return stream;
}

void enterFromFile(Vector *vectorArray, int &numberOfVectors){
    ifstream fin("input.txt", ios::in);
    for(int i = numberOfVectors; i < numberOfVectors + 35; ++i){
        int a, b, c;
        fin >> a >> b >> c;
        vectorArray[i].setVector(a, b, c);
    }
    numberOfVectors += 35;
    cout << "Векторы были успешно добавлены!\n";

    fin.close();
}

void enterWithOperator(Vector *vectorArray, int &numberOfVectors){
    int number;
    Vector temp;

    cout << "Введите кол-во векторов:\n";
    cin >> number;
    for(int i = numberOfVectors; i < numberOfVectors + number; ++i){
        cin >> temp;
        vectorArray[i] = temp;
    }
    numberOfVectors += number;
}

void showVectors(Vector *vectorArray, int &numberOfVectors){
    for(int i = 0; i < numberOfVectors; ++i){
        Vector temp = vectorArray[i];
        cout << temp;
    }
}

void defineLinear(Vector *vectorArray, int &numberOfVectors){
    for(int i = 0; i < numberOfVectors; ++i){
        for(int j = i; j < numberOfVectors; ++j){
            if(((vectorArray[i].getFirstCordinate () % vectorArray[j].getFirstCordinate ()) ==
                (vectorArray[i].getSecondCordinate() % vectorArray[j].getSecondCordinate())) &&
               ((vectorArray[i].getSecondCordinate() % vectorArray[j].getSecondCordinate()) ==
                (vectorArray[i].getThirdCordinate () % vectorArray[j].getThirdCordinate ()))
              ||
               ((vectorArray[j].getFirstCordinate () % vectorArray[i].getFirstCordinate ()) ==
                (vectorArray[j].getSecondCordinate() % vectorArray[i].getSecondCordinate())) &&
               ((vectorArray[j].getSecondCordinate() % vectorArray[i].getSecondCordinate()) ==
                (vectorArray[j].getThirdCordinate () % vectorArray[i].getThirdCordinate ()))){
                    if(i != j){
                        cout << vectorArray[i] << " и " << vectorArray[j] << " - колинеарны.\n";
                    }
                }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    const int N = 100;
    int numberOfVectors = 0;
    Vector *vectorArray = new Vector[N];

    while(true){
        cout << "\n"
             << " -1) Ввести векторы из файла\n"
             << " -2) Ввести векторы перегруженным оператором\n"
             << " -3) Вывести вектроры перегруженным оператором\n"
             << " -4) Определить коллинеарность векторов\n"
             << " -5) Выход\n";
        int c;
        cin >> c;

        switch(c){
            case 1:
                enterFromFile(vectorArray, numberOfVectors);
                break;
            case 2:
                enterWithOperator(vectorArray, numberOfVectors);
                break;
            case 3:
                showVectors(vectorArray, numberOfVectors);
                break;
            case 4:
                defineLinear(vectorArray, numberOfVectors);
                break;
            case 5:
                cout << "До свидания!\n";
                return 0;
            default:
                cout << "Ошибка!\n";
                break;
        }
    }

    return 0;
}
