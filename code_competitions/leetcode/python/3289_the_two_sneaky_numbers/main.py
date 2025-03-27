import unittest


def getSneakyNumbers(nums: list[int]) -> list[int]:
    temp = {}
    sneaky_numbers = []

    for num in nums:
        if num not in temp:
            temp[num] = True
        else:
            sneaky_numbers.append(num)

    return sneaky_numbers


class Test(unittest.TestCase):
    def test_getSneakyNumbers(self):
        self.assertCountEqual(getSneakyNumbers([0, 1, 1, 0]), [0, 1])
        self.assertCountEqual(getSneakyNumbers([0, 3, 2, 1, 3, 2]), [2, 3])
        self.assertCountEqual(
            getSneakyNumbers([7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2]), [4, 5]
        )


if __name__ == "__main__":
    unittest.main()
