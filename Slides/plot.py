#!/usr/bin/env python

# Plots for 06-cuadratura

from scipy.interpolate import lagrange
import matplotlib.pyplot as plt
import numpy as np

# Make up a function

xval = [0,   1,   2,   3,   4]
yval = [0.5, 1.5, 1.0, 1.5, 2.5]

poly = lagrange(xval, yval)

xx = np.linspace(0, 4, 200)
yy = [poly(x) for x in xx]

## Rectangles

plt.figure(1)

# Plot the function

plt.xticks([x for x in range(5)], []);
plt.yticks([]);

plt.plot(xx, yy, 'b')

# Plot the stair for rectangles, plot vertical lines

xr = np.linspace(0, 4, 5)
yr = [poly(x) for x in range(4)]

plt.stairs(yr, xr)
for k in range (5):
    plt.plot([xval[k], xval[k]], [0, yval[k]], 'g')

plt.savefig('rectangles.pdf')

## Midpoints

plt.figure(2)

# Plot the function

plt.xticks([x for x in range(5)], []);
plt.yticks([]);

plt.plot(xx, yy, 'b')

# Plot the stair for midpoints

xm = np.linspace(0, 4, 5)
ym = [poly(x + 0.5) for x in range(4)]

plt.stairs(ym, xm)
for k in range(4):
    xv = (xval[k] + xval[k + 1]) / 2
    yv = poly(xv)
    plt.plot([xv, xv], [0, yv], 'g--')
    plt.plot([xval[k], xval[k]], [0, yv], 'g')
    plt.plot([xval[k + 1], xval[k + 1]], [0, yv], 'g')
plt.plot([xval[4], xval[4]], [0, yval[4]], 'g')

plt.savefig('midpoints.pdf')

## Trapezoids

plt.figure(3)

# Plot the function

plt.xticks([x for x in range(5)], []);
plt.yticks([]);

plt.plot(xx, yy, 'b')

# Plot the trapezoids

plt.plot(range(5), [poly(x) for x in range(5)])
for k in range (5):
    plt.plot([xval[k], xval[k]], [0, yval[k]], 'g')

plt.savefig('trapezoids.pdf')

## Simpson (quadratic)

plt.figure(4)

# Plot the function
xval = [0,   1,   2,   3,   4]
yval = [0.2, 1.3, 0.7, 1.2, 2.2]

poly = lagrange(xval, yval)

plt.xticks([0, 2, 4], []);
plt.yticks([]);

xx = np.linspace(0, 4, 200)
yy = [poly(x) for x in xx]

plt.plot(xx, yy, 'b')

# Plot the quadratic

xval2 = [0,   2,   4]
yval2 = [0.2, 0.7, 2.2]

poly2 = lagrange(xval2, yval2)

yq = [poly2(x) for x in xx]

plt.plot(xx, yq)
for k in range(3):
    plt.plot([xval2[k], xval2[k]], [0, yval2[k]], 'g--')

plt.savefig('quadratic.pdf')
