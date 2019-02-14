import matplotlib
import matplotlib.pyplot as plt

matplotlib.use('Agg')

c = plt.Circle((0, 0), radius = 5, color='blue', linewidth=2, fill=False)
ax = plt.gca()
ax.add_patch(c)
plt.axis('scaled')
plt.show()
