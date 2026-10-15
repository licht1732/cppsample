#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        int next[26];
        int cnt;   // このprefixを通る文字列数
        int end;   // この文字列で終わる数
        Node(){
            memset(next,-1,sizeof(next));
            cnt = 0;
            end = 0;
        }
    };

    vector<Node> t;

    Trie(){
        t.emplace_back(); // root
    }

    void insert(const string &s){
        int cur = 0;
        for(char c : s){
            int x = c-'a';
            if(t[cur].next[x]==-1){
                t[cur].next[x]=t.size();
                t.emplace_back();
            }
            cur = t[cur].next[x];
            t[cur].cnt++;
        }
        t[cur].end++;
    }

    //各文字列の最大LCP
    int max_lcp_with_others(const string &s){
        int cur=0, depth=0, ans=0;

        for(char c:s){
            int x=c-'a';
            cur=t[cur].next[x];
            depth++;

            if(t[cur].cnt>=2)
                ans=depth;
        }
        return ans;
    }

    //prefixを持つ文字列数
    int count_prefix(const string &p){
        int cur=0;
        for(char c:p){
            int x=c-'a';
            if(t[cur].next[x]==-1) return 0;
            cur=t[cur].next[x];
        }
        return t[cur].cnt;
    }

    //同一文字列の個数
    int count_exact(const string &s){
        int cur=0;
        for(char c:s){
            int x=c-'a';
            if(t[cur].next[x]==-1) return 0;
            cur=t[cur].next[x];
        }
        return t[cur].end;
    }

    //LCP合計
    long long lcp_sum(){
        long long ans=0;
        for(auto &node : t){
            long long c=node.cnt;
            ans += c*(c-1)/2;
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<string> S(n);
    for(int i=0;i<n;i++) cin >> S[i];
    Trie trie;
    for(string s:S) trie.insert(s);

    //各文字列の最大LCP
    for(string s:S){
        cout<<trie.max_lcp_with_others(s)<<"\n";
    }

    //prefixを持つ文字列数
    for(string s:S){
        cout<<trie.count_prefix(s)<<"\n";
    }

    //同一文字列の個数
    for(string s:S){
        cout<<trie.count_exact(s)<<"\n";
    }

    //LCP合計
    cout << trie.lcp_sum() << "\n";
}

