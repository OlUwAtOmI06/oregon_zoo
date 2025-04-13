#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>


using namespace std;


const int adult_mem_fee = 59;
const int children_mem_fee = 39;
const int guest_mem_fee = 79;
string lower(string answer);
string check(string answer);
void introduction();
void member();
void group(int fixed_value);
void group_of_more_than_20();
void group_of_less_than_20();



int main()
{
	//output 
	printf("\n");
	introduction();
        printf("\n\n");
	string ans_1;
	cout << "Are you a member or would you like to be a member? " << endl;
	cout << "(Membership is the perfect Plan for those who visit the zoo more than 3 times a year)" << endl;
	cout << "Please Enter [Yes/No] ";
	cin >> ans_1;
        ans_1 = lower(ans_1);
	check(ans_1);
	printf("\n\n");
	if(ans_1 == "yes")	
	    {
	    member();
	    }
	else
         	{string group_size;
		cout << "Is the amount of adult and children in the up to 20? " << endl;
		cout << "Please Enter [Yes/No] ";
		cin >> group_size;
		group_size = lower(group_size);
		check(group_size);
		printf("\n\n");
		if(group_size == "yes")
	        	{group_of_more_than_20();
			}
		else
		{
		 group_of_less_than_20();

		
		 }
	
		}
return 0;}

























string lower(string answer)
{for(char &c : answer)
{c = tolower(c);	}
	return answer;
}

string check(string answer)
{while(answer != "yes" && answer != "no")
	{cout << "Please Enter [Yes/No] ";
	cin >> answer;
	}
	return answer;
}

void introduction()
{
        printf("Welcome to the Oregon zoo Calculator. \n"); //introducing the code
        printf("For this calculator everyone under the age of 2 has free entry to the zoo in compliance with the zoo regulation. \n");
        printf("From ages 2 - 11 is classified as a child and ages 12 - UP as an adult. \n");
        printf("Thanks for your understanding and time. \n");
}

void member()
{         
            string mem_check;
            cout << "Is your membership active? " << endl;
            cout << "Please Enter [Yes/No] ";
            cin >> mem_check;
            mem_check = lower(mem_check);
            check(mem_check);
            if(mem_check == "yes")
                   {
                    printf("As an active member of the zoo you are able to visit for free \n ");
                   }
            else
                    {
                     int adult_num;
                     cout << "How many adults interested in this membership? ";
                     cin >> adult_num;
                     int children_num;
                     cout << "How many children are interested in this membership? ";
                     cin >> children_num;
                     int guest_num;
                     cout << "How many guest may follow your  membership on average? ";
                     cin >> guest_num;
                     int total_mem = (adult_mem_fee * adult_num) + (children_mem_fee * children_num) + (guest_mem_fee * guest_num);

                     printf("Based on your input your estimate is $%d \n", total_mem);
                     }
         

}

void group(int fixed_value)
{      int size;
       cout <<"How many are you in the group ";
       cin >> size;
       while (size <= 20)
                 {cout << "The group must be greater than 20? ";
                 cin >> size;
		 }

                  int total = fixed_value * size;
                   printf("The group estimate would be $%d ", total);
		   printf("\n\n");
}


void group_of_more_than_20()
  {    string group_type;
       cout << "Is group non-profit" << endl;
       cout << "Please Enter [Yes/No] ";
       cin >> group_type;
       group_type = lower(group_type);
       check(group_type);
       if(group_type == "yes")
               {const int fixed = 13;
                 group(fixed);
                }
       else
            {const int profit_fixed = 19;
             group(profit_fixed);
              }


   }




void group_of_less_than_20()
{               string qualified;
                cout << "Do the members of the Group qualify for the followiing: " << endl;
                cout <<"(1) Income Assistance " <<endl;
                cout <<"(2) Are Oregon or Washington resisdent and can you a state lincensed Id as proof " <<endl;
                cout <<"Please note you must match both qualifications to click yes else click no [Yes/No] ";
                cin >> qualified;
                qualified = lower(qualified);
                check(qualified);
                int adult;
                int children;
                const int adult_non_mem_fee = 26;
                const int children_non_mem_fee = 21;
                cout << "Enter how many adult? ";
                cin >> adult;
                printf("\n");
                cout << "Enter how many children? ";
                cin >> children;

                int price;
                printf("\n\n");
                       if(qualified == "yes")
                       {int flat_rate = 13;
                        int sub = 4;
                        int discout_count = children + adult;
                        printf("\n\n");
                                if (discout_count <= sub)
                              {
                              price = discout_count * flat_rate;
                              cout <<"BASED ON ALL INFORMATION PROVIDED YOUR TRIP PRICE IS $" << price << endl;

                              }
                                else
                              { int discounted_adults = min(adult, sub);
                                int discounted_remaining = sub - discounted_adults;
                                int discounted_children = min(children, discounted_remaining);

                                // Remaining adults pay $26
                                int remaining_adults = adult - discounted_adults;

                                // Remaining children pay $21
                                int remaining_children = children - discounted_children;

                                price += discounted_adults * flat_rate;
                                price += discounted_children * flat_rate;
                                price += remaining_adults * adult_non_mem_fee;
                                price += remaining_children * children_non_mem_fee;
                                cout <<"BASED ON ALL INFORMATION PROVIDED YOUR TRIP PRICE IS $" << price << endl;

                              }
                       }
                       else
                           {price = (adult * adult_non_mem_fee) + (children * children_non_mem_fee);
                                     cout <<"BASED ON ALL INFORMATION PROVIDED YOUR TRIP PRICE IS $" << price << endl;


                           }


                }

