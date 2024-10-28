from functools import reduce


def get_average(lst):
    return round(reduce(lambda x, y: x + y["age"], lst, 0) / len(lst))
    # Better
    # return round(sum(x["age"] for x in lst) / len(lst))


list1 = [
    {
        "firstName": "Maria",
        "lastName": "Y.",
        "country": "Cyprus",
        "continent": "Europe",
        "age": 30,
        "language": "Java",
    },
    {
        "firstName": "Victoria",
        "lastName": "T.",
        "country": "Puerto Rico",
        "continent": "Americas",
        "age": 70,
        "language": "Python",
    },
]


print(get_average(list1))
