import numpy as np


def main():
    n, m = map(int, raw_input("Enter n, m: ").split())
    print n, m

    matrix = np.array([
        [
            m if i == j else (
                m - abs(i - j) if m - abs(i - j) >= n and m >= n else (
                    -abs(i - j) - n if m - abs(i - j) < n <= m else (
                        m + abs(i - j) if m + abs(i - j) <= n and m < n else (
                            -2 * m - abs(i - j) + n if m + abs(i - j) > n > m else 999))))
            for j in range(n)
        ]
        for i in range(n)
    ])

    print matrix


main()
