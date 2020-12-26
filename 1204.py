import numpy as np
from math import sqrt

while True:
    try:
        x, y, vx, vy, a, b = map(int, input().split())
        
        p = np.array([x, y])
        v = np.array([vx, vy])
        cont = 0

        while True:
            x,y = p
            vx, vy = v
            t = (-((vx*x)/(a*a)) - (vy*y)/(b*b) + sqrt(b*b*vx*vx + a*a*vy*vy - vy*vy*x*x + 2*vx*vy*x*y - vx*vx*y*y)/(a*b))/(vx*vx/(a*a) + vy*vy/(b*b))
            p = p + t*v
            print("%.3f %.3f" %(p[0], p[1]))

            psi = np.array([-2*p[1]/(b*b), 2*p[0]/(a*a)])
            psi = psi/np.linalg.norm(psi)
            v = 2*np.dot(v, psi)*psi - v
            cont += 1
            if cont >= 2:
                break
    except EOFError:
        break
