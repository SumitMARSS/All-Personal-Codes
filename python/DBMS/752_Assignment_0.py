class Student:
    def __init__(self, name, semester, roll_no, dob, cgpa, contact_no):
        self.name = name
        self.semester = semester
        self.roll_no = roll_no
        self.dob = dob
        self.cgpa = cgpa
        self.contact_no = contact_no

    def __str__(self):
        return f"{self.name} {self.semester} {self.roll_no} {self.dob} {self.cgpa} {self.contact_no}"
    
def insert_record():
    with open("students_details.txt", "a") as f:
        name = input("Enter name - ")
        semester = input("Enter semester - ")
        roll_no = input("Enter roll no - ")
        dob = input("Enter date of birth (dd/mm/yyyy) - ")
        cgpa = input("Enter CGPA - ")
        contact_no = input("Enter contact no - ")
        student = Student(name, semester, roll_no, dob, cgpa, contact_no) # Creating a student object
        f.write(str(student) + "\n")
        print()
        print("/n *********  Record inserted successfully.  *********** ")


def update_record():
    with open("students_details.txt", "r") as f:
        lines = f.readlines()
    with open("students_details.txt", "w") as f:
        num_attr = int(input("Enter number of attributes to be updated: "))
        attr_names = []
        new_values = []
        for i in range(num_attr):
            attr_name = input(f"Enter attribute name {i+1}: ")
            new_value = input(f"Enter new value for {attr_name}: ")
            attr_names.append(attr_name)
            new_values.append(new_value)
        num_cond = int(input("Enter number of conditions: "))
        cond_names = []
        cond_values = []
        for i in range(num_cond):
            cond_name = input(f"Enter condition attribute name {i+1}: ")
            cond_value = input(f"Enter condition value for {cond_name}: ")
            cond_names.append(cond_name)
            cond_values.append(cond_value)
        for line in lines:
            fields = line.split()
            student = Student(*fields)
            match = True
            for cond_name, cond_value in zip(cond_names, cond_values):
                if getattr(student, cond_name) != cond_value:
                    match = False
                    break
            if match:
                for attr_name, new_value in zip(attr_names, new_values):
                    setattr(student, attr_name, new_value)
            f.write(str(student) + "\n")
        print()
        print("/n ********* Record updated successfully.  *********** ")

def fetch_record():
    with open("students_details.txt", "r") as f:
        lines = f.readlines()
    fetch_attr = input("Enter attribute to fetch - ").split(",")
    query_attr = input("Enter query attribute - ").split(",")
    query_val = input("Enter query value - ").split(",")
    for line in lines:
        fields = line.split()
        student = Student(*fields)
        match = True
        for attr, val in zip(query_attr, query_val):
            if getattr(student, attr) != val:
                match = False
                break
        if match:
            for attr in fetch_attr:
                print(f"{attr}: {getattr(student, attr)}", end=" ")
            print()


def delete_record():
    with open("students_details.txt", "r") as f:
        lines = f.readlines()
    with open("students_details.txt", "w") as f:
        num_cond = int(input("Enter number of conditions: "))
        cond_names = []
        cond_values = []
        for i in range(num_cond):
            cond_name = input(f"Enter condition attribute name {i+1}: ")
            cond_value = input(f"Enter condition value for {cond_name}: ")
            cond_names.append(cond_name)
            cond_values.append(cond_value)
        for line in lines:
            fields = line.split()
            student = Student(*fields)
            match = True
            for cond_name, cond_value in zip(cond_names, cond_values):
                if getattr(student, cond_name) != cond_value:
                    match = False
                    break
            if not match:
                f.write(line)
            print()
            print("  ********* Record deleted successfully.  *********** ")



def display_menu():
    print("Choose One Option from these:-->> ")
    print("1. Insert Record: ")
    print("2. Update Record: ")
    print("3. Fetch Record: ")
    print("4. Delete Record: ")
    choice = int(input("Enter your choice: "))
    return choice

def main():
    while True:
        choice = display_menu()
        if choice == 1:
            insert_record()
        elif choice == 2:
            update_record()
        elif choice == 3:
            fetch_record()
        elif choice == 4:
            delete_record()
        else:
            print("Invalid choice. Please try again.")
        print()

if __name__ == "__main__":
    main()
