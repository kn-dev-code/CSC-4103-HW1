/* Student: Kyle Netterville */
#include <stdio.h>

typedef struct funcs {
    int (*openit)(char *name, int prot);
    void (*closeit)(void);
} funcs;

int my_openit(char *name, int prot) {
    printf("my_openit execution -> Opening: %s with protection flag: %d\n", name, prot);
    return 0;
}

void my_closeit(void) {
    printf("my_closeit execution -> Closed successfully.\n");
}

void f(funcs *f_ptr) {
    if (f_ptr != NULL) {
        f_ptr->openit = &my_openit;
        f_ptr->closeit = &my_closeit;
    }
}

int main(void) {
    printf("=== Part (b): Static Initialization ===\n");
    funcs static_var = { &my_openit, &my_closeit };
    
    static_var.openit("config.txt", 1);
    static_var.closeit();

    printf("\n=== Part (c): Initialization via Function f() ===\n");
    funcs func_init_var;
    f(&func_init_var);

    func_init_var.openit("data.bin", 2);
    func_init_var.closeit();

    return 0;
}