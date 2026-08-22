**Matthew Reed**
**Milestone 3 Markdown**

---
# Features Added:
**What features have been added this week? What does it do?**
→

---

## Updates to the system:
**Did you update any code in the system? If so, what did you update and why?**
→ **Cleaned up the loop syntax**: Stripped out the boolean values that added extra code like ("while (is_authenticated == true), if (is_running == false") and updated them to this ("while(!is_authenticated), and if(!is_running)") and added a base definition for is_running set to true in the constructor. 
→ 
→

---

### Refactoring Improvments:
**Was any refactoring done this week? If so, what was refactored and why?**
→ **Standardized Coding Conventions**: Refactored function input arguments and structural signatures to strickly use 'snake_case' style. what is updated so far is Account.h, Account.cpp, MenuInterface.h and MenuInterface.cpp files.
→ **Eliminated Magic Numbers**: Replaced hardcoded array size allocations ('50') inside the 'strcpy_s' from the constructor code block with the more dynamic 'sizeof(holder_name)' code. This will reduce structural dependencies and prevent memory trunication bugs if the array character storage size is ever altered in the future.
→ **Removed Hardcoded Default Parameters**: Removed the default values of ('= 0.0' and '= 0000') from the Account.h constructor. This folows Clean Code by removing hardcoded magic values, enforces explicit initilization, and stops possible c++ syntax issues with leading zeros compliling into base-8 octal literals.
→ **Implemented Conditional Guard Clauses**: Restructured transactional code within Deposit, Withdraw, and Transfer functions. These methods now use guard clauses to handle error conditions first and exit early, which eliminates un-needed else blocks and cleans up the code logic.
→ **Removed Visual Comment Clutter**: Purged descriptive comments from the 'MenuOption' enum that duplicated what the code already self-documented.
→ **Resolved Large Function Code Sections**: Extracted heavy code execution blocks entirely out of the main controller 'Run()' function and safely isolated them into separate standalone methods ('HandleAccountCreation()' and 'HandleLogin()'). This helps and follows Clean Code explanations by bringing functions into individual functions allowing each function to work independently while while not cluttering up one singular code block.
→ **Eliminated Global Variable Nesting**: Refactored user interface variables (such as 'type_choice', 'user_pin', and 'initial_deposit') away from the 'Run()' function storage and re-declared them locally within their processing functions. This ensures data state variables remain confined strictly to the blocks where they are actively used.
→
→
→
→
→
→
→
→

---