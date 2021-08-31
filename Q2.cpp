#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int op=1;
    while(op<=t)
    {
        int n,i,j,k=0;
        cin>>n;
        char arr[n][n];
        int nox, noo, nod;
        int min_req=n+1;
        int possible_sol=0;
        std::vector<pair <int,int>> rem;
        for(i=0; i<n; i++)
        {
            nox=0;
            nod=0;
            noo=0;
            for(j=0; j<n; j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]=='O') noo++;
                else if(arr[i][j]=='X') nox++;
                else nod++;
            }
            if(nod>0 && noo==0)
            {
                if(min_req==nod)
                {
                    possible_sol++;
                    if(nod==1)
                    {
                        for(j=0;j<n;j++)
                        {
                            if(arr[i][j]=='.'){
                                rem.push_back(make_pair(i,j));
                                break;
                            }
                        }
                    }
                }
                else if(min_req>nod){
                    min_req=nod;
                    possible_sol=1;
                    if(nod==1)
                    {
                        for(j=0;j<n;j++)
                        {
                            if(arr[i][j]=='.'){
                                rem.push_back(make_pair(i,j));
                                break;
                            }
                        }
                    }
                }
                
            }
        }
        for(i=0; i<n; i++)
        {
            nox=0;
            nod=0;
            noo=0;
            for(j=0; j<n; j++)
            {
                if(arr[j][i]=='O') noo++;
                else if(arr[j][i]=='X') nox++;
                else nod++;
            }
            if(nod>0 && noo==0)
            {
                if(min_req==nod)
                {
                    possible_sol++;
                    if(nod==1)
                    {
                        for(j=0;j<n;j++)
                        {
                            if(arr[j][i]=='.'){
                                rem.push_back(make_pair(j,i));
                                break;
                            }
                        }
                    }
                }
                else if(min_req>nod){
                    min_req=nod;
                    possible_sol=1;
                    if(nod==1)
                    {
                        for(j=0;j<n;j++)
                        {
                            if(arr[j][i]=='.'){
                                rem.push_back(make_pair(j,i));
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(min_req==n+1)
        {
            cout<<"Case #"<<op<<": Impossible"<<endl;
            op++;
        }
        else{
                int len=rem.size();
                if(len>=2)
                {
                    for(i=0; i<len; i++)
                    {
                        for(j=0; j<len; j++)
                        {
                            if(i!=j){
                                if((rem[i].first == rem[j].first) && (rem[i].second == rem[j].second))
                                k++;
                            }
                        }
                    }
                }
                possible_sol-=(k/2);
            cout<<"Case #"<<op<<": "<<min_req<<" "<<possible_sol<<endl;
            op++;
        }
    }
    return 0;
}
