#include <ittnotify.h>

extern __itt_domain *mylib_itt_domain;

void mylib_init(void);
void mylib_deinit(void);

void mylib_do_work(const char *filepath);
