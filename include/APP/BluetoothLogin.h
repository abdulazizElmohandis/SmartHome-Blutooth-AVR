#ifndef BluetoothLogin_H_
#define BluetoothLogin_H_


#define MAX_USERS 5
#define IndexOut 10

// Define the maximum length of username and password
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
		

typedef struct {
	char username[MAX_USERNAME_LENGTH];
	char password[MAX_PASSWORD_LENGTH];
} User;

u8 checkPass(u8* user_pass1, u8* written_password);

u8 checkUsername(u8* username);

u8 areStringsEqual(u8* str1, u8* str2);

void welcome_msg(void);


u8 checkPassword(u8* passwordPtr);



#endif /* BluetoothLogin_H_ */