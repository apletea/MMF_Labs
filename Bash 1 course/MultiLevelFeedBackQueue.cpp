
#include <bits/stdc++.h>

namespace manager
{

struct process
{

private:
    static bool exist;
    static int * counts;

public:

    int id;
    int time;
    int priority;

    process()
    {
        if (!exist)
        {
            exist =true;
            *count = 0;
        }
        *count += 1;
        id = *count;
        time = std::rand()%250;
        priority = std::rand()%100;
    }
};

class comprassion
{
public:
    bool operator() (const process & p1, const process & p2) const
    {
        return p1.priority > p2.priority;
    }
};

class mlq
{

private:

#define sqrt3 1.7320580757

    int def_quantum;
    std::vector<std::priority_queue<process, std::vector<process>, comprassion>> QS;

    void add_process_Nth(int n,process & prc)
    {
        QS[n-1].push(prc);
    }

public:
    mlq(int _def_quantum, uint QS_count)
    {
        this->def_quantum = _def_quantum;
        QS.resize(QS_count);
    }

    void add_process(process & prc)
    {
        add_process_Nth(1,prc);
    }

    bool procces_Nth(const int n, double lefted_time)
    {
        process proc = QS[n-1].top();
        QS[n-1].pop();
        lefted_time -= def_quantum;
        proc.time -= def_quantum;
        if (lefted_time < 0 && proc.time > 0)
        {
            add_process_Nth(n+1,proc);
            return true;
        }
        else if (proc.time < 0)
            return true;
        else
            add_process_Nth(n,proc);
        return false;

    }

    void run_mng()
    {
        int level = 0;
        std::map<int,double> manger_lefted_time;
        for (int i = 1; i < QS.size(); ++i)
        {
            manger_lefted_time[i] = pow(sqrt3*def_quantum,i);
        }
        while(true)
        {
            level%=QS.size();
            manger_lefted_time[level+1] -= def_quantum;
            if (procces_Nth(level+1,manger_lefted_time[level+1]))
            {
                manger_lefted_time[level+1] = pow(sqrt3*def_quantum, level+1);
            }
            level++;
        }
        return;
    }

};

}
