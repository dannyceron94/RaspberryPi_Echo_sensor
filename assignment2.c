
/**************************************************************
* Class: CSC-615-01 Spring 2020
* Name: Danny Daneth Ceron Garcia
* Student ID: 918581149
* Project: <Assignment 2 - Echo sensor>
*
* File: <assignment2.c>
*
* Description: We are to calculate the distance between the echo sensor and an object infront of it. we record the time the sound waves take to leave the sensor (trigger),
               hit the object and bouch back to the sensor reciever(echo).
*
* Sources: http://wiringpi.com/examples/blink/
           https://www.youtube.com/watch?v=kqJ8WYQu68w
**************************************************************/
// sources: 
// https://www.raspberrypi.org/forums/viewtopic.php?t=222142
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