#include <iostream>
#include <string.h>
#include <clocale>
#include <fstream>
using namespace std;
bool fromFile = false;
ifstream fin("trains.txt");
int numberOfTrains;
class Train{
    private:
        char endPoint[30];
        int trainNumber;
        int timeOutgoing;
        int commonPlaces;
        int majorPlacec;
        int uncommonPlaces;
    public:
        Train();
        void setTrainFromConsole();
        void setTrainFromFile();
        void showTrain();
        char *get_endPoint();
        int get_trainNumber();
        int get_timeOutgoing();
        int get_commonPlacec();
        int get_majorPlaces();
        int get_uncommonPlaces();
        bool isGoingToThePoint(char *searchingPoint);
        bool isGoingAfterTime(int Time);
        bool isEmptyCommonPlaces();
        friend ostream& operator << (ostream& out, const Train& T);
};
void PrintMenu(Train *listOfTrains);

int menu (Train *listOfTrains );

int chooseMenu(Train *listOfTrains);

void taskA(Train *listOfTrains);

void taskB(Train *listOfTrains);

void taskC(Train *listOfTrains);

int main(){
    setlocale(LC_ALL,"Russian");
    Train *listOfTrains;
    cout << "Введите число поездов"<<endl;
    cin >> numberOfTrains;
    cout << "Ввод из файла?Если да введите 1, если из консоли то 0" << endl;
    int a;
    cin >> a;
    if (a)
        fromFile = true;
    else
        fromFile = false;
    try{
        listOfTrains = new Train[numberOfTrains];
    }
    catch (exception e){
        cout << "Не достаточно памяти" << endl;
        throw e;
    }
    while(1)
    menu(listOfTrains);
    return 0;
}
int menu (Train *listOfTrains){
        PrintMenu(listOfTrains);
        chooseMenu(listOfTrains);
}

void PrintMenu(Train *listOfTrains){
        cout << "Введите 1, чтобы выполнить а) список поездов, следующих до заданного пункта назначения." << endl;//+
		cout << "Введите 2, чтобы выполнить б) список поездов, следующих до заданного пункта назначения и отправляющихся после заданного часа" << endl;//+
		cout << "Введите 3, чтобы выполнить в) строку список поездов, отправляющихся до заданного пункта назначения и имеющих общие места." << endl;
		cout << "Введите 4, чтобы хотите выйти из программы." << endl;
}

int chooseMenu(Train *listOfTrains){
        int status = 0;
        try{
            cin >> status;
        }
        catch(exception e){
            cout << "Вводить надо число" << endl;
        }
        switch (status){
            case 1:{taskA(listOfTrains);  break;}
            case 2:{taskB(listOfTrains);  break;}
            case 3:{taskC(listOfTrains);  break;}
            case 4:{return 1;}
            default: cout << "Введите число заново" << endl;break;
        }
}
void taskA(Train *listOfTrains){
    cout << "Введите конечный пункт"<<endl;
    char* searchingPoint= new char[50];
    cin >> searchingPoint;
    for (int i = 0; i < numberOfTrains; i++){
        if (listOfTrains[i].isGoingToThePoint(searchingPoint)){
            cout << listOfTrains[i];
        }
    }
}

void taskB(Train *listOfTrains){
    cout << "Введите конечный пункт"<<endl;
    char* searchingPoint= new char[50];
    cin >> searchingPoint;
    try{
        cout << "Введите час после которого собираетесь отправиться"<< endl;
        int Time;
        cin >> Time;
    }
    catch(exception e){
        cout << "не верный тип данных" << endl;
    }
    for (int i = 0; i < numberOfTrains; i++){
        if ((listOfTrains[i].isGoingToThePoint(searchingPoint)) && (listOfTrains[i].isGoingAfterTime(Time))){
            cout << listOfTrains[i];
        }
    }
}

void taskC(Train *listOfTrains){
     cout << "Введите конечный пункт"<<endl;
     char* searchingPoint= new char[50];
     cin >> searchingPoint;
     for (int i = 0; i < numberOfTrains; i++){
        if ((listOfTrains[i].isGoingToThePoint(searchingPoint)) && (listOfTrains[i].isEmptyCommonPlaces())){
            cout << listOfTrains[i];
        }
    }
}


Train::Train(){
      if (fromFile)
        setTrainFromFile();
      else
        setTrainFromConsole();
}

void Train::setTrainFromConsole(){
    try{
        cout << "Введдите конечный пункт" << endl;
        cin >> endPoint;
        cout << "Введите номер поезда" << endl;
        cin >> trainNumber;
        cout << "Введите время отправления" << endl;
        cin >> timeOutgoing;
        cout << "Введите число общих мест" << endl;
        cin >> commonPlaces;
        cout << "Ведите чило мест в купе" << endl;
        cin >> majorPlacec;
        cout << "Введите число мест в платскарте" << endl;
        cin >> uncommonPlaces;
    }
    catch(exception e){
        cout << "Неверный тип данных" << endl;
    }
}
void Train::setTrainFromFile(){
    try{
        char temp[1];
        fin.getline(endPoint,50);
        fin >> trainNumber;
        fin >> timeOutgoing;
        fin >> commonPlaces;
        fin >> majorPlacec;
        fin >> uncommonPlaces;
        fin.getline(temp, 1);
    }
    catch(exception e){
        cout << "Файл не найден" << endl;
        throw 0;
    }

}
char * Train::get_endPoint(){
    return endPoint;
}
int Train::get_trainNumber(){
    return trainNumber;
}
int Train::get_timeOutgoing(){
    return timeOutgoing;
}
int Train::get_commonPlacec(){
    return commonPlaces;
}
int Train::get_majorPlaces(){
    return majorPlacec;
}
int Train:: get_uncommonPlaces(){
    return uncommonPlaces;
}
bool Train:: isGoingToThePoint(char *searchingPoint){
    return !strcmp(this->endPoint, searchingPoint);
}
bool Train::isGoingAfterTime(int Time){
    return Time <= timeOutgoing;
}
bool Train::isEmptyCommonPlaces(){
    return this->commonPlaces;
}
ostream& operator << (ostream& out, const Train& T){
	out <<"№ поезда : " <<T.trainNumber << " | время отправляния : " << T.timeOutgoing << " | конечный пункт :  " << T.endPoint << "  | кол-во общих мест:  "<< T.commonPlaces << endl;
	return out;
}

void Train::showTrain(){
    cout << this;
}
