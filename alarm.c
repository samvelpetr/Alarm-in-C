#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>


void signal_handler(int);
int setTimer();
void timerIsWorking(int);


int alarmFlag = 1;
void start(){ 
    int time = setTimer();
    timerIsWorking(time);
}
void signal_handler(int signal){



    system("afplay budelnik.wav");
    printf("Time is over\n");
    return;       
}
int setTimer(){
    printf("Enter alarm timer (Enter -1 for exit) \n");
    char timer[200];

    scanf("%s", timer);
    int timer1 = atoi(timer);
    if(timer1< -1){
        return 0;
    }
    if(timer1 == -1){alarmFlag=0; return 0;}
    return timer1;

}
void timerIsWorking(int time){
    signal(SIGALRM,signal_handler);

    if(time == 0){
        printf("Program is exited\n");
    return;

    } 
    alarm(time);
    pause();
}



int main(){
    signal(SIGALRM,signal_handler);
    while(alarmFlag){
    start();
    }   
}