#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <time.h>

#define ECHO 31
#define TRIGGER 29

void startUpEcho();
double recordedTime(); 

int main(void){

    startUpEcho();
    double distance = recordedTime()*(340/2);
    printf("the distance is %lf cm",distance)
    return 0;
}

void startUpEcho(){

    wiringPiSetup();
    pinMode(TRIGGER,OUTPUT);
    pinMode(ECHO,INPUT);
    digitalWrite(TRIGGER,LOW);
    delay(0.01);//.00001s
    printf("setup function call\n");
}

double recordedTime(){
    clock_t start, end;
    printf("recorded function");
    while(digitalRead(ECHO) == LOW){
        printf("echo off\n");
        start = clock();
    }
    while(digitalRead(ECHO)==HIGH){
        end = clock();
        printf("echo tue\n");
    }

    return ((double)(end-start))/CLOCKS_PER_SEC;
}