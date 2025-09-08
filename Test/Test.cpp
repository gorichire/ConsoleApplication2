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
};