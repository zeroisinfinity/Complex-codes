#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Logic gates implementations using C
//gcc -o logical_gates logical_gates.c -lm ............. to run

typedef struct {int bits; //b1
                int (*binary)[];
                } input; //b1
   

int* maximum(int* num1, int* num2){//b4
    if(*num1 >= *num2){//b5
        return num1;
    }//b5
    else{//b6
        return num2;
    }//b6
}//b4

int* minimum(int* num1, int* num2){//b4
    if(*num1 <= *num2){//b5
        return num1;
    }//b5
    else{//b6
        return num2;
    }//b6
}//b4

int AND(input* inp_alpha_ptr , input* inp_beta_ptr){//b2
    
    int iter;
    int* max_bits = maximum(&inp_alpha_ptr -> bits , &inp_beta_ptr -> bits);
    int* min_bits = minimum(&inp_alpha_ptr -> bits , &inp_beta_ptr -> bits);
    char* logic_str = malloc(sizeof(char)*(*min_bits));
    for(iter = 0 ; iter < *min_bits ; iter++){//b3

              if((*inp_alpha_ptr -> binary)[inp_alpha_ptr -> bits - *min_bits + iter] == 1){//b8
                        if((*inp_beta_ptr -> binary)[inp_beta_ptr -> bits - *min_bits + iter] == 1){//b9
                                  logic_str[iter] = '1';
                                  }//b9
                        else{//b10
                                  logic_str[iter] = '0';
                                  }//b10
                        }//b8
              else{//b11
                        logic_str[iter] = '0';
                        }//b11
                   
    }//b3
    logic_str[*min_bits] = '\0';
    printf("\n%s\n",logic_str);
    int len_logic_str = strlen(logic_str);
    int cast_indx = 0;
    int result = 0;
    while(logic_str[cast_indx]!='\0'){//b12
            result += (logic_str[cast_indx] - '0')*pow(10.00,len_logic_str - cast_indx - 1);
            cast_indx ++;
    }//b12
    free(logic_str);
    logic_str = NULL;
    return result;
}//b2  


int OR(input* inp_alpha_ptr , input* inp_beta_ptr){//b2
    
    int iter;
    int* max_bits = maximum(&inp_alpha_ptr -> bits , &inp_beta_ptr -> bits);
    int* min_bits = minimum(&inp_alpha_ptr -> bits , &inp_beta_ptr -> bits);
    char* logic_str = malloc(sizeof(char)*(*min_bits));
    for(iter = 0 ; iter < *min_bits ; iter++){//b3

              if((*inp_alpha_ptr -> binary)[inp_alpha_ptr -> bits - *min_bits + iter] == 0){//b8
                        if((*inp_beta_ptr -> binary)[inp_beta_ptr -> bits - *min_bits + iter] == 0){//b9
                                  logic_str[iter] = '0';
                                  }//b9
                        else{//b10
                                  logic_str[iter] = '1';
                                  }//b10
                        }//b8
              else{//b11
                        logic_str[iter] = '1';
                        }//b11
                   
    }//b3
    logic_str[*min_bits] = '\0';
      printf("\n%s\n",logic_str);
    int len_logic_str = strlen(logic_str);
    int cast_indx = 0;
    int result = 0;
    while(logic_str[cast_indx]!='\0'){//b12
            result += (logic_str[cast_indx] - '0')*pow(10,len_logic_str - cast_indx - 1);
            cast_indx ++;
    }//b12
    free(logic_str);
    logic_str = NULL;
    return result;
}//b2  

int XOR(input* inp_alpha_ptr , input* inp_beta_ptr){//b2
    
    int iter;
    int* max_bits = maximum(&inp_alpha_ptr -> bits , &inp_beta_ptr -> bits);
    int* min_bits = minimum(&inp_alpha_ptr -> bits , &inp_beta_ptr -> bits);
    char* logic_str = malloc(sizeof(char)*(*min_bits));
    for(iter = 0 ; iter < *min_bits ; iter++){//b3

              if((*inp_alpha_ptr -> binary)[inp_alpha_ptr -> bits - *min_bits + iter] != (*inp_beta_ptr -> binary)[inp_beta_ptr -> bits - *min_bits + iter]){//b8
                                  logic_str[iter] = '1';
                                  }//b8
              else{//b10
                                  logic_str[iter] = '0';
                                  }//b10
                      
    }//b3
    logic_str[*min_bits] = '\0';
    printf("\n%s\n",logic_str);
    int len_logic_str = strlen(logic_str);
    int cast_indx = 0;
    int result = 0;
    while(logic_str[cast_indx]!='\0'){//b12
            result += (logic_str[cast_indx] - '0')*pow(10,len_logic_str - cast_indx - 1);
            cast_indx ++;
    }//b12
    free(logic_str);
    logic_str = NULL;
    return result;
}//b2  


int XNOR(input* inp_alpha_ptr , input* inp_beta_ptr){//b2
    
    int iter;
    int* max_bits = maximum(&inp_alpha_ptr -> bits , &inp_beta_ptr -> bits);
    int* min_bits = minimum(&inp_alpha_ptr -> bits , &inp_beta_ptr -> bits);
    char* logic_str = malloc(sizeof(char)*(*min_bits));
    for(iter = 0 ; iter < *min_bits ; iter++){//b3

              if((*inp_alpha_ptr -> binary)[inp_alpha_ptr -> bits - *min_bits + iter] != (*inp_beta_ptr -> binary)[inp_beta_ptr -> bits - *min_bits + iter]){//b8
                                  logic_str[iter] = '0';
                                  }//b8
              else{//b10
                                  logic_str[iter] = '1';
                                  }//b10
                      
    }//b3
    logic_str[*min_bits] = '\0';
    printf("\n%s\n",logic_str);
    int len_logic_str = strlen(logic_str);
    int cast_indx = 0;
    int result = 0;
    while(logic_str[cast_indx]!='\0'){//b12
            result += (logic_str[cast_indx] - '0')*pow(10,len_logic_str - cast_indx - 1);
            cast_indx ++;
    }//b12
    free(logic_str);
    logic_str = NULL;
    return result;
}//b2  

int NOT(input* inp_alpha_ptr){//b2
    
    int iter;
    char* logic_str = malloc(sizeof(char)*(inp_alpha_ptr -> bits+1));
    for(iter = 0 ; iter < inp_alpha_ptr -> bits  ; iter++){//b3

              if((*inp_alpha_ptr -> binary)[iter] == '0'){//b8
                                  logic_str[iter] = '1';
                                  }//b8
              else{//b10
                                  logic_str[iter] = '0';
                                  }//b10
                      
    }//b3
    logic_str[iter + 1] = '\0';
    printf("\n%s\n",logic_str);
    int len_logic_str = strlen(logic_str);
    int cast_indx = 0;
    int result = 0;
    while(logic_str[cast_indx]!='\0'){//b12
            result += (logic_str[cast_indx] - '0')*pow(10,len_logic_str - cast_indx - 1);
            cast_indx ++;
    }//b12
    free(logic_str);
    logic_str = NULL;
    return result;
}//b2  


int NOR(input* inp_alpha_ptr , input* inp_beta_ptr){//b2
    
    int iter;
    int* max_bits = maximum(&inp_alpha_ptr -> bits , &inp_beta_ptr -> bits);
    int* min_bits = minimum(&inp_alpha_ptr -> bits , &inp_beta_ptr -> bits);
    char* logic_str = malloc(sizeof(char)*(*min_bits));
    for(iter = 0 ; iter < *min_bits ; iter++){//b3

              if((*inp_alpha_ptr -> binary)[inp_alpha_ptr -> bits - *min_bits + iter] == 0){//b8
                        if((*inp_beta_ptr -> binary)[inp_beta_ptr -> bits - *min_bits + iter] == 0){//b9
                                  logic_str[iter] = '1';
                                  }//b9
                        else{//b10
                                  logic_str[iter] = '0';
                                  }//b10
                        }//b8
              else{//b11
                        logic_str[iter] = '0';
                        }//b11
                   
    }//b3
    logic_str[*min_bits] = '\0';
      printf("\n%s\n",logic_str);
    int len_logic_str = strlen(logic_str);
    int cast_indx = 0;
    int result = 0;
    while(logic_str[cast_indx]!='\0'){//b12
            result += (logic_str[cast_indx] - '0')*pow(10,len_logic_str - cast_indx - 1);
            cast_indx ++;
    }//b12
    free(logic_str);
    logic_str = NULL;
    return result;
}//b2  

int NAND(input* inp_alpha_ptr , input* inp_beta_ptr){//b2
    
    int iter;
    int* max_bits = maximum(&inp_alpha_ptr -> bits , &inp_beta_ptr -> bits);
    int* min_bits = minimum(&inp_alpha_ptr -> bits , &inp_beta_ptr -> bits);
    char* logic_str = malloc(sizeof(char)*(*min_bits));
    for(iter = 0 ; iter < *min_bits ; iter++){//b3

              if((*inp_alpha_ptr -> binary)[inp_alpha_ptr -> bits - *min_bits + iter] == 1){//b8
                        if((*inp_beta_ptr -> binary)[inp_beta_ptr -> bits - *min_bits + iter] == 1){//b9
                                  logic_str[iter] = '0';
                                  }//b9
                        else{//b10
                                  logic_str[iter] = '1';
                                  }//b10
                        }//b8
              else{//b11
                        logic_str[iter] = '1';
                        }//b11
                   
    }//b3
    logic_str[*min_bits] = '\0';
    printf("\n%s\n",logic_str);
   int len_logic_str = strlen(logic_str);
    int cast_indx = 0;
    int result = 0;
    while(logic_str[cast_indx]!='\0'){//b12
            result += (logic_str[cast_indx] - '0')*pow(10,len_logic_str - cast_indx - 1);
            cast_indx ++;
    }//b12
    free(logic_str);
    logic_str = NULL;
    return result;
}//b2


int main(){//b13
        
        input alpha;
        printf("Enter the no.of bits - ");
        scanf("%d",&alpha.bits);
        alpha.binary = malloc(sizeof(int)*(alpha.bits));
        int assign = 0;
        for(assign = 0 ; assign < alpha.bits ; assign++){//b14
                printf("Enter the %d number bit - ",assign+1);
                scanf("%d" , &(*alpha.binary)[assign]);
        }//b14
  
        input beta;
        printf("Enter the no.of bits - ");
        scanf("%d",&beta.bits);
        beta.binary = malloc(sizeof(int)*(beta.bits));
        for(assign = 0 ; assign < beta.bits ; assign++){//b15
                printf("Enter the %d number bit - ",assign+1);
                scanf("%d" , &(*beta.binary)[assign]);
        }//b15
       
        int logical_result =  NAND(&alpha , &beta);
        //int logical_result = NOT(&alpha);
        printf("\nLogical ans is - %d\n",logical_result);
        free(alpha.binary);
        free(beta.binary);
        alpha.binary = NULL;
        beta.binary = NULL;
        return 0;
}//b13
