/*write a program that computes avg temperature for a month, both by days and by hour. The temperatures are stored in a 2D array with rows = month and column = hour. Chapter 9, page 178, question 9 */

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include <omp.h> /*header for openMP, to allow parallal processes*/


#define GROUP_SIZE 5
#define DAYS_IN_MONTH 30
#define HOURS_IN_DAY 24

void print_arr(double arr[DAYS_IN_MONTH][HOURS_IN_DAY]){
	
	int i,j;
	 // print 2d array
	for(i = 0; i<DAYS_IN_MONTH; i++){
		for(j = 0; j<HOURS_IN_DAY; j++){
			printf("Day: %d, Hour: %d %.2f\n", i, j, arr[i][j]);
		}
	}
}


int main(void){

	double temperature_readings[DAYS_IN_MONTH][HOURS_IN_DAY];
	int max_temp = 100;
	int min_temp = 5;
	int i,j;
	float avg_day_temp[DAYS_IN_MONTH]; // array to store avg of daily temps
	float avg_hour_temp[HOURS_IN_DAY]; // array to store avg of hourly temps

	srand((unsigned) time(NULL));

	int day, hour;
	for(day = 0; day<DAYS_IN_MONTH; day++){
		for(hour = 0; hour<HOURS_IN_DAY; hour++){
			//temperature_readings[day][hour] = 1.00; //test for correct averages
			temperature_readings[day][hour] = (double)(rand() % max_temp) + min_temp;
		}


	}

	#pragma omp parallel for
	for(i =0; i< DAYS_IN_MONTH; i++){
		
		
		float day_sum = 0.00;
		for(j=0; j<HOURS_IN_DAY; j++){
			day_sum += temperature_readings[i][j];
		}
		avg_day_temp[i] =(float)(day_sum/HOURS_IN_DAY);
	}

	for(i=0;i<DAYS_IN_MONTH;i++){
		printf("Avg Temp on day %u : %.2f\n",i, avg_day_temp[i]);
	}


	#pragma omp parallel for
	for(i =0; i< HOURS_IN_DAY; i++){
		
		
		float hour_sum = 0.00;
		for(j=0; j<HOURS_IN_DAY; j++){
			hour_sum += temperature_readings[i][j];
		}
		avg_hour_temp[i] =(float)(hour_sum/DAYS_IN_MONTH);
	}

	for(i=0;i<HOURS_IN_DAY;i++){
		printf("Avg Temp at hour %u : %.2f\n",i, avg_hour_temp[i]);

	}


	//print_arr(temperature_readings);	


}
