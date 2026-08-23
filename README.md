

# Project & Portfolio 1

### Matthew Reed

Hello my name is Matthew Reed. I am a student from Oregon. The purpose of this repository is to practice development using version control. This work will help me begin to build a portfolio of skills and accomplishment that can be shared in the future.

<br>

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

⚙️ Overview - What I worked on this past week
<br>
🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - What is something I "leveled up" on this week
<br>
🔮 Next Steps - What I plan to prioritize and do next

<br>

### Week 1

End of Week Stand-Up Update:                           Overview - What I worked on this past week 

This week I worked on my version control.md Markdown file. I created a basic Bank Account System project, with 6 classes. I focused on Creating and coding an Account class Which holds the users account information for now, a Consol Utilities Class called ‘ConsoleUtil’ it has an Enum for coloring text and Write and WriteLine functions taken from inspiration from the card game in PG2 I believe. 
I created a MenuInterface class to pull the information from the Account.h  and ConsoleUtil.h, and write out the information to the console when prompted. It is also where the main Run function is linked to the account and users' input in order to get the user to create an account and display that new account information and Main Menu display.

Challenges - What problems did I have & how I'm addressing them: A problem that I had was figuring out how to make the Write and WriteLine functions like the instructors did. After figuring out how to create those functions, I was able to write out colored text to the console which at the moment is the extent of my artistic capabilities.

Accomplishments - What is something I "leveled up" on this week: I figured out a way to write code using Write and WriteLine making it colorful which I am proud of. Another thing i am proud of is that I planned and thought through a bit more before I started. I have other classes i want to implement later to add more to the Application.

Next Steps - What I plan to prioritize and do next: For this next week I want to code my Bank System which will store multiple different Accounts created by the user, if the user wants to stay with their main account, they can add sub accounts in the account.h file which would be the savings and/or checking account or a credit account.

### Week 2

End of Week 2 Stand-UP: 
Update: So far thus week I've worked on getting my account manager working that should be able to access multiple stored accounts in its vector. I also got the base for my user input filtration code up and running but i am still working out the kinks for it. 

Challenges: I've been finding places in my testing where i have had to press enter multiple times, so i am still finding out where I've gone wrong there. 

Accomplishments: This week i am proud of myself because i have been working on my code and assignments throughout the week, but i need to give even more time throughout the week still. 

What Next : This next week I plan on working on my storageManager class so i can have accounts be saved to a binary file that can be accessed in the next test and still have the old accounts. I'm still not entirely done with coding so i am going to take a break for the night since i have been working on it all day and i will finish it tomorrow.

### Week 3

  Weekly Stand-Up
 Overview - What I worked on this past week:
This week, I focused on setting up a database layer for the banking app. I changed the master registry vector from storing raw Account objects to storing Account pointers (Account*) inside the header file. I also created a binary file synchronization inside MenuInterface.cpp to load saved binary accounts automatically on application startup and save registry updates when selecting the exit option.

 Challenges - What problems did I have & how I'm addressing them:
Changing the master registry vector over to track pointers broke my old search loops and validation functions, throwing multiple compiler errors. I addressed this by refactoring my processing loops to swap out standard dot operators for pointer arrow operators. I also fixed a missing semicolon syntax typo inside the StorageManager.h file that was causing some build failures.

 Accomplishments - What is something I "leveled up" on this week:
I leveled up on C++ memory safety and cleaning up code logic. I implemented the class Destructor in the AccountManager class to properly delete heap allocated pointers on shutdown, and placed explicit '= delete' restrictions on the Copy Constructor and Copy Assignment Operator to stop any abrupt crashes. I also replaced nested if statements with compact ternary statements to save space (Which i also found neat since I forgot you could use ternary statements).

 Next Steps - What I plan to prioritize and do next
Now that the main menu screen loops through the master registry and prints the account ID, type, and balance for every account belonging to the logged-in user, my next step is upgrading my transactions. I plan to add a quick prompt inside our deposit and withdrawal options so users can select exactly which account ID they want to modify during their session.

### Week 4

My final stand up...
