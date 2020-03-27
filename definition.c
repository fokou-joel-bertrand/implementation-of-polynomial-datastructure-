#include<stdio.h>
#include<stdlib.h>
#include"header.h"


int power(int n, int p)
    { int i, r=1;
        for(i=0; i<p; i++) 
        r *=n;
        return r;
    }
/*___________________________create a new polynomial_____________________________*/

Poly new_polynomial()
{
    return NULL;
}

/*___________________list length____________________________*/

int list_length()
{
  return numberOfPOlynomials;
}
/*____________________check weither the set polynomial is empty or not____________*/

Bool is_polynomial_set_empty(Poly p)
{
    if(p == new_polynomial()) return true;
      return false;
}

/*____________________add a polynomial to the set(end)________________________________*/

Poly add_polynomial_end_of_the_set(Poly p)
{
    polynomial *g;
    int i, j = 0;
    g = malloc(sizeof(*g));
    if(g == NULL){
     fprintf(stderr, "Memory allocation problem\n");
     exit(1);}
numberOfPOlynomials++;
 printf("\n|** Enter the informations relative to the polynomial number %d **|\n\n", ++s);
     printf("enter the highest degree of your polynomial\n");
    scanf("%d", &g->deg);

    printf("\nenter the coefficients from the highest degree(plus the constant if either if not enter 0)\n");
    for(i = 0; i<=g->deg; i++)
    {
       scanf("%d", &(g->coefficients[i]));
    }      

    for(i = g->deg; i>=0; i--)
    {g->degree[j] = i; j++;}
   g->next = NULL;

   if(is_polynomial_set_empty(p)) return g;

polynomial *k;

 k = p;
   while(k->next!= NULL)
   {
       k = k->next;
   }
     k->next = g;
    return p;
}

/*____________________add a polynomial to the set(front)________________________________*/
Poly add_polynomial_front_of_the_set(Poly p)
{
    polynomial *g;
    int i, j = 0;
    g = malloc(sizeof(*g));
    if(g == NULL){
     fprintf(stderr, "Memory allocation problem\n");
     exit(1);}
numberOfPOlynomials++;
 printf("\n|** Enter the informations relative to the polynomial number %d **|\n\n", ++s);
     printf("enter the highest degree of your polynomial\n");
    scanf("%d", &g->deg);

    printf("\nenter the coefficients from the highest degree(plus the constant if either if not enter 0)\n");
    for(i = 0; i<=g->deg; i++)
    {
       scanf("%d", &(g->coefficients[i]));
    }      

    for(i = g->deg; i>=0; i--)
    {g->degree[j] = i; j++;}
    
       g->next = p;
    return g;
}

/*__________________________Print the set of polynomials_______________________________*/

void print_the_set_of_polynomials(Poly p)
{   int i, x, k = 0;
     static int t = 0;
 printf("\n\n");
    if(is_polynomial_set_empty(p)){ printf("The polynomial set is empty nothing to print\n");
                                      return;}

 while(p != new_polynomial()){
     printf("P(x)%d = ", ++t);
   for(i = 0; i<p->deg; i++)
      {
        if(!(p->coefficients[i])) continue;
          if(p->degree[i] && p->degree[i] != 1)
            { if(p->coefficients[i] < 0)
              printf("%dX^%d ", p->coefficients[i], p->degree[i]);
              else
              printf("%dX^%d + ", p->coefficients[i], p->degree[i]);
            }
            if(p->degree[i] == 1)
            { if(p->coefficients[p->deg])
              { if(p->coefficients[i] < 0)
                printf("%dX^%d ", p->coefficients[i], p->degree[i]);
                else
                printf("%dX + ", p->coefficients[i]);
              }
               else
            printf("%dX", p->coefficients[i]);
            }
      }
      if(p->coefficients[p->deg]) printf("%d", p->coefficients[p->deg]);
 printf("\n\n");
  p = p->next;}
}
    
/*________________________evaluate the polynomial p at x = a__________________________*/

void evaluate_a_polynomial_at_position_x(Poly p)
{
    int pos, xo, a = 1;
    int i, v = 0;
     
     if(p == new_polynomial()){ printf("\nThe polynomial is not set or does not exist\n"); return;}
     
 polynomial *g;

     printf("\nEnter the position [1..N] of the polynomial which you want to evaluate:\n");
      scanf("%d", &pos);
      if(pos>list_length()){printf("Position error\n"); return;}
    while(a <= pos)
    {
        g = p;
        p = p->next;
        a++;
    }
      
printf("Enter Xo\n"); scanf("%d", &xo);
    
    for(i = 0; i<g->deg; i++)  
    {                                                      
        v += g->coefficients[i]*power(xo, g->degree[i]);     
    }printf("The result is : %d\n", v+g->coefficients[g->deg]);                                    
}

/*_________________________delete front a polynomial from the set____________________*/

Poly delete_front_a_polynomial(Poly p)
{
    if(is_polynomial_set_empty(p)) return new_polynomial();
numberOfPOlynomials--; s-=1;
    polynomial *g;
    g = p->next;
    free(p); p = new_polynomial();
    return g;
}

/*______________________delete end a polynomial from the set________________________*/

Poly delete_end_a_polynomial(Poly p)
{
    if(is_polynomial_set_empty(p)) return new_polynomial();
numberOfPOlynomials--; s-=1;
    polynomial *before;
    polynomial *tmp;

    tmp = p;
    while(tmp != NULL)
    {
      before = tmp;
      tmp = tmp -> next;
    }
    before -> next = NULL;
    free(tmp);
    return p;
}
/*_____________________________clear the set___________________________________*/

Poly clear_the_set_of_polynomials(Poly p)
{  
    if(is_polynomial_set_empty(p)) return new_polynomial();
      
      while(p != new_polynomial()) delete_front_a_polynomial(p);
numberOfPOlynomials = 0; s = 0;
   return new_polynomial();
}

/*_____________________________derivative____________________________________*/

void evaluate_the_derivative_of_a_polynomial_x(Poly p)
{
    int pos, a = 1;
    int i, x, j = 0;
if(p == new_polynomial()){ printf("\nThe polynomial is not set or does not exist\n"); return;}

 polynomial *g;

printf("Enter the position [1..N] of the polynomial which you want to evaluate the derivative:\n");
    scanf("%d", &pos);
    if(pos>list_length()){printf("Position error\n"); return;}
    while(a <= pos)
    {
        g = p;
        p = p->next;
        a++;
    }
  printf("\nThe derivative is D(x) = ");
      for(i = 0; i<g->deg; i++)  
      {
        if(!(g->coefficients[i])) continue;
          if(g->degree[i] && g->degree[i] != 1){
       if(g->coefficients[i] < 0) 
       printf("%dX^%d ", g->coefficients[i]*g->degree[i], g->degree[i]-1);
       else
       printf("%dX^%d + ", g->coefficients[i]*g->degree[i], g->degree[i]-1);
          }

     else if(g->degree[i] == 1)
     {if(g->coefficients[i] < 0)
        printf("%dX ", g->coefficients[i]);
      else
      printf("%dX + ", g->coefficients[i]);
     }
     else if(!g->degree[i]) 
        printf("%d", g->coefficients[i]);
      }

}

/*_______________________________sum of two polynomials________________________________*/
/*-----service functions---------*/
/*-----------function 2--------*/
void service1(Poly p, Poly g, Poly h, int x)
{ int i,w,y,z;
    w = p->deg > g->deg ? p->deg : g->deg;
  for(i = x; i<w; i++)
        {
        if(p->deg > g->deg) {y = i-x; z = i;}  else{ z = i-x; y = i;}
           if(!p->coefficients[z] && g->coefficients[y])
             h->coefficients[i] = g->coefficients[y];

              else if(p->coefficients[z] && !g->coefficients[y])
             h->coefficients[i] = p->coefficients[z];

           else if(!p->coefficients[z] && !g->coefficients[y])
           h->coefficients[i] = 0;
       else{
     h->coefficients[i] = g->coefficients[y]+p->coefficients[z];
        }
     h->coefficients[w] = g->coefficients[g->deg] + p->coefficients[p->deg];
}
}

/*-----------function 2--------*/

void service2(Poly p, Poly g, Poly h, int x)
{   
    int i,w,y,z;
  w = p->deg > g->deg ? p->deg : g->deg;
    for(i = x; i<w; i++)
    {
      if(p->deg > g->deg) {y = i-x; z = i;}  else{ z = i-x; y = i;}
        if(p->degree[z] == g->degree[y] && g->degree[y] != 0 && p->degree[z] != 0)
        h->degree[i] = p->degree[z];
     else if(p->degree[i] && !g->degree[y])
        h->degree[i] = p->degree[z];
    else if(!p->degree[z] && g->degree[y])
        h->degree[i] = g->degree[y];
    else continue;
    }
}

Poly sum_of_two_polynomials(Poly p, Poly g)
{  
  if(p == new_polynomial() && g == new_polynomial()) return new_polynomial();
  else if(g == new_polynomial() && p != new_polynomial()) return p;
  else if(p == new_polynomial() && g != new_polynomial()) return g;

  polynomial *h;
    h = malloc(sizeof(*h));
    if(h == NULL){
     fprintf(stderr, "Memory allocation problem\n");
     exit(1);}
    int i;
    int x = 0;
         int tmp1 = p->deg;
            int tmp2 = g->deg;

  if(p->deg == g->deg)
    {  h->deg = p->deg;
      service1(p,g,h,0);
       service2(p,g,h,0);

        return h;}

   else if(p->deg > g->deg)
    {h->deg = p->deg; 
        while(tmp1 > tmp2){tmp2++; x++;}
       for(i=0; i<x; i++){
     h->coefficients[i] = p->coefficients[i];
     h->degree[i] = p->degree[i];}
        service1(p,g,h,x);
        service2(p,g,h,x);
      return h;
    }
    else
    {  h->deg = g->deg;
     while(tmp1 < tmp2){tmp1++; x++;}
     for(i=0; i<x; i++){
     h->coefficients[i] = g->coefficients[i];
     h->degree[i] = g->degree[i];}
     service1(p,g,h,x);
     service2(p,g,h,x);
       return h;
    }

}


/*_____________Print a polynomial____________________*/

void print_a_polynomial(Poly p)
{  int i; 
  if(p == new_polynomial()){ printf("\nThe polynomial is not set or does not exist that's nothing to print\n"); return;}
  printf("X(x) = ");
    for(i = 0; i<p->deg; i++)
      {
        if(!(p->coefficients[i])) continue;
          if(p->degree[i] && p->degree[i] != 1)
               { if(p->coefficients[i] < 0)
               printf("%dX^%d  ", p->coefficients[i], p->degree[i]);
               else
              printf("%dX^%d + ", p->coefficients[i], p->degree[i]);
               }
            if(p->degree[i] == 1)
            { if(p->coefficients[p->deg])
              { if(p->coefficients[i] < 0)
              printf("%dX  ", p->coefficients[i]);
              else
              printf("%dX + ", p->coefficients[i]);
            }
               else
            printf("%dX", p->coefficients[i]);
            }
      }
      if(p->coefficients[p->deg]) printf("%d", p->coefficients[p->deg]);
 printf("\n\n");
}

/*---------------int degree_of_a_polynomial_located_at_position_x------*/

int degree_of_a_polynomial_located_at_position_x(Poly p)
{
  int pos, xo, a = 1;
    int i;
     
     if(p == new_polynomial()){ printf("\nThe polynomial is not set or does not exist\n"); return 0;}
 polynomial *g;

     printf("\nEnter the position [1..N] of the polynomial which you want to evaluate:\n");
      scanf("%d", &pos);
      if(pos>list_length()){printf("Position error\n"); return-1;}
    while(a <= pos)
    {
        g = p;
        p = p->next;
        a++;
    }
    printf("\nThe degree of the polynomial located at position %d is %d", pos, g->deg);
  return g->deg;
}

/*---------------Print_a_polynomial_located_at_position_x_of_the_set------*/

void Print_a_polynomial_located_at_position_x_of_the_set(Poly p)
{
int pos, xo, a = 1;
    int i;
     
     if(p == new_polynomial()){ printf("\nThe polynomial is not set or does not exist\n"); return;}
 polynomial *g;

     printf("\nEnter the position [1..N] of the polynomial which you want to evaluate:\n");
      scanf("%d", &pos);
      if(pos>list_length()){printf("Position error\n"); return;}
    while(a <= pos)
    {
        g = p;
        p = p->next;
        a++;
    }
    printf("Polynomial located at position %d is:\n", pos);
  print_a_polynomial(g);
}


void menuFunction()
{
    printf("\n\n\t\t---------------MENU--------------\n");
    printf("\t0 = Show the options menu\n");
    printf("\t1 = Check whether the set is empty or not\n");
    printf("\t2 = Know the number of polynomials in the set\n");
    printf("\t3 = Add a polynomial at the end of the set\n");
    printf("\t4 = Add a polynomial front of the set\n");
    printf("\t5 = Print the set of polynomials\n");
    printf("\t6 = Print a polynomial located at position x of the set\n");
    printf("\t7 = Delete end a  polynomial from the set\n");
    printf("\t8 = Delete front a  polynomial from the set\n");
    printf("\t9 = Sum two polynomials\n");
   printf("\t10 = Evaluate the derivative of polynomial located at position x of the set\n");
   printf("\t11 = Evaluate a polynomial located at position x of the set at X0 that's P(X0)\n");
   printf("\t13 = Know the degree of a polynomial located at position x of the set\n");
   printf("\t14 = clear the set of polynomial\n");
   printf("\t15 = Exit the program\n");
}