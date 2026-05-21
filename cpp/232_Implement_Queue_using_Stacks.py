class MyQueue:

    def __init__(self):
        self.ins = []
        self.out = []

    def move(self):
        if not self.out:
            while self.ins:
                self.out.append(self.ins.pop())

    def push(self, x: int) -> None:
        self.ins.append(x)

    def pop(self) -> int:
        self.move()
        return self.out.pop()

    def peek(self) -> int:
        self.move()
        return self.out[-1]

    def empty(self) -> bool:
        return not self.ins and not self.out
