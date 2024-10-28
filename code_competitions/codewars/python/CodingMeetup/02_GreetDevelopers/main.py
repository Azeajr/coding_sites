def greet_developers(lst):
    # your code here
    return list(
        map(
            lambda x: {
                **x,
                "greeting": f"Hi {x['firstName']}, what do you like the most about {x['language']}?",
            },
            lst,
        )
    )


list1 = [
    {
        "firstName": "Sofia",
        "lastName": "I.",
        "country": "Argentina",
        "continent": "Americas",
        "age": 35,
        "language": "Java",
    },
    {
        "firstName": "Lukas",
        "lastName": "X.",
        "country": "Croatia",
        "continent": "Europe",
        "age": 35,
        "language": "Python",
    },
    {
        "firstName": "Madison",
        "lastName": "U.",
        "country": "United States",
        "continent": "Americas",
        "age": 32,
        "language": "Ruby",
    },
]


for obj in greet_developers(list1):
    print(obj)
