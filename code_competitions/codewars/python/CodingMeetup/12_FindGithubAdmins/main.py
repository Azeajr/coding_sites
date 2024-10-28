def find_admin(lst, lang):
    return list(
        filter(lambda x: x["githubAdmin"] == "yes" and x["language"] == lang, lst)
    )
    # Better
    # return [i for i in lst if i['language']==lang and i['githubAdmin']=='yes']


list1 = [
    {
        "firstName": "Harry",
        "lastName": "K.",
        "country": "Brazil",
        "continent": "Americas",
        "age": 22,
        "language": "JavaScript",
        "githubAdmin": "yes",
    },
    {
        "firstName": "Kseniya",
        "lastName": "T.",
        "country": "Belarus",
        "continent": "Europe",
        "age": 49,
        "language": "Ruby",
        "githubAdmin": "no",
    },
    {
        "firstName": "Jing",
        "lastName": "X.",
        "country": "China",
        "continent": "Asia",
        "age": 34,
        "language": "JavaScript",
        "githubAdmin": "yes",
    },
    {
        "firstName": "Piotr",
        "lastName": "B.",
        "country": "Poland",
        "continent": "Europe",
        "age": 128,
        "language": "JavaScript",
        "githubAdmin": "no",
    },
]


print(find_admin(list1, "JavaScript"))
