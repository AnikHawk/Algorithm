#include<bits/stdc++.h>
using namespace std;

struct key{
    int freq;
    char c;
    key(int f, int ch){
        freq = f; c = ch;
    }

    bool operator <(const key& x) const{
        return (freq<x.freq);
    }

};


void arrangeString(string str){
    int cnt[26] ={0};
    for(int i =0;i<str.length();i++){
        cnt[str[i]-'a']++;
    }
    priority_queue<key> pq;
    string result = "";

    for(char c = 'a';c<='z';c++){
        if(cnt[c - 'a']>0) pq.push({cnt[c-'a'], c});
    }

    key prev = key{-1,'#'};
    while(!pq.empty()){
        key tmp = pq.top(); pq.pop();
        result+=tmp.c;
        (tmp.freq)--;
        if(prev.freq>0){
            pq.push(prev);
        }
        prev = tmp;
    }

    cout<<result<<endl;

}


int main(){
    string str = "zbbbaaz";
     arrangeString(str);

    return 0;
}
