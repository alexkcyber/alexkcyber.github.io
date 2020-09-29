#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> 
#include <ctype.h>

//Code written by: Alexander Korobchuk

// Function prototypes.
void HammingMethod(char dataMessage[64]);
void HammingCorrection(char dataFrame[71]);
void CRCMethod(char bitStream[128], char generator[16]);
// End of function prototypes.


void main()
{

	// SELF-TESTING VARIABLES ************************************************************************
	char dataMessage[64] = "1101001100110101";
	char dataMessage2[64] = "z1010011bba0110101";
	char dataMessage3[64] = "1001000";
	char dataMessage4[64] = "1010101";
	char dataMessage5[64] = "11111111";

	char dataFrame[71] = "00110010000";
	char dataFrame1[71] = "00110010001";
	char dataFrame2[71] = "011110110011001110101";
	char dataFrame3[71] = "11110100101";
	char dataFrame4[71] = "111011101111";
	char dataFrame5[71] = "11110000101";
	char dataFrame6[71] = "100100110b01101s";

	char bitStream[128] = "1101011011011100";
	char generator[18] = "1101110111011101";
	char bitStream1[128] = "1101011011";
	char generator1[18] = "10011";
	char bitStream2[128] = "10011101";
	char generator2[18] = "1001";
	char bitStream3[128] = "100101abc";
	char generator3[18] = "10d1";
	// SELF-TESTING VARIABLES ************************************************************************

	// SELF-TESTING FUNCTION CALLS *******************************************************************
	printf("---Converting Bit Stream Into Frame w/ Hamming---------------------------------------------\n");
	printf("Original Message: ");
	for (int i = 0; i < strlen(dataMessage); i++)
	{
		printf("%c", dataMessage[i]);
	}
	printf("\n");
	HammingMethod(dataMessage);
	printf("\n");

	printf("Original Message: ");
	for (int i = 0; i < strlen(dataMessage2); i++)
	{
		printf("%c", dataMessage2[i]);
	}
	printf("\n");
	HammingMethod(dataMessage2);
	printf("\n");

	printf("Original Message: ");
	for (int i = 0; i < strlen(dataMessage3); i++)
	{
		printf("%c", dataMessage3[i]);
	}
	printf("\n");
	HammingMethod(dataMessage3);
	printf("\n");

	printf("Original Message: ");
	for (int i = 0; i < strlen(dataMessage4); i++)
	{
		printf("%c", dataMessage4[i]);
	}
	printf("\n");
	HammingMethod(dataMessage4);
	printf("\n");

	printf("Original Message: ");
	for (int i = 0; i < strlen(dataMessage5); i++)
	{
		printf("%c", dataMessage5[i]);
	}
	printf("\n");
	HammingMethod(dataMessage5);
	printf("\n");


	printf("---Single Bit Error Correction w/ Hamming--------------------------------------------------\n");
	printf("Received Data Frame: ");
	for (int i = 0; i < strlen(dataFrame); i++)
	{
		printf("%c", dataFrame[i]);
	}
	printf("\n");
	HammingCorrection(dataFrame);
	printf("\n");

	printf("Received Data Frame: ");
	for (int i = 0; i < strlen(dataFrame1); i++)
	{
		printf("%c", dataFrame1[i]);
	}
	printf("\n");
	HammingCorrection(dataFrame1);
	printf("\n");

	printf("Received Data Frame: ");
	for (int i = 0; i < strlen(dataFrame2); i++)
	{
		printf("%c", dataFrame2[i]);
	}
	printf("\n");
	HammingCorrection(dataFrame2);
	printf("\n");

	printf("Received Data Frame: ");
	for (int i = 0; i < strlen(dataFrame3); i++)
	{
		printf("%c", dataFrame3[i]);
	}
	printf("\n");
	HammingCorrection(dataFrame3);
	printf("\n");

	printf("Received Data Frame: ");
	for (int i = 0; i < strlen(dataFrame4); i++)
	{
		printf("%c", dataFrame4[i]);
	}
	printf("\n");
	HammingCorrection(dataFrame4);
	printf("\n");

	printf("Received Data Frame: ");
	for (int i = 0; i < strlen(dataFrame5); i++)
	{
		printf("%c", dataFrame5[i]);
	}
	printf("\n");
	HammingCorrection(dataFrame5);
	printf("\n");

	printf("Received Data Frame: ");
	for (int i = 0; i < strlen(dataFrame6); i++)
	{
		printf("%c", dataFrame6[i]);
	}
	printf("\n");
	HammingCorrection(dataFrame6);
	printf("\n\n");

	printf("---CRC for Error Detection-----------------------------------------------------------------\n");
	printf("Original bit stream: ");
	for (int i = 0; i < strlen(bitStream3); i++)
	{
		printf("%c", bitStream3[i]);
	}
	printf("\n");
	printf("Generator: ");
	for (int i = 0; i < strlen(generator3); i++)
	{
		printf("%c", generator3[i]);
	}
	printf("\n");
	CRCMethod(bitStream3, generator3);
	printf("\n\n");

	printf("Original bit stream: ");
	for (int i = 0; i < strlen(bitStream2); i++)
	{
		printf("%c", bitStream2[i]);
	}
	printf("\n");
	printf("Generator: ");
	for (int i = 0; i < strlen(generator2); i++)
	{
		printf("%c", generator2[i]);
	}
	printf("\n");
	CRCMethod(bitStream2, generator2);
	printf("\n");

	printf("Original bit stream: ");
	for (int i = 0; i < strlen(bitStream1); i++)
	{
		printf("%c", bitStream1[i]);
	}
	printf("\n");
	printf("Generator: ");
	for (int i = 0; i < strlen(generator1); i++)
	{
		printf("%c", generator1[i]);
	}
	printf("\n");
	CRCMethod(bitStream1, generator1);
	printf("\n");


	printf("Original bit stream: ");
	for (int i = 0; i < strlen(bitStream); i++)
	{
		printf("%c", bitStream[i]);
	}
	printf("\n");
	printf("Generator: ");
	for (int i = 0; i < strlen(generator); i++)
	{
		printf("%c", generator[i]);
	}
	printf("\n");
	CRCMethod(bitStream, generator);
	// SELF-TESTING FUNCTION CALLS *******************************************************************
	
	return 0;
}

// 1.1 CONVERTS A BIT STREAM OF A MESSAGE INTO A FRAME BY USING HAMMING CODING--------------------------------------------------------------------------------------------------------------

// Converts a dataMessage into a frame using Hamming coding. Prints the result.
void HammingMethod(char dataMessage[64]) 
{

	// Check to see if the string is a valid binary number.
	for (int i = 0; i < strlen(dataMessage); i++)
	{
		if (dataMessage[i] != '0' && dataMessage[i] != '1')
		{
			printf("%s", "Not a proper binary value!");
			printf("\n");
			return;
		}
	}
	

	int m = strlen(dataMessage); // Length of the dataMessage.
	int r = 1; // Number of parity bits required for the dataMessage. 1 is default.

	// Determine the number of parity bits needed.
	while ((pow(2, r)) <= (1 + m + r))
	{
		r++;
	}

	int parityPos[12]; // Stores where the position where the parity bits will be placed.
	int multiplier = 2; // Multiplies by 2 for each position of parity bit.

	// Calculates where each parity bit will be. Inserts in parityPos array.
	for (int i = 0; i < r; i++)
	{
		if (i == 0)
		{
			parityPos[i] = 0;
		}
		else
		{
			parityPos[i] = multiplier - 1; // Subtracts by one to get position in terms of an array.
			multiplier *= 2;
		}
	}

	char dataFrame[100]; // Initialize the dataFrame.
	int counter = 0;

	// Place the parity bits as zero as well as original dataMessage into one single dataFrame.
	for (int i = 0; i <= m+r; i++)
	{
		
		dataFrame[i] = dataMessage[counter];

		for (int j = 0; j < sizeof(parityPos) / sizeof(parityPos[0]); j++)
		{
			if (i == parityPos[j]) // If i is where a parity bit belongs.
			{
				dataFrame[i] = '0'; // Place the parity bit as a zero.
				counter -= 1;
			}
		}
		counter++;
	}

	// Determines if the parity bit should be 0 or 1.
	int iterator = 1;
	for (int i = 0; i < sizeof(parityPos) / sizeof(parityPos[0]); i++)
	{
		counter = 0;
		parityPos[i] += 1;
		iterator *= 2;

		for (int j = parityPos[i] - 1; j <= m + r; j += iterator) // Go through the dataFrame to count the 1's and 0's.
		{
			for (int k = 0; k < parityPos[i]; k++)
			{
				if (dataFrame[j + k] == '1') // If the dataFrame contained a 1, we increase the counter by 1.
				{
					counter++;
				}
			}
		}

		if (counter % 2 != 0) // If there is an odd amount of 1's, the dataFrame's parity bit becomes 1. Otherwise it stays as zero.
		{
			dataFrame[parityPos[i] - 1] = '1';
		}
	}
	
	printf("Final Frame: ");
	// Print out the entire dataFrame.
	for (int j = 0; j < strlen(dataFrame); j++) {
		printf("%c", dataFrame[j]);
	}
	printf("\n");
}
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 1.2 CORRECTS A SINGLE BIT ERROR OF A FRAME BY USING HAMMING AND OUTPUT THE PACKET--------------------------------------------------------------------------------------------------------

// Checks a dataFrame for any errors. Outputs the correct original message.
void HammingCorrection(char dataFrame[71])
{
	// Check to see if the string is a valid binary number. Print and return if it is not.
	for (int i = 0; i < strlen(dataFrame); i++)
	{
		if (dataFrame[i] != '0' && dataFrame[i] != '1')
		{
			printf("%s", "Not a proper binary value!");
			return;
		}
	}
	
	// Goes through the dataFrame and determines the bits that are parity bits.
	int parityPos[7]; // Holds the positions of all the parity bits in the dataFrame.
	int counter = 0;
	for (int i = 1; i < strlen(dataFrame); i *= 2)
	{
		parityPos[counter] = i;
		parityPos[counter] -= 1; // Subtracts one to get in terms of array.
		counter++;
	}

	// Checks all of the parity bits and determines if they are correct. If not, store which parity bit is not correct.
	int parityErrorPos[12]; // Pep.
	int iterator = 1;
	int pepCounter = 0; // Counts how many parity errors there are.
	for (int i = 0; i < sizeof(parityPos) / sizeof(parityPos[0]); i++)
	{
		counter = 0;
		parityPos[i] += 1;
		iterator *= 2;

		for (int j = parityPos[i] - 1; j <= strlen(dataFrame); j += iterator) // Go through the dataFrame to count the 1's and 0's.
		{
			for (int k = 0; k < parityPos[i]; k++)
			{
				if (dataFrame[j + k] == '1') // If the dataFrame contained a 1, we increase the counter by 1.
				{
					counter++;
				}
			}
		}

		if (counter % 2 != 0) // If there is an odd amount of 1's, there is an error at that parity bit. Store which parity bit is an error.
		{
			parityErrorPos[pepCounter] = parityPos[i];
			pepCounter++;
		}
	}

	// If the parityErrorCounter equals 0, this means there is no error with the parity bits. Print the original message and return.
	if (pepCounter == 0)
	{
		printf("There is no error!\n");
		printf("Original Message: ");

		// Go through the dataFrame and put a '-' where all of the parity bits are.
		for (int i = 0; i < sizeof(parityPos) / sizeof(parityPos[0]); i++)
		{

			if (parityPos[i] < 20 && parityPos[i] > 0) // Do this if statement because the unused values in the array are something like -402923871.
			{
				int position = parityPos[i] - 1;

				dataFrame[position] = '-';
			}
		}

		// Go through the dataFrame. If there is a '-', ignore it and move on. Prints the original data message.
		for (int i = 0; i < strlen(dataFrame); i++)
		{
			if (dataFrame[i] != '-')
			{
				printf("%c", dataFrame[i]);
			}
		}
		printf("\n");
		return;
	}


	// Determines which bit in the message contains an error.
	int errorPosition = 0; // errorPosition will hold which position bit is an error.
	for (int k = 0; k < pepCounter; k++)
	{
		errorPosition += parityErrorPos[k]; // Add all of error bits to find the position containing an error.
	}

	printf("Error found in position: %d\n", errorPosition);

	// Flip the error bit.
	if (dataFrame[errorPosition - 1] == '0')
	{
		dataFrame[errorPosition - 1] = '1';
	}
	else
	{
		dataFrame[errorPosition - 1] = '0';
	}

	// Print the corrected dataFrame.
	printf("Corrected data frame is: ");
	for (int i = 0; i < strlen(dataFrame); i++)
	{
		printf("%c", dataFrame[i]);
	}

	// Replaces all of the parity bits with a '-'.
	for (int i = 0; i < sizeof(parityPos) / sizeof(parityPos[0]); i++)
	{
		if (parityPos[i] < 20 && parityPos[i] > 0)
		{
			int position = parityPos[i] - 1;

			dataFrame[position] = '-';
		}
	}

	// Print the original data message. If there is a '-', skip it.
	printf("\n");
	printf("Original Message: ");
	for (int i = 0; i < strlen(dataFrame); i++)
	{
		if (dataFrame[i] != '-') 
		{
			printf("%c", dataFrame[i]);
		}
		
	}
	printf("\n");
}
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 2. CRC for Error Detection

// Takes a bitStream and a generator and then prints the transmitted bit stream with its CRC checksum bits.

void CRCMethod(char bitStream[128], char generator[16])
{
	int genLength = strlen(generator); // The length of the generator.
	int origLength = strlen(bitStream); // Length of the original bitStream.

	// Check to see if the string is a valid binary number.
	for (int i = 0; i < strlen(bitStream); i++)
	{
		if (bitStream[i] != '0' && bitStream[i] != '1')
		{
			printf("%s", "Not a proper binary value!");
			return;
		}
	}

	// Append genLength - 1 0's to the end of the bitStream.
	for (int i = 0; i < genLength - 1; i++)
	{
		bitStream[strlen(bitStream)] = '0';
	}

	int mesLength = strlen(bitStream); // The length of the message after appending 0's.

	int position = 0; // The position we are at in our message. Default is zero.

	char holder[50]; // Holds genLength bits of the bitStream. They will be XOR'd with the generator.

	// Place the first genLength bits into the holder. Increase position each bit so we know where we are at on the bitStream.
	for (int i = 0; i < genLength; i++)
	{
		holder[i] = bitStream[i] - '0';
		position += 1;
	}

	int counter = genLength; // Counter will be used to determine how many bits will be needed to append to the holder from the bitStream.
	bool goOn = true; // Keeps us looping.
	bool finish = false; // Tells us when to finish.

	// Performs binary division until it reaches a remainder. Appends the remainder to the bitStream and prints.
	START:while (goOn)
	{
		// If we have reached a remainder.
		if (finish == true)
		{
			goOn = false; // We must set goOn to false.
			
			counter = genLength - counter; // Counter becomes how many bits we need to append.

			int onePos = 0; // Stores the position we find zero. Go through the holder until we hit zero.
			for (int i = 0; i < genLength; i++)
			{
				if (holder[i] == 1)
				{
					onePos = i;
					break;
				}
			}

			// Remove the beginning 0's from the holder.
			for (int i = 0; i <= counter; i++)
			{
				holder[i] = holder[onePos];
				onePos += 1;
			}

			printf("Remainder: ");
			for (int i = 0; i < genLength - 1; i++)
			{
				printf("%d", holder[i]);
			}
			printf("\n");

			// Appends the bits (which are the remainder) to the end of the bitStream.
			for (int i = 0; i < genLength - 1; i++)
			{
				bitStream[origLength + i] = holder[i];
			}

			// We must do - '0' to make the chars into ints.
			for (int i = 0; i < origLength; i++)
			{
				bitStream[i] = bitStream[i] - '0';
			}

			printf("Final Frame: ");
			// Print the final message.
			for (int i = 0; i < mesLength; i++)
			{
				printf("%d", bitStream[i]);
			}
			printf("\n");
			break;
		}
		else // If we have not reached a remainder.
		{

			counter = genLength; // Counter gets established as the genLength.

			// XOR the holder with the generator.
			for (int i = 0; i < genLength; i++)
			{
				holder[i] = holder[i] ^ generator[i] - '0';
			}

			// Find where the first 1 happens. We subtract from counter each time we hit a 0.
			for (int i = 0; i < genLength; i++)
			{
				if (holder[i] == 0)
				{
					counter -= 1;
				}
				else 
				{
					break;
				}
			}

			counter = genLength - counter; // Counter becomes how many numbers need to be appended.

			// If we are at a position in the bitStream where position + counter is greater than the total mesLength, we do not have enough bits to append!
			// Therefore we have found the remainder.
			if ((position + counter) >= mesLength)
			{
				finish = true; //Set finish as true.
				goto START; // Jump to the start.
			}

			// If the counter is equal the the genLength, this means we need to append genLength more bits.
			// Example: if after XOR'd, the holder is 0000 and the genLength is 4, in this case we would need to append 4 bits, so they are equal. Simply append genLength more.
			if (counter == genLength)
			{
				for (int i = 0; i < genLength; i++)
				{
					holder[i] = bitStream[position] - '0';
					position += 1;
				}
			}
			else // If the amount of bits we need is not equal to the genLength.
			{
				// Place however many bits we need into the holder.
				for (int i = 0; i < counter; i++)
				{
					if (position < mesLength)
					{
						holder[genLength + i] = bitStream[position] - '0';
						position += 1;
					}
				}

				// We have appended however many bits we need, but we still have 0's in the front.
				// Find where the first zero is in the holder, and store its position in onePos.
				int onePos = 0;
				for (int i = 0; i < genLength; i++)
				{
					if (holder[i] == 1)
					{
						onePos = i;
						break;
					}
				}

				// Go through the holder deleting the 0's from the beginning.
				for (int i = 0; i < genLength; i++)
				{
					holder[i] = holder[onePos];
					onePos += 1;
				}
			}
		}
	}
}
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
