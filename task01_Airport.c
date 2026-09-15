#include <stdio.h>
int main() {
    int category_choice, flight_choice;
    int age, doc_status;
    float actual_weight, permitted_weight = 0.0;

    printf("Select Passenger Category:\n");
    printf("1. Adult\n2. Student\n3. Senior Citizen\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &category_choice);

    printf("\nSelect Flight Destination Type:\n");
    printf("1. Domestic\n2. International\n");
    printf("Enter choice (1-2): ");
    scanf("%d", &flight_choice);
    printf("\nEnter Passenger Age: ");
    scanf("%d", &age);
    
    printf("Enter Actual Baggage Weight (kg): ");
    scanf("%f", &actual_weight);
    
    printf("Are travel documents valid? (1 for Valid, 0 for Invalid): ");
    scanf("%d", &doc_status);

    
    switch (category_choice) {
        case 1: 
            switch (flight_choice) {
                case 1: permitted_weight = 20.0; break;
                case 2: permitted_weight = 30.0; break;
                default:
                    printf("\nInvalid flight destination choice.\n");
                    return 1;
            }
            break;
        case 2: 
            switch (flight_choice) {
                case 1: permitted_weight = 25.0; break;
                case 2: permitted_weight = 35.0; break;
                default:
                    printf("\nInvalid flight destination choice.\n");
                    return 1;
            }
            break;
        case 3: 
            switch (flight_choice) {
                case 1: permitted_weight = 30.0; break;
                case 2: permitted_weight = 40.0; break;
                default:
                    printf("\nInvalid flight destination choice.\n");
                    return 1;
            }
            break;
        default:
            printf("\nInvalid passenger category choice.\n");
            return 1;
    }
    char verification_cat;
    switch (age % 5) {
        case 0: verification_cat = 'A'; break;
        case 1: verification_cat = 'B'; break;
        case 2: verification_cat = 'C'; break;
        case 3: verification_cat = 'D'; break;
        case 4: verification_cat = 'E'; break;
        default: verification_cat = 'U'; break; 
    }
    int priority_assistance = (category_choice == 3) || (category_choice == 2 && flight_choice == 2);

    
    printf("\n============================================\n");
    printf("       PASSENGER VERIFICATION SUMMARY       \n");
    printf("============================================\n");
    
    
    printf("Passenger Category  : %s\n", 
           (category_choice == 1) ? "Adult" : (category_choice == 2) ? "Student" : "Senior Citizen");
    printf("Destination Type    : %s\n", 
           (flight_choice == 1) ? "Domestic" : "International");
    

    printf("Permitted Allowance : %.2f kg\n", permitted_weight);
    printf("Actual Weight       : %.2f kg\n", actual_weight);
    
    
    printf("Document Status     : %s\n", doc_status ? "Valid" : "Invalid");
    
    
    printf("Verification Code   : Category %c\n", verification_cat);
    printf("Priority Assistance : %s\n", priority_assistance ? "Granted" : "Not Eligible");
    
    
    printf("Boarding Status     : ");
    if (!doc_status) {
        printf("DENIED BOARDING (Invalid Documents)\n");
    } else if (actual_weight <= permitted_weight) {
        printf("PROCEED TO NORMAL BOARDING\n");
    } else {
        printf("REFERRED FOR ENHANCED BAGGAGE SCREENING\n");
    }
    printf("============================================\n");

    return 0;
}
