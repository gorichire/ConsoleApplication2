#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

template <typename T>
class myvector {
private:
    int num;
    int len;
    T* tmp;
    T* head;
    T* tail;
public:
    T* arr;
public:
    class myiterator {
        T* current;
    public:
        myiterator(T* node = 0) : current(node) {}

        myiterator& operator++() {
            current++;
            return *this;
        }

        myiterator& operator--() {
            current--;
            return *this;
        }

        T& operator*() {
            return *current;
        }

        bool operator !=(const myiterator& cmp) {
            return (current != cmp.current);
        }

        bool operator ==(const myiterator& cmp) {
            return (current == cmp.current);
        }
    };

    myvector() {
        myvector::num = 0;
        myvector::len = 10;                        
        myvector::arr = new T[len]{};               
        head = arr;                        
        tail = arr;
    }

    ~myvector() {                             
        delete[] arr;
        arr = nullptr;
        head = tail = nullptr;
        num = len = 0;
    }

    T front() {
        return *head;
    }

    T back() {
        return arr[num - 1];
    }

    int size() {
        return num;
    }

    bool empty() {
        return num == 0;         
    }

    void clear() {
        num = 0;
        delete[] arr;                            
        len = 10;                                  
        arr = new T[len]{};              
        head = arr;                       
        tail = arr;
    }

    void push_back(T input) {
        if (num == len) {                         
            len *= 2;
            tmp = arr;
            arr = new T[len];     
            for (int i = 0; i < num; i++) arr[i] = tmp[i];
            delete[] tmp;             
            head = &arr[0];
        }
        arr[num++] = input;
        tail = &arr[num];                     
    }

    void pop_back() {
        if (num == 0) return;    
        --num;

        if (len > 10 && num < len / 2) {
            len /= 2;
            tmp = arr;
            arr = new T[len];                  
            for (int i = 0; i < num; i++) arr[i] = tmp[i];
            delete[] tmp;                   
            head = &arr[0];
        }
        tail = &arr[num];
        if (num == 0) {
            head = arr;                        
            tail = arr;
        }
    }

    void resize(int n) {
        if (n < 0) n = 0;                  
        int old = num;
        int tmplen = len;                          
        while (tmplen < n) tmplen *= 2;
        if (tmplen != len) {
            tmp = arr;
            arr = new T[tmplen];
            int copyN = (old < n) ? old : n;
            for (int i = 0; i < copyN; ++i) arr[i] = tmp[i];
            delete[] tmp;
            len = tmplen;
        }

        if (n > old) {
            for (int i = old; i < n; ++i) arr[i] = T{};
        }
        num = n;
        head = &arr[0];
        tail = &arr[num];
    }

    T& at(int i) {                    
        if (i < 0 || i >= num) throw out_of_range("myvector::at");
        return arr[i];
    }
    const T& at(int i) const {
        if (i < 0 || i >= num) throw out_of_range("myvector::at");
        return arr[i];
    }

    myiterator begin() {
        return myiterator(head);
    }

    myiterator end() {
        return myiterator(tail);
    }
};

int main() {
    myvector<int> v;
    for (int i = 0; i < 15; i++)
        v.push_back(i);

    for (int i = 0; i < v.size(); i++)
        cout << v.arr[i] << ' ';

    cout << endl;
    for (int i = 0; i < 8; i++)
        v.pop_back();

    for (int i = 0; i < v.size(); i++)
        cout << v.arr[i] << ' ';
    cout << endl;
}
