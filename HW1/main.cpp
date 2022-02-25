/* Author:      Giang Tran (giangtran2@my.unt.edu)
 * Date:        02/20/2022
 * Instructor:  Dr. Rubenia Borge
 * Description: The program uses two data structures to read in student grade data, perform some calculations, sort the students in ascending order by average, determine some class statistics, and output the results.
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
    student* studentList[NUM_STUDENT];
    float totalAverage = 0; //total average of all students
    
    inFile = fopen("grades","r");
    if (inFile == NULL) {
        printf("Could not open file grades");
        return -1;
    }
    
    //allocating the memory each item in student list
    for (int i = 0; i < NUM_STUDENT; i++) {
        studentList[i] = (student*) malloc(sizeof(student));
        studentList[i]->first = (char*) malloc (40 * sizeof(char));
        studentList[i]->last = (char*) malloc (40 * sizeof(char));
    }
    
    //read the first line: title
    fscanf(inFile, "%s", title);
    
    for (int i = 0; i < NUM_STUDENT; i++) {
        fscanf(inFile, "%s %s", studentList[i]->first, studentList[i]->last);
        fscanf(inFile, "%d %d %d", &studentList[i]->exam1, &studentList[i]->exam2, &studentList[i]->exam3);
        
        studentList[i]->mean = (float)(studentList[i]->exam1 + studentList[i]->exam2 + studentList[i]->exam3) / 3;
        
        totalAverage += studentList[i]->mean;
    }
    
    fclose(inFile); //close input file
    
    bubble(studentList, NUM_STUDENT);
    
    stats.mean = totalAverage / NUM_STUDENT;
    stats.min  = studentList[0]->mean;
    stats.max  = studentList[NUM_STUDENT - 1]->mean;
    stats.median = studentList[NUM_STUDENT / 2]->mean;
    
    //output the digit line
    for(int i = 0; i < 6; i++) {
        printf("1234567890");
    }
    
    printf("\n");
    printf("%s MEAN: %7.2f MIN: %7.2f MAX: %7.2f MEDIAN: %7.2f\n", title, stats.mean, stats.min, stats.max, stats.median);
    
    for (int i = 0; i < NUM_STUDENT; i++) {
        //testing the results
        printf("%10s %10s", studentList[i]->first, studentList[i]->last);
        printf("%7.2f\n", studentList[i]->mean);
    }
    
    //free the dynamic memory
    for (int i = 0; i < NUM_STUDENT; i++) {
        free(studentList[i]->first);
        free(studentList[i]->last);
        free(studentList[i]);
    }
    
    
    return 0;
}
