#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Oct  5 14:46:25 2026

@author: khn4953a
"""

import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("resultats_oscillateur.txt")

x = data[:, 0]
y = data[:, 1]

w0=2
A=1
y_th = A*np.cos(w0*x)

plt.figure()
plt.plot(x, y, label="oscillateur ordre 2")
plt.plot(x, y_th, label="oscillateur theorique")
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.legend()
plt.show()