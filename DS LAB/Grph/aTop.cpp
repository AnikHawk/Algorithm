void topological(int n)
{
    for(int i = 1; i<=n; i++)
    {
        if(dcolor[i]==0) dfsC(i,n);

    }

    reverse(topsort.begin(), topsort.end());
    for(int i=0; i<topsort.size(); i++)
    {
        cout<<topsort[i]<<" ";
    }

}
