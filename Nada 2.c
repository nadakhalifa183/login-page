#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Structure to store user information with an active flag
struct User {
    char username[50];
    char password[50];
    union {
        int active;  // 1 for active, 0 for inactive
        bool isActive;  // You can use a boolean flag instead of an integer
    };
};

// Function to register a new user
void registerUser(struct User users[], int *userCount) {
    if (*userCount >= 10) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }

    struct User newUser;
    printf("Enter a username: ");
    scanf("%s", newUser.username);

    // Check if the username already exists
    for (int i = 0; i < *userCount; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists. Please choose a different username.\n");
            return;
        }
    }

    printf("Enter a password: ");
    scanf("%s", newUser.password);

    newUser.active = 1; // Set the user as active

    users[*userCount] = newUser;
    (*userCount)++;
    printf("Registration successful!\n");
}

// Function to log in a user
void loginUser(struct User users[], int userCount) {
    char username[50];
    char password[50];
    printf("Enter your username: ");
    scanf("%s", username);

    int found = 0;
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Enter your password: ");
            scanf("%s", password);
            if (strcmp(users[i].password, password) == 0) {
                if (users[i].active == 1) {
                    printf("Login successful! Welcome, %s!\n", username);
                    found = 1;
                } else {
                    printf("User is inactive. Please contact support.\n");
                }
                break;
            } else {
                printf("Incorrect password.\n");
            }
        }
    }

    if (!found) {
        printf("User not found. Please register or check your credentials.\n");
    }
}

int main() {
    struct User users[10];  // Assuming we can store up to 10 users
    int userCount = 0;

    int choice;
    while (1) {
        printf("1. Register\n2. Login\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser(users, &userCount);
                break;
            case 2:
                loginUser(users, userCount);
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
