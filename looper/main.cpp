#include <iostream>
#include "Message.h"
#include "Looper.h"

using namespace std;


void postTask(Looper *looper, int n) {

    for (int i = n * 10; i < n * 10 + 10; ++i) {

        auto *m = new Message();

        m->setWhat(i);
        string s = "data";
        m->setObj(s);

        looper->post(m);

        if (i % 5 == 0) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

    }


}


int main() {

    Looper l;


    std::thread workT2(postTask, &l, 1);
    workT2.detach();
    std::thread workT3(postTask, &l, 2);
    workT3.detach();
    std::thread workT4(postTask, &l, 3);
    workT4.detach();


    std::this_thread::sleep_for(std::chrono::seconds(5));


    return 0;
}