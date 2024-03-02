#include <stdio.h>
#include <gsl/gsl_poly.h>

import math

def deg3():
    print("This is a third degree polynomial calculator.")
    print("Please enter four numbers.")
    a = int(input())
    b = int(input())
    c = int(input())
    d = int(input())

# Apply Cardano's compressed method to find x root, broken up into different variables.
p = (-1 * b)/(3 * a)
q = p ** 3 + (b * c - (3 * a * d))/ (6 * (a ** 2)) 
r = c / (3 * a)

x = (q + (q**2 + (r - p**2)**3) **1/2) **1/3 + (q + (q**2 + (r - p**2)**3) **1/2) **1/3 + p
print("The root is:", x)

# Applies final cubic formula, and returns.
total = (a * x**3) + (b * x**2) + (c * x) + d
total = round(total, 3)
return total

# If discr > 0, then the equation has three distinct real roots.
# If discr = 0, then the equation has a multiple root and all its roots are real.
# If discr < 0, then the equation has one real root and
# two nonreal complex conjugate roots.