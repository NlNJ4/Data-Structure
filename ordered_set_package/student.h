#include <vector>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v=A;
    set<T> a;
    for(auto val:A) a.insert(val);
    for(auto b:B) (!a.count(b)) ? v.push_back(b) : void(0);
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> b;
    for(auto val:B) b.insert(val);
    for(auto a:A) (b.count(a)) ? v.push_back(a) : void(0);
    return v;
}