**Matthew Reed**
**Milestone 3 Markdown**

---
# Features Added:

→ **Binary Data Stream Engine**: Programmed a complete binary initialization engine 'StorageManager' that converts running data arrays into safe 'reinterpret_cast' binary byte-stream allocations on disk.
→ **Primitive Struct Data Contract**: Designed a struct 'AccountRecord' data blueprint utilizing fixed-size character arrays ('char[]') to ensure a permanent, predictable memory footprint for crash-free serialization within the StorageManager.
→ **Non-Secure Public Routing Directory**: Created a secure directory view system that displays public account holder names and destination ID metrics while successfully screening out personal session vectors to prevent accidental internal loops all within the transfer menu choice.
→ **Automated Profile Sub-Account Linking**: Built an account linkage engine that pulls authentication credentials straight from active pointer sessions (the active user profile information), spawning fresh heap allocations without demanding redundant data reentry.
→ 
→ 

---

## Updates to the system:

→ **Cleaned up the loop syntax**: Stripped out the boolean values that added extra code like ("while (is_authenticated == true), if (is_running == false") and updated them to this ("while(!is_authenticated), and if(!is_running)") and added a base definition for is_running set to true in the constructor. 
→ **Enforced Explicit Pointer Containment**: Changed the master registry vector from storing raw Account objects to storing Account pointers ('Account*') inside the header file. This stops object slicing and makes the vector run faster when resizing our database elements.
→ **Integrated Persistent File Synchronization**: Created access hooks inside MenuInterface.cpp to load saved binary accounts automatically on application startup and save registry updates when selecting the exit option.
→ **Dynamic Multi-Account Dashboard**: Updated the main menu screen to loop through the master registry and print the account ID, type, and balance for every account belonging to the logged-in user.
→ 
→ 
→ 
→ 

---

### Refactoring Improvments:

→ **Standardized Coding Conventions**: Refactored function input arguments and structural signatures to strickly use 'snake_case' style. what is updated so far is Account.h, Account.cpp, MenuInterface.h, MenuInterface.cpp, StorageManager.h, StorageManager.cpp, AccountManager.h, AccountManager.cpp, and main.cpp files files.
→ **Eliminated Magic Numbers**: Replaced hardcoded array size allocations ('50') inside the 'strcpy_s' from the constructor code block with the more dynamic 'sizeof(holder_name)' code. This will reduce structural dependencies and prevent memory trunication bugs if the array character storage size is ever altered in the future.
→ **Removed Hardcoded Default Parameters**: Removed the default values of ('= 0.0' and '= 0000') from the Account.h constructor. This folows Clean Code by removing hardcoded magic values, enforces explicit initilization, and stops possible c++ syntax issues with leading zeros compliling into base-8 octal literals.
→ **Implemented Conditional Guard Clauses**: Restructured transactional code within Deposit, Withdraw, and Transfer functions. These methods now use guard clauses to handle error conditions first and exit early, which eliminates un-needed else blocks and cleans up the code logic.
→ **Removed Visual Comment Clutter**: Purged descriptive comments from the 'MenuOption' enum that duplicated what the code already self-documented.
→ **Resolved Large Function Code Sections**: Extracted heavy code execution blocks entirely out of the main controller 'Run()' function and safely isolated them into separate standalone methods ('HandleAccountCreation()' and 'HandleLogin()'). This helps and follows Clean Code explanations by bringing functions into individual functions allowing each function to work independently while while not cluttering up one singular code block.
→ **Eliminated Global Variable Nesting**: Refactored user interface variables (such as 'type_choice', 'user_pin', and 'initial_deposit') away from the 'Run()' function storage and re-declared them locally within their processing functions. This ensures data state variables remain confined strictly to the blocks where they are actively used.
→ **Copy Lifecycle Operations**: Placed explicit '= delete' restrictions on the Copy Constructor and Copy Assignment Operator inside the 'AccountManager.h' header. This disables the ability to initialize or overwrite a manager as a direct copy of an existing instance, sealing the class against duplicate memory tracking and eliminating heap corruption crashes.
→ **Implemented Class Destructor**: Implemented the class Destructor in the AccountManager class header file to properly delete heap allocated pointers on shutdown of the application.
→ **Streamlined Control Evaluation Paths**: Replaced the nested if statements inside the login and creation functions with compact ternary statements to save space and clean up code logic.
→ 
→ 
→ 
→ 
→ 

---