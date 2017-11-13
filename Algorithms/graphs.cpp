#include <bits/stdc++.h>


namespace gf_graph
{
class graph
{
public:
    
    std::list<graph*> neignbohrs;
    int val;
    
    static graph* create_undirected()
    {
        return nullptr;
    }
    
    static std::vector<std::vector> create_directed(int n)
    {
        return nullptr;
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
        while(!st.empty())
        {
            
            graph* v = st.top();
            for (auto neighbor : v->neignbohrs)
            {
                neighbor->neignbohrs.remove(v);
                v->neignbohrs.remove(neighbor);
                st.push(neighbor);
            }
            ans.push_back(v);
            st.pop();
        }
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
    
    static int dejkstra(std::vector < std::vector < std::pair<int,int> > > g)
    {
        std::vector<int> d (n, INT32_MAX), p(n);
        graph* s = 
        d[this->val] = 0;
        std::vector<char> u (n);
    }
    
    static std::vector<int> find_path()
    {
        
    }
private:
    static int is_valid_euler(graph* edge ,std::set<graph*> & is_visitetd)
    {
       int ans = 0;
       if (is_visitetd.find(edge)==is_visitetd.end())
            return 0;
       for(auto  neignhbor : edge->neignbohrs)
       {
           is_visitetd.insert(edge);
           ans +=is_valid_euler(neignhbor, is_visitetd);
       }
       return ans+edge->neignbohrs.size()%2;
    }
    
   
};


}


int main(int argc, char ** argv)
{
    
}
