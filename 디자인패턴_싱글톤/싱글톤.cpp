#include <iostream>

class Singleton {
private:
    Singleton() {
        printf("생성자 호출\n");
    }
    ~Singleton() = delete;
    Singleton(const Singleton& ref);
    static Singleton* instance;
public:
    static Singleton* getInstance() {
        if (instance != nullptr) {
            return instance;
        }
        else {
            instance = new Singleton();
            return instance;
        }
    }
    int data;
};
Singleton* Singleton::instance = nullptr;
int main(void) {
    Singleton* s = Singleton::getInstance();
    s->data = 5;
    Singleton* s2 = Singleton::getInstance();
    Singleton* s3 = Singleton::getInstance();
    

    std::cout << "s : " << s << "\n" << s->data << std::endl;
    std::cout << "s2 : " << s2 << "\n" << s2->data<<std::endl;
    std::cout << "s3 : " << s3 << "\n" << s3->data<<std::endl;

}