# Importação de módulos auxiliares
import numpy as np
import matplotlib.pyplot as plt

# Importação de bisect
from scipy.optimize import bisect

l=10
g=9.8
k=80

# X = Massa 

# função = 
def f(x):
    return l + ((x * g) / k) * ( 1 + np.sqrt(1 + 2*((k*l) / x * g )))



# Analise gráfica simples
x = np.linspace(40,180)
plt.plot(x,f(x))
plt.axhline(y=0,color='r', linestyle='--')
plt.show()

"""
# Resolução com bisect 
x = bisect(f,-10,-9) # raiz
print(f'Raiz: x = {x:.3f}') # impressão de valor
"""