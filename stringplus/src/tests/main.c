#include "s21_string_test.h"

int main(void) {
  int number_failed;
  Suite *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9, *s10, *s11, *s12, *s13,
      *s14, *s15, *s16, *s17, *s18, *s19, *s20;
  SRunner *sr;

  s1 = strchr_suite();
  s2 = strstr_suite();
  s3 = strrchr_suite();
  s4 = strlen_suite();
  s5 = to_lower_suite();
  s6 = to_upper_suite();
  s7 = memcmp_suite();
  s8 = strncmp_suite();
  s9 = strerror_suite();
  s10 = strpbrk_suite();
  s11 = strtok_suite();
  s12 = memset_suite();
  s13 = insert_suite();
  s14 = memchr_suite();
  s15 = trim_suite();
  s16 = strcspn_suite();
  s17 = strncat_suite();
  s18 = strncpy_suite();
  s19 = memcpy_suite();
  s20 = sprintf_suite();

  sr = srunner_create(s1);
  srunner_add_suite(sr, s2);
  srunner_add_suite(sr, s3);
  srunner_add_suite(sr, s4);
  srunner_add_suite(sr, s5);
  srunner_add_suite(sr, s6);
  srunner_add_suite(sr, s7);
  srunner_add_suite(sr, s8);
  srunner_add_suite(sr, s9);
  srunner_add_suite(sr, s10);
  srunner_add_suite(sr, s11);
  srunner_add_suite(sr, s12);
  srunner_add_suite(sr, s13);
  srunner_add_suite(sr, s14);
  srunner_add_suite(sr, s15);
  srunner_add_suite(sr, s16);
  srunner_add_suite(sr, s17);
  srunner_add_suite(sr, s18);
  srunner_add_suite(sr, s19);
  srunner_add_suite(sr, s20);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}