# Insert student details
# db.mark.find(), col.find(), find_one()

from pymongo import MongoClient

client = MongoClient("mongodb://localhost:27017")
db = client["student_db"]
collection = db["mark"]

students_list = [
    {"name": "Arun", "age": 18, "grade": "12", "marks": 85.5},
    {"name": "Meera", "age": 17, "grade": "11", "marks": 90.0},
    {"name": "Rahul", "age": 18, "grade": "12", "marks": 78.0},
    {"name": "Anjali", "age": 17, "grade": "11", "marks": 88.5},
    {"name": "Vikram", "age": 18, "grade": "12", "marks": 92.0}
]

""" for i in range(5):
    print(f"\nEntre details for student {i+1}:")
    name = input("enter name : ")
    age = int(input("enter age : "))
    marks = int(input("enter marks : "))
    
    student = {
        "name" : name,
        "age" : age,
        "marks" : marks
    }
    
    students_list.append(student) """

collection.insert_many(students_list)

print("\n✅ 5 student records inserted successfully!")

print("\n Display student details : ")
for student in collection.find():
    print(student)
    
print("\n----- Next exercise -----")
print(collection.find_one({"age" : 21}))

print("\n----- Next exercise -----")
for student in collection.find({}, {"_id": 0, "name": 1}).sort("name", 1):  # -1 for desc
    print(student) # student["name"]