//███████▓█████▓▓╬╬╬╬╬╬╬╬▓███▓╬╬╬╬╬╬╬▓╬╬▓█
//████▓▓▓▓╬╬▓█████╬╬╬╬╬╬███▓╬╬╬╬╬╬╬╬╬╬╬╬╬█
//███▓▓▓▓╬╬╬╬╬╬▓██╬╬╬╬╬╬▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
//████▓▓▓╬╬╬╬╬╬╬▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
//███▓█▓███████▓▓███▓╬╬╬╬╬╬▓███████▓╬╬╬╬▓█
//████████████████▓█▓╬╬╬╬╬▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬█
//███▓▓▓▓▓▓▓╬╬▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
//████▓▓▓╬╬╬╬▓▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
//███▓█▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
//█████▓▓▓▓▓▓▓▓█▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
//█████▓▓▓▓▓▓▓██▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██
//█████▓▓▓▓▓████▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██
//████▓█▓▓▓▓██▓▓▓▓██╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██
//████▓▓███▓▓▓▓▓▓▓██▓╬╬╬╬╬╬╬╬╬╬╬╬█▓╬▓╬╬▓██
//█████▓███▓▓▓▓▓▓▓▓████▓▓╬╬╬╬╬╬╬█▓╬╬╬╬╬▓██
//█████▓▓█▓███▓▓▓████╬▓█▓▓╬╬╬▓▓█▓╬╬╬╬╬╬███
//██████▓██▓███████▓╬╬╬▓▓╬▓▓██▓╬╬╬╬╬╬╬▓███
//███████▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬████
//███████▓▓██▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓████
//████████▓▓▓█████▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█████
//█████████▓▓▓█▓▓▓▓▓███▓╬╬╬╬╬╬╬╬╬╬╬▓██████
//██████████▓▓▓█▓▓▓╬▓██╬╬╬╬╬╬╬╬╬╬╬▓███████
//███████████▓▓█▓▓▓▓███▓╬╬╬╬╬╬╬╬╬▓████████
//██████████████▓▓▓███▓▓╬╬╬╬╬╬╬╬██████████
//███████████████▓▓▓██▓▓╬╬╬╬╬╬▓███████████
#include <bits/stdc++.h>


namespace gf_graph
{
class graph
{
public:
    
    std::list<graph*> neignbohrs;
    int val;
    
    graph(int val)
    {
        this->val = val;
    }
    
    static graph* create_for_euler()
    {
        std::map<int,graph*> mp;
        for (int i = 1; i <=  6; ++i)
        {
            graph* tmp = new graph(i);
            mp[i] = tmp;
        }
        
        mp[1]->neignbohrs.push_back(mp[2]);
        mp[2]->neignbohrs.push_back(mp[1]);
        mp[2]->neignbohrs.push_back(mp[3]);
        mp[3]->neignbohrs.push_back(mp[2]);
        mp[4]->neignbohrs.push_back(mp[3]);
        mp[3]->neignbohrs.push_back(mp[4]);
        mp[4]->neignbohrs.push_back(mp[5]);
        mp[5]->neignbohrs.push_back(mp[4]);
        mp[5]->neignbohrs.push_back(mp[6]);
        mp[6]->neignbohrs.push_back(mp[5]);
        mp[6]->neignbohrs.push_back(mp[1]);
        mp[1]->neignbohrs.push_back(mp[6]);
        
        return mp[1];
        
    }
    
    static graph* create_for_not_euler()
    {
        std::map<int,graph*> mp;
        for (int i = 1; i <=  6; ++i)
        {
            graph* tmp = new graph(i);
            mp[i] = tmp;
        }
        
        mp[1]->neignbohrs.push_back(mp[2]);
        mp[2]->neignbohrs.push_back(mp[1]);
        mp[2]->neignbohrs.push_back(mp[3]);
        mp[3]->neignbohrs.push_back(mp[2]);
        mp[4]->neignbohrs.push_back(mp[3]);
        mp[3]->neignbohrs.push_back(mp[4]);
        mp[4]->neignbohrs.push_back(mp[5]);
        mp[5]->neignbohrs.push_back(mp[4]);
        mp[5]->neignbohrs.push_back(mp[6]);
        mp[6]->neignbohrs.push_back(mp[5]);
        mp[6]->neignbohrs.push_back(mp[1]);
        mp[1]->neignbohrs.push_back(mp[6]);
        
        
        
        mp[1]->neignbohrs.push_back(mp[3]);
        mp[3]->neignbohrs.push_back(mp[1]);
        mp[3]->neignbohrs.push_back(mp[5]);
        mp[5]->neignbohrs.push_back(mp[3]);
        mp[5]->neignbohrs.push_back(mp[1]);
        mp[1]->neignbohrs.push_back(mp[5]);
        return mp[1];
        
    }
    
    static graph* create_bound(int n)
    {
        std::map<int,graph*> mp;
        for (int i = 1; i <=  6; ++i)
        {
            graph* tmp = new graph(i);
            mp[i] = tmp;
        }
        return mp[1];
    }
    
    static graph* create_unbound(int n)
    {
        std::map<int,graph*> mp;
        for (int i = 1; i <=  6; ++i)
        {
            graph* tmp = new graph(i);
            mp[i] = tmp;
        }
        return mp[1];
    }
    
    static graph* create_for_dijctra(std::map<std::pair<graph*,graph*>,int> & weights)
    {
        std::map<int,graph*> mp;
        for (int i = 1; i <=  6; ++i)
        {
            graph* tmp = new graph(i);
            mp[i] = tmp;
        }
        
        mp[1]->neignbohrs.push_back(mp[2]);
        mp[2]->neignbohrs.push_back(mp[3]);
        mp[3]->neignbohrs.push_back(mp[4]);
        mp[1]->neignbohrs.push_back(mp[6]);
        mp[6]->neignbohrs.push_back(mp[5]);
        mp[5]->neignbohrs.push_back(mp[4]);
        mp[6]->neignbohrs.push_back(mp[2]);
        mp[5]->neignbohrs.push_back(mp[2]);
        
        weights[std::pair<graph*, graph*>{mp[1],mp[2]}] = 2;
        weights[std::pair<graph*, graph*>{mp[2],mp[3]}] = 6;
        weights[std::pair<graph*, graph*>{mp[3],mp[4]}] = 2;
        weights[std::pair<graph*, graph*>{mp[1],mp[6]}] = 3;
        weights[std::pair<graph*, graph*>{mp[5],mp[4]}] = 1;
        weights[std::pair<graph*, graph*>{mp[6],mp[5]}] = 5;
        weights[std::pair<graph*, graph*>{mp[6],mp[2]}] = 2;
        weights[std::pair<graph*, graph*>{mp[5],mp[2]}] = 1;
        
        return mp[1];
    }
    
    static std::map<std::pair<int,int>,short int> get_maze()
    {
        
    }
    
    std::vector<graph*> find_euler_path()
    {
        std::set<graph*> is_visited;
        if(this->is_valid_euler(this,is_visited)>2)
            return {};
        std::stack<graph*> st;
        std::vector<graph*> ans;
        st.push(this);
        std::set<std::pair<graph*,graph*>> set;
        //        while(!st.empty())
        //        {
        
        //            graph* v = st.top();
        //            st.pop();
        //            for (auto neighbor: v->neignbohrs)
        //            {
        //                if (set.find(std::pair<graph*,graph*>{neighbor,v})!=set.end())
        //                    continue;
        //                set.insert(std::pair<graph*,graph*>{neighbor,v});
        //                set.insert(std::pair<graph*,graph*>{v,neighbor});
        //                st.push(neighbor);
        //            }
        //            if (st.size())
        //                ans.push_back(st.top());
        //            //            ans.push_back(v);
        //        }
        //        ans[ans.size()-1] = this;
        find_euler(this,set,ans);
        return ans;
        
    }
    
    static bool is_bound_graph(int graph_size,graph* root)
    {
        std::stack<graph*> st;
        std::set<graph*> edges;
        st.push(root);
        while(!st.empty())
        {
            graph* v = st.top();
            st.pop();
            edges.insert(v);
            if (edges.find(v)!=edges.end())
                continue;
            for(auto neighbor : v->neignbohrs)
            {
                st.push(neighbor);
            }
            
        }
        return edges.size() == graph_size;
    }
    
    
    std::map<graph*, int> dejkstra(std::map<std::pair<graph*,graph*>,int> weights)
    {
        std::set<graph*> is_visited;
        std::map<graph*, int> res;
        std::stack<graph*> st;
        graph* v = this;
        res[v] = 0;
        st.push(v);
        while(!st.empty())
        {
            v = st.top();
            st.pop();
            if (is_visited.find(v)!=is_visited.end())
                continue;
            for (auto neighbor : v->neignbohrs)
            {
                if (res.find(neighbor)==res.end())
                    res[neighbor] = weights[std::pair<graph*,graph*>{v,neighbor}]+res[v];
                else
                    res[neighbor] = std::min(res[neighbor],weights[std::pair<graph*,graph*>{v,neighbor}]+res[v]);
                st.push(neighbor);
            }
            is_visited.insert(v);
            
        }
        return res;
    }
    
    static std::vector<int> find_path()
    {
        
    }
private:
    static int is_valid_euler(graph* edge ,std::set<graph*> & is_visitetd)
    {
        int ans = 0;
        if (is_visitetd.find(edge)!=is_visitetd.end())
            return 0;
        for(auto  neignhbor : edge->neignbohrs)
        {
            is_visitetd.insert(edge);
            ans +=is_valid_euler(neignhbor, is_visitetd);
        }
        return ans+edge->neignbohrs.size()%2;
    }
    
    void find_euler(graph* node,std::set<std::pair<graph*,graph*>> & set, std::vector<graph*> & res)
    {
        for (auto vertex : node->neignbohrs)
        {
            if (set.find(std::pair<graph*,graph*>{vertex,node})!=set.end())
                continue;
            set.insert(std::pair<graph*,graph*>{vertex,node});
            set.insert(std::pair<graph*,graph*>{node,vertex});
            find_euler(vertex,set,res);
        }
        res.push_back(node);
    }
    
    
};


}


int main(int argc, char ** argv)
{
    //    //euler
    //    gf_graph::graph* root=gf_graph::graph::create_for_euler();
    //    std::vector<gf_graph::graph*> res =root->find_euler_path();
    //    if (!res.size())
    //        std::cout << "There are not ueler path" << std::endl;
    //    for (auto v : res)
    //    {
    //        std::cout << v->val << " ";
    //    }
    //    std::cout << std::endl;
    //    //not euler
    //    gf_graph::graph* roots=gf_graph::graph::create_for_not_euler();
    //    std::vector<gf_graph::graph*> ress =roots->find_euler_path();
    //    if (!ress.size())
    //        std::cout << "There are not ueler path" << std::endl;
    //    //    std::cout << 1 << " ";
    //    for (auto v : ress)
    //    {
    
    //        std::cout << v->val << " ";
    //    }
    //dijcstra
    //    std::map<std::pair<gf_graph::graph*,gf_graph::graph*>,int>  weights;
    //    gf_graph::graph * root=gf_graph::graph::create_for_dijctra(weights);
    //    auto res = root->dejkstra(weights);
    //    for (auto v : res)
    //    {
    //        std::cout << "ver=" << v.first->val << " res=" << v.second << std::endl;
    //    }
    
}
