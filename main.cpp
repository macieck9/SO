#include<iostream>
#include<pthread.h>

using namespace std;

void* print(void* n)
{
    cout << "Watek nr " << (int)n << "\n";
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1, thread2;
    pthread_attr_t attr;
    
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    pthread_create(&thread1, &attr, print, (void *) 1);
    pthread_create(&thread2, &attr, print, (void *) 2);
    
    void* status;
    pthread_join(thread1, &status);
    pthread_join(thread2, &status);
    
    cout << "Koniec\n";
    
    
    return 0;
}
