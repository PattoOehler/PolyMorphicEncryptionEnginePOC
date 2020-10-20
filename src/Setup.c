#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

	int Location_Encryption_Value = 4122;
	int ByteCodeBeginning_Location = 8192;

	
	//This is the compliled code from Data.asm
	char bytecode[] = "\xb8\x01\x00\x00\x00\xbf\x01\x00\x00\x00\x5e\x48\x83\xee\x0c\xba\x0c\x00\x00\x00\x0f\x05\xb8\x3c\x00\x00\x00\xbf\x00\x00\x00\x00\x0f\x05\x48\x65\x6c\x6c\x6f\x20\x57\x6f\x72\x6c\x64\x0a";
	int bytecode_length = 46;
	
	srand(time(NULL));
	char random_encryption_byte[1] ;
	random_encryption_byte[0] =  (rand() % 254) +1;

	
	
	int i = 0;
	for(i; i<bytecode_length; i++) {
	
		bytecode[i] += random_encryption_byte[0];
	}
	
	
	
	
	FILE *file = fopen( "Needs_Setup", "r+b");
	
	fseek(file, Location_Encryption_Value, SEEK_SET);
	fwrite(random_encryption_byte, 1, 1, file);
	
	fseek(file, ByteCodeBeginning_Location, SEEK_SET);
	fwrite(bytecode, bytecode_length, 1, file);
	
	fclose(file);
	
	printf("Done\n");

}
