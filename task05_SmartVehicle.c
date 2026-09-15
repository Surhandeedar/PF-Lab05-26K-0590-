#include <stdio.h>

int main() {
    int subsystem_choice, severity_choice;
    int mileage, is_under_warranty;
    int is_high_priority = 0;

    printf("=== VEHICLE DIAGNOSTIC TERMINAL ===\n");
    printf("Select Vehicle Subsystem:\n");
    printf("1. Engine\n2. Transmission\n3. Braking System\n4. Electrical System\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &subsystem_choice);

    printf("\nSelect Diagnostic Severity:\n");
    printf("1. Minor\n2. Moderate\n3. Critical\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &severity_choice);

    printf("\nEnter Vehicle Mileage (km): ");
    scanf("%d", &mileage);

    printf("Is the vehicle under warranty? (1 for Yes, 0 for No): ");
    scanf("%d", &is_under_warranty);

    printf("\n============================================\n");
    printf("           DIAGNOSTIC SERVICE REPORT        \n");
    printf("============================================\n");
    printf("Recommended Action : ");

    switch (subsystem_choice) {
        case 1: 
            switch (severity_choice) {
                case 1: printf("Requires inspection.\n"); break;
                case 2: printf("Requires maintenance.\n"); break;
                case 3: printf("Requires immediate shutdown.\n"); break;
                default: printf("Invalid severity level.\n"); return 1;
            }
            break;

        case 2: 
            switch (severity_choice) {
                case 1: printf("May be monitored.\n"); break;
                case 2: printf("Requires service within 24 hours.\n"); break;
                case 3: printf("Requires towing.\n"); break;
                default: printf("Invalid severity level.\n"); return 1;
            }
            break;

        case 3: 
            switch (severity_choice) {
                case 1: printf("Requires immediate inspection.\n"); break;
                case 2: printf("Prohibit long-distance driving.\n"); break;
                case 3: printf("Prohibit vehicle operation.\n"); break;
                default: printf("Invalid severity level.\n"); return 1;
            }
            break;

        case 4: 
            switch (severity_choice) {
                case 1: printf("May be ignored temporarily.\n"); break;
                case 2: printf("Requires battery diagnostics.\n"); break;
                case 3: printf("Requires complete electrical isolation.\n"); break;
                default: printf("Invalid severity level.\n"); return 1;
            }
            break;

        default:
            printf("Invalid subsystem choice.\n");
            return 1;
    }

    is_high_priority = (severity_choice == 3) || (mileage > 200000);
    
    int service_code_num = (mileage + subsystem_choice) % 4;
    char service_code;
    switch (service_code_num) {
        case 0: service_code = 'A'; break;
        case 1: service_code = 'B'; break;
        case 2: service_code = 'C'; break;
        case 3: service_code = 'D'; break;
        default: service_code = 'U'; break;
    }

    printf("Priority Status    : %s\n", is_high_priority ? "HIGH PRIORITY" : "STANDARD PRIORITY");
    printf("Maintenance Alert  : %s\n", (mileage > 200000) ? "High Mileage Alert (Priority Increased)" : "Normal Mileage");
    printf("Warranty Coverage  : %s\n", is_under_warranty ? "Covered (Services may be free)" : "Out of Warranty");
    printf("Service Code       : Code %c\n", service_code);
    printf("============================================\n");

    return 0;
}
