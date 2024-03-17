def mdc(a, b):
    while True:
        r = a % b
        if r == 0:
            break
        a, b = b, r
    return b


def mmc(a, b):
    return a * b // mdc(a, b)
