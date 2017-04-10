
#include <stdio.h>
#include <time.h>
#include "E101.h"

class Movement{
public:
int speed;
int slow;
int high;
int medium;
int PWM;
int duration;

void drive_straight(int speed)
{
		int PWM = 10;
		if (speed == slow){
			PWM = 51;
		}
		else if (speed == medium){
			PWM = 127;}
		else if (speed == high){
			PWM = 255;
		}
		set_motor(1,PWM);
		set_motor(2,PWM);
}
		
void turn_left(int duration)
{
		
		
		set_motor(1,51);
		set_motor(2,-51);
		sleep1(duration,0000000);
		set_motor(1,0);
		set_motor(2,0);
		
	}


};

int main(){
	init();
		
		
	Movement movement;	 
		
		int adc_reading;
		
		while(adc_reading<500)
		{
			adc_reading = read_analog(0);
			//sleep1(0,500000);
			printf("%d",adc_reading);			
			if (adc_reading<=300){
				movement.drive_straight(movement.high);
				}
			else if (adc_reading<=400){
				movement.drive_straight(movement.medium);
				}
			else if (adc_reading<=500){
				movement.drive_straight(movement.slow);
				}				

		}		



		stop(0);
	return 0;
}
