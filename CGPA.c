#include <stdio.h>

int main() {
    int num_courses;
    printf("Enter the number of courses: ");
    scanf("%d", &num_courses);

    float total_credits = 0;
    float total_grade_points = 0;

    for (int i = 1; i <= num_courses; i++) {
        float credits, grade;
        printf("Enter credits and grade for course %d (separated by space): ", i);
        scanf("%f %f", &credits, &grade);
        
        total_credits += credits;
        total_grade_points += credits * grade;
    }

    float cgpa = total_grade_points / total_credits;
    printf("CGPA: %.2f\n", cgpa);

    return 0;
}
