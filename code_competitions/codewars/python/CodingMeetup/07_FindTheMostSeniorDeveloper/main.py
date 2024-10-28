from functools import reduce


def find_senior(lst):
    max_age = reduce(lambda x, y: x if x > y["age"] else y["age"], lst, 0)
    return list(filter(lambda x: x["age"] == max_age, lst))


# Better
# def find_senior(lst):
#     max_age = max(lst, key=lambda x: x["age"])
#     return [x for x in lst if x["age"] == max_age]

# Event Better
# def find_senior(lst):
#     max_age = max(x["age"] for x in lst)
#     return [x for x in lst if x["age"] == max_age]


list1 = [
    {
        "firstName": "Gabriel",
        "lastName": "X.",
        "country": "Monaco",
        "continent": "Europe",
        "age": 49,
        "language": "PHP",
    },
    {
        "firstName": "Odval",
        "lastName": "F.",
        "country": "Mongolia",
        "continent": "Asia",
        "age": 38,
        "language": "Python",
    },
    {
        "firstName": "Emilija",
        "lastName": "S.",
        "country": "Lithuania",
        "continent": "Europe",
        "age": 19,
        "language": "Python",
    },
    {
        "firstName": "Sou",
        "lastName": "B.",
        "country": "Japan",
        "continent": "Asia",
        "age": 49,
        "language": "PHP",
    },
]

print(find_senior(list1))
