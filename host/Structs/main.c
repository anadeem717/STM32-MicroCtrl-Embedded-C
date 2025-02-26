/*
 * main.c
 *
 *  Created on: Jan 10, 2025
 *      Author: arees
 */

#include <stdio.h>
#include <stdint.h>

struct carModel {
	uint32_t year;
	uint32_t price;
	uint32_t maxSpeed;
	float weight;
};

int main() {

	// C89 method
	struct carModel carBMW = {2023,50000,220,1330};
	struct carModel carFord = {2020,20000,160,1200};

	// C99 method, order doesnt matter
	struct carModel carHonda = {.weight = 900, .maxSpeed = 150};

	printf("Price of car BMW is %d\n", carBMW.price);

	// learn about struct padding
	printf("Size of struct carModel is %llu bytes\n", sizeof(struct carModel));


	getchar();

	return 0;
}


