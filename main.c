#include"thread.h"
#include<stdio.h>
#include <sys/time.h>


void fun1(){

  int i=0;
  for(i=0;i<10;i++){
    printf("thread id=%d time=%d\n",1,i);
    mysleep(2);
    
  }

}

void fun2(){


int i=0;
  for(i=0;i<10;i++){
    printf("thread id=%d time=%d\n",2,i);
    if(i==4){
      wait(1);
      printf("wait thread 1 \n");
    }
    mysleep(2);
    if(i==6){
      resume(1);
      printf("resume thread 1 \n");
    }
  }


}


void fun3(){

  int i=0;
  for(i=0;i<10;i++){
    printf("thread id=%d time=%d\n",3,i);
    mysleep(2);
    
  }

}



int main(){

  struct timeval start, end;
  gettimeofday(&start, NULL);
  int th1,th2,th3;
  printf("hello world!\n");
  thread_create(&th1,fun1);
  thread_create(&th2,fun2);
  thread_create(&th3,fun3);
  detach(th2);
  detach(th3);
  thread_join(th1);
gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double totalTime = seconds + microseconds*1E-6;

    printf("Total running time: %.3f seconds\n", totalTime);



  return 0;
}


