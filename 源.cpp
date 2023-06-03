#include <iostream>
#include <chrono>

template<typename T>
class MyList {
private:
    struct Node {
        T data;             // 节点存储的数据
        Node* next;        // 指向下一个节点的指针
        Node(const T& d) : data(d), next(nullptr) {} // 节点构造函数
    };
    Node* head;            // 头部节点指针
    Node* tail;            // 尾部节点指针

public:
    MyList() : head(nullptr), tail(nullptr) {} // 构造函数，初始化头部和尾部指针为nullptr

    ~MyList() { // 析构函数，释放链表内存
        while (head != nullptr) {
            Node* temp = head;     // 临时指针，指向当前头部节点
            head = head->next;     // 头部指针移动到下一个节点
            delete temp;           // 删除临时指针指向的节点
        }
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value); // 创建一个新节点，传入的值作为节点的数据
        if (head == nullptr) {           // 链表为空
            head = newNode;              // 将新节点设为头部节点
            tail = newNode;              // 将新节点设为尾部节点
        } else {
            tail->next = newNode;        // 将新节点追加到链表尾部
            tail = newNode;              // 更新尾部指针为新节点
        }
    }

    void print() {
        Node* current = head;            // 临时指针，指向当前节点，初始化为头部节点
        while (current != nullptr) {     // 循环遍历链表
            std::cout << current->data << " ";  // 输出当前节点的数据
            current = current->next;            // 指针移动到下一个节点
        }
        std::cout << std::endl;          // 输出换行符表示输出结束
    }
};




int main() {
    // 创建一个空链表
    MyList<int> myList;

    // 在链表尾部添加元素
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);

    // 输出链表内容
    myList.print();  // 输出: 10 20 30 40

    // 在链表尾部添加更多元素
    myList.push_back(50);
    myList.push_back(60);

    // 输出链表内容
    myList.print();  // 输出: 10 20 30 40 50 60

    // 创建一个新的链表
    MyList<std::string> stringList;

    // 在链表尾部添加字符串元素
    stringList.push_back("Hello");
    stringList.push_back("World");

    // 输出链表内容
    stringList.print();  // 输出: Hello World



    return 0;
}

