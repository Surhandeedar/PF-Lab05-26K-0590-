#include <stdio.h>

int main() {
    int user_permissions = 0;
    int choice, perm_choice;
    
    const int READ = 1;    
    const int WRITE = 2;   
    const int EXEC = 4;    
    const int ADMIN = 8;  

    printf("=== ENTERPRISE PERMISSION MANAGEMENT SYSTEM ===\n");
    printf("1. Add/Combine Permission (Bitwise OR |)\n");
    printf("2. Check Permission Status (Bitwise AND &)\n");
    printf("3. Toggle Permission (Bitwise XOR ^)\n");
    printf("4. Remove Permission (Bitwise AND with NOT & ~)\n");
    printf("5. Display Current Permissions\n");
    printf("6. Exit\n");

    printf("\nSelect an operation (1-6): ");
    scanf("%d", &choice);

    printf("\n--- Select Permission Flag ---\n");
    printf("1. Read (1)\n2. Write (2)\n3. Execute (4)\n4. Admin (8)\n");
    printf("Enter permission choice: ");
    scanf("%d", &perm_choice);

    
    int mask = 0;
    switch (perm_choice) {
        case 1: mask = READ; break;
        case 2: mask = WRITE; break;
        case 3: mask = EXEC; break;
        case 4: mask = ADMIN; break;
        default: 
            printf("Invalid permission selection.\n");
            return 1;
    }

    
    switch (choice) {
        case 1:
        
            user_permissions = user_permissions | mask;
            printf("\n[SUCCESS] Permission added.\n");
            break;

        case 2:
            
            if (user_permissions & mask) {
                printf("\n[CHECK] User HAS this permission.\n");
            } else {
                printf("\n[CHECK] User DOES NOT have this permission.\n");
            }
            break;

        case 3:
            
            user_permissions = user_permissions ^ mask;
            printf("\n[SUCCESS] Permission toggled.\n");
            break;

        case 4:
        
            user_permissions = user_permissions & (~mask);
            printf("\n[SUCCESS] Permission removed.\n");
            break;

        case 5:
        
            printf("\nCurrent Raw Permission Value: %d\n", user_permissions);
            break;

        default:
            printf("Invalid menu operation.\n");
            return 1;
    }
    printf("\n============================================\n");
    printf("         UPDATED PERMISSION PROFILE         \n");
    printf("============================================\n");
    printf("Decimal Value : %d\n", user_permissions);
    printf("Read    (0001): %s\n", (user_permissions & READ)  ? "GRANTED" : "DENIED");
    printf("Write   (0010): %s\n", (user_permissions & WRITE) ? "GRANTED" : "DENIED");
    printf("Execute (0100): %s\n", (user_permissions & EXEC)  ? "GRANTED" : "DENIED");
    printf("Admin   (1000): %s\n", (user_permissions & ADMIN) ? "GRANTED" : "DENIED");
    printf("============================================\n");

    return 0;
}
