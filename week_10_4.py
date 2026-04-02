class BrowserHistory:
    def __init__(self):
        self.back_stack = []
        self.forward_stack = []
        self.current = None

    # Visit new URL
    def visit(self, url):
        if self.current is not None:
            self.back_stack.append(self.current)

        self.current = url
        self.forward_stack.clear()  # VERY IMPORTANT

        print(f"Visited: {url}")

    # Go Back
    def back(self):
        if not self.back_stack:
            print("No pages to go back.")
            return

        self.forward_stack.append(self.current)
        self.current = self.back_stack.pop()

        print(f"Back to: {self.current}")

    # Go Forward
    def forward(self):
        if not self.forward_stack:
            print("No pages to go forward.")
            return

        self.back_stack.append(self.current)
        self.current = self.forward_stack.pop()

        print(f"Forward to: {self.current}")

    # Current Page (peek)
    def current_page(self):
        print(f"Current Page: {self.current}")
