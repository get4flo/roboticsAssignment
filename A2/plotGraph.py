import matplotlib.pyplot as plt
import numpy as np

def q1(t):
    t_via = 5/2
    if t <= t_via:
        return -2 * np.pi / 25 * t**2 + 2 * np.pi / 125 * t ** 3
    else:
        return - np.pi / 4 - np.pi / 10 * (t - t_via) - np.pi / 25 * (t - t_via)**2 + 2 * np.pi / 125 * (t - t_via)**3

def q2(t):
    t_via = 5/2
    if t <= t_via:
        return 6 * np.pi / 25 * t**2 - 8 * np.pi / 125 * t ** 3
    else:
        return np.pi / 2 - 3 * np.pi / 25 * (t - t_via)**2 + 4 * np.pi / 125 * (t - t_via)**3

def q3(t):
    t_via = 5/2
    if t <= t_via:
        return 0
    else:
        return 0

def generate_graph():
    X = np.linspace(0, 5, num=100)
    Y1 = [q1(x) for x in X]
    Y2 = [q2(x) for x in X]
    Y3 = [q3(x) for x in X]

    ticks = [-np.pi / 2, -np.pi / 4, 0, np.pi / 4, np.pi / 2]
    labels = [r'$-\pi/2$', r'$-\pi/4$', r'$0$', r'$\pi/4$', r'$\pi/2$']

    plt.plot(X, Y1, label='q1')
    plt.plot(X, Y2, label='q2')
    plt.plot(X, Y3, label='q3')
    plt.legend()
    plt.xlabel("time (s)")
    plt.ylabel("rotation of joint (rad)")
    plt.yticks(ticks, labels)
    plt.show()

if __name__ == "__main__":
    generate_graph()