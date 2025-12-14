#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>   // for strsignal

// include your sandbox prototype
int sandbox(void (*f)(void), unsigned int timeout, bool verbose);

// ------------ Test functions ------------

// good function
void nice_function(void) { return; }

// exits with error
void bad_exit(void) { exit(42); }

// segfault
void bad_segfault(void) { int *p = NULL; *p = 5; }

// infinite loop (timeout)
void bad_timeout(void) { while (1) {} }

// abort()
void bad_abort(void) { abort(); }

// division by zero (SIGFPE)
void bad_divzero(void) {
    raise(SIGFPE);
}
// raise SIGTERM
void bad_sigterm(void) { raise(SIGTERM); }

// raise SIGKILL
void bad_sigkill(void) { raise(SIGKILL); }

// ------------ Helper ------------
void run_test(const char *name, void (*f)(void), unsigned int t, int expected) {
    int result = sandbox(f, t, true);
    if (result == expected)
        printf("[PASS] %s -> %d\n", name, result);
    else
        printf("[FAIL] %s -> got %d expected %d\n", name, result, expected);
}

int main(void) {
    run_test("nice_function", nice_function, 2, 1);
    run_test("bad_exit", bad_exit, 2, 0);
    run_test("bad_segfault", bad_segfault, 2, 0);
    run_test("bad_timeout", bad_timeout, 1, 0);
    run_test("bad_abort", bad_abort, 2, 0);
    run_test("bad_divzero", bad_divzero, 2, 0);
    run_test("bad_sigterm", bad_sigterm, 2, 0);
    run_test("bad_sigkill", bad_sigkill, 2, 0);
    run_test("null_function", NULL, 2, 0);
}
