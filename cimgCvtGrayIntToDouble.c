#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <math.h>
#define MAX_RUNS 30

int compare_matrices(double *f_matrix, double *checker_matrix, int total) {
    int pass = 1;
	int i;
    for ( i = 0; i < total; i++) {
        double diff = f_matrix[i] - checker_matrix[i];

        if (diff > 0) {
            printf("Mismatch at index %d: ASM = %lf | C = %lf\n", 
                   i, f_matrix[i], checker_matrix[i]);
            pass = 0;
            break;
        }
    }

    if (pass) {
        printf("TEST PASSED");
    } else {
        printf("TEST FAILED\n");
    }

    return pass;
}


extern void asmimgCvtGrayIntToDouble(int total, uint8_t *matrix, double *f_matrix);

int main (){
	
	int rows;
    int cols;
    
    double C_time[MAX_RUNS];
	double ASM_time[MAX_RUNS];
	
	printf("Enter rows and column size: ");
    scanf("%d %d", &rows, &cols);
    printf("\n");
    
    int total = rows * cols;
    
    
    //initiate uint8 matrix
    uint8_t* matrix = malloc((rows * cols) * sizeof(uint8_t));
    //initialize ASM double matrix
    double* f_matrix = malloc(rows * cols * sizeof(double));
    //initialize C double matrix
    double* checker_matrix = malloc(rows * cols * sizeof(double));
    
    int i;
    int j;
    srand(time(NULL));
    uint8_t num;
    
    clock_t start, end;
	double asm_cpu_time_used;
	double c_cpu_time_used;
	
	int run;
	
	for (run = 0; run < MAX_RUNS; run++) {
    
	    printf("Run %d: \n", run + 1);
	    
//	    printf("\nInput: \n", run + 1);
    	
    	// Initialize uint8 matrix
	    for (i = 0; i < rows * cols; i++){
	    	num = rand() % 256;
	        matrix[i] = num;
		}
	
		// print initial matrix
//		for (i = 0; i < rows; i++) {
//		        for (j = 0; j < cols; j++)
//		            printf("%5u ", matrix[i * cols + j]);
//		        printf("\n");
//		}
		
	//	printf("\nMatrix values and addresses:\n");
	//
	//	for (i = 0; i < rows; i++) {
	//	    for (j = 0; j < cols; j++) {
	//	        int index = i * cols + j;
	//	
	//	        printf("matrix[%d][%d] = %3u  | address = %p\n",
	//	               i, j,
	//	               matrix[index],
	//	               (void*)&matrix[index]);
	//	    }
	//	}
	
		//execute ASM program
		start = clock();
		asmimgCvtGrayIntToDouble(total, matrix, f_matrix);
		end = clock();
		
		// ASM program output
//		printf("\nASM output Matrix: \n");
//		for (i = 0; i < rows; i++) {
//		        for (j = 0; j < cols; j++)
//		            printf("%lf ", f_matrix[i * cols + j]);
//		        printf("\n");
//		}
		
		asm_cpu_time_used = (((double)(end - start)) / CLOCKS_PER_SEC) * 1000.0;
		
		ASM_time[run] = asm_cpu_time_used;
		
		// execute C program
		start = clock();
		for (i = 0; i < rows * cols; i++) {
		    checker_matrix[i] = (double)matrix[i] / 255.0;
		}
		end = clock();
		
		c_cpu_time_used = (((double)(end - start)) / CLOCKS_PER_SEC) * 1000.0;
		
		C_time[run] = c_cpu_time_used;
		
//		printf("\nC output Matrix: \n");
//		for (i = 0; i < rows; i++) {
//		        for (j = 0; j < cols; j++)
//		            printf("%lf ", checker_matrix[i * cols + j]);
//		        printf("\n");
//		}
//		
//		printf("\n");
	
		compare_matrices(f_matrix, checker_matrix, total);	
		printf("\nASM Execution time: %f ms\n", asm_cpu_time_used);
		printf("C Execution time: %f ms\n", c_cpu_time_used);
		printf("========================================\n");
	}
	
	// --- Compute average times ---
    double asm_avg = 0.0, c_avg = 0.0;
    for ( i = 0; i < MAX_RUNS; i++) {
        asm_avg += ASM_time[i];
        c_avg += C_time[i];
    }
    asm_avg /= MAX_RUNS;
    c_avg /= MAX_RUNS;

    printf("\n--- Average Execution Time over %d runs ---\n", MAX_RUNS);
    printf("ASM Average: %f ms\n", asm_avg);
    printf("C   Average: %f ms\n", c_avg);
    printf("\n");

    free(matrix);
    free(f_matrix);
    free(checker_matrix);
	
	
	
	
	
	
	return 0;
}


