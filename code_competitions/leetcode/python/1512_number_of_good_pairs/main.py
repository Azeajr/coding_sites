import unittest


def numIdenticalPairs(nums: list[int]) -> int:
    freq: dict[int, int] = {}
    count = 0
    for num in nums:
        if num in freq:
            count += freq[num]
            freq[num] += 1
        else:
            freq[num] = 1
    return count


class Test(unittest.TestCase):
    def test_numIdenticalPairs(self):
        self.assertEqual(numIdenticalPairs([1, 2, 3, 1, 1, 3]), 4)
        self.assertEqual(numIdenticalPairs([1, 1, 1, 1]), 6)
        self.assertEqual(numIdenticalPairs([1, 2, 3]), 0)


if __name__ == "__main__":
    unittest.main()
