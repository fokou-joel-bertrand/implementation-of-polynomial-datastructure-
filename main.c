#include<stdio.h>
#include"header.h"                                                       
// gcc *.c -o p



int main(void)
{   
  Poly p = new_polynomial();

       Poly h = new_polynomial();
       Poly k = new_polynomial();
       Poly r = new_polynomial();

       Poly m = new_polynomial();
       Poly n = new_polynomial();

    int stop, x;

    menuFunction();

while(stop != 15){
     printf("\n\tEnter your choice\t");
     scanf("%d", &x);
    switch(x)
    { 
      case 0:
        menuFunction(); break;

      case 1:
      if(is_polynomial_set_empty(p)) printf("\nThe set is empty\n");
        else printf("\nThe set is empty\n"); break;

      case 2:
        printf("\nThe is(are) %d polynomial(s) in the set\n",list_length()); break;
      
      case 3: 
      p = add_polynomial_end_of_the_set(p); 
      printf("\nSuccessfully added a polynomial at the end of the set\n");break;

      case 4: 
      p = add_polynomial_front_of_the_set(p);
       printf("\nSuccessfully added a polynomial in front of the set\n");break;            

      case 5: 
      print_the_set_of_polynomials(p); break;

      case 6:
      Print_a_polynomial_located_at_position_x_of_the_set(p); break;

      case 7: 
      p = delete_end_a_polynomial(p);
      printf("\nSuccessfully deleted a polynomial at the end of the set\n");break;
    
      case 8: 
      p = delete_front_a_polynomial(p);
      printf("\nSuccessfully deleted a polynomial in front of the set\n");break;

      case 9:
       h = add_polynomial_end_of_the_set(h);
       k = add_polynomial_end_of_the_set(k);
      r = sum_of_two_polynomials(h, k); 
      h = delete_end_a_polynomial(h);
      k = delete_end_a_polynomial(k); break;

      case 10: 
      evaluate_the_derivative_of_a_polynomial_x(p); break;

      case 11: 
      evaluate_a_polynomial_at_position_x(p); break;

      case 12: 
       m = add_polynomial_end_of_the_set(m);
       n = add_polynomial_end_of_the_set(n);
       product_of_two_polynomials(m, n);
      m = delete_end_a_polynomial(m);
      n = delete_end_a_polynomial(n);break;

      case 13: 
      degree_of_a_polynomial_located_at_position_x(p);break;

      case 14: 
       p = clear_the_set_of_polynomials(p) ;
       printf("\nSuccessfully clear the polynomials'\n");break;

      case 15: 
          p = clear_the_set_of_polynomials(p);
          stop = 15;
          break;

      default:
     printf("\nWarning !!!!!  CHOICE ERROR\n");
     p = clear_the_set_of_polynomials(p);
     stop = 15;
    }
}
    
    return 0;
}
