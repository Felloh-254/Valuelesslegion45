#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>


#define HOUR_RATE 6.80
#define TAX_RATE 0.15

float GrossPay(float hours){
	float OverTime;
	float gross;

	if(hours>40){
		OverTime = (hours-40) * 0.8 * HOUR_RATE;
		gross = (40 * HOUR_RATE) + OverTime;
	}
	else{
		gross = hours * HOUR_RATE;
	}
	return gross;
}


float IncomeTax(float GrossPay){
	float itax;
	itax=TAX_RATE * GrossPay;
	return itax;
}


float NettPay(float GrossPay, float IncomeTax){
	float net;
	net=(GrossPay - IncomeTax);
	return net;
}


void Dispay(int hours, float gross, float itax, float net){
	printf("\nYour Income Details are as follows\n");
	printf("\nHours worked: %d\n", hours);
	printf("GrossPay: %.2f\n", gross);
	printf("Income Tax: %.2f\n", itax);
	printf("Net Income: %.2f\n", net);
}


int main(int argc, char const *argv[])
{
	/* code */
	char response;
	int hours;
	float gross, itax, net, dispay;

	printf("\tWelcome to the Paycheck system!!\n");
	do{
		printf("\nEnter the number of hours worked: ");
		scanf("%d", &hours);

		gross=GrossPay(hours);
		itax=IncomeTax(gross);
		net=NettPay(gross, itax);
		Dispay(hours, gross, itax, net);

		printf("Do you wnat to perform another paycheck(Y/N)?: ");
		scanf("%s", &response);
	}while(tolower(response)=='y');
	return 0;
}













