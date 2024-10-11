#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the phone number is valid (exactly 10 digits)
int is_valid_phone_number(const char* phone_number) {
    if (strlen(phone_number) != 10) return 0;  // Must be 10 characters long
    for (int i = 0; i < 10; i++) {
        if (!isdigit(phone_number[i])) return 0;  // All characters must be digits
    }
    return 1;  // Valid phone number
}

int main() {
    int employee_id, month_leaves, years_worked, rating;
    char employee_name[50], phone_number[15];
    float basic_salary = 50000.0, professional_tax, final_salary, leave_deduction;
    int joining_year, current_year = 2024;

    // Input employee ID
    printf("Enter Employee ID: ");
    scanf("%d", &employee_id);
    if (employee_id <= 0) {
        printf("Invalid Employee ID\n");
        return 1;
    }

    // Input employee name (without limiting input length)
    printf("Enter Employee Name: ");
    scanf("%s", employee_name);  // This reads only one word before any space

    // Input valid phone number
    while (1) {
        printf("Enter Telephone Number (10 digits): ");
        scanf("%14s", phone_number);  // Limit input to 14 characters to avoid buffer overflow
        if (is_valid_phone_number(phone_number)) break;
        else printf("Invalid phone number. Please enter exactly 10 digits.\n");
    }

    // Input number of leaves taken in the current month
    printf("Enter the Number of Leaves taken in the current month: ");
    scanf("%d", &month_leaves);

    // Input joining year
    printf("Enter Joining Year: ");
    scanf("%d", &joining_year);

    // Calculate years worked
    years_worked = current_year - joining_year;

    // Set rating based on years worked
    if (years_worked > 7) rating = 5;
    else if (years_worked > 5) rating = 4;
    else if (years_worked > 3) rating = 3;
    else if (years_worked > 1) rating = 2;
    else rating = 1;

    // Calculate professional tax (5% of basic salary)
    professional_tax = 0.05 * basic_salary;

    // Calculate leave deduction (if more than 1 leave taken in the current month)
    int excess_leaves = month_leaves > 1 ? month_leaves - 1 : 0;
    leave_deduction = excess_leaves > 0 ? (basic_salary / 30) * excess_leaves : 0;

    // Calculate final salary after deductions
    final_salary = basic_salary - professional_tax - leave_deduction;

    // Output salary slip
    printf("\n\n*********************************************************************************\n");
    printf("MMCOE Pvt. Ltd.                           Employee Salary Slip - October 2024\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("Employee ID        : %d\n", employee_id);
    printf("Employee Name      : %s\n", employee_name);
    printf("Phone Number       : %s\n", phone_number);
    printf("Years Worked       : %d\n", years_worked);

    // Display Employee Rating with stars
    printf("Employee Rating    : ");
    for (int i = 0; i < rating; i++) printf("★ ");
    for (int i = rating; i < 5; i++) printf("☆ ");
    printf("(%d/5)\n", rating);

    printf("\n---------------------- Salary Details -----------------------\n");
    printf("Basic Salary       : Rs %.2f\n", basic_salary);
    printf("Professional Tax   : Rs %.2f\n", professional_tax);
    printf("Leave Deduction    : Rs %.2f (for %d excess leaves)\n", leave_deduction, excess_leaves);
    printf("--------------------------------------------------------------\n");
    printf("Final Salary       : Rs %.2f\n", final_salary);
    printf("--------------------------------------------------------------\n");

    // Thank you note
    printf("\nThank you for your dedication and hard work!\n");
    printf("***********************************************************************\n");

    return 0;
}
