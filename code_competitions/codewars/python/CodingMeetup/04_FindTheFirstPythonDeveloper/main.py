def get_first_python(users):
    return (
        next(
            (
                f"{x['first_name']}, {x['country']}"
                for x in users
                if x["language"] == "Python"
            ),
            None,
        )
        or "There will be no Python developers"
    )

    # Better solution
    # return next(
    #     (
    #         f"{x['first_name']}, {x['country']}"
    #         for x in users
    #         if x["language"] == "Python"
    #     ),
    #     "There will be no Python developers",
    # )


list1 = [
    {
        "first_name": "Mark",
        "last_name": "G.",
        "country": "Scotland",
        "continent": "Europe",
        "age": 22,
        "language": "JavaScript",
    },
    {
        "first_name": "Victoria",
        "last_name": "T.",
        "country": "Puerto Rico",
        "continent": "Americas",
        "age": 30,
        "language": "Python",
    },
    {
        "first_name": "Emma",
        "last_name": "B.",
        "country": "Norway",
        "continent": "Europe",
        "age": 19,
        "language": "Clojure",
    },
]

list2 = [
    {
        "first_name": "Kseniya",
        "last_name": "T.",
        "country": "Belarus",
        "continent": "Europe",
        "age": 29,
        "language": "JavaScript",
    },
    {
        "first_name": "Amar",
        "last_name": "V.",
        "country": "Bosnia and Herzegovina",
        "continent": "Europe",
        "age": 32,
        "language": "Ruby",
    },
]

list3 = [
    {
        "first_name": "Sofia",
        "last_name": "P.",
        "country": "Italy",
        "continent": "Europe",
        "age": 41,
        "language": "Clojure",
    },
    {
        "first_name": "Jayden",
        "last_name": "P.",
        "country": "Jamaica",
        "continent": "Americas",
        "age": 42,
        "language": "JavaScript",
    },
    {
        "first_name": "Sou",
        "last_name": "B.",
        "country": "Japan",
        "continent": "Asia",
        "age": 43,
        "language": "Python",
    },
    {
        "first_name": "Rimas",
        "last_name": "C.",
        "country": "Jordan",
        "continent": "Asia",
        "age": 44,
        "language": "Java",
    },
]


print(get_first_python(list1))
print(get_first_python(list2))
print(get_first_python(list3))
