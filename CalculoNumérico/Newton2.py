import numpy as np
import matplotlib.pyplot as plt 
import sympy as sy

from scipy.optimize import newton 

# função anônima
g = lambda x: x**3 - 3.23*x**2 - 5.54*x + 9.84

# função (User-Defined Function)
def f(x): 
    return x**3 - 3.23*x**2 - 5.54*x + 9.84

# 1a. derivada
def df(x):
    return 3*x**2 - 2*3.23*x - 5.54

x = np.linspace(-4,5)
plt.plot(x,f(x));
plt.plot(x,df(x));
plt.axhline(y=0,color='k',ls='--');
plt.axvline(x=0,color='r',ls='--');
plt.legend(['$f(x)$','$f\'(x)$','$y=0$','$x=0$'],
           loc='upper right',
           ncol=1,
           bbox_to_anchor = (0,0));
plt.show()

# resolução com newton 
x0 = -1.
x = newton(f,x0) # raiz 
print('Raiz: x = %f' % x)