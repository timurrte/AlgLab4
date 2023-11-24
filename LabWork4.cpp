#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

//Стек
class MyStack
{
public:

    int elementsBetweenMinMax(MyStack& stack) {
        if (stack.empty()) {
            std::cout << "Стек порожній" << std::endl;
            return 0;
        }

        int minElement = INT_MAX;
        int maxElement = INT_MIN;
        MyStack tempStack; // Тимчасовий стек

        // Знаходимо мінімальний і максимальний елементи у стеці
        while (!stack.empty()) {
            int current = stack.pop();
            tempStack.push(current);

            if (current < minElement)
                minElement = current;

            if (current > maxElement)
                maxElement = current;
        }

        int elementsBetween = -1;
        bool foundMin = false, foundMax = false;

        // Шукаємо кількість елементів між мінімальним і максимальним
        while (!tempStack.empty()) {
            int current = tempStack.pop();
            stack.push(current); // Повертаємо елементи назад у вихідний стек

            if (foundMin && !foundMax)
                elementsBetween++;

            if (current == minElement)
                foundMin = true;

            if (current == maxElement)
                foundMax = true;

            if (foundMin && foundMax)
                break;
        }

        if (!foundMin || !foundMax) {
            std::cout << "Мінімальний або максимальний елемент не знайдено" << std::endl;
            return 0;
        }

        return elementsBetween;
    }



    //Конструктор за замовчуванням
    MyStack() : apex(nullptr) {}

    //Додавання елемента на початок стеку
    void push(const int& x) {
        Node* newnode = new Node;
        newnode->value = x;
        newnode->next = apex;
        apex = newnode;
    }

    //Перевірка наявності елементів у стеку
    bool empty() {
        return apex == nullptr;
    }

    //Видалення елемента з верхньої частини стека
    int pop() {
        if (empty())
            throw length_error("Stack is empty");
        Node* delnode = apex;
        int x = delnode->value;
        apex = delnode->next;
        return x;
    }

    //Виведення стеку
    void show(MyStack mystack) {
        while (!mystack.empty()) {
            cout << mystack.pop() << ' ';
        }
        cout << endl;
    }

    //Деструктор
    ~MyStack() {
        while (!empty()) {
            pop();
        }
    }

private:
    //Вузол стеку
    struct Node {
        int value;
        Node* next;
    };
    Node* apex;
};

struct queue {
    int q[10000];
    int first;
    int last;

    queue() {
        first = 0;
        last = 0;
    }

    //Додавання елемента в кінець черги
    void push(int a) {
        q[last] = a;
        last++;
    }

    //Видалення елемента з передньої частини черги
    int pop() {
        if (empty()) {
            throw length_error("Queue is empty");
        }
        int a = q[first];
        first++;
        return a;
    }

    //Перевірка на наявність елементів у черзі
    bool empty() {
        return first == last;
    }

    //Виведення черги
    void show() {
        if (empty()) {
            cout << "Error" << endl;
            //throw length_error("Queue is empty");
        }

        for (int i = first; i < last; i++)
        {
            cout << q[i] << ' ';
        }
        cout << endl;
    }

    void splitQueue(queue& original, queue& evenQueue, queue& oddQueue) {
        while (!original.empty()) {
            int current = original.pop();
            if (current % 2 == 0) {
                evenQueue.push(current);
            }
            else {
                oddQueue.push(current);
            }
        }
        return;
    }
};

int main() {
    srand(time(NULL));
    MyStack mystack;
    queue myqueue;
    queue evenQueue;
    queue oddQueue;
    int N = 15;

    for (int i = 0; i < N; i++) {
        mystack.push(rand() % N);
        myqueue.push(rand() % N);
    }

    cout << "*Stack*\n";
    mystack.show(mystack);
    cout << endl;

    cout << "Element between Min Max:" << endl;
    cout << mystack.elementsBetweenMinMax(mystack) << endl;


    cout << "\n*Queue*\n";
    myqueue.show();
    cout << endl;

    cout << "Split queue into 2:" << endl;
    myqueue.splitQueue(myqueue, evenQueue, oddQueue);
    cout << "Even numbers:" << endl;
    evenQueue.show();
    cout << "Odd numbers : " << endl;
    oddQueue.show();


    cout << endl;
    system("pause");
    return 0;
}
