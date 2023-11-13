#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

enum FlagType { INTEGER, BOOLEAN };

struct Flag {
    enum FlagType type;
    union {
        int intValue;
        bool boolValue;
    } value;
};

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    struct Flag flag;
};

struct User users[MAX_USERS];
int numUsers = 0;
char flagInput[10];
void registerUser() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached. Cannot register new user.\n");
        return;
    }

    struct User newUser;

    printf("Enter username: ");
    scanf("%s", newUser.username);

    printf("Enter password: ");
    scanf("%s", newUser.password);

    printf("Enter flag (0 or 1 for integer, ( true , yes ) or  ( false , no ) for boolean): ");
    scanf("%s", flagInput);

    if (strcmp(flagInput, "0") == 0 || strcmp(flagInput, "1") == 0) {
        newUser.flag.type = INTEGER;
        newUser.flag.value.intValue = atoi(flagInput);
    }
    else if (strcmp(flagInput, "true") == 0 || strcmp(flagInput, "yes") == 0) {
        newUser.flag.type = BOOLEAN;
        newUser.flag.value.boolValue = true;
    }
    else if (strcmp(flagInput, "false") == 0 || strcmp(flagInput, "no") == 0) {
        newUser.flag.type = BOOLEAN;
        newUser.flag.value.boolValue = false;
    }
    else {
        printf("Invalid flag input. Defaulting to 0 (integer).\n");
        newUser.flag.type = INTEGER;
        newUser.flag.value.intValue = 0;
    }

    users[numUsers++] = newUser;

    printf("User registered successfully.\n");
}

void loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    if ((strcmp(flagInput, "true") == 0 || strcmp(flagInput, "yes") == 0 || strcmp(flagInput, "1") == 0)) {
        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        for (int i = 0; i < numUsers; i++) {
            if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
                if (users[i].flag.type == INTEGER && users[i].flag.value.intValue == 0) {
                    printf("You are not active. Login failed.\n");
                }
                else if (users[i].flag.type == BOOLEAN && users[i].flag.value.boolValue == false) {
                    printf("You are not active. Login failed.\n");
                }
                else {
                    printf("Login successful. Welcome, %s!\n", username);
                }
                return;
            }
        }
    }
    else {
        printf("You are not active. Login failed.\n");
    }
    
    printf("Invalid username or password. Login failed.\n");
}


int main() {
    int choice;

    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("See You Soon...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}
// if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
