/*
  BarkingDog created from RF_Sniffer
  
  Hacked from http://code.google.com/p/rc-switch/
  
  by @justy to provide a handy RF code sniffer
*/

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>     
     
RCSwitch mySwitch;
 


int main(int argc, char *argv[]) {
  
     // This pin is not the first pin on the RPi GPIO header!
     // Consult https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     // for more information.
     int PIN = 2;
     
     if(wiringPiSetup() == -1)
       return 0;

     mySwitch = RCSwitch();
     mySwitch.enableReceive(PIN);  // Receiver on inerrupt 0 => that is pin #2
     system("mpc clear");
     system("mpc add Big-dog.mp3");
     int isCurrentlyPlaying = 0;   
    
     while(1) {
  
     if (mySwitch.available()) {
    
        int value = mySwitch.getReceivedValue();
    
        if (value == 0) {
           printf("Unknown encoding\n");
        } else if(value ==5393){
            printf("WARNING SOMEONE IS AT THE DOOR\n");
            FILE *fp = popen("mpc current","r");
            char buf[1024];
            if(fgets(buf,1024,fp)==NULL){
               // no file currently playing we can triger the dog barking song
               system("mpc play 1");
            }
        }
        else if(value ==5396){
           printf("No motion\n");
           //system("mpc stop");
        }
        else {    
          printf("Received %i\n", mySwitch.getReceivedValue() );
        }
    
        mySwitch.resetAvailable();
      }
      
  
  }

  exit(0);


}

