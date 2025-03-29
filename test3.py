import math
class MathOperations:
    def __init__(self, num1, num2):
        self.num1 = num1
        self.num2 = num2
    def add(self):
        return self.num1 + self.num2
    def subtract(self):
        return self.num1 - self.num2
    def multiply(self):
        return self.num1 * self.num2
    def divide(self):
        return self.num1 / self.num2 if self.num2 != 0 else "Undefined"
def main():
    num1 = 987654321987654321
    num2 = 123456789123456789
    print("### Long Math Operations ###")
    math_ops = MathOperations(num1, num2)
    print(f"Addition: {math_ops.add()}")
    print(f"Subtraction: {math_ops.subtract()}")
    print(f"Multiplication: {math_ops.multiply()}")
    print(f"Division: {math_ops.divide()}")
if __name__ == "__main__":
    main()