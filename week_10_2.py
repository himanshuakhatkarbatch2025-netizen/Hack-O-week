class Book:
    def __init__(self, title, author):
        self.title = title
        self.author = author

    def display(self):
        return f"{self.title} by {self.author}"


class LibraryCatalogue:
    def __init__(self, capacity):
        self.capacity = capacity
        self.books = [None] * capacity  # Fixed-size array
        self.count = 0

    # Add Book
    def add_book(self, title, author):
        if self.count >= self.capacity:
            print("Catalogue is full. Cannot add more books.")
            return

        self.books[self.count] = Book(title, author)
        self.count += 1
        print(f"Book '{title}' added.")

    # Remove Book by Title
    def remove_book(self, title):
        index = -1

        # Search for the book
        for i in range(self.count):
            if self.books[i].title == title:
                index = i
                break

        if index == -1:
            print("Book not found.")
            return

        # Shift elements left
        for i in range(index, self.count - 1):
            self.books[i] = self.books[i + 1]

        self.books[self.count - 1] = None
        self.count -= 1

        print(f"Book '{title}' removed.")

    # Search Book
    def search_book(self, title):
        for i in range(self.count):
            if self.books[i].title == title:
                print("Book Found:", self.books[i].display())
                return

        print("Book not found.")

    # Display all books
    def display_books(self):
        if self.count == 0:
            print("Catalogue is empty.")
            return

        print("\nLibrary Catalogue:")
        for i in range(self.count):
            print(self.books[i].display())
