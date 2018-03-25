#include <bits/stdc++.h>

using namespace std;

void init_gp(vector<vector<int>> & gp)
{
    for (int i = 0; i < gp.size(); ++i)
    {
        for (int j  = i+1; j < gp.size(); ++j)
        {
            gp[i][j]  = rand()%80+10;
            gp[j][i] = gp[i][j];
        }
        gp[i][i] = INT_MAX;
    }

    for (int i = 0; i < gp.size(); ++i)
    {
        for (int j  = 0; j < gp.size(); ++j)
        {
            cout << gp[i][j] << " ";
        }
        cout << "  " <<endl;
    }
}

int getPathWeight(const vector<int> &path, const vector<vector<int>> &gp)
{
    int res = 0;
    int cur = 0;
    for (int i = 0; i < path.size(); ++i)
    {
        res+=gp[cur][path[i]];
        cur = path[i];
    }
    return res;
}

bool in(const vector<int> &path, const int & i)
{
    for (int j = 0; j < path.size() ; ++j)
    {
        if (path[j] == i)
            return true;
    }
    return false;
}

vector<int> true_path;
int true_weight = INT_MAX;
int findPathBruteForce(vector<int> &path, vector<vector<int>> &gp,long long int iterations = 0, int weight = 0)
{
    if (!iterations)
        path.push_back(0);
    if (path.size() == gp.size())
    {
        if (true_weight > weight)
        {
            true_weight = weight;
            true_path = path;
        }
        return iterations;
    }
    for (int i = 0; i < gp.size(); ++i)
    {
        if (in(path,i))
            continue;
        iterations++;
//        if (weight+gp[i][path[path.size()-2]] < 0)
//        {
//            cout << gp[i][path[path.size()-2]] <<endl;
//            cout << i << endl;
//            cout << path[path.size()-2] << endl;
//            cout << weight << endl;
//            throw;
//        }
        path.push_back(i);
        iterations = findPathBruteForce(path,gp,iterations,weight+gp[i][path[path.size()-2]]);
        path.pop_back();
path
    }
    if (path.size() == 1)
        path = true_path;
    return iterations;
}

int greedy(vector<int> & path,  vector<vector<int>> &gp)
{
    int iterations = 0;
    for (int i = 0; i < gp.size(); ++i)
    {
        int min = INT_MAX;
        int nearest = 10;
        for (int j = 0; j < gp.size(); ++j)
        {
            if (in(path,j))
                continue;
            iterations++;
            if (gp[path[path.size()-1]][j] < min)
            {
                min = gp[path[path.size()-1]][j];
                nearest = j;
            }
        }
        path.push_back(nearest);
    }
    return iterations;
}

int branchAndboundary(vector<int> &path, vector<vector<int>> &gp,long long int iterations = 0, int weight = 0)
{
    if (weight > true_weight)
        return iterations;
    if (!iterations)
        path.push_back(0);
    if (path.size() == gp.size())
    {
        if (true_weight > weight)
        {
            true_weight = weight;
            true_path = path;
        }
        return iterations;
    }
    for (int i = 0; i < gp.size(); ++i)
    {
        if (in(path,i))
            continue;
        iterations++;
        path.push_back(i);
        iterations = findPathBruteForce(path,gp,iterations,weight+gp[i][path[path.size()-1]]);
        path.pop_back();

    }
    if (path.size() == 1)
        path = true_path;
    return iterations;
}

vector<int> revesePath(vector<int> path, int i, int j)
{
    for (int k = i; k <=j/2 ; k++)
    {
        int tmp = path[k];
        path[k] = path[j-k + i];
        path[j-k + i] = tmp;
    }
        return path;
}

int LocalSearch2(vector<int> &path, vector<vector<int>> &gp, int weight)
{
    int iterations = 0;
    for (int i = 1; i < gp.size()-2; ++i)
    {
        for (int j  = i+1; j < gp.size(); ++j)
        {
            iterations++;
            vector<int> reverpath = revesePath(path, i, j);
            int pathWEigh = getPathWeight(reverpath,gp);
            if (pathWEigh < weight)
            {
                weight = pathWEigh;
                path = reverpath;
                i = 1;
                j = 2;
            }
        }
    }
    return iterations;
}

int main(int argc, char *argv[])
{

    system("echo   > out.txt");
    vector<vector<int>> gp(10,vector<int>(10));
    vector<int> path;
    string write_to_file;
    long long int iter = 0, path_weight;
    init_gp(gp);


    iter = findPathBruteForce(path, gp);
    path_weight = getPathWeight(path, gp);
    write_to_file = "echo BryteForce weight = " + to_string(path_weight) + " iterations = " + to_string(iter) + " >> out.txt";
    system(write_to_file.data());
    path.erase(path.begin(), path.end());

    true_weight = INT_MAX;
    true_path.erase(true_path.begin(), true_path.end());
    iter = branchAndboundary(path, gp);
    path_weight = getPathWeight(path, gp);
    write_to_file = "echo branch and boundary method weight = " + to_string(path_weight) + " iterations = " + to_string(iter) + " >> out.txt";
    system(write_to_file.data());
    path.erase(path.begin(), path.end());

    iter = greedy(path, gp);
    path_weight = getPathWeight(path, gp);
    write_to_file  = "echo Greedy algh weight = " + to_string(path_weight) + " iterations = " + to_string(iter) + " >> out.txt";
    system(write_to_file.data());
    path.erase(path.begin(), path.end());

//    iter = findPathBruteForce(path, gp);
//    path_weight = getPathWeight(path, gp);
//    write_to_file = "echo Local Search 2 algh weight = " + to_string(path_weight) + " iterations = " + to_string(iter) + " >> out.txt";
//    system(write_to_file.data());
//    path.erase(path.begin(), path.end());

//    iter = findPathBruteForce(path, gp);
//    path_weight = getPathWeight(path, gp);
//    write_to_file = "echo Local Search 3 algh weight = " + to_string(path_weight) + " iterations = " + to_string(iter) + " >> out.txt";
//    system(write_to_file.data());
//    path.erase(path.begin(), path.end());
}
