class Node:
    def __init__(self, value):
        self.data = value
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    # Insertion functions
    def insert_at_beginning(self, value):
        new_node = Node(value)
        new_node.next = self.head
        self.head = new_node

    def insert_at_end(self, value):
        new_node = Node(value)

        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next is not None:
                current = current.next
            current.next = new_node

    def insert_at_position(self, value, position):
        if position <= 0:
            self.insert_at_beginning(value)
        else:
            new_node = Node(value)
            current = self.head
            current_position = 0

            while current is not None and current_position < position - 1:
                current = current.next
                current_position += 1

            if current is not None:
                new_node.next = current.next
                current.next = new_node
            else:
                print("Invalid position!")

    # Deletion functions
    def delete_at_beginning(self):
        if self.head is not None:
            temp = self.head
            self.head = self.head.next
            temp.next = None
            del temp
        else:
            print("List is empty!")

    def delete_at_end(self):
        if self.head is not None:
            if self.head.next is None:
                temp = self.head
                self.head = None
                del temp
            else:
                current = self.head
                previous = None

                while current.next is not None:
                    previous = current
                    current = current.next

                previous.next = None
                del current
        else:
            print("List is empty!")

    def delete_at_position(self, position):
        if self.head is not None:
            if position <= 0:
                self.delete_at_beginning()
            else:
                current = self.head
                previous = None
                current_position = 0

                while current is not None and current_position < position:
                    previous = current
                    current = current.next
                    current_position += 1

                if current is not None:
                    previous.next = current.next
                    current.next = None
                    del current
                else:
                    print("Invalid position!")
        else:
            print("List is empty!")

    # Display function
    def display(self):
        current = self.head

        if current is None:
            print("List is empty!")
        else:
            print("Linked List:", end=" ")
            while current is not None:
                print(current.data, end=" ")
                current = current.next
            print()

    # Reverse the linked list
    def reverse(self):
        current = self.head
        previous = None

        while current is not None:
            next_node = current.next
            current.next = previous
            previous = current
            current = next_node

        self.head = previous

    # Find duplicates in the linked list
    def find_duplicates(self):
        if self.head is None:
            print("List is empty!")
            return

        current = self.head
        seen = set()

        while current is not None:
            if current.data in seen:
                print("Duplicate found:", current.data)
            else:
                seen.add(current.data)

            current = current.next

    # Find an element in the linked list
    def find_element(self, value):
        current = self.head
        count=0
        while current is not None:
            if current.data == value:
                return count
            current = current.next
            count = count + 1

        return False

    # Find the length of the linked list
    def length(self):
        count = 0
        current = self.head

        while current is not None:
            count += 1
            current = current.next

        return count

    # Sort the linked list in ascending order (using bubble sort)
    def sort(self):
        if self.head is None or self.head.next is None:
            return  # List is empty or has only one element

        swapped = True
        last = None

        while swapped:
            swapped = False
            current = self.head

            while current.next != last:
                if current.data > current.next.data:
                    current.data, current.next.data = current.next.data, current.data
                    swapped = True
                current = current.next

            last = current


# Usage example
list = LinkedList()

list.display()  # List is empty!

list.insert_at_beginning(10)
list.insert_at_beginning(20)
list.insert_at_beginning(20)
list.insert_at_beginning(25)
list.insert_at_beginning(430)
list.insert_at_end(30)
list.insert_at_position(40, 1)

list.display()  # Linked List: 20 40 10 30
print("position of element is ",list.find_element(25))
print("length is ",list.length())
list.sort()
list.display()
list.find_duplicates()
list.reverse()
list.display()
list.delete_at_beginning()
list.delete_at_end()
list.delete_at_position(1)

list.display()  # Linked List: 40
