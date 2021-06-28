//
// Created by Tinggeng Yan on 2019-11-09.
//

#include <string>
#include <iostream>

using namespace std;

struct Dequeue {
    int capacity = 7;
    int elements[7];
    int head = 0;
    int tail = 0;
};

bool full(Dequeue &dequeue) {
    return dequeue.head % dequeue.capacity == (dequeue.tail + 1) % dequeue.capacity;
}


bool empty(Dequeue &dequeue) {

    return dequeue.head % dequeue.capacity == dequeue.tail % dequeue.capacity;

}


void push(int e, Dequeue &dequeue) {
    if (full(dequeue)) {
        std::cout << "full " << std::endl;
        return;
    }
    int tail = dequeue.tail;
    dequeue.elements[tail] = e;

    std::cout << "push element in index:" << tail << std::endl;

    dequeue.tail = (++tail) % dequeue.capacity;
}

int pop(Dequeue &dequeue) {
    if (empty(dequeue)) {
        std::cout << "empty " << std::endl;
        return -1;
    }

    int head = dequeue.head;
    int d = dequeue.elements[head];
    std::cout << "pop element in index:" << head << std::endl;

    dequeue.head = (++head) % dequeue.capacity;
    return d;
}


int main() {

    Dequeue dequeue;

    for (int i = 0; i < 7; ++i) {
        push(i, dequeue);
    }

    pop(dequeue);

    push(1, dequeue);
    push(1, dequeue);


    pop(dequeue);


//    if (i > -1) {
//        std::cout << "main pop: " << i << std::endl;
//    }


    return 0;
}