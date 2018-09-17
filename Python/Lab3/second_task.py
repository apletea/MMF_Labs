def main():
    f = open("second_task.txt", "r")

    n = int(f.readline())

    files = {}
    for i in range(n):
        temp = f.readline().split()
        files[temp[0]] = temp[1:]

    print files

    m = int(f.readline())
    for i in range(m):
        temp = f.readline().split()
        if temp[1] in files[temp[0]]:
            print "OK"
        else:
            print "Access denied"

    f.close()


main()
