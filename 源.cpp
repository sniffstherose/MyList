#include <iostream>
#include <chrono>

template<typename T>
class MyList {
private:
    struct Node {
        T data;             // �ڵ�洢������
        Node* next;        // ָ����һ���ڵ��ָ��
        Node(const T& d) : data(d), next(nullptr) {} // �ڵ㹹�캯��
    };
    Node* head;            // ͷ���ڵ�ָ��
    Node* tail;            // β���ڵ�ָ��

public:
    MyList() : head(nullptr), tail(nullptr) {} // ���캯������ʼ��ͷ����β��ָ��Ϊnullptr

    ~MyList() { // �����������ͷ������ڴ�
        while (head != nullptr) {
            Node* temp = head;     // ��ʱָ�룬ָ��ǰͷ���ڵ�
            head = head->next;     // ͷ��ָ���ƶ�����һ���ڵ�
            delete temp;           // ɾ����ʱָ��ָ��Ľڵ�
        }
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value); // ����һ���½ڵ㣬�����ֵ��Ϊ�ڵ������
        if (head == nullptr) {           // ����Ϊ��
            head = newNode;              // ���½ڵ���Ϊͷ���ڵ�
            tail = newNode;              // ���½ڵ���Ϊβ���ڵ�
        } else {
            tail->next = newNode;        // ���½ڵ�׷�ӵ�����β��
            tail = newNode;              // ����β��ָ��Ϊ�½ڵ�
        }
    }

    void print() {
        Node* current = head;            // ��ʱָ�룬ָ��ǰ�ڵ㣬��ʼ��Ϊͷ���ڵ�
        while (current != nullptr) {     // ѭ����������
            std::cout << current->data << " ";  // �����ǰ�ڵ������
            current = current->next;            // ָ���ƶ�����һ���ڵ�
        }
        std::cout << std::endl;          // ������з���ʾ�������
    }
};




int main() {
    // ����һ��������
    MyList<int> myList;

    // ������β�����Ԫ��
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);

    // �����������
    myList.print();  // ���: 10 20 30 40

    // ������β����Ӹ���Ԫ��
    myList.push_back(50);
    myList.push_back(60);

    // �����������
    myList.print();  // ���: 10 20 30 40 50 60

    // ����һ���µ�����
    MyList<std::string> stringList;

    // ������β������ַ���Ԫ��
    stringList.push_back("Hello");
    stringList.push_back("World");

    // �����������
    stringList.print();  // ���: Hello World



    return 0;
}

