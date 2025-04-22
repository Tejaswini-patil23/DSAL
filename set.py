class SetOperations:
    def __init__(self):
        self.setA = []
        self.setB = []

    def insert(self):
        n1 = int(input("Number of elements in SET A:\t"))
        for i in range(n1):
            nm = int(input(f"Element {i+1} in SET A:\t"))
            if nm not in self.setA:
                self.setA.append(nm)

        n2 = int(input("Number of elements in SET B:\t"))
        for i in range(n2):
            nm = int(input(f"Element {i+1} in SET B:\t"))
            if nm not in self.setB:
                self.setB.append(nm)

    def display(self):
        print("SET A:\t", self.setA)
        print("SET B:\t", self.setB)

    # def union(self):
    #     res = []
    #     for i in self.setA:
    #         res.append(i)
    #     for j in self.setB:
    #         duplicate = False
    #         for k in res:
    #             if j == k:
    #                 duplicate = True  
    #                 break  
    #         if not duplicate:
    #             res.append(j)

    #     return res

    #     print("Union:\t", res) 

    def union(self):
        res = []
        for i in self.setA:
            res.append(i)
        for i in self.setB:
            if i not in res:
                res.append(i)

        print("Union:\t", res)


    def intersection(self):
        res = []
        for i in self.setA:
            if i in self.setB and i not in res:
                res.append(i)
        print("Intersection:\t", res)

    def difference(self):
        res = []
        for i in self.setA:
            if i not in self.setB:
                res.append(i)
        for i in self.setB:
            if i not in self.setA:
                res.append(i)
        print("Difference:\t", res)

    def find(self):
        t = int(input("1. SET A\n2. SET B\nChoose an option (1/2):\t"))
        s = int(input("Element to search:\t"))
        found = False

        if t == 1:
            if s in self.setA:
                found = True
        elif t == 2:
            if s in self.setB:
                found = True

        print("Element exists." if found else "Element does not exist.")

    def remove(self):
        t = int(input("1. SET A\n2. SET B\nChoose an option (1/2):\t"))
        s1 = int(input("Element to be deleted:\t"))
        removed = False

        if t == 1:
            if s1 in self.setA:
                self.setA.remove(s1)
                removed = True
        elif t == 2:
            if s1 in self.setB:
                self.setB.remove(s1)
                removed = True

        if removed:
            print(f"Element {s1} removed successfully.")
        else:
            print(f"Element {s1} does not exist in the selected set.")

        self.display()

    def size(self):
        print("Size of SET A:\t", len(self.setA))
        print("Size of SET B:\t", len(self.setB))

    def iterator(self, set_choice):
        if set_choice == 1:
            return iter(self.setA)
        elif set_choice == 2:
            return iter(self.setB)

    def subset(self):
        set5 = []
        flag = False
        for i in self.setB:
            if i in self.setA:
                set5.append(i)
                flag = True

        if flag and len(set5) == len(self.setB):
            print("Subset", set5)
            print("SET B is a subset of SET A.")
        else:
            print("SET B is NOT Subset of SET A.")


if __name__ == "__main__":
    operations = SetOperations()

    while True:
        print("--- SET OPERATIONS ---")
        print("1 -> Insert")
        print("2 -> Display")
        print("3 -> Union")
        print("4 -> Intersection")
        print("5 -> Difference")
        print("6 -> Size of Sets")
        print("7 -> Find")
        print("8 -> Delete an Element")
        print("9 -> Subset")
        print("10 -> Iterate Over Set")
        print("0 -> Exit")

        ch = int(input("Choose an option (0-10):\t"))

        if ch == 1:
            operations.insert()
        elif ch == 2:
            operations.display()
        elif ch == 3:
            operations.union()
        elif ch == 4:
            operations.intersection()
        elif ch == 5:
            operations.difference()
        elif ch == 6:
            operations.size()
        elif ch == 7:
            operations.find()
        elif ch == 8:
            operations.remove()
        elif ch == 9:
            operations.subset()
        elif ch == 10:
            set_choice = int(input("1. SET A\n2. SET B\nChoose a set to iterate over (1/2):\t"))
            for element in operations.iterator(set_choice):
                print(element)
        elif ch == 0:
            print("\n## END OF CODE\n")
            break
        else:
            print("Please choose a valid option (0-10).")

