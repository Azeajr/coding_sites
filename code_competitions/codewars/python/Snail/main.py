import numpy as np


def snail(snail_map: list[list[int]]) -> list[int]:
    """
    Tests:
        >>> snail([[1,2,3],[4,5,6],[7,8,9]])
        [1, 2, 3, 6, 9, 8, 7, 4, 5]
        >>> snail([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]])
        [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
        >>> snail([[1,2,3],[8,9,4],[7,6,5]])
        [1, 2, 3, 4, 5, 6, 7, 8, 9]
    """
    data = np.array(snail_map)
    output = []

    while data.size:
        output.extend(map(int, data[0]))
        data = np.rot90(data[1:])

    return output
