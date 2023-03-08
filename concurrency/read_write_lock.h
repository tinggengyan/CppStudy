//
// Created by TinggengYan on 2023/3/8.
//

#ifndef CPPSTUDY_READ_WRITE_LOCK_H
#define CPPSTUDY_READ_WRITE_LOCK_H

#include<cstdio>
#include<pthread.h>
#include<unistd.h>


int buf = 0;  //buf全局变量就是临界资源。
pthread_rwlock_t rwlock;  //读写锁

void *myread(void *arg) {
    while (1) {
        if (pthread_rwlock_tryrdlock(&rwlock) != 0) //申请锁失败
        {
            printf("writer is working!\n");
            printf("reader do other thing!\n");
            continue;  //继续申请锁

        } else {
            printf("reading:%d\n", buf);
            pthread_rwlock_unlock(&rwlock); //释放锁
        }
//        sleep(1);
    }
}


void *mywrite(void *arg) {
    while (1) {
        if (pthread_rwlock_trywrlock(&rwlock) != 0) {
            printf("reader is working!\n");
            printf("writer do other thing!\n");
            continue;
        } else {
            buf++;
            pthread_rwlock_unlock(&rwlock);
        }
        //写者隔1秒竞争一次锁资源
        sleep(1);
    }
}


int read_write_lock_method() {
    // 初始化属性
    pthread_rwlock_init(&rwlock, NULL);

    pthread_t id1, id2;
    pthread_create(&id1, NULL, myread, NULL);
    pthread_create(&id2, NULL, mywrite, NULL);

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);

    pthread_rwlock_destroy(&rwlock);


    return 0;
}


#endif //CPPSTUDY_READ_WRITE_LOCK_H
