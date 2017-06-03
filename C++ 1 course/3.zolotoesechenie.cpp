#include <iostream>
#include <clocale>
#include <iomanip>


using  std::endl;
using  std::cout;
using  std::cin;
using std::setw;
using std::setfill;
using std::setprecision;
using std::fixed;
using std::right;
// Покажите к чему стремится отношение соседних чисел Фибоначчи.
int main()
{  setlocale(LC_ALL,"Russian");
   double mas[40];
   double r,r1;
   mas[0]=1;
   mas[1]=1;
   cout<<"--------------------------------------------------------------------\n";
	cout<<"    Последующее к предыдущему    |    Предыдущее к последующему    |\n";
	cout<<"--------------------------------------------------------------------\n";
	cout<<"               1                 |               1                 | \n";
	for  (int i=2;i<40;i++)
	{
		mas[i]=mas[i-1]+mas[i-2];
		r=mas[i]/mas[i-1];
		r1=mas[i-1]/mas[i];

		cout << setw(20) <<setprecision(7)<<r<<setw(25)<<fixed<<setprecision(7)<<" "<<r1 <<"\n";

	}
	cout<<"----------------------------------------------------------------------\n";

   cout<<"Отношение последущего к предыдущему,стремится к золотому сечению РАВНОМУ и тут формула и расчет ))))"<<endl;
   return 0;
}
