

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../include/MCAL/EXTI/EXTI_Interface.h"
#include "../include/MCAL/GIE/GIE_Interface.h"
#include "../include/MCAL/ADC/ADC_Interface.h"
#include "../include/MCAL/UART/UART_Interface.h"
#include "../include/APP/BluetoothLogin.h"
#include "../include/HAL/MOTORS/MOTORS_Interface.h"



// Define the structure for user credentials

// Define the array of users and their credentials
User users[MAX_USERS] = {
    {"user1", "pass1"},
    {"user2", "pass2"},
    {"user3", "pass3"},
    {"user4", "pass4"},
    {"user5", "pass5"}
};

// u8 user1[] = "user1";
// u8 pass1[] = "pass1";
//extern User users[MAX_USERS];

u8 username[MAX_USERNAME_LENGTH];
u8 password[MAX_PASSWORD_LENGTH];



int main()
{
	MDIO_voidInit(); 
	MUART_voidInit();
	MADC_voidInit();
	HLCD_voidInit();
	HMOTORS_voidServoInit();
	//u16 tempReading ;
	u8 Recieved_u8Data;
	u8 LoginFlag = 0;
	u8 correctPass = 0;
	u8 WlcFLag = 0;
	u8 reloginFlag = 0;
	//u8 failedPassAttempts = 0;
	u8 checkPass;
	u8* usernamePtr = username;
	u8* passwordPtr = password;


	MUART_voidSendStringSyncBlocking((u8*)"Welcome to our system\n");
	MUART_voidSendStringSyncBlocking((u8*)"\nEnter 'L' to login\n");


	_delay_ms(500);

	while (1)
	{
		Recieved_u8Data =  MUART_u8ReadByteSyncNonBlocking();
		if(LoginFlag == 0){

			if (reloginFlag)
			{
				MUART_voidSendStringSyncBlocking((u8*)"Welcome to our system\n");
				MUART_voidSendStringSyncBlocking((u8*)"\nEnter 'L' to login\n");
				reloginFlag = 0;
			}
			
				if (Recieved_u8Data == 'L') {
                	//HLCD_VoidSendString((u8*)"Enter username:");
					MUART_voidSendStringSyncBlocking((u8*)"Enter username:");

					MUART_voidReadStringSyncBlocking(usernamePtr);
					
					MUART_voidSendByteSyncBlocking('\n');


					if (checkUsername(usernamePtr)) {
						for (int i = 0; i < 5; i++) {  // Loop for 5 password attempts
							MUART_voidSendStringSyncBlocking((u8*)"Enter password:\n");

							MUART_voidReadStringSyncBlocking(password);
						
							checkPass = checkPassword(passwordPtr);

							if (checkPass == 1) {
								MUART_voidSendStringSyncBlocking((u8*)"Login successful\n");
								correctPass = 1;
								LoginFlag = 1;
								break;  // Exit the loop if the password is correct
							}else if (checkPass == 2)//if user wanted to go to username input
							{
								LoginFlag = 0;
								correctPass = 0;
								WlcFLag = 0;
								reloginFlag = 1;
								break; // Exit the loop if the user wants to go back to the username input
							}
							

							 else {
								MUART_voidSendStringSyncBlocking((u8*)"Password is incorrect\n");

								MUART_voidSendStringSyncBlocking((u8*)"Remaining attempts: ");
								MUART_voidSendByteSyncBlocking((4 - i) + '0');  // Remaining attempts start from 4
								MUART_voidSendStringSyncBlocking((u8*)"\n"); 
								MUART_voidSendStringSyncBlocking((u8*)"Enter E= to Exit or ...\n");

								if (i == 4) {  // If it's the 5th attempt, raise emergency mode flag
									MDIO_void_SetPinDirection(PORTD, PIN7, OUTPUT);
									MDIO_void_SetPinValue(PORTD, PIN7, DIO_SET);
									_delay_ms(2000);
									MDIO_void_SetPinValue(PORTD, PIN7, DIO_RESET);
									_delay_ms(2000);
									LoginFlag = 2; //Emergency mode
									break;  // Exit the loop
								}
							}
						}
					} 
					else {
						MUART_voidSendStringSyncBlocking((u8*)"Username does not exist\n");
						reloginFlag = 1;
						MUART_voidSendStringSyncBlocking(username);

					}

				}
		}

		else if(LoginFlag == 1 && correctPass){ // Logged in

				if(!WlcFLag){
					welcome_msg();
					WlcFLag = 1;
				}

				switch (Recieved_u8Data)
				{
				case 'P':
					//LED A0 on
					MDIO_void_SetPinValue(PORTA, PIN0, DIO_SET);
					break;
				case 'K':
					//LED A0 off
					MDIO_void_SetPinValue(PORTA, PIN0, DIO_RESET);	
					break;
				case 'M':
					//LED A1 on
					MDIO_void_SetPinValue(PORTA, PIN1, DIO_SET);
					break;
				case 'N':
					//LED A1 off
					MDIO_void_SetPinValue(PORTA, PIN1, DIO_RESET);
					break;
				case 'D':
					MUART_voidSendStringSyncBlocking((u8*)"Start Stepper forward!\n");
					HMOTORS_voidStepperForward();
					MUART_voidSendStringSyncBlocking((u8*)"End Stepper!forward\n");
					break;
				case 'C':
					MUART_voidSendStringSyncBlocking((u8*)"Start Stepper back!\n");
					HMOTORS_voidStepperBackward();
					MUART_voidSendStringSyncBlocking((u8*)"End Stepper back!\n");
					break;
				case 'L':
					MUART_voidSendStringSyncBlocking((u8*)"Logged In Already type 'O' to log out\n");
					break;
				case 'O':
					//log out
					LoginFlag = 0;
					correctPass = 0;
					WlcFLag = 0;
					reloginFlag = 1;
					MUART_voidSendStringSyncBlocking((u8*)"Logged out\n");
					break;
				case 'W':

					HMOTORS_voidServoSetAngle(180);

					MUART_voidSendStringSyncBlocking((u8*)"Windows On\n");
					_delay_ms(1000);
					break;
				case 'Q':
					HMOTORS_voidServoSetAngle(0);

					MUART_voidSendStringSyncBlocking((u8*)"Windows off\n");
					_delay_ms(1000);
					break;

				
				}
				



				
			
		}else if(LoginFlag == 2){ //Emergency mode
			MUART_voidSendStringSyncBlocking((u8*)"Emergency mode\n");
			//buzzer on
			

			MUART_voidSendStringSyncBlocking((u8*)"Enter 'E' to exit\n");
			
			//break;
			Recieved_u8Data = MUART_u8ReadByteSyncBlocking();

			if (Recieved_u8Data == 'E')
				{
					MUART_voidSendStringSyncBlocking((u8*)"Exiting emergency mode\n");
					LoginFlag = 0;
					correctPass = 0;
					WlcFLag = 0;
					reloginFlag = 1;
				}

		}

		


	}

}
		





