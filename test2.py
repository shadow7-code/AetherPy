class Student:
    def __init__(self, student_id, name, age, course):
        self.student_id = student_id
        self.name = name
        self.age = age
        self.course = course
    def display_info(self):
        print(f"ID: {self.student_id} | Name: {self.name} | Age: {self.age} | Course: {self.course}")
class College:
    def __init__(self):
        self.students = []
    def add_student(self, student_id, name, age, course):
        student = Student(student_id, name, age, course)
        self.students.append(student)
    def display_all_students(self):
        if not self.students:
            print("No students found.")
            return
        print("\n--- College Students ---")
        for student in self.students:
            student.display_info()
if __name__ == "__main__":
    college = College()
    college.add_student(101, "Alice Johnson", 19, "Computer Science")
    college.add_student(102, "Bob Smith", 20, "Mechanical Engineering")
    college.add_student(103, "Charlie Davis", 18, "Electrical Engineering")
    college.display_all_students()