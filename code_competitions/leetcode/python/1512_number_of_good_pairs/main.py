import unittest


# A pair (i, j) is called good if nums[i] == nums[j] and i < j.
def numIdenticalPairs(nums: list[int]) -> int:
    count = 0
    for j in range(len(nums)):
        for i in range(j):
            if nums[i] == nums[j]:
                count += 1
    return count


class Test(unittest.TestCase):
    def test_numIdenticalPairs(self):
        self.assertEqual(numIdenticalPairs([1, 2, 3, 1, 1, 3]), 4)
        self.assertEqual(numIdenticalPairs([1, 1, 1, 1]), 6)
        self.assertEqual(numIdenticalPairs([1, 2, 3]), 0)


if __name__ == "__main__":
    unittest.main()
