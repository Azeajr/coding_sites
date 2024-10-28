from functools import reduce


def count_developers(lst):
    # Your code here
    return reduce(
        lambda acc, dev: acc + 1
        if dev.get("continent") == "Europe" and dev.get("language") == "JavaScript"
        else acc,
        lst,
        0,
    )


list1 = [
    {
        "firstName": "Noah",
        "lastName": "M.",
        "country": "Switzerland",
        "continent": "Europe",
        "age": 19,
        "language": "JavaScript",
    },
    {
        "firstName": "Maia",
        "lastName": "S.",
        "country": "Tahiti",
        "continent": "Oceania",
        "age": 28,
        "language": "JavaScript",
    },
    {
        "firstName": "Shufen",
        "lastName": "L.",
        "country": "Taiwan",
        "continent": "Asia",
        "age": 35,
        "language": "HTML",
    },
    {
        "firstName": "Sumayah",
        "lastName": "M.",
        "country": "Tajikistan",
        "continent": "Asia",
        "age": 30,
        "language": "CSS",
    },
]
list2 = [
    {
        "firstName": "Oliver",
        "lastName": "Q.",
        "country": "Australia",
        "continent": "Oceania",
        "age": 19,
        "language": "HTML",
    },
    {
        "firstName": "Lukas",
        "lastName": "R.",
        "country": "Austria",
        "continent": "Europe",
        "age": 89,
        "language": "HTML",
    },
]

print(count_developers(list1))
print(count_developers(list2))
