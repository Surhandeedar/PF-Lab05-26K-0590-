#include <stdio.h>

int main() {
    int dept_choice, sub_condition;
    int age, heart_rate, conscious_status, severity;
    float temp;
    
    printf("Select Emergency Department:\n");
    printf("1. General Emergency\n2. Cardiology\n3. Neurology\n4. Trauma\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &dept_choice);

    printf("\nEnter Patient Age: ");
    scanf("%d", &age);

    printf("Enter Heart Rate (bpm): ");
    scanf("%d", &heart_rate);

    printf("Enter Body Temperature (*C): ");
    scanf("%f", &temp);

    printf("Is the patient conscious? (1 for Conscious, 0 for Unconscious): ");
    scanf("%d", &conscious_status);

    printf("Enter Severity Level (1 to 10): ");
    scanf("%d", &severity);

    int dept_emergency = 0;

    switch (dept_choice) {
        case 1: 
            printf("\nGeneral Emergency Condition (1: Standard, 2: Severe Disturbance): ");
            scanf("%d", &sub_condition);
            switch (sub_condition) {
                case 1: dept_emergency = 0; break;
                case 2: dept_emergency = 1; break;
                default: dept_emergency = 0; break;
            }
            break;

        case 2: 
            
            printf("\nCardiology Condition (1: Normal Rhythm, 2: Abnormal HR/Arrhythmia): ");
            scanf("%d", &sub_condition);
            switch (sub_condition) {
                case 1: dept_emergency = (heart_rate < 50 || heart_rate > 120); break;
                case 2: dept_emergency = 1; break;
                default: dept_emergency = 0; break;
            }
            break;

        case 3: 
            
            printf("\nNeurology Condition (1: Alert, 2: Unconscious/Stroke Symptoms): ");
            scanf("%d", &sub_condition);
            switch (sub_condition) {
                case 1: dept_emergency = (!conscious_status); break;
                case 2: dept_emergency = 1; break;
                default: dept_emergency = 0; break;
            }
            break;

        case 4: 
            
            printf("\nTrauma Condition (1: Minor Trauma, 2: Severe Trauma): ");
            scanf("%d", &sub_condition);
            switch (sub_condition) {
                case 1: dept_emergency = (severity >= 7); break;
                case 2: dept_emergency = 1; break;
                default: dept_emergency = 0; break;
            }
            break;

        default:
            printf("\nInvalid department choice.\n");
            return 1;
    }

    int is_critical = ((heart_rate < 50 || heart_rate > 120) && !conscious_status);

    int temp_alert = (temp < 36.0 || temp > 38.0);

    int is_senior = (age >= 65);

    char case_category;
    switch ((age + heart_rate) % 4) {
        case 0: case_category = 'A'; break;
        case 1: case_category = 'B'; break;
        case 2: case_category = 'C'; break;
        case 3: case_category = 'D'; break;
        default: case_category = 'U'; break;
    }

    printf("\n============================================\n");
    printf("        HOSPITAL EMERGENCY TRIAGE REPORT    \n");
    printf("============================================\n");

    printf("Department          : %s\n", 
           (dept_choice == 1) ? "General Emergency" : 
           (dept_choice == 2) ? "Cardiology" : 
           (dept_choice == 3) ? "Neurology" : "Trauma");

    printf("Patient Age         : %d (%s)\n", age, is_senior ? "Senior Priority" : "Standard Age Group");
    printf("Heart Rate          : %d bpm\n", heart_rate);
    printf("Body Temperature    : %.1f *C (%s)\n", temp, temp_alert ? "ALERT: Abnormal" : "Normal");
    printf("Consciousness       : %s\n", conscious_status ? "Conscious" : "Unconscious");
    printf("Severity Level      : %d/10\n", severity);
    printf("Case Category       : Category %c\n", case_category);
    printf("Dept Emergency Flag : %s\n", dept_emergency ? "YES" : "NO");

    printf("--------------------------------------------\n");
    printf("TRIAGE DECISION     : ");

    if (is_critical) {
        printf("CRITICAL - IMMEDIATE MEDICAL ATTENTION REQUIRED\n");
    } else if (dept_emergency || is_senior || temp_alert) {
        printf("HIGH PRIORITY - ASSIGNED FOR FURTHER ASSESSMENT\n");
    } else {
        printf("ROUTINE - ASSIGNED TO ROUTINE MEDICAL ASSESSMENT\n");
    }

    printf("============================================\n");

    return 0;
}
