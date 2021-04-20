with open("import.txt") as file :
    for i in file:
        list = i.split("\n")[0]

        str = "#pragma comment(linker, \"/EXPORT:{name}=sqlite3back.{name}\")".format(name=list.strip())
        print(str)