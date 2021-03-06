 
/* 
             define from  wiringPi.h                     define from Board DVK511
                 3.3V | | 5V               ->                 3.3V | | 5V
                8/SDA | | 5V               ->                  SDA | | 5V
                9/SCL | | GND              ->                  SCL | | GND
                    7 | | 15/TX            ->                  IO7 | | TX
                  GND | | 16/RX            ->                  GND | | RX
                    0 | | 1                ->                  IO0 | | IO1
                    2 | | GND              ->                  IO2 | | GND
                    3 | | 4                ->                  IO3 | | IO4
                  VCC | | 5                ->                  VCC | | IO5
              MOSI/12 | | GND              ->                 MOSI | | GND
              MISO/13 | | 6                ->                 MISO | | IO6
               SCK/14 | | 10/CE0           ->                  SCK | | CE0
                  GND | | 11/CE1           ->                  GND | | CE1
              30/ID_SD| | 31/ID_SC         ->                ID_SD | | ID_SC
                    21| | GND              ->                  SDA | | 5V
                    22| | 26               ->                  SCL | | GND
                    23| | GND              ->                  IO7 | | TX
                    24| | 27               ->                  GND | | RX
                    25| | 28               ->                  IO0 | | IO1
                   GND| | 29               ->                  IO2 | | GND
                  */

#include <stdio.h>
#include <string.h> 
#include <errno.h>

#include<wiringPi.h>

char KEY[]={4,5,6,7};
char LED[]={0,1,2,3};
char i;

int main(){
if (wiringPiSetup() < 0)
{
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
    return 1 ;
}
for(i=0;i<4;i++) {
pinMode (LED[i],OUTPUT);
digitalWrite (LED[i],0);
pinMode (KEY[i],INPUT) ;
pullUpDnControl(KEY[i], PUD_UP);
}

//pullUpDnControl(LED, PUD_UP);

while(1)
{
  for(i=0;i<4;i++) {
if (digitalRead (KEY[i]) == 0)  
    { 
    	if(i==0){digitalWrite (LED[0],1);digitalWrite (LED[1],0);digitalWrite (LED[2],0);digitalWrite (LED[3],0);};
    	if(i==1){digitalWrite (LED[0],0);digitalWrite (LED[1],1);digitalWrite (LED[2],0);digitalWrite (LED[3],0);};
    	if(i==2){digitalWrite (LED[0],0);digitalWrite (LED[1],0);digitalWrite (LED[2],1);digitalWrite (LED[3],0);};
    	if(i==3){digitalWrite (LED[0],0);digitalWrite (LED[1],0);digitalWrite (LED[2],0);digitalWrite (LED[3],1);};   	   	
    	printf ("press the key : %d\n",i) ;
    delay(500);
    }
  }

}
}
