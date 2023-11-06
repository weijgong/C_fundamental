#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#define UNW_LOCAL_ONLY
#include <libunwind.h>

// gcc print_stack_trace_fp_chain.c -funwind-tables -lunwind -o print_stack_trace_fp_chain
void print_stack_trace_libnuwind(){
    printf("Stack trace from libunwind\n");
    unw_cursor_t cursor;
    unw_context_t uc;
    unw_word_t pc,sp;
    unw_getcontext(&uc);
    unw_init_local(&cursor, &uc);
    while(unw_step(&cursor)>0){
        unw_get_reg(&cursor,UNW_REG_IP,&pc);
        unw_get_reg(&cursor,UNW_REG_SP,&sp);
        printf("Program counter: 0x%016" PRIxPTR "\n", (uintptr_t) pc);
        printf("Stack pointer: 0x%016" PRIxPTR "\n", (uintptr_t) sp);
        printf("\n");
    }
    printf("end\n");
}

int main(){
    print_stack_trace_libnuwind();
    return 0;

}
// gcc print_stack_trace_fp_chain.c -fno-omit-frame-pointer -o print_stack_trace_fp_chain
// // 以下代码会报异常
// void print_stack_trace_fp_chain(){
//     printf("Stack trace from fp chain\n");
//     uintptr_t *fp;
//     asm("mv %0, fp":"=r"(fp) : :);
//     while(fp){
//         printf("Return address: 0x%016" PRIxPTR "\n", fp[-1]);
//         printf("Old stack pointer: 0x%16" PRIxPTR "\n", fp[-2]);
//         printf("\n");
//         fp = (uintptr_t *) fp[-2];
//     }
//     printf("end\n");
// }