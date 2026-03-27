# mark > 50, $ge
# total marks calc
# ^S : starts with 'S'
# regex

from pymongo import MongoClient

client = MongoClient("mongodb://localhost:27017")
db = client["student_db"]
collection = db["total_marks"]

students_list = [
    {"name": "Arun", "mark1": 85, "mark2": 78, "mark3": 92},
    {"name": "Meera", "mark1": 90, "mark2": 88, "mark3": 95},
    {"name": "Rahul", "mark1": 70, "mark2": 75, "mark3": 80},
    {"name": "Anjali", "mark1": 88, "mark2": 84, "mark3": 91},
    {"name": "Vikram", "mark1": 92, "mark2": 89, "mark3": 94},
    {"name": "Sneha", "mark1": 76, "mark2": 81, "mark3": 79},
    {"name": "Kiran", "mark1": 65, "mark2": 70, "mark3": 68},
    {"name": "Divya", "mark1": 89, "mark2": 92, "mark3": 90},
    {"name": "Rohit", "mark1": 78, "mark2": 74, "mark3": 77},
    {"name": "Pooja", "mark1": 91, "mark2": 93, "mark3": 89}
]

# Calculating total marks field
for student in students_list:
    student["total"] = student["mark1"] + student["mark2"] + student["mark3"]
 
collection.delete_many({}) # To avoid repetition
collection.insert_many(students_list)
   
for student in collection.find({}, {"_id" : 0, "name" : 1, "total" : 1}):
    print(student)
    

print("\n----- Next exercise -----")
for student in collection.find(
    {"total": {"$gt": 255}},
    {"_id": 0, "name": 1, "total": 1}
):
    print(student)
    
print("\n----- Next exercise -----")
# Names that start with A
for student in collection.find({"name" : {"$regex" : "^A"}}, {"_id" : 0, "name" : 1}):
    print(student)
    
print("\n----- Next exercise -----")
# Names that ends with 'i'
for student in collection.find({"name" : {"$regex" : "i$"}}, {"_id" : 0, "name" : 1}):
    print(student)

print("\n----- Next exercise -----")
collection.delete_one({"name": "Kiran"})
    
print("\n----- Next exercise -----")  
# Update mark1 for Rahul
collection.update_one(
    {"name": "Rahul"},       # filter: which student to update
    {"$set": {"mark1": 95}}  # new value for mark1
)
for student in collection.find({}, {"_id" : 0, "name" : 1, "mark1" : 1}):
    print(student)
    
    
