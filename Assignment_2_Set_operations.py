class Set:
	
	def createSet(self):
		s=[]
		n=int(input("Enter number of elements in set : "))
		for i in range(n):
			element=int(input())
			if(element not in s):
				s.append(element)
			else:
				print("Element is all ready Exist")
				n=n+1
		return s
		
	def Add(self,s):
		element=int(input("Enter your Element to be Insert : " ))
		if(element not in s):
			s.append(element)
			print("Element Added successfully")
			print(s)
		else:
			print("Element is all ready Exist")
			
	def Remove(self,s):
		element=int(input("Enter your Element to be Remove : " ))
		if(element not in s):
			print("Element is Not Exist")
		else:
			s.remove(element)
			print("Element Removed successfully")
			print(s)
			
	def Contains(self,s):
		element=int(input("Enter your Element for Search : " ))
		if(element not in s):
			return False
		else:
			return True
			
	def Size(self,s):
		count=0
		for i in s:
			count=count+1
		print("Size of the Set is ",count)
		
			
	def Union(self,s1,s2):
		s=[]
		for i in s1:
			s.append(i)
		for i in s2:
			if(i not in s ):
				s.append(i)
		print("Union : ",s)
				
	def Intersection(self,s1,s2):
		s=[]
		for i in s1:
			if(i in s2):
				s.append(i)
		for i in s2:
			if(i in s1 and i not in s):
				s.append(i)
		print("Intersection : ",s)
		
	def Diffrence(self,s1,s2):
		s=[]
		for i in s1:
			if(i not in s2):
				s.append(i)
		print("Diffrence : ",s)
		
	def Subset(self,s1,s2):
		for i in s2:
			if(i not in s1):
				return False
		return True
s1=Set()	

set1=s1.createSet()

s1.Add(set1)

s1.Remove(set1)

res=s1.Contains(set1)
if(res):
	print("Element is Present!!!")
else:
	print("Element is Not Present!!!")

s1.Size(set1)
print()
print("Enter two sets to prform Set Operation on It ")
print()
print()
firstSet=s1.createSet()
secondSet=s1.createSet()
print("Your First Set : ",firstSet)
print("Your Second Set : ",secondSet)

s1.Union(firstSet,secondSet)

s1.Intersection(firstSet,secondSet)

s1.Diffrence(firstSet,secondSet)

res=s1.Subset(firstSet,secondSet)
if(res):
	print("Subset!!!")
else:
	print("Not Subset!!!")















