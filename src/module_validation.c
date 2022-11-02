#include "s21_smartcalc.h"

/*  Первый этап создания калькулятора - проверить входную строчкку на
   валидность. Для того, что бы не отлавливать ошибки на уровне алгоритма
   перевода в обратную польскую запись. Для валидации используется текущий и
   следющий символ входной строки. Все правила основаны на том, какой символ
   точно НЕ может идти после текущего.

    Все возможные символы:
        цифры: 0 1 2 3 4 5 6 7 8 9  пунктуация: + - * / ^ ( )  слова: mod

    Пункты валидации:
        0. Проверка на пустую строку, когда "" и указатель на '\0'
        1. Проверка цифры: после [0-9] не может быть '('
        2. Проверка пунктуации: после точки '.' может быть только цифра [0-9]
                                после '(' не может быть: ) ^ / *
                                после ')' не может быть: [0-9] и '('
                                после + - не может быть + - * / ^ )
                                после * / ^ не может быть + - * / ^ ) и [0-9]
        3. Проверка на равенство скобок: количество '(' должно быть равно ')'
                                         не может быть ')', пока не было '('
        4. Проверка на 2 точки в одном числе
        5. Первый символ строки не может быть * / ^ )
        6. Последний символ может быть только [0-9] и )

*/

int input_validation(char *input) {
  int input_length = strlen(input);
  // int string_size = 0;

  // узнаем размер строки
  // for(int i = 0; i < input_length + 1; i++) {
  //     string_size += sizeof(input[i]);
  //     printf("## %d: %c\n", i, input[i]);
  // }

  // printf("       входная строка: \"%s\"\n", input);
  // printf("длинна входной строки: %d char + '\\0' = %d chars\n", input_length,
  // input_length + 1); printf("размер входной строки: %d bit\n", string_size);

  // Проверка на пустую строку, когда "" и указатель на '\0'
  if (empty_input(input)) return ER_IN_EMPTY_INPUT;

  char current_char = 0;
  char next_char = 0;
  int count_op_brace = 0;
  int count_cl_brace = 0;
  // int count_dot = 0;

  for (int i = 0; i < input_length; i++) {
    next_char = input[i];

    if (validation_rules(current_char, next_char)) {
      return ERROR;

    } else {
      // if (current_char == '.') {
      //     if (count_dot) return ER_IN_SECOND_DOT; else count_dot++;
      // }
      if (strchr("*/^)", input[0])) {
        return ER_IN_FIRST_CHAR_IS_OPS;
      }
      if (!strchr("0123456789)", input[input_length - 1])) {
        return ER_IN_LAST_CHAR_IS_OPS;
      }
      current_char = next_char;
      if (current_char == '(') {
        count_op_brace++;
        // printf("колво скобок таких ( : %d\n", count_op_brace);
      }
      if (current_char == ')') {
        count_cl_brace++;
        // printf("колво скобок таких ) : %d\n", count_cl_brace);
      }
      // printf("текущий эл емент %d: %c \n", i, current_char);
      // printf("                     следующий элемент %d: %c \n", i,
      // next_char);
      if (count_cl_brace > 0 && count_op_brace == 0) {
        return ER_IN_TOO_FEW_BRACERS;
      }
    }
  }
  if (count_op_brace != count_cl_brace) {
    return ER_IN_TOO_FEW_BRACERS;
  }
  
  return OK;
}

int validation_rules(char current_char, char next_char) {
  //  Проверка цифры:
  if (isdigit(current_char)) {
    if (open_brace_after_digit(
            next_char)) {  // После цифры [0-9] не может быть: '('
      return ER_IN_OP_BRACE_AFTER_DIGIT;
    }
  }
  //  Проверка пунктуации:
  if (ispunct(current_char)) {
    if (current_char == '.') {  // после точки '.' может быть только цифра [0-9]
      if (invalid_char_after_dot(next_char)) {
        return ER_IN_NON_DIGIT_AFTER_DOT;
      } else if (next_char == '.') {
        return ER_IN_NON_DIGIT_AFTER_DOT;
      }
    }
    if (current_char == '(') {  // после '(' не может быть: ) ^ / *
      if (invalid_char_after_op_brace(next_char)) {
        return ER_IN_WRONG_CHAR_AFTER_OPENED_BRACE;
      }
    }
    if (current_char == ')') {
      if (invalid_char_after_cl_brace(
              next_char)) {  // после ')' не может быть: [0-9] и '('
        return ER_IN_WRONG_CHAR_AFTER_CLOSED_BRACE;
      }
    }
    if (strchr("+-*/^", current_char)) {  // после + - не может быть + - * / ^ )
      if (invalid_char_after_plus_minus(next_char)) {
        return ER_IN_INV_CHAR_AFTER_OPS;
      }
    }
  }
  return OK;
}

int empty_input(char *input) {
  int error = 0;
  return error = (*(input) == '\0') ? YES : NO;
}

int open_brace_after_digit(char next) {
  int error = 0;
  return error = (next == '(') ? YES : NO;
}

int invalid_char_after_dot(char next) {
  int error = 0;
  return error = (isdigit(next) != 0) ? NO : YES;
}

int invalid_char_after_op_brace(char next) {
  int error = 0;
  return error = (strchr(")^/*", next) == 0) ? NO : YES;
}

int invalid_char_after_cl_brace(char next) {
  int error = 0;
  return error = (strchr("0123456789(", next) == 0) ? NO : YES;
}

int invalid_char_after_plus_minus(char next) {
  int error = 0;
  return error = (strchr("+-*/^)", next) == 0) ? NO : YES;
}

int invalid_char_after_other_ops(char next) {
  int error = 0;
  return error = (strchr("+-*/^)", next) == 0) ? NO : YES;
}

int error_print(int valid) {
  if (valid == ER_IN_EMPTY_INPUT) {
    printf("Получена пустая строка!\n");
  } else if (valid == ER_IN_OP_BRACE_AFTER_DIGIT) {
    printf("Обнаружена '(' после числа!\n");
  } else if (valid == ER_IN_NON_DIGIT_AFTER_DOT) {
    printf("Не число после точки!\n");
  } else if (valid == ER_IN_INV_CHAR_AFTER_OPS) {
    printf(
        "Некорректный символ после операции плюс или минус!\n");
  } else if (valid == ER_IN_WRONG_CHAR_AFTER_OPENED_BRACE) {
    printf(
        "Некорректный символ после ОТКРЫТОЙ скобки!\n");
  } else if (valid == ER_IN_WRONG_CHAR_AFTER_CLOSED_BRACE) {
    printf(
        "Некорректный символ после ЗАКРЫТОЙ скобки!\n");
  } else if (valid == ER_IN_TOO_FEW_BRACERS) {
    printf("Нехватает скобок!\n");
  } else if (valid == ER_IN_SECOND_DOT) {
    printf("Вторая точка в числе!\n");
  } else if (valid == ER_IN_LAST_CHAR_IS_OPS) {
    printf("Последний символ не может быть операция!\n");
  } else if (valid == ER_IN_FIRST_CHAR_IS_OPS) {
    printf("Первый символ не может быть операция!\n");
  } else {
    printf("Строка валидна!\n");
  }
  return 0;
}
