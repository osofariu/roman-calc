#include <check.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "test_roman_runner.h"


const char* temp_stderr = "redir_stderr.txt";
const char* temp_stdout = "redir_stdeout.txt";

void setup_output() {
  freopen(temp_stderr, "w", stderr);
  freopen(temp_stdout, "w", stdout);
}

void clean_up_output() {
  int ret = remove(temp_stdout);
  ck_assert_int_eq(0, ret);
  
  ret = remove(temp_stderr);
  ck_assert_int_eq(0, ret);
}

void read_program_output(char** ptr, const char* file_name) {
  FILE* temp_file = fopen(file_name, "r");
  size_t line_len=0;
  getline(ptr, &line_len, temp_file);
}

START_TEST (when_main_called_without_args_print_usage_to_strerr)
{
  setup_output();
  
  char* args[0];
  main(0, args);
  fflush(stderr);
  
  char* line_ptr = NULL;
  read_program_output(&line_ptr, temp_stderr);
  ck_assert_str_eq("Usage: roman_runner [+ num num | - num num]\n", line_ptr);
  free(line_ptr);
  clean_up_output();
}
END_TEST


START_TEST (when_adding_two_romans_output_goes_to_stdout)
{
  setup_output();

  char* args[4] = {"prog_name", "+", "I", "IV"};
  main(4, args);
  fflush(stdout);
  fflush(stderr);

  char* output_ptr = NULL;
  read_program_output(&output_ptr, temp_stdout);
  ck_assert_str_eq("I + IV = V\n", output_ptr);
  free(output_ptr);
  
  read_program_output(&output_ptr, temp_stderr);
  ck_assert_str_eq("", output_ptr);
  free(output_ptr);
  clean_up_output();
}
END_TEST

START_TEST (when_adding_two_romans_error_reported_on_stderr)
{
  setup_output();

  char* args[4] = {"prog_name", "+", "S", "I"};
  main(4, args);
  fflush(stderr);

  char* stderr_ptr = NULL;
  read_program_output(&stderr_ptr, temp_stderr);
  ck_assert_str_eq("Roman numeral contains invalid characters\n", stderr_ptr);

  free(stderr_ptr);
  clean_up_output();
}
END_TEST

START_TEST (when_subtracting_two_romans_output_goes_to_stdout)
{
  setup_output();

  char* args[4] = {"prog_name", "-", "II", "I"};
  main(4, args);
  fflush(stdout);
  
  char* output_ptr = NULL;
  read_program_output(&output_ptr, temp_stdout);
  ck_assert_str_eq("II - I = I\n", output_ptr);
  free(output_ptr);
  clean_up_output();

}
END_TEST
     
Suite * roman_runner_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman To Int");
    tc_core = tcase_create("roman-to-int");

    tcase_add_test(tc_core, when_main_called_without_args_print_usage_to_strerr);

    tcase_add_test(tc_core, when_adding_two_romans_output_goes_to_stdout);
    tcase_add_test(tc_core, when_adding_two_romans_error_reported_on_stderr);
    
    tcase_add_test(tc_core, when_subtracting_two_romans_output_goes_to_stdout);
    suite_add_tcase(s, tc_core);

    return s;
}
