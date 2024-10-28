from functools import reduce


def all_continents(lst: list):
    def get_continents(acc: set, val: dict):
        acc.add(val["continent"])
        return acc

    return len(reduce(get_continents, lst, set())) == 5


# Best
# def all_continents(lst: list):
#     return len({x["continent"] for x in lst}) == 5


list1 = [
    {
        "firstName": "Fatima",
        "lastName": "A.",
        "country": "Algeria",
        "continent": "Africa",
        "age": 25,
        "language": "JavaScript",
    },
    {
        "firstName": "Agustín",
        "lastName": "M.",
        "country": "Chile",
        "continent": "Americas",
        "age": 37,
        "language": "C",
    },
    {
        "firstName": "Agustín",
        "lastName": "M.",
        "country": "Chile",
        "continent": "Americas",
        "age": 37,
        "language": "C",
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
        "firstName": "Laia",
        "lastName": "P.",
        "country": "Andorra",
        "continent": "Europe",
        "age": 55,
        "language": "Ruby",
    },
    {
        "firstName": "Oliver",
        "lastName": "Q.",
        "country": "Australia",
        "continent": "Oceania",
        "age": 65,
        "language": "PHP",
    },
]


print(all_continents(list1))
