**Matthew Reed**
**Milestone 3 Markdown**

---
# Features Added:
**What features have been added this week? What does it do?**
→

---

## Updates to the system:
**Did you update any code in the system? If so, what did you update and why?**
→

→

---

### Refactoring Improvments:
**Was any refactoring done this week? If so, what was refactored and why?**
→ **Standardized Coding Conventions**: Refactored function input arguments and structural signatures to strickly use 'snake_case' style. what is updated so far is Account.h, and Account.cpp files.
→**Eliminated Magic Numbers**: Replaced hardcoded array size allocations ('50') inside the 'strcpy_s' from the constructor code block with the more dynamic 'sizeof(holder_name)' code. This will reduce structural dependencies and prevent memory trunication bugs if the array character storage size is ever altered in the future.
→**Removed Hardcoded Default Parameters**: Removed the default values of ('= 0.0' and '= 0000') from the Account.h constructor. This folows Clean Code by removing hardcoded magic values, enforces explicit initilization, and stops possible c++ syntax issues with leading zeros compliling into base-8 octal literals.
→**Implemented Conditional Guard Clauses**: Restructured transactional code within Deposit, Withdraw, and Transfer functions. These methods now use guard clauses to handle error conditions first and exit early, which eliminates un-needed else blocks and cleans up the code logic.

---