import numpy as np
import matplotlib.pyplot as plt


temperatura=np.genfromtxt("circulo.txt",delimiter=",",filling_values="2" )
plt.imshow(temperatura)
plt.show()
