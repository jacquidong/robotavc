#include <stdio.h>
#include <time.h>
#include "E101.h"
int main(){
	init();

		// gate closed
		char ip [15] = "130.195.6.196";
		int port = 1024;
   		connect_to_server(ip, port); // connects to the gate server

		char message [24] = "Please";
		send_to_server(message); // requests password


		//char message [24]; // init variable to store password
		receive_from_server(message);
		send_to_server(message); // sends password to server
		// gate opens

		printf("Gate opened \n");

		//set_motor(1,60);
		//sleep1(1,0);

		//printf("Hi Emma  \n");

		//int row  = 1;
		//double weight = -160;
		//double  total = 0;  //biggest possible total 12880 or -12880

		int picCount = 0;
        	//take_picture();

       		//display_picture(5,0);
		while (picCount < 2000)
		{
			set_motor(1, 42);  //left motor
			set_motor(2, 42); //right motor 

			int row = 1;
			double weight = -160;
			double total = 0;

			double numWhite = 0;

			//sleep1(1,0);
			take_picture();
			while (row<320)
			{
				//int red = get_pixel(120, row, 0); //row is 240 down, column is 320 sideways
				//int green = get_pixel(120, row, 1);
				//int blue = get_pixel(120, row, 2);

				int white = get_pixel(120, row, 3);

				//printf("Pixel Number %d: ", row);

				//if(red>100 && green>100 && blue>100)
				if(white>100)
				{
					//printf("White \t");
					total = total+weight;
					numWhite = numWhite +1;
				}
				else
				{
					//printf("Black \t");
				}

				//printf("Red:  %d, \t", red);
	                	//printf("Green:  %d, \t", green);
	        	        //printf("Blue:  %d \n", blue);

				row++;
				//weight++;
				weight = weight + 1;
			}

			//printf("Total: %f \n", total);
			printf("White pixel: %f \n", numWhite);

 			if(numWhite>280) //if there is an intersection turn left
			{
				//set_motor(1,0);
				//set_motor(2,0);
				//sleep1(0,100000);
                                //set_motor(1,-40);
                                //set_motor(2, 40);
                                //sleep1(1,0);
				printf("Yes\n");
                                //set_motor(1,0);
				set_motor(1,0);
				sleep1(0,100000);

			}

			else if(numWhite<1) //if nothing keep turning left until you see something  (for q3)
			{
				//set_motor(1,0);
				//set_motor(2,0);
				//sleep1(0,100000);
				//set_motor(1,-40);
				//set_motor(2, -40);
				//sleep1(1,0);
				//set_motor(1,0);
				//set_motor(2,0);

				//above is for q2
				set_motor(1,0);
                                set_motor(2,0);
				sleep1(1,0);
				set_motor(1,-42);
				set_motor(2,42);
				sleep1(1,300000);
				set_motor(1,0);
                                set_motor(2,0);
				sleep1(1,0);

			}

			else
			{
				if (total<-2000)
				{
					set_motor(1,0);
					sleep1(0,100000);
				}
				else if (total>2000)
				{
					set_motor(2,0);
					sleep1(0,100000);
				}
			}

			//else if (total>=-1000) && (total<=1000))

			//sleep1(0,100000);
			picCount++;
			

		}
		set_motor(1,0);
		set_motor(2,0);

			//sleep1(1,0);

		return 0;
	}




