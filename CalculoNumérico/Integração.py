import numpy as np
from scipy.stats import norm
from scipy.integrate import quad

# Parâmetros
n = 100.0
media_blackjack = 0.4222
desvio_padrao = 4.974
x = 50.0

# Parâmetros para a distribuição normal
media = n * media_blackjack
desvio = np.sqrt(n) * desvio_padrao

# Define a função f(x) usando a distribuição normal
def f(x):
    return (1 / (desvio_padrao * np.sqrt(2 * np.pi))) * np.exp(-0.5 * ((x - media) / desvio_padrao) ** 2)

# Calcula a probabilidade usando a distribuição normal acumulada
resultado, erro = quad(f, x, np.inf)

print(resultado)
print(erro)
