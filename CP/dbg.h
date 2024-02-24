#include <bits/stdc++.h>

#define dbg(...) __f(#__VA_ARGS__,__VA_ARGS__) 
// trace std::pair
template<class L,class R> std::ostream& operator<<(std::ostream& os,std::pair<L,R>& P){
    return os<<"{"<<P.first<<":"<<P.second<<"}";
}
// trace std::vector
template<class T> std::ostream& operator<<(std::ostream& os,std::vector<T>& V){
    os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";
}
// trace std::map;
template<class L,class R> std::ostream& operator<<(std::ostream& os,std::map<L,R>& MP) {
    os<<"[ ";for(auto& P : MP) os<<P<<" ";return os<<"]";
}
// trace unordred_std::map
template<class L,class R> std::ostream& operator<<(std::ostream& os,std::unordered_map<L,R>& MP) {
    os<<"[ ";for(auto& P : MP) os<<P<<" ";return os<<"]";
}
// trace std::set
template<class T> std::ostream& operator<<(std::ostream& os,std::set<T>& S){
    os<<"[ ";for(auto s:S)os<<s<<" ";return os<<"]";
}
// trace std::unordered_set
template<class T> std::ostream& operator<<(std::ostream& os,std::unordered_set<T>& S){
    os<<"[ ";for(auto s:S)os<<s<<" ";return os<<"]";
}
// std::stack FUN
template<class T> void F_Stack(std::stack<T> st, std::string& cont) { 
    if(st.empty()) return;
    T mem=st.top();st.pop();F_Stack(st,cont);cont+=" "+to_string(mem);  
}
// trace std::stack                                                  
template<class T> std::ostream& operator<<(std::ostream& os,std::stack<T> st) {
    os<<"[";std::string cont="";F_Stack(st,cont);return os<<cont<<" ]";
}
// track std::queue
template<class T> std::ostream& operator<<(std::ostream& os,std::queue<T> q) {
    os<<"[ ";while(!q.empty()) os<<q.front()<<" ",q.pop();return os<<"]";
}

// for last arg.
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){
    std::cerr<<name<<" : "<<arg1<<std::endl;
}
// for variable arg
template <typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){
    const char* comma=strchr(names+1,',');std::cerr.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);
}

// dbg std::std::array
template<class T, size_t S> std::ostream& operator<<(std::ostream& os,std::array<T, S> V){
    os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";
}

// debug 1D std::array
#define dbg1(...) std::cerr<<#__VA_ARGS__[0]<<" : "; print1DArray(__VA_ARGS__);

template <class T>
void print1DArray(T a[], int n){
    std::cerr<<"[ ";
    for(int i=0;i<n;i++){
        std::cerr<<a[i]<<" ";
    }
    std::cerr<<"]\n";
}

template <class T>
void print1DArray(T a[], int s, int e){
    std::cerr<<"[ ";
    for(int i=s;i<=e;i++){
        std::cerr<<a[i]<<" ";
    }
    std::cerr<<"]\n";
}

// debug 2D std::array
#define dbg2(...) std::cerr<<#__VA_ARGS__[0]<<" : "; print2DArray(__VA_ARGS__);

template <class T, size_t S>
void print2DArray(T a[][S], int n, int m){
    std::cerr<<"[ ";
    for(int i=0;i<n;i++){
        std::cerr<<"[ ";
        for(int j=0;j<m;j++){
            std::cerr<<a[i][j]<<" ";
        }
        std::cerr<<"] ";
    }
    std::cerr<<"]\n";
}

template <class T, size_t S>
void print2DArray(T a[][S], int sr, int er, int sc, int ec){
    std::cerr<<"[ ";
    for(int i=sr;i<=er;i++){
        std::cerr<<"[ ";
        for(int j=sc;j<=ec;j++){
            std::cerr<<a[i][j]<<" ";
        }
        std::cerr<<"] ";
    }
    std::cerr<<"]\n";
}