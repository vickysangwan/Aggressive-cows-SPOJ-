#include<bits/stdc++.h>
using namespace std;
bool placeCows(vector<int> &stalls,int N,int C,int mid)
{
    int count=1;
    int last_cow=stalls[0];
    for(int i=1;i<N;i++)
    {
        if(stalls[i]-last_cow>=mid)
        {
            last_cow=stalls[i];
            count++;
            if(count==C)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int N,C;
        cin>>N>>C;
        vector<int> stalls(N);
        for(int i=0;i<N;i++)
        {
            cin>>stalls[i];
        }
        sort(stalls.begin(),stalls.end());
        int s=0;
        int e=stalls[N-1]-stalls[0];
        int ans=0;
        while(s<=e)
        {
            int mid=(s+e)/2;
            bool ispossible=placeCows(stalls,N,C,mid);
            if(ispossible)
            {
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
