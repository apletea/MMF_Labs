#include <bits/stdc++.h>


void fill_info(std::vector<std::vector<int>> & info, int argv, char ** argc)
{
    if (argv < 2)
        throw 1;
    std::ifstream in(argc[1]);
    for (int i = 0; i < 9 ; ++i)
    {
        for (int j = 0 ; j < 9; ++j)
        {
            in >> info[i][j];
            if (!info[i][j])
                info[i][j] = INT32_MAX;
        }
    }
    in.close();
}
//param - file with matrix 9x9 where arr[i][j] is the cost for i -> j, 0 if is not path from i -> j
int main(int argv, char ** argc)
{
    std::vector<std::vector<int>> info(9,std::vector<int>(9));
    fill_info(info,argv,argc);
    int cost = 0;
    int count = 0;
    while (count != 4)
    {
        int minVal = INT32_MAX;
        int from;
        int to;
        for (int i = 0 ; i < info.size(); ++i)
        {
            for (int j = 0; j < info.size(); ++j)
            {
                if (info[i][j] < minVal)
                {
                    minVal = info[i][j];
                    from = i;
                    to = j;
                }
            }
        }
        count++;
        cost += minVal;
        std::cout <<"(" << from << ", " << to <<")"<< std::endl;
        for (int i = 0; i < info.size(); ++i)
        {
            info[from][i] = INT32_MAX;
            info[i][from] = INT32_MAX;
            info[i][to] = INT32_MAX;
            info[to][i] = INT32_MAX;
        }
    }
    std::cout << "Величина потока = 4, стоимость = " << cost << std::endl;
}
