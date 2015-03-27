#include <iostream>
using namespace std;

template <class T> class ForwardIterator {
private:
    T *p; // [0;size-1]
    size_t size;
    T *first;
    T *last; // &p[size-1];
public:
    ForwardIterator (const T* w, int sz = 32) {
        cout << "Constructor \n"; 
        size = sz;
        p = new T[size];
        first = &p[0];
        last = &p[size-1];
        
        T* tmp = w;
        for (p = first; p != last; ++p) {
            *p = *w;
            cout << *p << endl;
            ++w;
        }
    }
    ForwardIterator (const ForwardIterator &it) {
        cout << "Copy constructor \n"; 
        size = it.size;
        p = new T[size];
        first = &p[0];
        last = &p[size-1];
    }
    ForwardIterator operator++ () {
        cout << "Pre-increment \n";
        T *tmp;
        ++tmp;
        if (tmp == last) cerr << "[!]Out of bounds! \n";
        else ++p;
        return *this;
    }
    inline void printAddr() {
        cout << "Iterator address: " << p << endl;
    }
    bool onLast()
    {
        cout << "OnLast check \n";
        if (p == last) return true;
        return false;
    }
    ~ForwardIterator(){ cout << "Destructor \n"; delete [] first; }

};



int main()
{

    const int sz = 10;
    int *q = new int[sz];

    ForwardIterator it(q, sz);

    it.printAddr();
    ++it;
    it.printAddr();
 //   ForwardIterator<int> a(it);
    cout << sizeof(size_t) << endl;
    
}
