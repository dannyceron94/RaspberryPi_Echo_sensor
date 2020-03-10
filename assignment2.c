#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <time.h>

#define ECHO 22    //pin 40
#define TRIGGER 21 //pin 15

void startUpEcho();
double recordedTime(); 

int main(void){
    double distance =0;
    while(1){
        startUpEcho();
        distance = recordedTime()*(340/2)*100;
        printf("distance is %f cm\n",distance);
        }
    return 0;
}

void startUpEcho(){
    if(wiringPiSetup()){
        printf("wire was etup");
        }
    
    pinMode(TRIGGER,OUTPUT);
    pinMode(ECHO,INPUT);

    digitalWrite(TRIGGER,LOW);
    delay(500);//.00001s
    digitalWrite(TRIGGER,HIGH);
    delay(0.05);//.00001s
    digitalWrite(TRIGGER,LOW);
    //delay(0.01);//.00001s
    //printf("setup function call\n");
}

double recordedTime(){
    clock_t start, end;
    //printf("recorded function");
    while(digitalRead(ECHO) == LOW){
        printf("echo off\n");
        start = clock();
    }
    while(digitalRead(ECHO)==HIGH){
        end = clock();
        printf("echo on\n");
    }

    return ((double)(end-start))/CLOCKS_PER_SEC;
}
