/* Author:      Giang Tran (giangtran2@my.unt.edu)
 * Date:        02/23/2022
 * Instructor:  Dr. Rubenia Borge
 * Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "bubble.h"

typedef struct classStats {
    float mean;
    float min;
    float max;
    float median;
    char* name;
} classStats;

int main() {
    const int NUM_STUDENT = 19;
    char title[20];
    classStats stats;
    FILE* inFile = NULL;    //file pointer
    int i = 0;
    student* studentList[NUM_STUDENT];
    
    inFile = fopen("grades","r");
    if (inFile == NULL) {
        printf("Could not open file grades");
        return -1;
    }
    
    //allocating the memory each item in student list
    for (int i = 0; i < NUM_STUDENT; i++) {
        studentList[i] = (student*) malloc(sizeof(student));
    }
    
    //read the first line: title
    fscanf(inFile, "%s", title);
    printf("%s\n", title);
    
    for (int i = 0; i < NUM_STUDENT; i++) {
        fscanf(inFile, "%s %s", studentList[i]->first, studentList[i]->last);
        fscanf(inFile, "%d %d %d", &studentList[i]->exam1, &studentList[i]->exam2, &studentList[i]->exam3);
//        *studentList++;
//
        printf("%s %s", studentList[i]->first, studentList[i]->last);
        printf("%d %d %d \n", studentList[i]->exam1, studentList[i]->exam2, studentList[i]->exam3);
    }
    
    fclose(inFile);
    return 0;
}
