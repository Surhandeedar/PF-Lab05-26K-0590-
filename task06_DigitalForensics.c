#include <stdio.h>

int main() {
    int category_choice;
    float evidence_size_gb;
    int is_encrypted;
    int has_sensitive_info;
    int packet_size;
    int priority_level = 0; 
    
    printf("=== DIGITAL FORENSICS EVIDENCE CLASSIFICATION ===\n");
    printf("Select Evidence Category:\n");
    printf("1. Mobile Device\n2. Computer System\n3. Network Capture\n4. Cloud Account\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &category_choice);

    printf("\nEnter Evidence Size (in GB): ");
    scanf("%f", &evidence_size_gb);

    printf("Is encryption detected? (1 for Yes, 0 for No): ");
    scanf("%d", &is_encrypted);

    printf("Does it contain sensitive information? (1 for Yes, 0 for No): ");
    scanf("%d", &has_sensitive_info);

    printf("\n============================================\n");
    printf("        EVIDENCE EVALUATION REPORT          \n");
    printf("============================================\n");
    printf("Category            : ");

    switch (category_choice) {
        case 1: 
            printf("Mobile Device\n");
            printf("Extraction Status   : %s\n", 
                   is_encrypted ? "SPECIALIZED EXTRACTION REQUIRED" : "Standard Extraction");
            break;

        case 2: 
            printf("Computer System\n");
            
            if (evidence_size_gb > 500.0 && is_encrypted) {
                priority_level = 1; 
            }
            printf("Storage Flag        : %s\n", 
                   (evidence_size_gb > 500.0) ? "Large Storage (> 500 GB)" : "Standard Storage");
            break;

        case 3: 
            printf("Network Capture\n");
            printf("Enter Packet Size (bytes): ");
            scanf("%d", &packet_size);

            
            switch (packet_size % 2000) {
                case 0:
                    printf("Packet Data Type    : Structured Capture\n");
                    break;
                default:
                    printf("Packet Data Type    : Irregular Traffic Data\n");
                    break;
            }
            break;

        case 4: 
            printf("Cloud Account\n");
            
            if (has_sensitive_info && is_encrypted) {
                printf("Legal Flag          : LEGAL AUTHORIZATION VERIFICATION REQUIRED\n");
            } else {
                printf("Legal Flag          : Standard Clearance\n");
            }
            break;

        default:
            printf("Invalid Category\n");
            return 1;
    }

    int case_code = ((int)evidence_size_gb + category_choice) % 3;
    char lab_section;
    switch (case_code) {
        case 0: lab_section = 'A'; break;
        case 1: lab_section = 'B'; break;
        case 2: lab_section = 'C'; break;
        default: lab_section = 'U'; break;
    }

    printf("Encryption Detected : %s\n", is_encrypted ? "YES" : "NO");
    printf("Sensitive Content   : %s\n", has_sensitive_info ? "YES" : "NO");
    printf("Assigned Priority   : %s\n", priority_level ? "HIGH PRIORITY" : "STANDARD PRIORITY");
    printf("Lab Allocation Code : Section %c\n", lab_section);
    printf("============================================\n");

    return 0;
}
