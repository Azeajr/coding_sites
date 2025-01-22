# /// script
# requires-python = ">=3.12"
# dependencies = [
#     "icecream==2.1.4",
#     "marimo",
# ]
# ///

import marimo

__generated_with = "0.10.15"
app = marimo.App(width="full")


@app.cell
def _(mo):
    mo.md(
        """
        # 70. Climbing Stairs

        You are climbing a staircase. It takes n steps to reach the top.

        Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

     

        - Example 1:
            Input: n = 2
            Output: 2
            Explanation: There are two ways to climb to the top.
            1. 1 step + 1 step
            2. 2 steps
        - Example 2:
            Input: n = 3
            Output: 3
            Explanation: There are three ways to climb to the top.
            1. 1 step + 1 step + 1 step
            2. 1 step + 2 steps
            3. 2 steps + 1 step
     

        Constraints:

        1 <= n <= 45
        """
    )
    return


@app.cell
def _():
    class Solution:
        def climbStairs(self, n: int) -> int:
            dp = [None] * (n + 1)
            dp[0] = 1
            dp[1] = 1

            for i in range(2, n + 1):
                if dp[i - 2] and dp[i - 1]:
                    dp[i] = dp[i - 2] + dp[i - 1]

            return dp[n]
    return (Solution,)


@app.cell
def _(Solution):
    from typing import NamedTuple
    from icecream import ic


    class Data(NamedTuple):
        input: int
        output: int


    test_data = [
        Data(input, output)
        for input, output in [(1, 1), (2, 2), (3, 3), (4, 5), (5, 8)]
    ]

    solution = Solution()

    for datum in test_data:
        assert solution.climbStairs(datum.input) == datum.output
    return Data, NamedTuple, datum, ic, solution, test_data


@app.cell
def _():
    import marimo as mo
    return (mo,)


if __name__ == "__main__":
    app.run()
