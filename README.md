# Face-Book
a Social-Media-Platform made in C++ language.

## 1) About
Face-Book app allows members to socialize and communicate with their friends.   
Each member is defined by a unique name, and his date of birth.   
   
The member will be promped with a menu of options, and will choose the desired option to use by entering its option number. 
   
The database of `members` / `fan pages` will be read from a database file each time the app will run. All of the changes will be saved into this file after the exit option is chosen.    
   
> In case the database file does not exist (as when running the program the first time), it will be created with a set of pre-made members and fan pages made for testing.   
<br />

The program checks for `input errors`, and handles `exceptions` depending on their context.   
<br />

#### There is a high emphasis on:
1. OOP principles: `abstraction`, `encapsulation`, `polymorphism`, `inheritance`
2. `overloading` methods and operators
3. `constructor` implementation
4. `exception` handling
<br />

## 2) User Options
### 2.1) Add a New Member
Creates a new member and adds him to the database.   
Checks for validity of the date of birth.   

### 2.2) Add a New Fan Page
Creates a new fan page and edds it to the database.
a fan page represents a business or a shared interest.   

### 2.3) Add a Status to a Member / Fan Page
Creates a new status and adds it to a member **OR** to a fan page.
Checks for input errors, and lets the user choose if the status will be a   
`Status (text)` / `ImageStatus` / `VideoStatus`.   

> The user will get an option to choose between the options.

### 2.4) Show All Statuses of a Member / Fan Page
Prints to the screen all the statuses of a member / fan page.

> The user will get an option to choose between the options.

The format will be:
```
  {content}

   published on: {time of upload}
   This status is printed in {Colorful / Black & White}
   This status is shown using a {simple / playback} program
```  
> **Colorful:** for image or video status<br />
> **Black & White:** for text status<br />
> **Simple program:** for text / image status<br />
> **Playback program:** for video status

<br />

For example for a `VideoStatus` uploaded by user1:
```
   lol :)))

   published on: 18/1/2023, 18:39:40
   This status is printed in Colorful
   This status is shown using a playback program
```
<br />  
 
### 2.5) Show 10 of the Most Recent Statuses of a Member / Fan Page
Prints the 10 most recent status posts of a member **OR** a fan page.   

> The user will get an option to choose between the options.<br />  

### 2.6) Connect Two Members - Add a Friendship
**Adds** a **friendship** between two **members**.<br />  

### 2.7) Disconnect Two Members - Remove a Friendship
**Remove** a **friendship** that exists between two **members**. 

* If they are not friend - an exception will be thrown
<br />  

### 2.8) Add a Member as a Fan of a Fan Page
Add an existing member as a fan to an existing fan page.
   
* If at least one was not found - an exception will be thrown
<br />  

### 2.9) Remove a Member (a Fan) of a Fan Page
Remove a fan to an existing fan page.

* If at least one was not found - an exception will be thrown
<br />  

### 2.10) Show All Members and Fan Pages in the system
Print all existing users in the system.  <br />  

### 2.11) Show All Fans / Friends of a Fan Page / Member
Print all members that were set as fans of a fan page **OR**   
Print all the members that were set as friends of a member.  

> The user will get an option to choose between the options.<br />  

### 2.12) Finish and Quit
This option will close the program and save all the data and all of the changes made since starting the program into a `system.bin` file.   

> Overwrites the `system.bin` file if one already exists
