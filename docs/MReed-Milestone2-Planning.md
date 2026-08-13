> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name:**
→   Banking Account System
  
**What does your program currently do? (1–3 sentences)**   
→ Currently the Program tells you to create an account with the company, then displays that new account information and the Main Menu. Then you can choose from the Deposit or Withdraw choices to and follow the prompts to add or withdraw money. then you can exit the application which closes it entirely. 

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   I am currently working on the Instructor critiques to the code that was shown to them.
  
**What is NOT working or incomplete?**   
→ I need to add BankSystem class renamed to AccountManager class code and reformat the Run function to pull from that class instead of the current Account class that it is pulling from.
  
**What feels confusing or messy in your code?**   
→ My Code is currently only in .h files so it is messy and must be put into .cpp and .h folders together.

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   
→   Transfer
  
**What does this feature do?**   
→   This feature with work with the stored accounts and transfer money from other accounts to different accounts.
  
**Why is this feature important?**   
→   It will add the simulation of moving money between accounts creating more for the user to choose from.
  
---
### Feature 2  
**Name:**   
→   Storage Manager
  
**What does this feature do?**   
→   It stores all created accounts and writes to a binary file to be accessible even after the console application has been closed and reopened.
  
**Why is this feature important?**   
→   It is important because it allows access to other accounts to utilize the other features in place.
  
---
### Feature 3 (optional)  
**Name:**   
→ Login 
  
**What does this feature do?**   
→ Login will allow you to log in to your existing account.
  
**Why is this feature important?**   
→ It will allow returning users to access their account that is already there instead of having to create a new one.

---
### Feature 4 (optional)  
**Name:**   
→ Verify Account is yours  
  
**What does this feature do?**   
→ This feature will ask you to verify the account is yours with a password/pin you created in order to access other accounts (say to transfer money from one of your accounts to another)
  
**Why is this feature important?**   
→   It will add security to the users account so that only the right user can access that account.

---
### Feature 5 (optional)  
**Name:**   
→ Checking/Savings Accounts
  
**What does this feature do?**   
→ This feature will add the Checking and savings account options for when you create an account and the account will be labeled accordingly while also providing interest for certain accounts.
  
**Why is this feature important?**   
→   It will allow users more options to choose from whether they want an account to have all their money in or one that will increase in value over time or both.
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   StorageManager (For Feature 2): A dedicated utility class that handles saving and loading accounts to and from the binary file on a disk.

→ AccountManager (For Features 1, 3, 4, 5): A central database/controller class. Right now the MenuInterface class interacts with exactly one Account. This new class will hold all accounts, handle lookups for transfers, verify logins/PINs, and track which account is currently active.
  
**Will you modify any existing classes? How?**   
→   Account Class Modifications:
Adding a PIN/Password field (Feature 4): Add a 'char pin[5]' or 'int pin' variable to store accounts security code. 
Add an Account Type indicator (Feature 5): Add an enum AccountType with Checking and Savings  account variables.



**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   User creates account or signed into existing account if one was already created.
2. User chooses →   Whether they want to make a deposit, withdrawal, Transfer money or exit the app.
3. Program responds →   With whichever choice is choses and prompts user for the details needed for that feature.
4. Loop/next step →   After loop ends, you are send back to the main menu, then the user can choose an additional option or exit the program.
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   
  
- Better error handling:   
→   
  
- Improved menu/navigation:   
→   
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   
  
- Better error handling:   
→   
  
- Improved menu/navigation:   
→   
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   
  
**What is your plan if you get stuck?**   
→   
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   
  
**What is your plan if you get stuck?**   
→   
  
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→   
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [ ]   
- [ ]   
- [ ]   
- [ ]   
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [ ] Do I know what I’m building this week?   
- [ ] Do I know where to start?   
- [ ] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> Plan it now… or debug it later.