import threading

# Shared list
shared_list = []

# Lock for synchronizing access to the shared list
list_lock = threading.Lock()

# Function to append even numbers
def append_even_numbers(n):
    for i in range(0, n, 2):
        with list_lock:
            shared_list.append(i)

# Function to append odd numbers
def append_odd_numbers(n):
    for i in range(1, n, 2):
        with list_lock:
            shared_list.append(i)

# Number of elements to append
n = 10

# Creating threads
even_thread = threading.Thread(target=append_even_numbers, args=(n,))
odd_thread = threading.Thread(target=append_odd_numbers, args=(n,))

# Starting threads
even_thread.start()
odd_thread.start()

# Waiting for threads to complete
even_thread.join()
odd_thread.join()

# Printing the shared list
print("Shared list:", shared_list)
