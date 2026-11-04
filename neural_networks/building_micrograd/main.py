import marimo

__generated_with = "0.25.2"
app = marimo.App(width="medium")


@app.cell
def _():
    import marimo as mo

    return (mo,)


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    from micrograd.engine import Value

    a = Value(-4.0)
    b = Value(2.0)
    c = a + b
    d = a * b + b**3
    c += c + 1
    c += 1 + c + (-a)
    d += d * 2 + (b + a).relu()
    d += 3 * d + (b - a).relu()
    e = c - d
    f = e**2
    g = f / 2.0
    g += 10.0 / f
    print(f"{g.data:.4f}")  # prints 24.7041, the outcome of this forward pass
    g.backward()
    print(
        f"{a.grad:.4f}"
    )  # prints 138.8338, i.e. the numberical value of dg/da
    print(
        f"{b.grad:.4f}"
    )  # prints 645.5773, i.e. the numberical value of dg/db
    """)
    return


@app.cell
def _():
    import math
    import numpy as np
    import matplotlib.pyplot as plt

    return np, plt


@app.function
def f(x):
    return 3 * x**2 - 4 * x + 5


@app.cell
def _():
    f(3.0)
    return


@app.cell
def _(np, plt):
    xs = np.arange(-5, 5, 0.25)
    ys = f(xs)
    plt.plot(xs, ys)
    return


@app.cell
def _():
    h = 0.00000000001
    x = 3.0
    (f(x + h) - f(x)) / h
    return


if __name__ == "__main__":
    app.run()
