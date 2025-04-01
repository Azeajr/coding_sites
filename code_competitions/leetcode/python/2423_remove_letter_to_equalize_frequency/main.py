import unittest
from collections import Counter
import timeit
from typing import Callable
from functools import partial


def equalFrequency_1(word: str) -> bool:
    freq = Counter(word)
    freq_counts = Counter(freq.values())

    if len(freq_counts) == 1:
        (f, how_many) = next(iter(freq_counts.items()))
        if f == 1 or how_many == 1:
            return True
        return False

    if len(freq_counts) > 2:
        return False

    (f1, c1), (f2, c2) = freq_counts.items()

    if (f1 == 1 and c1 == 1) or (f2 == 1 and c2 == 1):
        return True

    if abs(f1 - f2) == 1:
        if (f1 > f2 and c1 == 1) or (f2 > f1 and c2 == 1):
            return True

    return False


def equalFrequency_2(word: str):
    counts = Counter(Counter(word).values())

    if len(counts) == 1:
        return list(counts.keys())[0] == 1 or list(counts.values())[0] == 1

    if len(counts) == 2:
        f1, f2 = min(counts.keys()), max(counts.keys())
        return (f1 + 1 == f2 and counts[f2] == 1) or (f1 == 1 and counts[f1] == 1)

    return False


# -------------- TESTS --------------

param_list = [
    ("abcc", True),
    ("bac", True),
    ("abbcc", True),
    ("zz", True),
    ("a", True),
    ("ab", True),
    ("aaabb", True),
    ("aazz", False),
    ("ddaccb", False),
    ("babbdd", False),
]


class TestEqualFrequency(unittest.TestCase):
    # def test_equalFrequency(self):
    #     for word, expected in param_list:
    #         with self.subTest(word=word, expected=expected):
    #             result = equalFrequency_1(word)
    #             self.assertEqual(result, expected)

    def test_equalFrequency(self):
        functions = [equalFrequency_1, equalFrequency_2]
        for word, expected in param_list:
            for func in functions:
                with self.subTest(word=word, expected=expected, func=func.__name__):
                    result = func(word)
                    self.assertEqual(result, expected)


def benchmark(function: Callable):
    for word, _ in param_list:
        function(word)


if __name__ == "__main__":
    unittest.main(exit=False, verbosity=2)

    n = 1_000_000

    elapsed = timeit.timeit(partial(benchmark, equalFrequency_2), number=n)
    print(f"Elapsed time: {elapsed:.6f} sec for {n:_} executions for equalFrequency_2")

    elapsed = timeit.timeit(partial(benchmark, equalFrequency_1), number=n)
    print(f"Elapsed time: {elapsed:.6f} sec for {n:_} executions for equalFrequency_1")
