

class Star_Cinema():
    hall_list=[]

    def __init__(self):
        pass

    def entry_hall(self,Hall):
        Star_Cinema.hall_list.append(self)


class Hall(Star_Cinema):
    HallNo=0
    def __init__(self,rows,cols):
            self.seats={}
            self.show_list=[]
            self.rows=rows
            self.cols=cols

            Hall.HallNo=Hall.HallNo+1
            self.hall_no=Hall.HallNo

            self.entry_hall(self)

    def entry_show(self,id,movie_name,time):
        tempTuple=(id,movie_name,time)
        self.show_list.append(tempTuple)

        seatAvailable=[]

        for row in range(self.rows):
            rowInfo=[]
            for col in range(self.cols):
                rowInfo.append(True)
            seatAvailable.append(rowInfo)

        self.seats={f'id':seatAvailable}


    def book_seats(self,name,phone,id,seats):

        movie=""
        for show in self.show_list:
            if show[0]==id:
                movie=show[1]
        
        if movie=="":
            print(f'No Movie Found for id: {id} !!')
            return

        print(f'{len(seats)} seats are requested to book by {name} ({phone}) for Movie-"{movie}" at positions :')

        for seat in seats:
            if self.seats[id][seat[0]][seat[1]]==True:
                self.seats[id][seat[0]][seat[1]]=False
                print(f'row:{seat[0]} , col:{seat[1]}')
            else:
                print(f'No seat available at row:{seat[0]} , col:{seat[1]} for movie {movie}')



    def view_show_list(self):
        for show in self.show_list:
            print(f'Movie: {show[1]}({show[0]}) at {show[2]}')



hall0=Hall(4,9)
hall0.entry_show("23","josna","2:45 PM")
hall0.entry_show("21","jos","2:25 PM")
print(hall0.view_show_list())

hall0.book_seats("Mr Haq","0198","23",[(2,3),(3,3),(2,3)])
hall0.book_seats("Mr Haq","0198","21",[(2,3),(3,3),(2,6)])

# hall1=Hall(6,7)

# print(hall0.hall_list[1].rows)









