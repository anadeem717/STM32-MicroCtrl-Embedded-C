/*
 * main.c
 *
 *  Created on: Jan 10, 2025
 *      Author: arees
 */

#include <stdio.h>
#include <stdint.h>

struct packet {

	uint8_t crc;
	uint8_t status;
	uint16_t payload;
	uint8_t bat;
	uint8_t sensor;
	uint8_t longAddr;
	uint8_t shortAddr;
	uint8_t addrMode;

};

struct packet_bitField {

	uint32_t crc : 			2;
	uint32_t status : 		1;
	uint32_t payload : 		12;
	uint32_t bat : 			3;
	uint32_t sensor : 		3;
	uint32_t longAddr : 	8;
	uint32_t shortAddr : 	2;
	uint32_t addrMode : 	1;

};

int main() {

	uint32_t packetVal;
	printf("Enter the 32bit packet value:");
	scanf("%X", &packetVal);

	//struct packet packet;
	struct packet_bitField packet; // using bit fields

	packet.crc = (uint8_t) packetVal & 0x3; // only need last 2 bits
	packet.status = (uint8_t) ( (packetVal >> 2) & 0x1 );
	packet.payload = (uint16_t) ( (packetVal >> 3) & 0xFFF );
	packet.bat = (uint8_t) ( (packetVal >> 15) & 0x7 );
	packet.sensor = (uint8_t) ( (packetVal >> 18) & 0x7 );
	packet.longAddr = (uint8_t) ( (packetVal >> 21) & 0xFF );
	packet.shortAddr = (uint8_t) ( (packetVal >> 29) & 0x3 );
	packet.addrMode = (uint8_t) ( (packetVal >> 31) & 0x1 );



    // Print each member of the packet
    printf("\nPacket Information:\n");
    printf("CRC: 0x%X\n", packet.crc);
    printf("Status: 0x%X\n", packet.status);
    printf("Payload: 0x%X\n", packet.payload);
    printf("Battery: 0x%X\n", packet.bat);
    printf("Sensor: 0x%X\n", packet.sensor);
    printf("Long Address: 0x%X\n", packet.longAddr);
    printf("Short Address: 0x%X\n", packet.shortAddr);
    printf("Address Mode: 0x%X\n", packet.addrMode);



	getchar();
	getchar();

	return 0;
}


