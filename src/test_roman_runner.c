#include <check.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "test_roman_runner.h"


START_TEST (when_main_called_without_args_print_usage_to_strerr)
{
  char* temp_filename = "redir_stderr.txt";
  freopen(temp_filename, "w", stderr);
  
  char* args[0];
  main(0, args);

  struct stat st;
  fflush(stderr);
  stat(temp_filename, &st);
  ck_assert_int_eq(44, st.st_size);

  FILE* temp_file = fopen(temp_filename, "r");
  char *line_ptr = NULL;
  size_t line_len=0;
  ck_assert_int_gt(getline(&line_ptr, &line_len, temp_file), 0);
  ck_assert_str_eq("Usage: roman_runner [+ num num | - num num]\n", line_ptr);
  free(line_ptr);
  int ret = remove(temp_filename);
  ck_assert_int_eq(0, ret);
}
END_TEST


Suite * roman_runner_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman To Int");
    tc_core = tcase_create("roman-to-int");

    tcase_add_test(tc_core, when_main_called_without_args_print_usage_to_strerr);
    suite_add_tcase(s, tc_core);

    return s;
}
