import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-4, 2, 500)
y = x**3 + 5*x**2 + 7*x + 2

plt.plot(x, y)
plt.show()