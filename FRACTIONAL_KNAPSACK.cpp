


    static bool cmp(const  pair<double,pair<int,int>>&a,const pair<double,pair<int,int>>&b){
    return a.first > b.first;
    }


double function1 (vector<pair<int, int>>& items, int n, int target)   //TC-O(NLON)     SC-O(N)
{
    vector<pair<double,pair<int,int>>>v;
    for(int i=0;i<n;i++){
        double val=(items[i].second * 1.0)/(items[i].first *1.0);
        pair<int,int> p1={items[i].first,items[i].second};
        pair<double,pair<int,int>> p2={val,p1};
        v.push_back(p2);
    }

    sort(v.begin(),v.end(),cmp);
    double maxi=0;
    int i=0;
    while(target){
        pair<double,pair<int,int>> p3=v[i];
        pair<int,int> p4=p3.second;
        double o=p3.first;
        int w=p4.first;
        int prof=p4.second;
        if(w<=target){
            maxi+=prof;
            target-=w;
        }
        else if(target<w){
           maxi+=(o*target*1.0);
           target=0;
        }
        i++;
    }
    return maxi;
}
    

bool cmp2 (pair<int, int> &a, pair<int, int> &b) {
    return (1.0*a.second/a.first*1.0) > (1.0*b.second/b.first*1.0);
}

double function2 (vector<pair<int, int>>& items, int n, int w)    //TC-O(NLOGN)       SC-O(1)
{
    sort(items.begin(), items.end(), &cmp2);
    double ans = 0;
    int i=0;
    while (w && i < items.size()) {
        int temp = min(w, items[i].first);
        ans += (double)items[i].second * temp / items[i].first;
        i += 1;
        w -= temp;
    }
    
    return ans;
}
        



