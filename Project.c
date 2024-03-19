//admin panel password = 1234

#include <stdio.h>
#include <string.h>

char rooms[20];
char employs[10];
int money=0;
int *ptr = &money;
char emp_1[50],emp_2[50],emp_3[50],emp_4[50],emp_5[50],emp_6[50],emp_7[50],emp_8[50],emp_9[50],emp_10[50];

void admin_panel();
void login_panel();
void check_in();
void check_out();
int assign_room();
void room_lelo(int room);
void display_rooms();
void employ_management();

int main() {
	
	FILE *fptr_rooms;
	FILE *fptr_employs;
	FILE *fptr_money;
	FILE *ptr_emp1,*ptr_emp2,*ptr_emp3,*ptr_emp4,*ptr_emp5,*ptr_emp6,*ptr_emp7,*ptr_emp8,*ptr_emp9,*ptr_emp10;
	
	fptr_rooms= fopen("Rooms.txt","r");
	int a;
	int i=0;
	while ( ( a = fgetc(fptr_rooms) ) != EOF ){
		rooms[i]=a;
		i++;
	}
	fclose(fptr_rooms);
	
	fptr_employs= fopen("Employs.txt","r");
	int b;
	int j=0;
	while ( ( b = fgetc(fptr_employs) ) != EOF ){
		employs[j]=b;
		j++;
	}
	fclose(fptr_employs);
	
	fptr_money= fopen("Money.txt","r");
	fscanf(fptr_money,"%d",&money);
	fclose(fptr_money);
	
	ptr_emp1= fopen("Emp1.txt","r");
	fgets(emp_1,50,ptr_emp1);	
	fclose(ptr_emp1);
	
	ptr_emp2= fopen("Emp2.txt","r");
	fgets(emp_2,50,ptr_emp2);	
	fclose(ptr_emp2);
		
	ptr_emp3= fopen("Emp3.txt","r");
	fgets(emp_3,50,ptr_emp3);	
	fclose(ptr_emp3);
		
	ptr_emp4= fopen("Emp4.txt","r");
	fgets(emp_4,50,ptr_emp4);	
	fclose(ptr_emp4);
		
	ptr_emp5= fopen("Emp5.txt","r");
	fgets(emp_5,50,ptr_emp5);	
	fclose(ptr_emp5);
		
	ptr_emp6= fopen("Emp6.txt","r");
	fgets(emp_6,50,ptr_emp6);	
	fclose(ptr_emp6);
		
	ptr_emp7= fopen("Emp7.txt","r");
	fgets(emp_7,50,ptr_emp7);	
	fclose(ptr_emp7);
		
	ptr_emp8= fopen("Emp8.txt","r");
	fgets(emp_8,50,ptr_emp8);	
	fclose(ptr_emp8);
		
	ptr_emp9= fopen("Emp9.txt","r");
	fgets(emp_9,50,ptr_emp9);	
	fclose(ptr_emp9);
		
	ptr_emp10= fopen("Emp10.txt","r");
	fgets(emp_10,50,ptr_emp10);	
	fclose(ptr_emp10);
	
	int select;
	while(1) {
		printf("====(HOTEL MANAGEMENT SYSTEM)====\n\n");
		printf("1. Admin Panel\n");
		printf("2. Check-in\n");
		printf("3. Check-out\n");
		printf("4. Exit\n");
		scanf("%d", &select );

		switch(select) {

			case 1:
				login_panel();  // password = 1234 
				break;

			case 2:
				printf("\n====(Check In)====\n\n");
				check_in();
				break;

			case 3:
				printf("\n====(Check Out)====\n\n");
				check_out();
				break;

			case 4:
				printf("Thanks for visiting our hotel.   :)\n");
				
				fptr_rooms= fopen("Rooms.txt","w");
				for (int i=0;i<20;i++){
					fputc(rooms[i],fptr_rooms);
				}
				fclose(fptr_rooms);
				
				fptr_employs= fopen("Employs.txt","w");
				for (int i=0;i<10;i++){
					fputc(employs[i],fptr_employs);
				}
				fclose(fptr_employs);
				
				fptr_money= fopen("Money.txt","w");
				fprintf(fptr_money,"%d",money);
				fclose(fptr_money);
				
				ptr_emp1= fopen("Emp1.txt","w");
				fputs(emp_1,ptr_emp1);	
				fclose(ptr_emp1);
				
				ptr_emp2= fopen("Emp2.txt","w");
				fputs(emp_2,ptr_emp2);	
				fclose(ptr_emp2);
		
				ptr_emp3= fopen("Emp3.txt","w");
				fputs(emp_3,ptr_emp3);	
				fclose(ptr_emp3);
		
				ptr_emp4= fopen("Emp4.txt","w");
				fputs(emp_4,ptr_emp4);	
				fclose(ptr_emp4);
		
				ptr_emp5= fopen("Emp5.txt","w");
				fputs(emp_5,ptr_emp5);	
				fclose(ptr_emp5);
		
				ptr_emp6= fopen("Emp6.txt","w");
				fputs(emp_6,ptr_emp6);	
				fclose(ptr_emp6);
		
				ptr_emp7= fopen("Emp7.txt","w");
				fputs(emp_7,ptr_emp7);	
				fclose(ptr_emp7);
		
				ptr_emp8= fopen("Emp8.txt","w");
				fputs(emp_8,ptr_emp8);	
				fclose(ptr_emp8);
		
				ptr_emp9= fopen("Emp9.txt","w");
				fputs(emp_9,ptr_emp9);	
				fclose(ptr_emp9);
		
				ptr_emp10= fopen("Emp10.txt","w");
				fputs(emp_10,ptr_emp10);	
				fclose(ptr_emp10);
				
				return 0;
				break;

			default:
				printf("Please Retry\n\n");
				break;

		}

	}

	return 0;
}

void admin_panel() {
    int panel_exit=0;	
	while(1){
    
	printf("\n====(ADMIN PANEL)====\n\n");
    int choose;
    
        printf("1. Available Rooms\n");
        printf("2. Employs Management\n");
		printf("3. Money\n");
		printf("4. Exit\n");

    	scanf("%d", &choose );

		switch(choose) {

			case 1:
		    	display_rooms();
				break;
			
			case 2:
				employ_management();
				break;

			case 3:
				printf("\n====(MONEY)====\n");
			    printf("\nTotal Money is %d Rs\n",*ptr);
				break;

        	case 4:
			    panel_exit=1;
				break;

			default:
				printf("Invalid Option....Please Retry\n\n");
				break;

		}
		if (panel_exit==1){
	    break;
	}
	}
}
//--------------------------------------------------------------------------------
void check_in() {
	int count=0;
	for (int i=0;i<20;i++){
		if (rooms[i]=='E'){
			int nights=0 , bill=0, total_bill=0 ; 

			printf("Charges Per night : 4000pkr\n");
			printf("How many nights you want to stay :");
			scanf("%d" ,&nights);

			total_bill = nights * 4000;
			printf("Your total bill will be: %d pkr\n" , total_bill);

			do {
				printf("Please pay the bill: ");
				scanf("%d" , &bill);

				if(bill==total_bill) {
					int assigned_room = assign_room();

					printf("Your room number is %d\n\n", ++assigned_room);
				} else {
					printf("Invalid amount.\n");
				}

			} while(bill!=total_bill);

    		*ptr += bill;
    		
			break;
		}
		else{
			count++;
		}
	}
	if (count==20){
		printf("No Rooms Empty\n\n");
	}

}
//--------------------------------------------------------------------------------
void check_out() {

	int room_no;

	printf("Enter the room no. you stayed in: ");
	scanf("%d" , &room_no);

	room_lelo(room_no);

}

//--------------------------------------------------------------------------------


void login_panel() {
    int panel_exit=0;
	while(1){
	
	int input,option;
	printf("\n====(PASSWORD)====\n\n");
	printf("Pin Code required to enter Admin Panel.\n\nPin Code: ");
	scanf("%d",&input);
	if (input==1234){
	    printf("\n");
		admin_panel();
		break;
	}
	else{
		printf("Invalid Pin\nPress 1 to Retry\nPress any other num to Exit\n");
		scanf("%d",&option);
		if (option==1){
			continue;
		}
		else {
			panel_exit=1;
		}
		
	}
	if (panel_exit==1){
	    break;
	}
	}
}


//--------------------------------------------------------------------------------

int assign_room() {

	int assigned_room;
	for (int i=0; i<20; i++) {
		if(rooms[i]=='E') {
			rooms[i]='F';
			assigned_room = i;
			break;
		}
	}
	return assigned_room;
}

//--------------------------------------------------------------------------------

void room_lelo(int room) {
	if (rooms[room-1]!='E'){
		rooms[room-1]='E';
		printf("Thanks for staying in our hotel.\n\n");
	}
	else{
		printf("Room is already Empty\n\n");
	}
}

//--------------------------------------------------------------------------------

void display_rooms() {
	int count=1;
	int count_2=1;
	printf("\n====(Available Rooms)====\n\n");
	for (int i=0; i<20; i++) {
		if(rooms[i]=='E') {
			printf("Room No: %d\n" , count);
			count++;
			count_2++;
		}else{
		    ++count;
		}
	}
	if (count_2==1){
		printf("No Rooms Available\n");
	}
}

//--------------------------------------------------------------------------------

void employ_management()
{	
    int panel_exit=0;
	while (1){
    char first[25];
    char last [25];	
	int option;
    int emp;
    char id[10] = {'0','1','2','3','4','5','6','7','8','9'};
    int fire;
    printf("\n====(Employs Management)====\n\n");
    printf ("1. Hire\n2. Fire\n3. Employs Data\n4. Exit\n");
    scanf ("%d",&option);
    
    switch (option){
    	
    	case 1:
			emp=0;
    		for (int i=0; i<10 ;i++){
				if (employs[i]=='E'){
					
					employs[i] = id[i];
					
				    printf("Enter First Name: ");
                    scanf ("%s",first);
                    printf("Enter Last Name : ");
                    scanf ("%s",last);
                    
                    char full [50]="";
                    strcat(full,first);
                    strcat(full," ");
                    strcat(full,last);
                    
                    switch(i){
                        case 0:
                            strcpy(emp_1,full);
					        printf ("Hired %s....Employ ID: %c\n",emp_1,id[i]);
                            break;
                        case 1:
                            strcpy(emp_2,full);
					        printf ("Hired %s....Employ ID: %c\n",emp_2,id[i]);
                            break;
                        case 2:
                            strcpy(emp_3,full);
					        printf ("Hired %s....Employ ID: %c\n",emp_3,id[i]);
                            break;
                        case 3:
                            strcpy(emp_4,full);
					        printf ("Hired %s....Employ ID: %c\n",emp_4,id[i]);
                            break;
                        case 4:
                            strcpy(emp_5,full);
					        printf ("Hired %s....Employ ID: %c\n",emp_5,id[i]);
                            break;
                        case 5:
                            strcpy(emp_6,full);
					        printf ("Hired %s....Employ ID: %c\n",emp_6,id[i]);
                            break;
                        case 6:
                            strcpy(emp_7,full);
					        printf ("Hired %s....Employ ID: %c\n",emp_7,id[i]);
                            break;
                        case 7:
                            strcpy(emp_8,full);
					        printf ("Hired %s....Employ ID: %c\n",emp_8,id[i]);
                            break;
                        case 8:
                            strcpy(emp_9,full);
					        printf ("Hired %s....Employ ID: %c\n",emp_9,id[i]);
                            break;
                        case 9:
                            strcpy(emp_10,full);
					        printf ("Hired %s....Employ ID: %c\n",emp_10,id[i]);
                            break;
                        default:
                            break;
                    }
                    break;
				}
				else{
					emp++;
				}
			}
			if (emp==10){
				printf("Cant hire more employs.\n");
			}
    		break;
    		
    	case 2:
    	    printf("Enter Employ ID to fire: ");
    		scanf("%d",&fire);
    		
				if (employs[fire]!='E'){
					employs[fire] ='E';
					switch(fire){
					    case 0:
					        printf ("Successfully Fired %s.\n",emp_1);
					        break;
					    case 1:
					        printf ("Successfully Fired %s.\n",emp_2);
					        break;
					   case 2:
					        printf ("Successfully Fired %s.\n",emp_3);
					        break;
					   case 3:
					        printf ("Successfully Fired %s.\n",emp_4);
					        break;
					   case 4:
					        printf ("Successfully Fired %s.\n",emp_5);
					        break;
					   case 5:
					        printf ("Successfully Fired %s.\n",emp_6);
					        break;
					   case 6:
					        printf ("Successfully Fired %s.\n",emp_7);
					        break;
					   case 7:
					        printf ("Successfully Fired %s.\n",emp_8);
					        break;
					   case 8:
					        printf ("Successfully Fired %s.\n",emp_9);
					        break;
					   case 9:
					        printf ("Successfully Fired %s.\n",emp_10);
					        break;
					   default:
					        break;
					}
				}
				else{
					printf("First hire then fire\n");
				}
			
    		
    		break;
    		
    	case 3:
    		printf("\n====(Employs Data)====\n\nTotal Employ Capacity: 10\n\n");
    		printf("Hired Employs:\n\n");
    		int count=0;
    		for (int i=0; i<10; i++){
    			if (employs[i]!='E'){
    			    switch(i){
					    case 0:
					        printf ("Employ ID: %d\tName: %s\n",i,emp_1);
					        break;
					    case 1:
					        printf ("Employ ID: %d\tName: %s\n",i,emp_2);
					        break;
					   case 2:
					        printf ("Employ ID: %d\tName: %s\n",i,emp_3);
					        break;
					   case 3:
					        printf ("Employ ID: %d\tName: %s\n",i,emp_4);
					        break;
					   case 4:
					        printf ("Employ ID: %d\tName: %s\n",i,emp_5);
					        break;
					   case 5:
					        printf ("Employ ID: %d\tName: %s\n",i,emp_6);
					        break;
					   case 6:
					        printf ("Employ ID: %d\tName: %s\n",i,emp_7);
					        break;
					   case 7:
					        printf ("Employ ID: %d\tName: %s\n",i,emp_8);
					        break;
					   case 8:
					        printf ("Employ ID: %d\tName: %s\n",i,emp_9);
					        break;
					   case 9:
					        printf ("Employ ID: %d\tName: %s\n",i,emp_10);
					        break;
					   default:
					        break;
					}
    				count++;
				}
			}
			printf("\n%d Employs can still be hired.\n\n",10-count);
    		break;
    		
    	case 4:
    		panel_exit=1;
    		break;
    		
    	default :
    		printf("Invalid Option...Retry\n");
    		break;
    		
	}
	if (panel_exit==1){
	    break;
	}
	}  
}




