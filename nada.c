#include <stdio.h>
#include <string.h>

typedef struct {
    char username[50];
    char password[50];
} User;

// Array of users for our system
User users[100];
// Keep track the number of registered users
int registeredUsers = 0;

void registerUser() {
    printf("Enter username: ");
    scanf("%s", users[registeredUsers].username);
    
    printf("Enter password: ");
    scanf("%s", users[registeredUsers].password);
    
    printf("User %s was successfully registered.\n", users[registeredUsers].username);
    registeredUsers++;
}

void authenticateUser() {
    char username[50], password[50];
    
    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    for (int i = 0; i < registeredUsers; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            printf("User %s authenticated.\n", users[i].username);
            return;
        }
    }
    
    printf("Username and password do not match any registered users.\n");
}

int main() {
    int option;
    
    while (1) {
        printf("Press '1' to Register, '2' to Authenticate, or '3' to Quit:\n");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                registerUser();
                break;
            case 2:
                authenticateUser();
                break;
            case 3:
                printf("Goodbye.\n");
                return 0;
        }
    }
}
