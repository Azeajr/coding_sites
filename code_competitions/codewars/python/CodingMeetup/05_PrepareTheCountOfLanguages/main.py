from functools import reduce
# from collections import Counter

def count_languages(lst):
    def language_counter(acc, val):
        acc[val["language"]] = acc.get(val["language"], 0) + 1
        return acc

    return reduce(language_counter, lst, {})
    # return Counter([d['language'] for d in lst])


list1 = [
    {
        "firstName": "Noah",
        "lastName": "M.",
        "country": "Switzerland",
        "continent": "Europe",
        "age": 19,
        "language": "C",
    },
    {
        "firstName": "Anna",
        "lastName": "R.",
        "country": "Liechtenstein",
        "continent": "Europe",
        "age": 52,
        "language": "JavaScript",
    },
    {
        "firstName": "Ramon",
        "lastName": "R.",
        "country": "Paraguay",
        "continent": "Americas",
        "age": 29,
        "language": "Ruby",
    },
    {
        "firstName": "George",
        "lastName": "B.",
        "country": "England",
        "continent": "Europe",
        "age": 81,
        "language": "C",
    },
]

answer = {"C": 2, "JavaScript": 1, "Ruby": 1}


print(count_languages(list1))

assert count_languages(list1) == answer
