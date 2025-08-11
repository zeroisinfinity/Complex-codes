#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Logic gates implementations using C

typedef struct {int bits; //b1
                int binary[];
                } input; //b1
   

int AND(input* inp_alpha_ptr , input* inp_beta_ptr){//b2
    
    int iter;
    int* max_bits = max(&inp_alpha_ptr -> bits , &inp_bits_ptr -> bits);
    char logic_str[*max_bits + 1] = ""; 
    for(iter = 0 ; iter < *max_bits ; iter++){//b3
            if(inp_alpha_ptr -> bits - iter == 0){//b4
                    if(inp_beta_ptr -> bits - iter == 0){//b6
                          if(inp_alpha_ptr -> binary[iter] == 1){//b8
                                if(inp_beta_ptr -> binary[iter] == 1){//b9
                                  logic_str[iter] = '1';
                                }//b9
                                else{//b10
                                      logic_str[iter] = '0';
                                }//b10
                          }//b8
                          else{//b11
                                logic_str[iter] = '0';
                          }//b11
                    }//b6
                    else{//b7
                          logic_str[iter] = '0';
                    }//b7
            }//b4
            else{//b5
                  logic_str[iter] = '0';
            }//b5
    }//b3
    logic_str[iter + 1] = '\0';
    int result = 0;
    size_t len_logic_str = sizeof(logic_str)/sizeof(char) - 1;
    for(int cast_indx = 0 ; cast_indx < len_logic_str ; cast_indx++){//b12
            result += int(logic_str[cast_indx])*(10**(len_logic_str - cast_indx - 1));
    }//b12
    
    return result;
}//b2  

int* max(int* num1, int* num2){//b4
    if(*num1 >= *num2){//b5
        return num1;
    }//b5
    else{//b6
        return num2;
    }//b6
}//b4

int main(){//b13
        
        input alpha;
        printf("Enter the no.of bits - ");
        scanf("%d",&alpha);
        for(int assign = 0 ; assign < bits ; bits++){//b14
                print("Enter the %d number bit - ",assign+1);
                scanf("%d" , alpha.binary[assign]);
        }//b14
        input beta;
        printf("Enter the no.of bits - ");
        scanf("%d",&beta);
        for(int assign = 0 ; assign < bits ; bits++){//b14
                print("Enter the %d number bit - ",assign+1);
                scanf("%d" , beta.binary[assign]);
        }//b14
        int logical_result = AND(&alpha , &beta);
        printf("%d",logical_result);
        return 0;
}//b13
