import datetime
import uuid

class Task():

    def __init__(self,task):
            self.id=uuid.uuid4()
            self.task=task
            self.created_time=datetime.datetime.now()
            self.updated_time="Not Updated Yet"
            self.completed_time="Not Completed Yet"
            self.task_done=False

    def update_task(self,task):
        self.task=task
        self.updated_time=datetime.datetime.now()
    

    def complete_task(self):
        self.completed_time=datetime.datetime.now()
        self.task_done=True



def showTask(t):
    print(f'\nTask ID: {t.id}')
    print(f'Task: {t.task}')
    print(f'Created Time: {t.created_time}')
    print(f'Updated Time: {t.updated_time}')
    print(f'Completed Time: {t.completed_time}')
    print(f'Completed: {t.task_done}\n\n')



tasks=[]

while True:

    print("\n0 : Exit")
    print("1 : Create new Task")
    print("2 : Show all the Tasks")
    print("3 : Show Incomple Tasks")
    print("4 : Show Coompletedd Tasks")
    print("5 : Update A Task")
    print("6 : Complete A Task\n")

    c=int(input("Enter your Choice:"))

    if c==0:
        break

    elif c==1:
       taskName=input("Enter Task name:")
       tasks.append(Task(taskName))
       print("\nNew Task Created Successfully")
    




    elif c==2:
        if len(tasks)>0:
            for t in tasks:
                showTask(t)
        else:
            print("\nNo Task to Show !\n")

    

    
    elif c==3:
        count=0

        for t in tasks:
            if t.task_done==False:
                count+=1
                showTask(t)
        
        if count==0:
            print("\nNo Incomplete Task Found !\n")




    elif c==4:
        count=0

        for t in tasks:
            if t.task_done==True:
                count+=1
                showTask(t)
        
        if count==0:
            print("\nNo Complete Task Found !\n")




    elif c==5:
        count=0
        for t in tasks:
            print(f'Task No:{count+1}')
            showTask(t)
            count+=1
        
        taskNo=int(input("Enter Task No to update:"))
        taskNo=taskNo-1
        updatedName=input("Enter Updated Task name:")

        if taskNo>=len(tasks):
            print(f"No Task Found with Task No {taskNo+1}")

        else:
            if tasks[taskNo].task_done==False:
                tasks[taskNo].update_task(updatedName)
                print(f'\nTask "{tasks[taskNo].task}" Updated Successfully !')
            else:
                print(f'\nTask "{tasks[taskNo].task}" is already Completed !')

    

    elif c==6:
        count=0
        for t in tasks:
            print(f'Task No:{count+1}')
            showTask(t)
            count+=1
        
        taskNo=int(input("Enter Task No to Complete:"))
        taskNo=taskNo-1
    
        if taskNo>=len(tasks):
            print(f"\nNo Task Found with Task No {taskNo+1}")

        else:
            if tasks[taskNo].task_done==False:
                tasks[taskNo].complete_task()
                print(f'\nTask "{tasks[taskNo].task}" Completed Successfully !')
            else:
                print(f'\nTask "{tasks[taskNo].task}" is already Completed !')

    

    else:
        print("\nInvalid Choice !\n")