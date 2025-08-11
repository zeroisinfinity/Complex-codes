#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int bits;
    int *binary;
} input;

int* minimum(int* num1, int* num2) {
    return (*num1 <= *num2) ? num1 : num2;
}

int AND(input* inp_alpha_ptr, input* inp_beta_ptr) {
    int iter;
    int* min_bits = minimum(&inp_alpha_ptr->bits, &inp_beta_ptr->bits);
    
    int result = 0;  // Initialize result to zero

    for (iter = 0; iter < *min_bits; iter++) {
        int bit_a = inp_alpha_ptr->binary[inp_alpha_ptr->bits - *min_bits + iter];
        int bit_b = inp_beta_ptr->binary[inp_beta_ptr->bits - *min_bits + iter];
        
        // Perform AND operation and accumulate into the result integer
        result = (result << 1) | (bit_a & bit_b);
    }
    
    return result;
}

int main() {
    input alpha, beta;

    // Get binary inputs for alpha
    printf("Enter the number of bits for alpha - ");
    scanf("%d", &alpha.bits);
    alpha.binary = malloc(sizeof(int) * alpha.bits);
    for (int assign = 0; assign < alpha.bits; assign++) {
        printf("Enter the %d-th bit for alpha - ", assign + 1);
        scanf("%d", &alpha.binary[assign]);
    }

    // Get binary inputs for beta
    printf("Enter the number of bits for beta - ");
    scanf("%d", &beta.bits);
    beta.binary = malloc(sizeof(int) * beta.bits);
    for (int assign = 0; assign < beta.bits; assign++) {
        printf("Enter the %d-th bit for beta - ", assign + 1);
        scanf("%d", &beta.binary[assign]);
    }

    // Call the AND function and print the logical result as an integer
    int logical_result = AND(&alpha, &beta);
    printf("\nLogical AND result is - %d\n", logical_result);

    // Free allocated memory
    free(alpha.binary);
    free(beta.binary);

    return 0;
}



/*
typedef struct {
    int bits;
    int *binary;
} input;

int* minimum(int* num1, int* num2) {
    return (*num1 <= *num2) ? num1 : num2;
}

char* AND(input* inp_alpha_ptr, input* inp_beta_ptr) {
    int iter;
    int* min_bits = minimum(&inp_alpha_ptr->bits, &inp_beta_ptr->bits);
    
    // Allocate memory for the result string, including space for the null terminator
    char* logic_str = malloc(sizeof(char) * (*min_bits + 1));

    for (iter = 0; iter < *min_bits; iter++) {
        int bit_a = inp_alpha_ptr->binary[inp_alpha_ptr->bits - *min_bits + iter];
        int bit_b = inp_beta_ptr->binary[inp_beta_ptr->bits - *min_bits + iter];
        
        // Perform AND operation and store result as '1' or '0' in the result string
        logic_str[iter] = (bit_a == 1 && bit_b == 1) ? '1' : '0';
    }
    logic_str[*min_bits] = '\0';  // Null-terminate the string
    return logic_str;
}

int main() {
    input alpha, beta;

    // Get binary inputs for alpha
    printf("Enter the number of bits for alpha - ");
    scanf("%d", &alpha.bits);
    alpha.binary = malloc(sizeof(int) * alpha.bits);
    for (int assign = 0; assign < alpha.bits; assign++) {
        printf("Enter the %d-th bit for alpha - ", assign + 1);
        scanf("%d", &alpha.binary[assign]);
    }

    // Get binary inputs for beta
    printf("Enter the number of bits for beta - ");
    scanf("%d", &beta.bits);
    beta.binary = malloc(sizeof(int) * beta.bits);
    for (int assign = 0; assign < beta.bits; assign++) {
        printf("Enter the %d-th bit for beta - ", assign + 1);
        scanf("%d", &beta.binary[assign]);
    }

    // Call the AND function and print the logical result as a binary string
    char* logical_result = AND(&alpha, &beta);
    printf("\nLogical AND result is - %s\n", logical_result);

    // Free allocated memory
    free(alpha.binary);
    free(beta.binary);
    free(logical_result);  // Free the result string

    return 0;
}

// Logic gates implementations using C

/*typedef struct {
    int bits;
    int *binary;
} input;

int* maximum(int* num1, int* num2) {
    return (*num1 >= *num2) ? num1 : num2;
}

int* minimum(int* num1, int* num2) {
    return (*num1 <= *num2) ? num1 : num2;
}

int AND(input* inp_alpha_ptr, input* inp_beta_ptr) {
    int iter;
    int* min_bits = minimum(&inp_alpha_ptr->bits, &inp_beta_ptr->bits);
    char* logic_str = malloc(sizeof(char) * (*min_bits + 1));

    for (iter = 0; iter < *min_bits; iter++) {
        int bit_a = inp_alpha_ptr->binary[inp_alpha_ptr->bits - *min_bits + iter];
        int bit_b = inp_beta_ptr->binary[inp_beta_ptr->bits - *min_bits + iter];
        
        logic_str[iter] = (bit_a == 1 && bit_b == 1) ? '1' : '0';
    }
    logic_str[*min_bits] = '\0';
    printf("\n%s\n", logic_str);

    int result = 0;
    int len_logic_str = strlen(logic_str);
    for (int cast_indx = 0; cast_indx < len_logic_str; cast_indx++) {
        result += (logic_str[cast_indx] - '0') << (len_logic_str - cast_indx - 1);
    }
    free(logic_str);
    return result;
}

// Define OR, XOR, XNOR, NAND, NOR, and NOT functions similarly

int main() {
    input alpha, beta;

    printf("Enter the number of bits for alpha - ");
    scanf("%d", &alpha.bits);
    alpha.binary = malloc(sizeof(int) * alpha.bits);
    for (int assign = 0; assign < alpha.bits; assign++) {
        printf("Enter the %d number bit - ", assign + 1);
        scanf("%d", &alpha.binary[assign]);
    }

    printf("Enter the number of bits for beta - ");
    scanf("%d", &beta.bits);
    beta.binary = malloc(sizeof(int) * beta.bits);
    for (int assign = 0; assign < beta.bits; assign++) {
        printf("Enter the %d number bit - ", assign + 1);
        scanf("%d", &beta.binary[assign]);
    }

    int logical_result = AND(&alpha, &beta);
    printf("\nLogical AND result is - %d\n", logical_result);

    free(alpha.binary);
    free(beta.binary);
    return 0;
}

















/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#include <stdio.h>
#include <stdlib.h>

// Define the struct for input bits
typedef struct {
    int bits;            // Number of bits in the binary number
    int *binary;         // Pointer to hold the binary digits
} input;

// Helper functions to find maximum and minimum of two integers
int* maximum(int* num1, int* num2) {
    return (*num1 >= *num2) ? num1 : num2;
}

int* minimum(int* num1, int* num2) {
    return (*num1 <= *num2) ? num1 : num2;
}

// AND operation function
int AND(input* inp_alpha_ptr, input* inp_beta_ptr) {
    int min_bits = *minimum(&inp_alpha_ptr->bits, &inp_beta_ptr->bits);
    int result = 0;

    for (int iter = 0; iter < min_bits; iter++) {
        // Calculate corresponding bits in the binary
        int bit_a = (*inp_alpha_ptr->binary)[inp_alpha_ptr->bits - min_bits + iter];
        int bit_b = (*inp_beta_ptr->binary)[inp_beta_ptr->bits - min_bits + iter];
        
        // Perform AND operation and use bit-shift for positioning the result
        result = (result << 1) | (bit_a & bit_b);
    }
    return result;
}

// OR operation function
int OR(input* inp_alpha_ptr, input* inp_beta_ptr) {
    int min_bits = *minimum(&inp_alpha_ptr->bits, &inp_beta_ptr->bits);
    int result = 0;

    for (int iter = 0; iter < min_bits; iter++) {
        int bit_a = (*inp_alpha_ptr->binary)[inp_alpha_ptr->bits - min_bits + iter];
        int bit_b = (*inp_beta_ptr->binary)[inp_beta_ptr->bits - min_bits + iter];
        
        // Perform OR operation and use bit-shift
        result = (result << 1) | (bit_a | bit_b);
    }
    return result;
}

// NAND operation function
int NAND(input* inp_alpha_ptr, input* inp_beta_ptr) {
    int min_bits = *minimum(&inp_alpha_ptr->bits, &inp_beta_ptr->bits);
    int result = 0;

    for (int iter = 0; iter < min_bits; iter++) {
        int bit_a = (*inp_alpha_ptr->binary)[inp_alpha_ptr->bits - min_bits + iter];
        int bit_b = (*inp_beta_ptr->binary)[inp_beta_ptr->bits - min_bits + iter];
        
        // Perform NAND operation and use bit-shift
        result = (result << 1) | (~(bit_a & bit_b) & 1);
    }
    return result;
}

// Main function for testing
int main() {
    // Allocate and input first binary number
    input alpha;
    printf("Enter the number of bits for alpha: ");
    scanf("%d", &alpha.bits);
    alpha.binary = malloc(alpha.bits * sizeof(int));
    for (int i = 0; i < alpha.bits; i++) {
        printf("Enter bit %d for alpha: ", i + 1);
        scanf("%d", &alpha.binary[i]);
    }

    // Allocate and input second binary number
    input beta;
    printf("Enter the number of bits for beta: ");
    scanf("%d", &beta.bits);
    beta.binary = malloc(beta.bits * sizeof(int));
    for (int i = 0; i < beta.bits; i++) {
        printf("Enter bit %d for beta: ", i + 1);
        scanf("%d", &beta.binary[i]);
    }

    // Perform NAND operation and print result
    int result = NAND(&alpha, &beta);
    printf("\nNAND result is: %d\n", result);

    // Free allocated memory
    free(alpha.binary);
    free(beta.binary);

    return 0;
}



/*int main(){//b13
    
 
    /*struct in{
    int (*binary)[];
    };
    struct in *i = malloc(sizeof(struct in));
    
    //i = malloc(sizeof(struct in));
    i -> binary = malloc(sizeof(int)*6);
    //int (*a)[] = i->binary;
    //a = malloc(sizeof(int)*6);
    
    for(int j = 0 ; j < 6 ; j++){
       //scanf("%d",&(*a)[i]);
       scanf("%d", &(*i->binary)[j]);
       }
       
     for(int k = 0 ; k < 6 ; k++){
      //printf("%d ",(*a)[i]);
     printf("%d ", (*i->binary)[k]);
      }
      
      char logic_str[] = {'1','0','0','0','1','1','\0'};
         int len_logic_str = strlen(logic_str);
       int cast_indx = 0;
       int result = 0;
    while(logic_str[cast_indx]!='\0'){//b12
            result += (logic_str[cast_indx] - '0')*pow(10,len_logic_str - cast_indx - 1);
            cast_indx ++;
    }//b12
    printf("\n%d",result);
     //printf("%d ",*((int*)a + i));
    
        
    printf("\n");*/
    
    /*int r = 0;
    r = 1<<1;
    printf("%d",r);*/
    //return 0;
//}//b13*/


