from datetime import date


def add_username(lst):
    return list(
        map(
            lambda x: {
                **x,
                "username": x["firstName"].lower()
                + x["lastName"][0].lower()
                + str(date.today().year - x["age"]),
            },
            lst,
        )
    )


list1 = [
    {
        "firstName": "Emily",
        "lastName": "N.",
        "country": "Ireland",
        "continent": "Europe",
        "age": 30,
        "language": "Ruby",
    },
    {
        "firstName": "Nor",
        "lastName": "E.",
        "country": "Malaysia",
        "continent": "Asia",
        "age": 20,
        "language": "Clojure",
    },
]


print(add_username(list1))
