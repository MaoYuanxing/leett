#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct Test
{
    int num;
    int age;
};

void *callback(void *arg)
{
    for (int i = 0; i < 5; ++i)
    {
        printf("子线程：i = %d\n", i);
    }
    printf("子线程：%ld\n", pthread_self());
    struct Test *t = (struct Test *)arg;
    t->num = 100;
    t->age = 18;

    return t;
}

int main()
{
    pthread_t tid;
    struct Test t;
    pthread_create(&tid, NULL, callback, &t);
    // for (int i = 0; i < 5; ++i)
    // {
    //     printf("主线程：i = %d\n", i);
    // }
    printf("主线程：%ld\n", pthread_self());

    pthread_detach(tid);

    // void *ptr;
    // pthread_join(tid, &ptr);//阻塞主线程
    // printf("num = %d, age = %d\n", t.num, t.age);
    pthread_exit(NULL);
    //  sleep(3);//想一想这个动作的作用，如果注释了会怎么样
    return (0);
}