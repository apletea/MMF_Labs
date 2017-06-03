#include <iostream>
#include <clocale>

using std::endl;
using std::cin;
using std::cout;
// "Нормальный" калькулятор. Обработка ситуации деления на 0. Результат вычислений остается как текущее значение. Если вместо операции ввести символ ’c’, то калькулятор сбрасывается в начало, при вводе символа ’e’ вместо операции калькулятор завершает работу (exit).
int main()
{   setlocale(LC_ALL,"Russian");
  int x1,x2,i=0;// вводить можно только целые? Бред...
  double res;
  char op;
    while (i==0)
    {
            i++;
      cout << "Введи первое число" << endl;
      cin>>x1;
      cout<<"Введи операцию(для выхода введите е,для обнуления введите с)"<<endl;
      cin>>op;
       switch (op)
    {
             case 'c':i=0;
             break;
             case 'e': i=2;
             break;
             default:

      cout<<"Введи второе число"<<endl;
      cin>>x2;
       switch (op)
       {
        case  '+' : res=x1+x2;
            cout<<res<<endl;
        break;
        case '-' :res=x1-x2;
            cout<<res<<endl;
        break;
        case '*':res=x1*x2;
            cout<<res<<endl;
        break;
        case '/' :
            switch (int(x2))//а тут зачем приведение типов?????
            {
                case 0:
                     cout<<"на ноль делить нельзя"<<endl;
                break;
                default:  res=x1/x2;
                     cout<<res<<endl;
                break;
            }
        break;
         case 'e' :i=2; ;
       }
                    while (i==1)
                {
                        cout<<"Введи операцию(для выхода введите e,для обнуления введите с) "<<endl;
                        cin>>op;
                         switch (op)
                         {
                             case 'e'  :i=2;
                             break;
                             case 'c' :i=0;
                             break;
                             default:
                                cout<<"Введи  число"<<endl;
                                cin>>x2;
                                    switch (op)
                                {
                                        case  '+' : res=res+x2;
                                            cout<<res<<endl;
                                        break;
                                        case '-' :res=res-x2;
                                            cout<<res<<endl;
                                        break;
                                        case '*':res=res*x2;
                                            cout<<res<<endl;
                                        break;
                                        case '/' :
                                            switch (int(x2))
                                            {
                                                    case 0:
                                                        cout<<"на ноль делить нельзя"<<endl;
                                                    break;
                                                    default:  res=res/x2;
                                                        cout<<res<<endl;
                                                    break;
                                            }
                                }
                        }
                }
        }
    }

    return 0;
}
