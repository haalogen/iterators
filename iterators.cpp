#include <iostream>
using namespace std;

template<class T> class Fwd_iter {
protected:
    T *it;
public:
    Fwd_iter (T *c) { cout << "Fwd_iter constructor \n"; it = c; }

    Fwd_iter (Fwd_iter &t) { it = t.it; }

    ~Fwd_iter () { cout << get_addr() << " Fwd_iter destructor \n"; }

    inline int* get_addr() { return it; }
    
    T& operator* () { return *it; }
    
    T* operator++ () { ++it; return it; }
};



int main()
{
    cout << "Hello" << endl;
    register int i = 0;
    int a[30];
    cout << a << endl;
    
    for (i=0;i<30;++i)
    {
        a[i] = i;
        cout << a[i] << " ";
    }
    cout << endl;
    
    Fwd_iter<int> itfwd_begin(a);

    cout << itfwd_begin.get_addr() << endl;
    
    Fwd_iter<int> itfwd(a);
    cout << itfwd.get_addr() << endl;
    
    for (i=0;i<10;++i) {
        cout << *itfwd << " ";
        ++itfwd;
    }
    cout << "\n\n";
        
//    Bid_iter<int> it(itfwd, itfwd_begin);
//    
//    for (i=0;i<5;++i) {
//        cout << *it << " ";
//        ++it;
//    }
//    cout << "\n\n";
//    
//    for (i=0;i<5;++i) {
//        cout << *it << " ";
//        --it;
//    }
}


