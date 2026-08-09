# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [Version Control & Markdown Documentation]

- **[ Matthew Reed ]**
- **[ August 8th 2026 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

[CMD's For Windows Command Prompt]
- [ cls ]: Clear the Screen
- [ cd ]: Print the "Working Directory"
- [ dir ]: List files and folders
- [ dir /a ]: List files and folders, including invisible files
- [ dir /b]: List all files and folders, in human readable form. Same as printing working directory
- [ cd 'type folder name from current' ]: Change directory while inside current drive.
- [ cd \ ]: Change directory, go to root directory
- [ cd %USERPROFILE% ]: Change directory and go to user home directory
- [ cd .. ]: Change directory, go up one folder level
- [ cd .. \ .. ]: Change directory, go up two folder levels
- [ cd %USERPROFILE%\OneDrive\Desktop ]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ It Changes the directory from the old directory to the folder directory and then you can print its contents to the terminal. ]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ 1. Local Version Control: all projects stored on single computer and usually only one user with no remote collaboration.]
[2. Centralized Version Control: all files are stored in a centralized server for multiple developers to access or modify files, meaning commits are immediately available for other developers when commit and pushed..]
[3. Distributed version Control: gives each developer a local repository and a working copy of the project so each individual gets a chance to do their own work while not overwriting everyone else.]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone <repository-link]: Clone a repository
- [ git config --global user.name "Your Name' ]: Set-up a global user name
- [ git config --global user.email "youremail@example.com" ]: Set-up a global email address (to match my GitHub account email)
- [ git status ]: Shows the current state of your directory and staging area
- [ git add . ]: Add modified files to the next commit
- [ git commit -m "your commit message" ]: Make a commit with a new message
- [ git log ]: Show my commit history
- [ git help ]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ 1. Create a repository if needed, then copy the repository Https URL for example "https://github.com/reeddevgames-hub/rand.git" ]

[2. Open CMD Prompt and change directories (cd) to the active work project directory folder being used. Then clone the git repository using 'git clone https://github.com/reeddevgames-hub/rand.git'. It will them place a git folder named 'rand' in the work project folder linking that project folder and the repository together. ]

[3. Now move to the new directory with CMD (cd rand) which will open the git folder and make it my active folder path I am in.]

[4. Then i will go to GitHub an generate a new token because GitHub does not generate based on your web browser GitHub profile password. Go to Profile picture >> Select Settings >> Scroll Down to and select 'Developer Settings' >> expand Personal Access Tokens sidebar and select Tokens (classic) >> select Generate new token >> Give token descriptive name like "Windows CMD Access", set expiration length, check main checkbox that says repo so it has full access for commit and pushing to repositories >> select Green "Generate token" and copy and save token.]

[5. Finally when i want to make changes, i will stage with CMD (git add), then commit with CMD (git commit). Windows will ask for credentials, I enter GitHub username, and The Personal Access Token generated earlier, which ill allow me access to repo where files will then be uploaded.]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [The purpose of a .gitignore file is to specify and exclude certain files files from version control tracking. It keeps things clean and secure by preventing temporary artifacts, or logs, or unwanted files or dependencies and prevents them from being pushed to cloud hubs like GitHub.]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [It is a Hidden file found in Mac computers used for storage of folder-specific metadata like colour, icon size, and file order. It is Mac exclusive but can show up on windows if uploaded to shared projects between the two OSs'. It causes clutter and is an unnecessary file for windows users or other mac users besides the original user.]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
- [.vs is a hidden directory automatically generated by Visual Studio. Like the .DS_Store for MacOS, it stores local, individual developer-specific configuration data like open tab history, window layout, debugger breakpoints, etc... It causes unnecessary clutter and should be deleted if not put in .gitignore before Final upload to GitHub.]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ Research Summary: What resource(s) did you find most helpful this past week and why? ]

**Terminal Commands**  
https://www.geeksforgeeks.org/techtips/most-useful-cmd-commands-in-windows/
https://www.geeksforgeeks.org/operating-systems/cmd-dir-command/
https://www.geeksforgeeks.org/techtips/list-all-files-in-a-directory-using-cmd/
https://www.geeksforgeeks.org/techtips/how-to-search-files-using-cmd/
https://www.geeksforgeeks.org/computer-science-fundamentals/os-commands-on-windows/

**Three Types of Version Control**  
https://www.geeksforgeeks.org/git/version-control-systems/

**Git Commands**  
https://www.geeksforgeeks.org/git/useful-git-commands-and-basic-concepts/

**Connecting to GitHub using Terminal**  
https://www.geeksforgeeks.org/git/what-is-git-clone/
https://www.geeksforgeeks.org/git/how-to-generate-personal-access-token-in-github/
https://www.geeksforgeeks.org/git/how-to-authenticate-git-push-with-github-using-a-token/

**Using .gitignore and Why it's Important**  
https://www.geeksforgeeks.org/git/what-is-git-ignore-and-how-to-use-it/
https://www.geeksforgeeks.org/blogs/what-is-ide/
