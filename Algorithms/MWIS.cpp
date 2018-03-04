#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;
int main(int argc, char** argv) {


    if (argc < 3)
    {
        std::cout << "./app input.txt output.txt" << std::endl;
        return 0;
    }

    int n,i,j,d,last=-1;
    int total=0;

    std::fstream in;
    std::ofstream out(argv[2]);

    char buffer[1000];

    int gp[n];
    int gc[n];
    int w[n];
    int a[n][n];
    int deg[n];
    float gw[n];

    in.open(argv[1],ios::in);
    in.getline(buffer,sizeof(buffer),'\n');
    n=atoi(buffer);


    for(i=0;i<n;i++)
    {
        if(i==n-1)	in.getline(buffer,sizeof(buffer),'\n');
        else in.getline(buffer,sizeof(buffer),' ');
        w[i]=atoi(buffer);
    }

    for(i=0;i<n;i++)
    {
        d=0;
        for(j=0;j<n;j++)
        {
            if(j==n-1)	in.getline(buffer,sizeof(buffer),'\n');
            else in.getline(buffer,sizeof(buffer),' ');

            a[i][j]=atoi(buffer);
            if(a[i][j]==1) d++;
            if(j==n-1) deg[i]=d;
        }
    }

    for(i=0;i<n;i++)
    {
        gp[i]=0;
        gc[i]=0;
        gw[i]=(float)w[i]/(float)(deg[i]+1.0);
    }

    int t,flag=1;
    int x=0;
    while(flag==1)
    {
        for(i=0;i<n;i++)
        {
            t=0;
            for(j=0;j<n;j++)
            {
                if(a[i][j]==1)
                {
                    if(gw[j]>gw[i] && gp[j]==1)
                    {
                        t=1;
                        gc[i]=0;
                    }
                    if(gw[j]==gw[i] && gp[j]==1 && i>j)
                    {
                        t=1;
                        gc[i]=0;
                    }
                }
            }
            if(t==0)
            {
                gc[i]=1;
            }

        }

        if(x!=0){
            for(i=0;i<n;i++)
            {
                if(gp[i]!=gc[i])	break;
                if(gp[i]==1)	last=i;
                if(i==n-1)	flag=0;
            }
        }

        for(i=0;i<n;i++)
        {
            gp[i]=gc[i];
        }
        x++;
    }


    out<<"MWIS: {";
    for(i=0;i<n;i++)
    {
        if(i==last){
            total+=w[i];
            out<<i;
            break;
        }
        if(gc[i]==1)
        {
            out<<i<<",";
            total+=w[i];
        }
    }
    out<<"}"<<endl;
    out<<"total weight is:"<<total;

    in.close();
    out.close();

    return 0;
}
