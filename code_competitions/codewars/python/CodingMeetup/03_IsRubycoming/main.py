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


def is_ruby_coming(lst):
    return len([x for x in lst if x["language"] == "Ruby"]) > 0
    # return len(list(filter(lambda x: x["language"] == "Ruby", lst))) > 0

# def is_ruby_coming(lst): 
#     return any(x["language"] == "Ruby" for x in lst)