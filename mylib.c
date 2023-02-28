#include "mylib.h"

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

__itt_domain *mylib_itt_domain;
__itt_string_handle *mylib_itt_do_work;

void mylib_init(void) {
    mylib_itt_domain = __itt_domain_create("software.amazon.awssdk.crt");
    mylib_itt_do_work = __itt_string_handle_create("mylib_do_work");
}

void mylib_deinit(void) {
}

void mylib_do_work(const char *filepath) {
    __itt_task_begin(mylib_itt_domain, __itt_null, __itt_null, mylib_itt_do_work);
    printf("working on %s...\n", filepath);
    sleep(1);
    __itt_task_end(mylib_itt_domain);
}
