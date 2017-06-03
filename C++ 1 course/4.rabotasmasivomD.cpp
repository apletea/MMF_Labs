#include <iostream>
#include <clocale>
//Заполнить двумерный массив размера N на N (число N объявить как константу равную нескольким десятков)
using std::cin;
using std::cout;
using std::endl;
int main()
{  const int N=10;
   setlocale(LC_ALL,"Russian");
   int mas[N][N];
   int l=1;
   cout<<"построчно слева-направо"<<endl;
     for (int i=0;i<N;i++)
     {
         for (int j=0;j<N;j++)
         {
             mas[i][j]=l;
             cout<<mas[i][j]<<"\t";
             l++;
         }
         cout<<""<<endl;
     }

     cout<<"построчно справа-налево"<<endl;
     for (int i=0;i<N;i++)
     {
         for (int j=N-1;j>=0;j--)
         {

             cout<<mas[i][j]<<"\t";

         }
         cout<<""<<endl;
     }
     cout<<"плуг"<<endl;
     for (int i=0;i<N;i++)
     {
         if (i%2!=0)
            {
             for (int j=N-1;j>=0;j--)
              {
                  cout<<mas[i][j]<<"\t";
              }
            }
         else
         {
             for (int j=0;j<N;j++)
             {
                 cout<<mas[i][j]<<"\t";
             }
         }
         cout<<""<<endl;
     }

   int k=0;
     cout<<"змейка"<<endl;
     for (int i=0;i<N;i++)
     {


          if (i%2!=0)
            {


               for (int j=0;j<N;j++)
                {
                 cout<<mas[j][i]<<"\t";
                }
            }
            else
            {
                for (int j=N-1;j>=0;j++)
                {
                    cout<<mas[j][i]<<"\t";
                }
            }
         cout<<""<<endl;
     }

   return 0;
}

