class Node:
    def __init__(self, item_id, name, price, quantity):
        self.item_id = item_id
        self.name = name
        self.price = price
        self.quantity = quantity
        self.next = None


class ShoppingCart:
    def __init__(self):
        self.head = None

    # Insert at Head
    def add_at_head(self, item_id, name, price, quantity):
        new_node = Node(item_id, name, price, quantity)
        new_node.next = self.head
        self.head = new_node
        print(f"Item '{name}' added at head.")

    # Insert at Tail
    def add_at_tail(self, item_id, name, price, quantity):
        new_node = Node(item_id, name, price, quantity)

        if self.head is None:
            self.head = new_node
            print(f"Item '{name}' added as first item.")
            return

        temp = self.head
        while temp.next:
            temp = temp.next

        temp.next = new_node
        print(f"Item '{name}' added at tail.")

    # Remove by ID
    def remove_item(self, item_id):
        temp = self.head
        prev = None

        while temp:
            if temp.item_id == item_id:
                if prev is None:
                    self.head = temp.next  # removing head
                else:
                    prev.next = temp.next

                print(f"Item ID {item_id} removed.")
                return

            prev = temp
            temp = temp.next

        print("Item not found.")

    # Display Cart + Total
    def display_cart(self):
        if self.head is None:
            print("Cart is empty.")
            return

        temp = self.head
        total = 0

        print("\nShopping Cart:")
        while temp:
            cost = temp.price * temp.quantity
            total += cost
            print(f"ID: {temp.item_id}, {temp.name}, Qty: {temp.quantity}, Price: {temp.price}, Total: {cost}")
            temp = temp.next

        print(f"\nTotal Cart Value: {total}")
