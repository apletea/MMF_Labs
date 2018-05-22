def main():
    bd = sorted(map(lambda x: tuple([x.split()[0], x.split()[1], int(x.split()[2])]), open("first_task.txt", "r").read().split("\n")))
    print bd

    user_list = {}
    for index, user in enumerate(bd):
        if user[0] not in user_list:
            user_list[user[0]] = {}

        if user[1] not in user_list[user[0]]:
            user_list[user[0]][user[1]] = 0

        user_list[user[0]][user[1]] += user[2]

    for key in sorted(user_list):
        print "%s: %s" % (key, user_list[key])


main()
