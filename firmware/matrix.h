#ifndef MATRIX_H
#define MATRIX_H

extern const unsigned char matrix_row_num;
extern const unsigned char matrix_col_num;

struct matrix {
  unsigned char pressed[matrix_row_num][matrix_col_num];
  unsigned long last_scan;
};

void matrix_init(struct matrix *m);
void matrix_scan(struct matrix *m);

#endif
