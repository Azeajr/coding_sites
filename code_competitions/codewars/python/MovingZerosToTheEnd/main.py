def move_zeros(lst):
    return [x for x in lst if x != 0] + [x for x in lst if x == 0]

# Best solution IMO
# def move_zeros(array):
#     return sorted(array, key=lambda x: x==0 and type(x) is not bool)


list1 = [1, 2, 0, 1, 0, 1, 0, 3, 0, 1]
ans1 = [1, 2, 1, 1, 3, 1, 0, 0, 0, 0]

list2 = [9, 0, 0, 9, 1, 2, 0, 1, 0, 1, 0, 3, 0, 1, 9, 0, 0, 0, 0, 9]
ans2 = [9, 9, 1, 2, 1, 1, 3, 1, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]


print(move_zeros(list1))
assert move_zeros(list1) == ans1
assert move_zeros(list2) == ans2