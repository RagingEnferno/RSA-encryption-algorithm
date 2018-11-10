#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;


int primeFirstElement, primeSecondElement;

int dp, e, rf, objectFlag;
// Encrypt and decrypt number with temporary
long int encryptValue[50], decryptValue[50], temporaryValue[50], j;
// Encrypt and decrypt message
char encryptedMessage[50], decryptedMessage[50];


char messageOriginalContent[100];

// Code snippet to check prime number
int primeCheckMethod(long int num)
{


	for (int w = 2; w <= sqrt(num); w++)
	{
		// Checks if the number is divisible by loop variable
		if (num % w == 0)
			// Return 0 for not prime
			return 0;
	}
	// Returns 1 for prime
	return 1;
}


long int cd(long int data)
{
	
	long int v = 1;

	while (1)
	{
		// Here we will Increase the v value by e
		v = v + e;
		// here we will Checks if the v value is divisible by data
		if (v % data == 0)
			// Returns the quotient
			return(v / data);
	}
}

// code snippet to generate encryption key
void encryptionKey()
{
	// Initialize v to zero
	int v = 0;

	for (rf = 2; rf < e; rf++)
	{
		// Checks if e is divisible by loop value rf
		if (e % rf == 0)
			// Continue the loop
			continue;
		// Otherwise call he function to check rf is prime or not
		// set the objectFlag to function return value 0 or 1
		objectFlag = primeCheckMethod(rf);

		// Checks if the objectFlag value is 1 and
		// loop variable rf is not equals to first and second prime number entered by the user
		if (objectFlag == 1 && rf != primeFirstElement && rf != primeSecondElement)
		{
			// Assigns the loop variable rf value to encryptValue of v index position
			encryptValue[v] = rf;
			// Calls the function CD with encryptValue v index position value
			// Stores the return value in objectFlag
			objectFlag = cd(encryptValue[v]);
			// Checks if objectFlag value is greater than 0
			if (objectFlag > 0)
			{
				// Stores objectFlag value in decryptValue array's v index position
				decryptValue[v] = objectFlag;
				// Increase the v value by one
				v++;
			}// End of inner if condition
			 // Checks if the v value is 99 then come out of the loop
			if (v == 99)
				break;
		}
	}// End of for loop
}

// Function to encrypt the message
void encrypt()
{
	long int hp, ju, key = encryptValue[0], v, objectLength;
	rf = 0;

	objectLength = strlen(messageOriginalContent);


	while (rf != objectLength)
	{
		// Stores the decrypt message array rf index position data in hp
		hp = decryptedMessage[rf];
		// Subtract 96 from hp and stores it in hp
		hp = hp - 96;
		// Initialize v to one
		v = 1;
		// Loops till key value
		for (j = 0; j < key; j++)
		{
			// Multiplies v with hp and stores the result in v
			v = v * hp;
			// Divides v with dp and stores the remainder in v
			v = v % dp;
		}
		temporaryValue[rf] = v;
		// Updates ju by assigning v added to 96
		ju = v + 96;
		// Stores the ju value at rf index position of encrypted message array
		encryptedMessage[rf] = ju;
		// Increase the counter by one
		rf++;
	}
	
	encryptedMessage[rf] = -1;

	cout << "\n\nTHE ENCRYPTED MESSAGE IS\n";
	// Loops till -1
	for (rf = 0; encryptedMessage[rf] != -1; rf++)

		cout << encryptedMessage[rf];
}


void decrypt()
{
	long int hp, ju, key = decryptValue[0], v;
	rf = 0;
	// Loops till -1
	while (encryptedMessage[rf] != -1)
	{

		ju = temporaryValue[rf];
		// initialize v to 1
		v = 1;


		for (j = 0; j < key; j++)
		{
			// Multiplies v with ju and stores the result in v
			v = v * ju;
			// Divides v with dp and stores the remainder in v
			v = v % dp;
		}
		// Updates hp by assigning v added to 96
		hp = v + 96;

		decryptedMessage[rf] = hp;
		// Increase the counter by one
		rf++;
	}


	decryptedMessage[rf] = -1;

	cout << "\n\nTHE DECRYPTED MESSAGE IS\n";
	// Loops till -1
	for (rf = 0; decryptedMessage[rf] != -1; rf++)
		// Displays the decrypted message
		cout << decryptedMessage[rf];
	cout << endl;
}// End of function

 // main function definition
int main()
{

	primeFirstElement = 17;
	cout << "Num 1 : " << primeFirstElement;
	primeSecondElement = 13;
	cout << "\nNum 2: " <<primeSecondElement;

	
	// Checks if objectFlag is zero or first prime number is equals to second prime number then error message and stop


	fflush(stdin);

	cout << "\nEnter original message to encrypt: ";
	cin.getline(messageOriginalContent, 100);


	for (rf = 0; messageOriginalContent[rf] != '\0'; rf++)
		// Assigns message
		decryptedMessage[rf] = messageOriginalContent[rf];
	// Multiplies first and second prime number and stores it in dp
	dp = primeFirstElement * primeSecondElement;
	// Multiplies first and second prime number minus one and stores it in e
	e = (primeFirstElement - 1) * (primeSecondElement - 1);
	// Calls the function to generate encryption key
	encryptionKey();

	cout << "\nPossible values of e and d are: \n";
	// Loops till j minus one times
	for (rf = 0; rf < j - 1; rf++)
		cout << "\n" << encryptValue[rf] << "\e" << decryptValue[rf];

	encrypt();
	// Calls the function to decrypt
	decrypt();

	system("pause");
	//return 0;
}
