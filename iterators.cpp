#include <iostream>
#include <algorithm>
using namespace std;

// Forward iterator class
template<class T> class Fwd_iter {
protected:
    T *it;
public:
    
    Fwd_iter (T *c = NULL) { cout << "Fwd_iter constructor \n"; it = c; }

    Fwd_iter (Fwd_iter &t) { it = t.it; }

    ~Fwd_iter () { cout << get_addr() << " Fwd_iter destructor \n"; }

    inline int* get_addr() { return it; }
    
    T& operator* () { return *it; }
    
    Fwd_iter* operator++ () { ++it; return this; }
};


// Bidirectional iterator class
template<class T> class Bid_iter {
protected:
    Fwd_iter<T> f; // forward iterator on current element
    Fwd_iter<T> fb; // forward iterator on first(begin) element
    unsigned int dist; // distance from f to fb == |&f-&fb|
public:
    Bid_iter (Fwd_iter<T> &fwd, Fwd_iter<T> &fwdb) { 
        cout << "Bid_iter constructor \n"; 
        f = fwd;
        fb = fwdb;
        dist = abs( ( f.get_addr() - fb.get_addr() ) );
    }
    
    Bid_iter (Bid_iter &it) { 
        cout << "Bid_iter copy constructor \n"; 
        f = it.f;
        fb = it.fb;
        dist = it.dist;
    }
    
    ~Bid_iter () { cout << "Bid_iter destructor \n"; }
    
    inline int* get_addr() { return f.get_addr(); }
    
    inline int get_dist() { return dist; }
    
    T& operator* () { return *f; }
    
    Bid_iter* operator++ () { ++f; ++dist; return this; }

    Bid_iter operator++(int notused) {
        Bid_iter tmp = *this;
        ++f; ++dist;
        return tmp;
    }
    
    Bid_iter* operator-- () {
        Fwd_iter<T> tmp = fb;
        for (int i=0; i<(dist-1); ++i)
            ++tmp;
        
        f = tmp;
        dist--;
        return this; 
    }
    
    Bid_iter operator-- (int notused) {
        Bid_iter<T> t = *this;
        Fwd_iter<T> tmp = fb;
        for (int i=0; i<(dist-1); ++i)
            ++tmp;
        
        f = tmp;
        dist--;
        return t;
    }

};

int main()
{
    cout << "Hello" << endl;
    register int i = 0;
    int a[30];
    cout << a << endl;

    
    for (i=0;i<15;++i)
    {
        a[i] = i;
        cout << a[i] << " ";
    }
    cout << endl;

    
    Fwd_iter<int> itfwd_begin(a);
    cout << itfwd_begin.get_addr() << endl;

    
    Fwd_iter<int> itfwd(a);
    cout << itfwd.get_addr() << endl;



    for (i=0;i<5;++i) {
        cout << *itfwd << " ";
        ++itfwd;
    }
    
    cout << endl;
    cout << itfwd.get_addr() << "\n\n";
    
        
    Bid_iter<int> it(itfwd, itfwd_begin);
    
    cout << endl;

    Bid_iter<int> it2 = it;
    cout << it2.get_addr() << endl << endl;


cout << "\n Pre-increment tests: \n\n";
    for (i=0;i<5;++i) {
        cout << *it << " ";
        ++it;
    }
    cout << "\n";
    cout << it.get_addr() << "\t" << it.get_dist() << "\n\n";

    
cout << "\n Post-inc tests: \n\n";
    for (i=0;i<5;++i) {
        cout << *it << " ";
        it++;
    }
    cout << "\n";
    cout << it.get_addr() << "\t" << it.get_dist() << "\n\n";

    
cout << "\n Pre-decrement tests: \n\n";
    for (i=0;i<5;++i) {
        --it;
        cout << *it << " ";
    }
    cout << "\n";
    cout << it.get_addr() << "\t" << it.get_dist() << "\n\n";


cout << "\n Post-dec tests: \n\n";
for (i=0;i<5;++i) {
        it--;
        cout << *it << " ";
    }
    cout << "\n";
    cout << it.get_addr() << "\t" << it.get_dist() << "\n\n";


    cout << endl;
}


