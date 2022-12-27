
#include<bits/stdc++.h>
#include<iostream>
#include<string.h>

using namespace std;

class calender
{
	private:
		
	public:
		 
		int dayNumber(int day, int month, int year)   	//returns the index of the day of the date- day/month/year
		{
 
    			static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    			year -= month < 3;
    			return ( year + year/4 - year/100 +	year/400 + t[month-1] + day) % 7;
		}
		
		string getMonthName(int monthNumber)			//returns name of the month with given month number 
		{
    			string months[] = {"January", "February", "March",
                       "April", "May", "June",
                       "July", "August", "September",
                       "October", "November", "December"
                      			};
 
    			return (months[monthNumber]);
		}
		
		int numberOfDays (int monthNumber, int year)		//returns the days in the month 
		{
    		// January
    		if (monthNumber == 0)
        	return (31);
 
    		// February
    		if (monthNumber == 1)
    		{
        		// If the year is leap then February has
        		// 29 days
        		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        		{
        			return (29);
				}
        		else
				{
					return (28);
				}
        	}
        	
        	// March
    		if (monthNumber == 2)
        	return (31);
 
    		// April
    		if (monthNumber == 3)
        	return (30);
 
    		// May
    		if (monthNumber == 4)
        	return (31);
 
    		// June
    		if (monthNumber == 5)
        	return (30);
 
    		// July
    		if (monthNumber == 6)
        	return (31);
 
    		// August
    		if (monthNumber == 7)
        	return (31);
 	
    		// September
    		if (monthNumber == 8)
        	return (30);
 
    		// October
    		if (monthNumber == 9)
        	return (31);
 
    		// November
    		if (monthNumber == 10)
        	return (30);
 
    		// December
    		if (monthNumber == 11)
        	return (31);
		}
		
		
		void printCalendar()
		{
    		int year;
    		cout<<"\nEnter the year:";
    		cin>>year;
			printf ("         Calendar - %d\n\n", year);
    		int days;
 
    		// Index of the day from 0 to 6
    		int current = dayNumber (1, 1, year);
 
    		// i --> Iterate through all the months
    		// j --> Iterate through all the days of the
    		//       month - i
    		for (int i = 0; i < 12; i++)
    		{
        		days = numberOfDays (i, year);
 	
        		// Print the current month name
        		printf("\n  ------------%s-------------\n",getMonthName (i).c_str());
 
        		// Print the columns
        		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
 
        		// Print appropriate spaces
        		int k;
        		
        		for (k = 0; k < current; k++)
            	{
					printf("     ");
 				}
        		for (int j = 1; j <= days; j++)
        		{
            		printf("%5d", j);
 
            		if (++k > 6)
            		{
                		k = 0;
                		printf("\n");
            		}
        		}
 
        		if (k)
            	{
					printf("\n");
 				}
        		current = k;
    		}
 
    		return;
		}
		
		void leapyear()
		{
			int year;
			cout<<"\nEnter the year:";
			cin>>year;
			
        	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        	{
        		cout<<"\nThe year is Leap year !";
			}
        	else
			{
				cout<<"\nThe year is not leap year !";
			}
        }
		
};


int main()
{
    calender c;
    int choice;
    do
	{
		cout<<"\n1. Print Calender"
			"\n2. Predict Leap year";
		cout<<"\nEnter the choice:";
    	cin>>choice;
    	switch(choice)
		{
			case 1:
    			c.printCalendar();
    			break;
    			
    		case 2:
    			c.leapyear();
    			
    		default:
    			cout<<"\nExit !";
    	}
    	
    }while(choice!=3); 
    
	return (0);
}
	
