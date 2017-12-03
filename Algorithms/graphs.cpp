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
        mp[2]->neignbohrs.push_back(mp[6]);
        mp[6]->neignbohrs.push_back(mp[2]);

        mp[4]->neignbohrs.push_back(mp[6]);
        mp[6]->neignbohrs.push_back(mp[4]);

        mp[2]->neignbohrs.push_back(mp[4]);
        mp[4]->neignbohrs.push_back(mp[2]);
        return mp[1];
        
    }

    static graph* create_for_p_k(std::map<std::pair<graph*,graph*>,int> & weights)
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
        mp[3]->neignbohrs.push_back(mp[4]);
        mp[4]->neignbohrs.push_back(mp[3]);
        mp[4]->neignbohrs.push_back(mp[5]);
        mp[5]->neignbohrs.push_back(mp[4]);
        mp[5]->neignbohrs.push_back(mp[1]);
        mp[1]->neignbohrs.push_back(mp[5]);


        mp[1]->neignbohrs.push_back(mp[6]);
        mp[2]->neignbohrs.push_back(mp[6]);
        mp[3]->neignbohrs.push_back(mp[6]);
        mp[4]->neignbohrs.push_back(mp[6]);
        mp[5]->neignbohrs.push_back(mp[6]);
        mp[6]->neignbohrs.push_back(mp[1]);
        mp[6]->neignbohrs.push_back(mp[2]);
        mp[6]->neignbohrs.push_back(mp[3]);
        mp[6]->neignbohrs.push_back(mp[4]);
        mp[6]->neignbohrs.push_back(mp[5]);

        weights[std::pair<graph*, graph*>{mp[1],mp[2]}] = 5;
        weights[std::pair<graph*, graph*>{mp[2],mp[1]}] = 5;
        weights[std::pair<graph*, graph*>{mp[2],mp[3]}] = 4;
        weights[std::pair<graph*, graph*>{mp[3],mp[2]}] = 4;
        weights[std::pair<graph*, graph*>{mp[3],mp[4]}] = 3;
        weights[std::pair<graph*, graph*>{mp[4],mp[3]}] = 3;
        weights[std::pair<graph*, graph*>{mp[4],mp[5]}] = 2;
        weights[std::pair<graph*, graph*>{mp[5],mp[4]}] = 2;
        weights[std::pair<graph*, graph*>{mp[5],mp[1]}] = 6;
        weights[std::pair<graph*, graph*>{mp[1],mp[5]}] = 6;

        weights[std::pair<graph*, graph*>{mp[1],mp[6]}] = 1;
        weights[std::pair<graph*, graph*>{mp[2],mp[6]}] = 2;
        weights[std::pair<graph*, graph*>{mp[3],mp[6]}] = 3;
        weights[std::pair<graph*, graph*>{mp[4],mp[6]}] = 4;
        weights[std::pair<graph*, graph*>{mp[5],mp[6]}] = 5;
        weights[std::pair<graph*, graph*>{mp[6],mp[1]}] = 1;
        weights[std::pair<graph*, graph*>{mp[6],mp[2]}] = 2;
        weights[std::pair<graph*, graph*>{mp[6],mp[3]}] = 3;
        weights[std::pair<graph*, graph*>{mp[6],mp[4]}] = 4;
        weights[std::pair<graph*, graph*>{mp[6],mp[5]}] = 5;


        return mp[1];
    }
    
    static graph* create_bound(int n)
    {
        std::map<int,graph*> mp;
        for (int i = 1; i <=  n; ++i)
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

        return mp[6];
    }
    
    static std::map<std::pair<int,int>,short int> get_maze()
    {
        
    }
    

    static std::vector<std::pair<int,int>> prim_alg(std::map<std::pair<graph*, graph*>,int> & weights)
    {
        std::vector<std::pair<int,int>> ans = kraskal_alg(weights);
        std::set<graph*> is_visited;
        std::map<graph*, int> res;
        std::stack<graph*> st;
        graph* v = pick_start(weights);
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
        return ans;
    }


    //system of non overcrosing sets
    static std::vector<std::pair<int,int>> kraskal_alg(std::map<std::pair<graph*, graph*>,int> & weights)
    {
        std::vector<std::pair<graph*,graph*>> sorted_pairs = sort_pair(weights);
        std::vector<std::pair<int,int>> ans = {};
        std::map<graph*,int> mp;
        int i = 0;
        for (auto pair : sorted_pairs)
        {
            if (mp.find(pair.first)!=mp.end() && mp[pair.first] == mp[pair.second])
                continue;
            else
            {

                ans.push_back({pair.first->val,pair.second->val});
                if (mp.find(pair.first) == mp.end() && mp.find(pair.second) == mp.end())
                {
                    mp[pair.first] = i;
                    mp[pair.second] = i;
                    i++;
                    continue;
                }
                if (mp.find(pair.first) != mp.end() && mp.find(pair.second) != mp.end())
                    union_set(mp,mp[pair.first],mp[pair.second]);
                else if (mp.find(pair.first) == mp.end())
                    mp[pair.first] = mp[pair.second];
                else
                    mp[pair.second] = mp[pair.first];

            }
        }

        return ans;

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
            if (edges.find(v)!=edges.end())
                continue;
            for(auto neighbor : v->neignbohrs)
            {
                st.push(neighbor);
            }
            edges.insert(v);
            
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

    static void sort_arr(std::vector<std::pair<graph*, graph*>>&ans,std::map<std::pair<graph*, graph*>,int> &  wieghts, int l = 0,int r = 15)
    {
        int pivot  = wieghts[ans[(l+r)/2]];
        int i = l;
        int j = r;
        while (i <= j)
        {
            while(wieghts[ans[i]] < pivot) i++;
            while(wieghts[ans[j]] > pivot) j--;
            if (i <= j)
            {
                auto tmp = ans[i];
                ans[i] = ans[j];
                ans[j] = tmp;
                i++;
                j--;
            }
        }
        if (i < r)
            sort_arr(ans,wieghts,i,r);
        if (j > l)
            sort_arr(ans,wieghts,l,j);
    }

    static std::vector<std::pair<graph*,graph*>>  sort_pair(std::map<std::pair<graph*, graph*>,int> & weights)
    {
        std::vector<std::pair<graph*,graph*>> ans = {};
        std::set<std::pair<graph*,graph*>> st;
        for (auto pair : weights)
        {
            if (st.find({pair.first.first,pair.first.second})!=st.end() || st.find({pair.first.second,pair.first.first})!=st.end())
                continue;
            ans.push_back(pair.first);
            st.insert(pair.first);
        }
        sort_arr(ans,weights,0,ans.size()-1);
        return ans;
    }

    static void union_set(std::map<graph*,int> & mp,int a, int b)
    {
        for (auto pair: mp)
        {
            if (mp[pair.first] == b)
                mp[pair.first] = a;
        }
    }

    static graph* pick_start(std::map<std::pair<graph*, graph*>,int> & weights)
    {
        for (auto pair : weights)
        {
            return pair.first.first;
        }
    }
    
    
};


}


int main(int argc, char ** argv)
{
    //euler
    //    gf_graph::graph* root=gf_graph::graph::create_for_euler();
    //    std::vector<gf_graph::graph*> res =root->find_euler_path();
    //    if (!res.size())
    //        std::cout << "There are not ueler path" << std::endl;

    //    for (auto v : res)
    //    {
    //        std::cout << v->val << " ";
    //    }
    //    std::cout << std::endl;
    //    //    not euler
    //    gf_graph::graph* roots=gf_graph::graph::create_for_not_euler();
    //    std::vector<gf_graph::graph*> ress =roots->find_euler_path();
    //    if (!ress.size())
    //        std::cout << "There are not ueler path" << std::endl;
    //    //    std::cout << 1 << " ";
    //    for (auto v : ress)
    //    {

    //        std::cout << v->val << " ";
    //    }
    //    //   dijcstra
    //    std::map<std::pair<gf_graph::graph*,gf_graph::graph*>,int>  weights;
    //    gf_graph::graph * root=gf_graph::graph::create_for_dijctra(weights);
    //    auto res = root->dejkstra(weights);
    //    for (auto v : res)
    //    {
    //        std::cout << "ver=" << v.first->val << " res=" << v.second << std::endl;
    //    }
    //    bounded
    //    int n = 6;
    //    gf_graph::graph * root = gf_graph::graph::create_bound(n);
    //    if (gf_graph::graph::is_bound_graph(n,root))
    //        std::cout << "This graph bounded" << std::endl;
    //    else
    //        std::cout << "This graph unbounded" << std::endl;
    //kraskal
    //        std::map<std::pair<gf_graph::graph*,gf_graph::graph*>,int>  weights;
    //        gf_graph::graph * root = gf_graph::graph::create_for_p_k(weights);
    //        auto res = gf_graph::graph::kraskal_alg(weights);
    //        for (auto tmp : res)
    //            std::cout << tmp.first << "  " << tmp.second << std::endl;
    //prima
    std::map<std::pair<gf_graph::graph*,gf_graph::graph*>,int>  weights;
    gf_graph::graph * root = gf_graph::graph::create_for_p_k(weights);
    auto res = gf_graph::graph::prim_alg(weights);
    for (auto tmp : res)
        std::cout << tmp.first << "  " << tmp.second << std::endl;


}


