#ifndef __polynomial__
#define __polynomial__

typedef enum{false, true}Bool;

typedef struct polynomial
{    int coefficients[500];
     int degree[500];
     int deg;
    struct polynomial *next;
}polynomial, *Poly;

static int s=0;
static int numberOfPOlynomials = 0;



Poly new_polynomial();
Bool is_polynomial_set_empty(Poly);
Poly add_polynomial_end_of_the_set(Poly);
Poly add_polynomial_front_of_the_set(Poly);
void print_the_set_of_polynomials(Poly);
void print_a_polynomial(Poly);
int list_length();
void evaluate_a_polynomial_at_position_x(Poly);
Poly delete_front_a_polynomial(Poly);
Poly delete_end_a_polynomial(Poly);
Poly clear_the_set_of_polynomials(Poly);
void evaluate_the_derivative_of_a_polynomial_x(Poly);
Poly sum_of_two_polynomials(Poly, Poly);
void Print_a_polynomial_located_at_position_x_of_the_set(Poly);
int degree_of_a_polynomial_located_at_position_x(Poly);

/*---------------------------*/
int power(int, int);
void menuFunction();
/*--------------------------*/

#endif