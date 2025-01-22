# /// script
# requires-python = ">=3.12"
# dependencies = [
#     "icecream==2.1.4",
# ]
# ///

import marimo

__generated_with = "0.10.15"
app = marimo.App(width="full")


@app.cell
def _(mo):
    mo.image("118_pascals_triangle/PascalTriangleAnimated2.gif")
    return


@app.cell
def _(mo):
    mo.md(
        r"""
        #118. Pascal's Triangle

        Given an integer numRows, return the first numRows of Pascal's triangle.

        In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


        - Example 1:

            Input: numRows = 5
            Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
      
        - Example 2:

            Input: numRows = 1
            Output: [[1]]
     

        Constraints:
        1 <= numRows <= 30
        """
    )
    return


@app.cell
def _():
    from typing import NamedTuple
    from icecream import ic


    class Solution:
        def generate(self, numRows: int) -> list[list[int]]:
            dp = [None] * max((numRows + 1), 3)
            dp[1] = [[1]]
            dp[2] = [[1], [1, 1]]
            if numRows > 0 and numRows <= 2:
                return dp[numRows]

            for i in range(3, numRows + 1):
                if dp[i - 1]:
                    temp = [
                        first + second
                        for first, second in zip(dp[i - 1][-1], dp[i - 1][-1][1:])
                    ]

                    dp[i] = dp[i - 1] + [[1] + temp + [1]]

            return dp[numRows]
    return NamedTuple, Solution, ic


@app.cell
def _(NamedTuple, Solution):
    class Data(NamedTuple):
        input: int
        output: list[list[int]]


    test_data = [
        Data(input, output)
        for input, output in [
            (5, [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]),
            (1, [[1]]),
        ]
    ]

    solution = Solution()

    for datum in test_data:
        assert solution.generate(datum.input) == datum.output
    return Data, datum, solution, test_data


@app.cell
def _():
    import marimo as mo
    return (mo,)


if __name__ == "__main__":
    app.run()
