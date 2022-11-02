#include "s21_tests.h"

START_TEST(test_1) {
    char *str = malloc(250 * sizeof(char));
    strcpy(str, "12.2345+(-235)");
    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    // printf("%s \n", infix);
    double output = postfix_to_result(infix);
    double true_res = -222.765500;
    ck_assert_double_eq(output , true_res);
    free(str);
}
END_TEST

START_TEST(test_2) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "12.3-2");

    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    // printf("%s \n", infix);
    double output = postfix_to_result(infix);
    double true_res = 12.3-2;
    ck_assert_double_eq(output, true_res);
    free(str);
}
END_TEST

START_TEST(test_3) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "2+3+(-3)");

    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    // printf("%s \n", infix);
    double output = postfix_to_result(infix);
    double true_res = 2+3+(-3);
    ck_assert_double_eq(output, true_res);
    free(str);
}
END_TEST

// START_TEST(test_4) {
//     char *str = malloc(50 * sizeof(char));
//     strcpy(str, "/10");
//     int true_res = 1;
//     int error = validation(str);
//     ck_assert_int_eq(error, true_res);
//     free(str);
// }
// END_TEST

// START_TEST(test_5) {
//     char *str = malloc(50 * sizeof(char));
//     strcpy(str, "5(");
//     int true_res = 1;
//     int error = validation(str);
//     ck_assert_int_eq(error, true_res);
//     free(str);
// }
// END_TEST

START_TEST(test_6) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "s(10)");
    int true_res = sin(10);

    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    // printf("%s \n", infix);
    double output = postfix_to_result(infix);

    ck_assert_int_eq(output, true_res);
    free(str);
}
END_TEST

START_TEST(test_7) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "c(3)");
    double true_res = cos(3);
    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    // printf("%s \n", infix);
    double output = postfix_to_result(infix);
    ck_assert_double_eq(fabs(output - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_8) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "t(3)+33");
    double true_res = tan(3)+33;
    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    // printf("%s \n", infix);
    double output = postfix_to_result(infix);
    ck_assert_double_eq(fabs(output - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_9) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "k(1)");
    double true_res = acos(1);
    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    // printf("%s \n", infix);
    double output = postfix_to_result(infix);
    ck_assert_double_eq(output, true_res);
    free(str);
}
END_TEST

START_TEST(test_10) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "i(1)");
    double true_res = asin(1);
    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    double output = postfix_to_result(infix);
    ck_assert_double_eq(output, true_res);
    free(str);
}
END_TEST

START_TEST(test_11) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "a(3)");
    double true_res = atan(3);
    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    double output = postfix_to_result(infix);
    ck_assert_double_eq(fabs(output - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_12) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "q(9)+c(20)");
    double true_res = sqrt(9)+cos(20);
    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    double output = postfix_to_result(infix);
    ck_assert_double_eq(fabs(output - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_13) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "n(10)");
    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    double output = postfix_to_result(infix);
    double true_res = log10(10);
    ck_assert_double_eq(fabs(output - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_14) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "o(10)");
    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    double output = postfix_to_result(infix);
    double true_res = log(10);
    ck_assert_double_eq(fabs(output - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_15) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "t(3)");
    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    double output = postfix_to_result(infix);
    double true_res = tan(3);
    ck_assert_double_eq(fabs(output - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_16) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "a(3.3)");
    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    double true_res = atan(3.3);
    double output = postfix_to_result(infix);
    ck_assert_double_eq(fabs(output - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_17) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "5*2.2/2-1");
    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    double output = postfix_to_result(infix);
    double true_res = 5 * 2.2 / 2 - 1;
    ck_assert_double_eq(fabs(output - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_18) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "2^10");
    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    double output = postfix_to_result(infix);
    double true_res = pow(2, 10);
    ck_assert_double_eq(fabs(output - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_19) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "36m5");    
    char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    printf("%s \n", infix);
    double output = postfix_to_result(infix);
    double true_res = 1;
    ck_assert_double_eq(fabs(output - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_20) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "36m5+(9*4)/2+3-10");
            char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    double output = postfix_to_result(infix);
    double true_res = 1 + (9*4) / 2 + 3 -10;
    ck_assert_double_eq(fabs(output - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_21) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "c(20) + 1");
            char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    double output = postfix_to_result(infix);
    double true_res = cos(20) + 1;
    ck_assert_double_eq(fabs(output - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_22) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "2^3^3");
            char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    double output = postfix_to_result(infix);
    double true_res = 134217728;
    ck_assert_double_eq(fabs(output - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_23) {
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "2^3+3/1+(3*2)");
            char* infix_input_with_unary_minus = replace_unary_minus(str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    double output = postfix_to_result(infix);
    double true_res = 17;
    ck_assert_double_eq(fabs(output - true_res), 0.0);
    free(str);
}
END_TEST

// START_TEST(test_24) {
//     char *str = malloc(50 * sizeof(char));
//     strcpy(str, "(1+2)*4*cos(x*7-2)+sin(2*x)");
//     double output = postfix_to_result(str);
//     double true_res = (1+2)*4*cos(x*7-2)+sin(2*x);
//     ck_assert_double_eq(fabs(output - true_res), 0.0);
//     free(str);
// }
// END_TEST

// START_TEST(test_25) {
//     char *str = malloc(50 * sizeof(char));
//     strcpy(str, "-sqrt(x^log(5-x))+ln(55/(2+x))");
//     double output = postfix_to_result(str);
//     double true_res = 17;
//     ck_assert_double_eq(fabs(output - true_res), 0.0);
//     free(str);
// }
// END_TEST

// START_TEST(test_26) {
//     char *str = malloc(50 * sizeof(char));
//     strcpy(str, "100.235+x-(x+10)");
//     double output = postfix_to_result(str);
//     double true_res = 17;
//     ck_assert_double_eq(fabs(output - true_res), 0.0);
//     free(str);
// }
// END_TEST

// START_TEST(test_27) {
//     char *str = malloc(50 * sizeof(char));
//     strcpy(str, "-(3)*(-x-(7*(-(-(-(--7))))))");
//     double output = postfix_to_result(str);
//     double true_res = 17;
//     ck_assert_double_eq(fabs(output - true_res), 0.0);
//     free(str);
// }
// END_TEST

Suite *suite_s21_calc_notation(void) {

    Suite *s = suite_create("s21_calc");
    TCase *tc = tcase_create("s21_calc");

    tcase_add_test(tc, test_1);
    tcase_add_test(tc, test_2);
    tcase_add_test(tc, test_3);
    // tcase_add_test(tc, test_4);
    // tcase_add_test(tc, test_5);
    tcase_add_test(tc, test_6);
    tcase_add_test(tc, test_7);
    tcase_add_test(tc, test_8);
    tcase_add_test(tc, test_9);
    tcase_add_test(tc, test_10);
    tcase_add_test(tc, test_11);
    tcase_add_test(tc, test_12);
    tcase_add_test(tc, test_13);
    tcase_add_test(tc, test_14);
    tcase_add_test(tc, test_15);
    tcase_add_test(tc, test_16);
    tcase_add_test(tc, test_17);
    tcase_add_test(tc, test_18);
    tcase_add_test(tc, test_19);
    tcase_add_test(tc, test_20);
    tcase_add_test(tc, test_21);
    tcase_add_test(tc, test_22);
    tcase_add_test(tc, test_23);
    // tcase_add_test(tc, test_24);
    // tcase_add_test(tc, test_25);
    // tcase_add_test(tc, test_26);
    // tcase_add_test(tc, test_27);
    suite_add_tcase(s, tc);
    return s;
}