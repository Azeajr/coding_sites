from functools import reduce


def add_age(x, y):
    if y["age"] >= 10 and y["age"] <= 100:
        x.add(y["age"] // 10 * 10)
    elif y["age"] > 100:
        x.add(100)
    return x


def is_age_diverse(lst):
    return len(reduce(add_age, lst, set())) == 10
    # Better
    # arr = list(map(lambda x: x["age"] // 10, lst))
    # return any(x >= 10 for x in arr) and all(i in arr for i in range(1, 10))

list1 = [
    {
        "firstName": "Harry",
        "lastName": "K.",
        "country": "Brazil",
        "continent": "Americas",
        "age": 19,
        "language": "Python",
    },
    {
        "firstName": "Kseniya",
        "lastName": "T.",
        "country": "Belarus",
        "continent": "Europe",
        "age": 29,
        "language": "JavaScript",
    },
    {
        "firstName": "Jing",
        "lastName": "X.",
        "country": "China",
        "continent": "Asia",
        "age": 39,
        "language": "Ruby",
    },
    {
        "firstName": "Noa",
        "lastName": "A.",
        "country": "Israel",
        "continent": "Asia",
        "age": 40,
        "language": "Ruby",
    },
    {
        "firstName": "Andrei",
        "lastName": "E.",
        "country": "Romania",
        "continent": "Europe",
        "age": 59,
        "language": "C",
    },
    {
        "firstName": "Maria",
        "lastName": "S.",
        "country": "Peru",
        "continent": "Americas",
        "age": 60,
        "language": "C",
    },
    {
        "firstName": "Lukas",
        "lastName": "X.",
        "country": "Croatia",
        "continent": "Europe",
        "age": 75,
        "language": "Python",
    },
    {
        "firstName": "Chloe",
        "lastName": "K.",
        "country": "Guernsey",
        "continent": "Europe",
        "age": 88,
        "language": "Ruby",
    },
    {
        "firstName": "Viktoria",
        "lastName": "W.",
        "country": "Bulgaria",
        "continent": "Europe",
        "age": 99,
        "language": "PHP",
    },
    {
        "firstName": "Piotr",
        "lastName": "B.",
        "country": "Poland",
        "continent": "Europe",
        "age": 1,
        "language": "JavaScript",
    },
]


print(is_age_diverse(list1))
