class HashTable:
    def __init__(self):
        self.m = int(input("Enter Table Size : "))
        self.hashtable = [None] * self.m
        self.elecount = 0
        self.comp = 0
        print(self.hashtable)
        
    def hashfun(self, key):
        return key % self.m
        
    def isFull(self):
        if self.elecount == self.m:
            return True
        else:
            return False
            
    def linearProbing(self, key, data):
        index = self.hashfun(key)
        self.comp = 0
        i = 1
        if self.hashtable[index] == None:
            self.hashtable[index] = [key, data]
            print("Data inserted at ", index)
            print(self.hashtable)
            print("No of Comparison ", self.comp)
        else:
            if self.isFull():
                print("Hash Table is Full!!!")
                return
            while self.hashtable[index] != None:
                index = (index + i) % self.m
                self.comp = self.comp + 1
                i = i + 1
                self.hashtable[index] = [key, data]
                self.elecount = self.elecount + 1      
            print("Data inserted at ", index)
            print(self.hashtable)
            print("No of Comparison ", self.comp)
        
    def linearProbingSearch(self, key, data):
        index = self.hashfun(key)
        self.comp = 0
        i = 0
        if self.hashtable[index] == [key, data]:
            print(key, " found at index ", index)
            print(self.hashtable)
            print("No of Comparison ", self.comp)
        else:
            while self.hashtable[index] != None:
                index = (index + i) % self.m
                if self.hashtable[index] == [key, data]:
                    print(key, " found at index ", index)
                    print(self.hashtable)
                    print("No of Comparison ", self.comp)
                    return
                self.comp = self.comp + 1
                i = i + 1
            print("Element is not in Hash Table")

    def quadraticProbingSearch(self, key, data):
        index = self.hashfun(key)
        self.comp = 0
        i = 0
        if self.hashtable[index] == [key, data]:
            print(key, " found at index ", index)
            print(self.hashtable)
            print("No of Comparison ", self.comp)
        else:
            while self.hashtable[index] != None:
                index = ((index) + (i * i)) % self.m
                if self.hashtable[index] == [key, data]:
                    print(key, " found at index ", index)
                    print(self.hashtable)
                    print("No of Comparison ", self.comp)
                    return
                self.comp = self.comp + 1
                i = i + 1
            print("Element is not in Hash Table")

    def quadraticProbing(self, key, data):
        index = self.hashfun(key)
        self.comp = 0
        i = 0
        if self.hashtable[index] == None:
            self.hashtable[index] = [key, data]
        else:
            if self.isFull():
                print("Hash Table is Full")
            else:
                while self.hashtable[index] != None:
                    index = ((index) + (i * i)) % self.m
                    self.comp = self.comp + 1
                    i = i + 1
                self.hashtable[index] = [key, data]
                self.elecount = self.elecount + 1
                print("Data inserted at ", index)
                print(self.hashtable)
                print("No of Comparison ", self.comp)

flag = True
h1 = HashTable()
h2 = HashTable()
while flag:
    print("*********************MENU****************")
    print("1. Linear Probing")
    print("2. Quadratic Probing")
    print("3. Exit")
    ch = int(input("Enter your choice : "))
    if ch == 1:
        while True:
            print("***************Linear Probing***************")
            print("1. Insert")
            print("2. Search")
            print("3. Exit")
            ch2 = int(input("Enter your choice : "))
            if ch2 == 1:
                name = input("Enter your Name : ")
                key = int(input("Enter your Telephone Number : "))
                h1.linearProbing(key, name)
            if ch2 == 2:
                name = int(input("Enter your Name : "))   
                key = int(input("Enter your Telephone Number : ")) 
                h1.linearProbingSearch(key, name)
            if ch2 == 3:
                break
    if ch == 2:
        while True:
            print("***************Quadratic Probing***************")
            print("1. Insert")
            print("2. Search")
            print("3. Exit")
            ch3 = int(input("Enter your choice : "))
            if ch3 == 1:
                name = input("Enter your Name : ")
                key = int(input("Enter your Telephone Number : "))
                h2.quadraticProbing(key, name)
            if ch3 == 2:
                name = int(input("Enter your Name : "))   
                key = int(input("Enter your Telephone Number to be Search : "))   
                h2.quadraticProbingSearch(key, name)
            if ch3 == 3:
                break
    if ch == 3:
        flag = False
