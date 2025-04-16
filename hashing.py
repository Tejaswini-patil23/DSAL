clients = []
client_name = []
m = int(input("Enter table size: "))
n = int(input("Enter number of clients: "))

for k in range(m):
	clients.append(' ')
	client_name.append(' ')

def linear():
	for i in range(n):
		no  = int(input("Enter telephone number of client for linear hashing: "))
		name = input("Enter name of client for linear hashing: ")
		key = no%m
		temp = key
		if(clients[key] == ' '):
			client_name[key] = name
			clients[key] = no
		else:
			while(1):
				if(clients[temp] != ' '):
					if(temp == m-1):
						temp = 0
					else:
						temp = temp + 1
				else: 
					client_name[temp] = name
					clients[temp] = no
					break

def display():
	for j in range(m):
		print(j," |", client_name[j],"|",  clients[j])
		
def search():
	searchTel = int(input("Enter number of the client that u want to search: "))
	h = searchTel%m
	temp = h 
	counter = 0  
	
	if(clients[temp] == searchTel):
		counter = counter + 1
		print("Number found at index: ", temp, "name of client is: ",client_name[temp])
		print("Number of comparison required to search required telephone number is: ",counter)
	else:
		counter = counter + 1
		while(1):
				if(clients[temp] != searchTel):
					counter = counter + 1
					if(temp == m-1):
						temp = 0
					else:
						temp = temp + 1
				else: 
					print("Number found at index: ", temp, "name of client is: ",client_name[temp])
					print("Number of comparison required to search required telephone number is: ",counter)
					break
	
clients1 = []
client_name1 = []

for k in range(m):
	clients1.append(' ')
	client_name1.append(' ')

def display1():
	for z in range(m):
		print(z," |", client_name1[z],"|",  clients1[z])

def double():
	for i in range(n):
		no  = int(input("Enter telephone number of client for double hashing: "))
		name = input("Enter name of client for double hashing: ")
		key = no%m
		h3 = key
		if(clients1[key] == ' '):
			client_name1[key] = name
			clients1[key] = no
		else:
			point = 0
			while(1): 
				if(clients1[h3] != ' '):
					point = point + 1
					h2 = 7 - (no%7)
					h3 = (key + (point * h2))%m
				else:
					client_name1[h3] = name
					clients1[h3] = no
					break

def search1():
	searchTel = int(input("Enter number of the client: "))
	h = searchTel%m
	temp = h
	counter = 0
	
	if(clients1[temp] == searchTel):
		counter = counter + 1
		print("Number found at index: ", temp, "name of client is: ",client_name1[temp])
		print("Number of comparison required to search required telephone number is: ",counter)
	else:
		counter = counter + 1
		point = 0
		while(1):
				if(clients1[temp] != searchTel):
					counter = counter + 1
					point = point + 1
					h2 = 7 - (searchTel%7)
					temp = (h + (point * h2))%m
				else: 
					print("Number found at index: ", temp, "name of client is: ",client_name1[temp])
					print("Number of comparison required to search required telephone number is: ",counter)
					break

def main():
	while(1):
		print("\n")
		print("YOUR CHOICES ARE")
		print("\n1. Linear Hashing \n2. Search (Linear hash) \n3. Double Hashing \n4. Search (Double Hash) \n5. Exit")
		n = int(input("Enter your choice: "))
		if(n == 1):
			linear()
			display()
		elif(n == 2):
			search()
		elif(n == 3):
			double()
			display1()
		elif(n == 4):
			search1()
		elif(n == 5):
			exit(0)
		elif(n<0 and n>5):
			print("Enter valid choice!!!")
main()
