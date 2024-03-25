#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/UART/UART_Interface.h"
#include "../include/APP/BluetoothLogin.h"
#include <util/delay.h>

//#include <string.h>

extern User users[MAX_USERS];
// extern u8 user1[];
// extern u8 pass1[];

// Define the array of users

u8 userFound = 0;
u8 userIndex;

	u8 checkPassword(u8* passwordPtr) {
		MUART_voidSendStringSyncBlocking("Type again:\n");
		MUART_voidReadStringSyncBlocking(passwordPtr);
		//MUART_voidSendStringSyncBlocking(passwordPtr);

			if (userIndex == IndexOut)
			{
				MUART_voidReadStringSyncBlocking((u8*)"ERROR: user Index not defined\n");
				return 0; // user not found
			}
		//for (u8 i = 0; i < MAX_USERS; i++) {
			if (areStringsEqual(users[userIndex].password, passwordPtr)) {
				return 1; // pass correct
			}
			else if(areStringsEqual("E", passwordPtr)){
				return 2; // exit
			}
		//}
		return 0; // pass is not  correct
	}


	u8 checkPass(u8* user_pass1, u8* written_password) {
		// for (u8 i = 0; i < MAX_USERS; i++) {

		// 	if (areStringsEqual(user1, username) == 0) {
		// 		userIndex = i;
		// 		userFound = 1;
		// 	}
		// }

		// if (userFound)
		// {
			// MUART_voidReadStringSyncBlocking(user_pass1);
			// MUART_voidReadStringSyncBlocking((u8*)" ");
			// MUART_voidReadStringSyncBlocking(written_password);


			if (areStringsEqual(user_pass1, written_password)) {
					MUART_voidReadStringSyncBlocking((u8*)"it returned 1 so its equal\n");

					return 1; // Password is correct
				} else {
					MUART_voidReadStringSyncBlocking((u8*)"check:pass is wrong\n");
					return 0; // Password is incorrect
				}
			
		// }

		MUART_voidSendStringSyncBlocking((u8*)"check:usr not found\n");

		return 0; // Username does not exist
	}

	// u8 checkPassword(u8* username, u8* password) {
	// 	for (u8 i = 0; i < MAX_USERS; i++) {
	// 		if (strcmp(users[i].username, username) == 0) {
	// 			if (strcmp(users[i].password, password) == 0) {
	// 				return 1; // Password is correct
	// 			} else {
	// 				return 0; // Password is incorrect
	// 			}
	// 		}
	// 	}
	// 	return 0; // Username does not exist
	// }


    	u8 checkUsername(u8* username) {
		for (u8 i = 0; i < MAX_USERS; i++) {
			if (areStringsEqual(users[i].username, username)) {
				userIndex = i;
				return 1; // Username exists
			}
		}
		userIndex = IndexOut;
		return 0; // Username does not exist
	}

	void welcome_msg(void){
		MUART_voidSendStringSyncBlocking((u8*)"Hi! Welcome agian!\n");
		_delay_ms(100);
		MUART_voidSendStringSyncBlocking((u8*)"Options:\n 'P': 1st LED on \nK: 1st LED off\nM: 2nd LED on\nN: 2nd LED off\nD: Door On \n C: Close door \nW: Window on\nQ:Window Close\nO: Log out\n");
	}


	u8 areStringsEqual(u8* str1, u8* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (*str1 - *str2) == 0 ? 1 : 0;
}
