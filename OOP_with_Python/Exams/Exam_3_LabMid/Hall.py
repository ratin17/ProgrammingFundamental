

####     Answer to Question : 1    ####

class Star_Cinema():
    __hall_list=[]

    def __init__(self):
        pass

    def entry_hall(self,Hall):
        Star_Cinema.__hall_list.append(self)


####     Answer to Questions : 2 , 9    ####

class Hall(Star_Cinema):
    __HallNo=0

    def __init__(self,rows,cols):
            self.__seats={}
            self.__show_list=[]
            self.__rows=rows
            self.__cols=cols

            Hall.__HallNo=Hall.__HallNo+1
            self.__hall_no=Hall.__HallNo

            self.entry_hall(self) #use of Inheritance




####     Answer to Question : 3    ####

    def entry_show(self,id,movie_name,time):
        tempTuple=(id,movie_name,time)
        self.__show_list.append(tempTuple)

        seatAvailable=[]

        for row in range(self.__rows):
            rowInfo=[]
            for col in range(self.__cols):
                rowInfo.append(True)
            seatAvailable.append(rowInfo)
        
        self.__seats[id]=seatAvailable



####     Answer to Questions : 4 , 8   ####

    def book_seats(self,name,phone,id,seats):

        movie=""
        for show in self.__show_list:
            if show[0]==id:
                movieInfo=show
                movie=movieInfo[1]
                break
        
        print("\n----------------------------------------------------\n")

        if movie=="":
            print(f'No Movie Found for id: {id} !!')
            print("\n----------------------------------------------------\n")
            return

        print(f'{len(seats)} seats are requested to book by {name} ({phone}) for "{movie}" at: {movieInfo[2]} at Hall {self.__hall_no}:\n')

        for seat in seats:

            if seat[0]>(self.__rows-1) or seat[1]>(self.__cols-1):
                print(f'\t{chr(seat[0]+65)}{seat[1]} is an Inavalid seat !')
                continue

            if self.__seats[id][seat[0]][seat[1]]==True:
                self.__seats[id][seat[0]][seat[1]]=False
                print(f'\t{chr(seat[0]+65)}{seat[1]} is booked succesfully !')
            else:
                print(f'\t{chr(seat[0]+65)}{seat[1]}  was not Available')
        print("\n----------------------------------------------------\n")



####     Answer to Questions : 5 , 8   ####

    def view_show_list(self):

        print("\n----------------------------------------------------\n")

        print(f'Current Show List of Hall {self.__hall_no}:\n')
        for show in self.__show_list:
            print(f'\tShow Id: {show[0]}  , Movie: {show[1]} ,  at: {show[2]}')
        
        print("\n----------------------------------------------------\n")




####     Answer to Questions : 6 , 8   ####

    def view_available_seats(self,id):
        movie=""
        for show in self.__show_list:
            if show[0]==id:
                movieInfo=show
                movie=movieInfo[1]
                break
        
        print("\n----------------------------------------------------\n")
        
        if movie=="":
            print(f'No Movie Found for id: {id} !!')
            print("\n----------------------------------------------------\n")
            return

        for showId,showSeats in self.__seats.items():
            if id==showId:
                seatDetails=showSeats

        print(f'\nAvailable Seats for "{movie}" At {movieInfo[2]} At Hall {self.__hall_no} :\n')

        print("[ -- for booked seats ]\n")
        for row in range(len(seatDetails)):
            for col in range(len(seatDetails[0])):
                if seatDetails[row][col]==True:
                    print(f'  {chr(65+row)}{col}  ',end="")
                else:
                    print(f'  --  ',end="")
            print("\n")

        print("\n----------------------------------------------------\n")





# Some aurbitary initializations

hall1=Hall(4,9)
hall2=Hall(5,8)

hall1.entry_show("11","3 Idiots","11/12/2022 2:45 PM")
hall1.entry_show("12","Titanic","11/12/2022 4:25 PM")
hall1.entry_show("13","3 Idiots","11/12/2022 10:45 PM")
hall2.entry_show("13","3 Idiots","11/12/2022 10:45 PM")

# hall1.book_seats("Mehrab Rabbi","+88 017","11",[(1,3),(2,4)])




####     Answer to Question : 7    ####

while True:

    print("\n0 : Exit")
    print("1 : Check current Show List")
    print("2 : Check Available seats in a Show")
    print("3 : Book Tickets in a show\n")

    c=int(input("Enter your Choice:"))

    if c==0:
        break

    elif c==1:
       hall1.view_show_list()

    elif c==2:
        show=str(input("Enter ID of the show:"))
        hall1.view_available_seats(show)

    elif c==3:
        name=str(input("Enter your Name:"))
        phone=str(input("Enter your Phone No:"))
        id=str(input("Enter ID of the show:"))
        num=int(input("Enter number of Tickets you want to book:"))
        tickets=[]

        for i in range(num):
            print("\tInput for Ticket: ",i+1)
            seat=str(input("Enter Seat (Ex: A3):"))

            r=ord(seat[0])
            if r>=97 and r<=122:
                r=r-97
            else:
                r=r-65
            

            c=""
            for j in range(1,len(seat)):
                c=c+seat[j]
            
            c=int(c)

            ticket=(r,c)
            tickets.append(ticket)
        
        hall1.book_seats(name,phone,id,tickets)

    else:
        print("\nInvalid Choiche !")











